#include "Booster.h"
#include "Enemy.h"
#include "Player.h"
#include "Score.h"

#include <random>
#include <iostream>


Booster::Booster(int digit)
{
	//accelerator
	if(digit == 1)
	{
		//sf::Color color(255, 140, 0);
		booster.setSize(sf::Vector2f(30.f, 29.f));//rozmiar obrazka
	//	booster.setFillColor(color);
		booster.setPosition(sf::Vector2f(-50.f, -50.f));

		std::string spriteName;
		spriteName = "obrazki/booster/accel.png";
		if (!accelTexture.loadFromFile(spriteName))
		{
			booster.setFillColor(sf::Color::Yellow);
			std::cout << "nie udalo sie zaladwac obrazka" <<spriteName<< '\n';
		}
		accelSprite.setTexture(accelTexture);
		accelSprite.setPosition(booster.getPosition().x, booster.getPosition().y);
	}
	//destroyer
	else if (digit == 2)
	{
		//sf::Color color (136, 8, 8);
		destroyer.setSize(sf::Vector2f(28.f, 30.f));
		//destroyer.setFillColor(color);
		destroyer.setPosition(sf::Vector2f(-50.f, -50.f));

		std::string spriteName;
		spriteName = "obrazki/booster/destroyer.png";
		if (!destroyerTexture.loadFromFile(spriteName))
		{
			destroyer.setFillColor(sf::Color::Red);
			std::cout << "nie udalo sie zaladwac obrazka" << spriteName << '\n';
		}
		destroyerSprite.setTexture(destroyerTexture);
		destroyerSprite.setPosition(destroyer.getPosition().x, destroyer.getPosition().y);
	}
	//slower
	else if (digit == 3)
	{
		//sf::Color color(176, 224, 230);
		slower.setSize(sf::Vector2f(22.f, 22.f));
		//slower.setFillColor(color);
		slower.setPosition(sf::Vector2f(-50.f, -50.f));

		std::string spriteName;
		spriteName = "obrazki/booster/slower.png";
		if (!slowerTexture.loadFromFile(spriteName))
		{
			slower.setFillColor(sf::Color::White);
			std::cout << "nie udalo sie zaladwac obrazka" << spriteName << '\n';
		}
		slowerSprite.setTexture(slowerTexture);
		slowerSprite.setPosition(slower.getPosition().x, slower.getPosition().y);
	}
	//friendly
	else if (digit == 4)
	{
		//sf::Color color(124, 252, 0);
		friendly.setSize(sf::Vector2f(32.f, 32.f));
		//friendly.setFillColor(color);
		friendly.setPosition(sf::Vector2f(-50.f, -50.f));

		std::string spriteName;
		spriteName = "obrazki/booster/friendly.png";
		if (!friendlyTexture.loadFromFile(spriteName))
		{
			friendly.setFillColor(sf::Color::White);
			std::cout << "nie udalo sie zaladwac obrazka" << spriteName << '\n';
		}
		friendlySprite.setTexture(friendlyTexture);
		friendlySprite.setPosition(friendly.getPosition().x, friendly.getPosition().y);

	}
	//helper
	else if (digit == 5)
	{
		//sf::Color color(52, 235, 195);
		helper.setSize(sf::Vector2f(32.f, 32.f));
		//helper.setFillColor(color);
		helper.setPosition(-90.f, -90.f);

		std::string spriteName;
		spriteName = "obrazki/booster/helper.png";
		if (!helperTexture.loadFromFile(spriteName))
		{
			helper.setFillColor(sf::Color::White);
			std::cout << "nie udalo sie zaladwac obrazka" << spriteName << '\n';
		}
		helperSprite.setTexture(helperTexture);
		helperSprite.setPosition(helper.getPosition().x, helper.getPosition().y);

	}
	//shot
	else if (digit == 6)
	{
		for (int i = 0; i < NUMBER_OF_SHOTS; i++)
		{


			shot[i].setSize(sf::Vector2f(10.f, 3.f));
			//shot[i].setFillColor(sf::Color::White);
			shot[i].setPosition(-600.f, -360.f);
			shot[i].setRotation(-90.f*i - 135.f);

			std::string spriteName;
			spriteName = "obrazki/booster/shot.png";
			if (!shotTexture.loadFromFile(spriteName))
			{
				shot[i].setFillColor(sf::Color::White);
				std::cout << "nie udalo sie zaladwac obrazka" << spriteName << '\n';
			}
			shotSprite[i].setTexture(shotTexture);
			shotSprite[i].setPosition(shot[i].getPosition().x, shot[i].getPosition().y);
			shotSprite[i].setOrigin(15.f, 2.f);
			shotSprite[i].setRotation(  135.f - 90.f * i);
			
		}
	}
}

//tutaj chce wyœwietlacz czas respawnu boostera po jego zebraniu itp
void Booster::showTime(std::string name, int cooldown, sf::Time timeLeft, sf::Vector2f position )
{	
	arial.loadFromFile("arial.ttf");
	showedTime.str("");

	if ((cooldown / 1000 - timeLeft.asMilliseconds() / 1000) <= 0)
	{
		showedTime << name << " is ready!";
	}

	else
	{
		showedTime << name <<" respawns in: " << cooldown/1000 - timeLeft.asMilliseconds()/1000;
	}

	timeVis.setCharacterSize(20);
	timeVis.setPosition(position);
	timeVis.setFont(arial);
	timeVis.setString(showedTime.str());
}



void Booster::spawnBooster()
{
	sf::Time timeAcc = respawnTimeAcc.getElapsedTime();
	std::random_device pos;
	std::uniform_real_distribution<float> rangeX(0, 1280 - booster.getSize().x);
	std::uniform_real_distribution<float> rangeY(0, GROUND_HEIGHT - booster.getSize().y);	

	if (timeAcc.asMilliseconds() >= cooldownAccelerator && boosterCanBeSpawned[0] == true)
	{
		booster.setPosition(rangeX(pos), rangeY(pos));
		boosterCanBeSpawned[0] = false;
	}	
	accelSprite.setPosition(booster.getPosition().x, booster.getPosition().y);

}


void Booster::spawnDestroyer()
{
	sf::Time time = respawnTimeDes.getElapsedTime();
	std::random_device pos;
	std::uniform_real_distribution<float> rangeX(0, 1280 - destroyer.getSize().x);
	std::uniform_real_distribution<float> rangeY(0, GROUND_HEIGHT - destroyer.getSize().y);

	if (time.asMilliseconds() >= cooldownDestroyer && boosterCanBeSpawned[1] == true)
	{
		destroyer.setPosition(rangeX(pos), rangeY(pos));
		boosterCanBeSpawned[1] = false;
	}
	destroyerSprite.setPosition(destroyer.getPosition().x, destroyer.getPosition().y);

}

void Booster::spawnSlower()
{
	sf::Time time = respawnTimeSlo.getElapsedTime();
	std::random_device pos;
	std::uniform_real_distribution<float> rangeX(0, 1280 - slower.getSize().x);
	std::uniform_real_distribution<float> rangeY(0, GROUND_HEIGHT - slower.getSize().y);

	if (time.asMilliseconds() >= cooldownSlower && boosterCanBeSpawned[2] == true)
	{
		slower.setPosition(rangeX(pos), rangeY(pos));
		boosterCanBeSpawned[2] = false;
	}	
	slowerSprite.setPosition(slower.getPosition().x, slower.getPosition().y);

}

void Booster::spawnFriendly()
{
	sf::Time time = respawnTimeFri.getElapsedTime();

	std::random_device pos;
	std::uniform_real_distribution<float> rangeX(0, 1280 - friendly.getSize().x);
	std::uniform_real_distribution<float> rangeY(0, GROUND_HEIGHT - friendly.getSize().y);

	if (time.asMilliseconds() >= cooldownFriendly && boosterCanBeSpawned[3] == true)
	{
		friendly.setPosition(rangeX(pos), rangeY(pos));
		//friendly.setPosition(300.f, 237.f);
		boosterCanBeSpawned[3] = false;
	}
	friendlySprite.setPosition(friendly.getPosition().x, friendly.getPosition().y);

}

void Booster::spawnHelper(int digit)//TO NIE JEST TO SAMO CO FRIENDLY! HELPER TO TEN CO LATA PO PLANSZY, FRIENDLY TO COLLECTABLE KLOCEK, "BOOSTER"!
{

	if (digit == 1)
	{

		std::random_device pos;
		std::uniform_real_distribution<float> rangeX(0, 1280 - helper.getSize().x);
		std::uniform_real_distribution<float> rangeY(0, GROUND_HEIGHT - helper.getSize().y);


		helper.setPosition(sf::Vector2f(rangeX(pos), rangeY(pos)));
		helperSprite.setPosition(helper.getPosition().x, helper.getPosition().y);

	}
	if (digit != 1)
	{
		helper.setPosition(sf::Vector2f(-93.f, -99.f));
		helperSprite.setPosition(helper.getPosition().x, helper.getPosition().y);
	}
}



void Booster::accel(Player* object) 
{	
	sf::Time time = timePassed.getElapsedTime();
	int duration = 10000;	
	showTime("Accelerator", cooldownAccelerator, time, sf::Vector2f (600.f,620.f));

	if (time.asMilliseconds() >= duration)//musi byc przed tym drugim ifem - inaczej po zebraniu czasem sie nie zalacza booster, czas sie resetuje w kolejnym wywolaniu funkcji dopiero?
	{
		boosterActive = false;
	}

	if (object->getShape().getGlobalBounds().intersects(booster.getGlobalBounds()))
	{
		timePassed.restart();
		boosterActive = true;
		booster.setPosition(-50.f, -50.f);
		respawnTimeAcc.restart();
		boosterCanBeSpawned[0] = true;
	}
	object->movementPlayer(boosterActive);
}

void Booster::destroy(Player* object, Enemy* enemy, Score* score)
{	
	shellNo = object->NUMBER_OF_SHELL;
	sf::Time time = timePassedDes.getElapsedTime();
	sf::Time timeEnemyRespawn[NUMBER_OF_ENEMIES];
	int duration = 5000;
	showTime("Destroyer", cooldownDestroyer, time, sf::Vector2f(880.f, 620.f));

	for (int j = 0; j < NUMBER_OF_ENEMIES; j++)
	{
		enemy->enemyIsDead(j);
	}	
	
	if (object->getShape().getGlobalBounds().intersects(destroyer.getGlobalBounds()))
	{
		timePassedDes.restart();
		boosterActiveDes = true;
		destroyer.setPosition(-100.f, -100.f);		
		respawnTimeDes.restart();		
		boosterCanBeSpawned[1] = true;
	}
	object->glowPlayer(boosterActiveDes);
	

	for (int i = 0; i < NUMBER_OF_ENEMIES; i++)
	{
		for (int j = 0; j<shellNo;j++)
		{
			if (boosterActiveDes == true && object->getShapeShell(j).getGlobalBounds().intersects(enemy->getShape(i).getGlobalBounds()))
			{
				enemy->teleportEnemy(i);
				boosterActiveDes = false;
				score->getScore(5);
			}
		}
	}
	//std::cout << "destroyer active: " << boosterActiveDes << '\n';
}




void Booster::slow(Player* object, Enemy* enemy)
{
	sf::Time time = timePassedSlo.getElapsedTime();	
	sf::Time timeToShow = timePassedSloShow.getElapsedTime();
	int duration = 5000;
	showTime("Slower", cooldownSlower, timeToShow, sf::Vector2f(600.f, 660.f));
	if (boosterActiveSlo == false)
	{
		for (int i = 0; i < NUMBER_OF_ENEMIES; i++)
		{
			enemy->moveEnemy(i, boosterActiveSlo);
			enemy->moveEnemySprite(i);
		}
		timePassedSlo.restart();
	}

	if (object->getShape().getGlobalBounds().intersects(slower.getGlobalBounds()))
	{
		boosterActiveSlo = true;
		slower.setPosition(-150.f, -150.f);
		respawnTimeSlo.restart();
		boosterCanBeSpawned[2] = true;
		timePassedSloShow.restart();
	}

	if (boosterActiveSlo == true && time.asMilliseconds() < duration)
	{
		for (int i = 0; i < NUMBER_OF_ENEMIES; i++)
		{
			enemy->moveEnemy(i, boosterActiveSlo);
			enemy->moveEnemySprite(i);
		}		
	}

	else if (time.asMilliseconds() > duration)
	{
		boosterActiveSlo = false;
	}
}

void Booster::friendShots(Player* object, Enemy* enemy, Booster* helps, Booster* ptrShot, Score* score)
{	
	sf::Time time = timePassedFri.getElapsedTime();
	sf::Time timeToShow = timePassedFriShow.getElapsedTime();
	sf::Time timeEnemyRespawn[NUMBER_OF_ENEMIES];
	showTime("Friend", cooldownFriendly, timeToShow, sf::Vector2f(880.f, 660.f));

	for (int j = 0; j < NUMBER_OF_ENEMIES; j++)
	{
		enemy->enemyIsDead(j);
	}

	int helperDuration = 5000;
	int boosterDuration = helperDuration*2;
	int intervalBetweenShots = 500;

	if (object->getShape().getGlobalBounds().intersects(friendly.getGlobalBounds()))
	{
		timePassedFri.restart();
		boosterActiveFri = true;
		friendly.setPosition(-90.f, -90.f);
		respawnTimeFri.restart();
		helps->spawnHelper(1);
		boosterCanBeSpawned[3] = true;
		timePassedFriShow.restart();

	}

	if (boosterActiveFri == true && time.asMilliseconds() < boosterDuration)
	{
		if (time.asMilliseconds() < helperDuration)
		{
			helps->moveHelper();
		}

		else if (time.asMilliseconds() > helperDuration)
		{
			helps->spawnHelper(2);
		}

		for (int j = 0; j < NUMBER_OF_ENEMIES; j++)
		{
			for (int i = 0; i < NUMBER_OF_SHOTS; i++)
			{
				if (ptrShot->getShotShape(i).getGlobalBounds().intersects(enemy->getShape(j).getGlobalBounds()))
				{
					killedByBullet[j] = true;
					enemy->teleportEnemy(j);
					score->getScore(5);
				}
			}
		}
	}
	else
	{
		boosterActiveFri = false;
		helps->spawnHelper(2);
		timePassedFri.restart();//musze tutaj resetowaæ czas, bo inaczej po up³ywie czasu o wartoœci 'duration' if odpowiedzialny za helps->moveHeler() nie dostaje time = 0 tylko np 5623ms
	}
	for (int i = 0; i < NUMBER_OF_SHOTS; i+=4)
	{
		if (time.asMilliseconds() > (i/4) * intervalBetweenShots && time.asMilliseconds() < (i/4) * intervalBetweenShots + 25)
		{
			for (int j = i; j < i+4; j++)
			{
				ptrShot->spawnShot(enemy, helps, j);
			}
		}
		if (time.asMilliseconds() > (i / 4) * intervalBetweenShots)
		{
			for (int j = i; j < (i + 4); j++)
			{
				ptrShot->moveShot(j);
			}
		}
	}
	

}




void Booster::spawnShot(Enemy* enemy, Booster* helps, int digit)//tego nie wywo³ujê w Game.cpp tylko w funkcji metodzie friendShots z klasy Booster
{
	for (int i = 0; i < NUMBER_OF_SHOTS; i += 4)
	{
		if (digit == i /*|| digit == 4 || digit == 8*/)
		{
			shot[digit].setPosition(sf::Vector2f(helps->getHelperShape().getPosition().x,
				helps->getHelperShape().getPosition().y));
		}
		if (digit == i+1 /*|| digit == 5 || digit == 9*/)
		{
			shot[digit].setPosition(sf::Vector2f(helps->getHelperShape().getPosition().x,
				helps->getHelperShape().getPosition().y + helps->getHelperShape().getSize().y));
		}
		if (digit == i+2 /*|| digit == 6 || digit == 10*/)
		{
			shot[digit].setPosition(sf::Vector2f(helps->getHelperShape().getPosition().x + helps->getHelperShape().getSize().x,
				helps->getHelperShape().getPosition().y + helps->getHelperShape().getSize().y));
		}
		if (digit == i+3 /*|| digit == 7 || digit == 11*/)
		{
			shot[digit].setPosition(sf::Vector2f(helps->getHelperShape().getPosition().x + helps->getHelperShape().getSize().x,
				helps->getHelperShape().getPosition().y));
		}
	}
}

void Booster::moveShot(int digit)
{
	for (int i = 0; i < NUMBER_OF_SHOTS; i += 4)
	{
		if (digit == i)
		{
			shot[digit].setPosition(shot[digit].getPosition().x - movXSHOT, shot[digit].getPosition().y - movYSHOT);
			shotSprite[digit].setPosition(shot[digit].getPosition().x, shot[digit].getPosition().y);
		}
		if (digit == i+1)
		{
			shot[digit].setPosition(shot[digit].getPosition().x - movXSHOT, shot[digit].getPosition().y + movYSHOT);
			shotSprite[digit].setPosition(shot[digit].getPosition().x, shot[digit].getPosition().y);
		}
		if (digit == i+2)
		{
			shot[digit].setPosition(shot[digit].getPosition().x + movXSHOT, shot[digit].getPosition().y + movYSHOT);
			shotSprite[digit].setPosition(shot[digit].getPosition().x, shot[digit].getPosition().y);
		}
		if (digit == i+3)
		{
			shot[digit].setPosition(shot[digit].getPosition().x + movXSHOT, shot[digit].getPosition().y - movYSHOT);
			shotSprite[digit].setPosition(shot[digit].getPosition().x, shot[digit].getPosition().y);
		}
	}
}



float Booster::changeDirection(float& mov)
{
	mov = -mov;
	return mov;
}



void Booster::moveHelper()
{

	if (helper.getGlobalBounds().left < 0.f || helper.getGlobalBounds().left > WINDOW_WIDTH - helper.getSize().x)
	{
		changeDirection(movXHELP);
		
	}
	if (helper.getGlobalBounds().top < 0.f || helper.getGlobalBounds().top > GROUND_HEIGHT - helper.getSize().y)
	{
		changeDirection(movYHELP);
	}

	helper.setPosition(helper.getPosition().x + movXHELP, helper.getPosition().y + movYHELP);
	helperSprite.setPosition(helper.getPosition().x, helper.getPosition().y);
	

}



void Booster::drawBooster(sf::RenderWindow& window)
{
	window.draw(accelSprite);
	window.draw(destroyerSprite);
	window.draw(slowerSprite);
	window.draw(friendlySprite);
	window.draw(helperSprite);
	for (int i = 0; i < NUMBER_OF_SHOTS; i++)
	{
		window.draw(shotSprite[i]);
	}
	window.draw(timeVis);
}



sf::RectangleShape Booster::getBoosterShape()
{
	return booster;
}

sf::RectangleShape Booster::getShotShape(int digit)
{
	return shot[digit];
}

sf::RectangleShape Booster::getHelperShape()
{
	return helper;
}

Booster::~Booster()
{

}
