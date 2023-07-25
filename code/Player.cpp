#include <sstream>
#include <iostream>
#include <vector>


#include "Player.h"
#include "Coin.h"
#include "Enemy.h"
#include "Inventory.h"
#include "Item2.h"
#include "Obstacle.h"
#include "Score.h"



//#include "Obstacle.h"

//float jumpSpeed = 8.f;

sf::Vector2f startPosition({ 150.f, 75.f });
//wielkoœæ, kolor i punkt pocz¹tkowy gracza
Player::Player() 
{
	//sf::Color color(255, 20, 147);
	player.setSize(sf::Vector2f({ playerWidth,playerHeight }));
	player.setFillColor(sf::Color::Green);
	
	player.setPosition(sf::Vector2f({startPosition })); 

	std::string spriteName;
	spriteName = "obrazki/player/player30x50R_0.png";

	if (!playerTexture.loadFromFile(spriteName))
	{
		player.setFillColor(sf::Color::Green);
		std::cout << "nie udalo sie zaladwac obrazka " << spriteName << '\n';
	}
	float scaleX = playerWidth / 120.f;
	float scaleY = playerHeight / 200.f;
	playerSprite.setTexture(playerTexture);
	playerSprite.setPosition(player.getPosition().x, player.getPosition().y);
	playerSprite.setScale(scaleX,scaleY);
	playerSprite.setScale(1.f,1.f);	
	
	//playerTextureTest.loadFromFile("obrazki/player/player30x50.png");
	//playerSpriteTest.setTexture(playerTextureTest);
	//playerSpriteTest.setPosition(player.getPosition().x+50.f, player.getPosition().y);
	////playerSpriteTest.setScale(scaleX,scaleY);
	//playerSpriteTest.setScale(4.f,4.f);
} 

Player::~Player()
{

}

void Player::setPlayerTexturePosition()
{
	playerSprite.setPosition(player.getPosition().x, player.getPosition().y);
}

void Player::setAnimationLeft(float speedRatio)
{
	sf::Time timePassedCoinAnimation = animationClockPlayer.getElapsedTime();
	int changeFrameTime = static_cast<int>(150 / speedRatio);

	std::string spriteName;
	if (timePassedCoinAnimation.asMilliseconds() > changeFrameTime)
	{
		if (n > 1)
		{
			n = 0;
		}
		std::string path = "obrazki/player/player30x50L_";
		std::string format = ".png";

		std::string nToString = std::to_string(n);

		spriteName = path + nToString + format;
		n++;
		if (!playerTexture.loadFromFile(spriteName))
		{
			player.setFillColor(sf::Color::Yellow);
			std::cout << "nie udalo sie zaladwac obrazka playerLEFT" << '\n';
		}
		animationClockPlayer.restart();
	}
	playerSprite.setTexture(playerTexture);
}

void Player::setAnimationRight(float speedRatio)
{
	sf::Time timePassedCoinAnimation = animationClockPlayer.getElapsedTime();
	int changeFrameTime = static_cast<int>(150/speedRatio);

	std::string spriteName;
	if (timePassedCoinAnimation.asMilliseconds() > changeFrameTime)
	{
		if (n > 1)
		{
			n = 0;
		}
		std::string path = "obrazki/player/player30x50R_";
		std::string format = ".png";

		std::string nToString = std::to_string(n);

		spriteName = path + nToString + format;
		n++;
		if (!playerTexture.loadFromFile(spriteName))
		{
			player.setFillColor(sf::Color::Yellow);
			std::cout << "nie udalo sie zaladwac obrazka playerRIGHT" << '\n';
		}
		animationClockPlayer.restart();
	}
	playerSprite.setTexture(playerTexture);
}

//tylko jak chce wy³¹czyæ skakanie
void Player::movementPlayerNoGravity()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		player.move(-movSpeed, 0.f);
		//playerSprite.move(-movSpeed, 0.f);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{

		player.move(movSpeed, 0.f);
		//playerSprite.move(movSpeed, 0.f);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		//playerSprite.move(0.f, movSpeed);
		player.move(0.f, movSpeed);
	}	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		//playerSprite.move(0.f, -movSpeed);
		player.move(0.f, -movSpeed);
	}
}

void Player::movementPlayer(bool accelActive)
{
	setPlayerTexturePosition();
	if (accelActive == false)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			setAnimationLeft(1.f);
			player.move(-movSpeed, 0.f);
			playerSprite.move(-movSpeed, 0.f);

		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			setAnimationRight(1.f);
			playerSprite.move(movSpeed, 0.f);
			player.move(movSpeed, 0.f);
		}
	}
	else
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			setAnimationLeft(boosterRatio);
			player.move(-boosterRatio*movSpeed, 0.f);
			playerSprite.move(-boosterRatio*movSpeed, 0.f);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			setAnimationRight(boosterRatio);
			player.move(boosterRatio*movSpeed, 0.f);
			playerSprite.move(boosterRatio*movSpeed, 0.f);
		}		

	}
}

void Player::drawTo(sf::RenderWindow& window) 
{

	for (int i = 0; i<4;i++)
	{
		window.draw(shell[i]);
	}
	//window.draw(player); 
	window.draw(playerSprite); 
	//window.draw(playerSpriteTest); 
}

//wy³¹czam te metode w mainie, bo jej nie potrzebuje
void Player::moveDown(sf::Vector2f distance)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		player.move(distance);
		//playerSprite.move(distance);
	}
}


//skakanie 
void Player::jump()//TODO zrobiæ skakanie przez sf::Event
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) == true && canJump == true )
	{		
		isInAir(true);		
	}

}

void Player::isInAir(bool jumping)
{
	if (jumping == false)
	{
		jumpHeight = player.getPosition().y + playerHeight - jumpRange;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) == false)//dzieki temu pozbywam siê wielokrotnego skoku przy trzymaniu Up
		{
			canJump = true;
		}
	}
	else
	{
		player.move(0.f, -JUMP_SPEED);
		if (player.getPosition().y <= jumpHeight)
		{
			canJump = false;			
		}
	}		
}



void Player::gravity(Obstacle* platform)
{
	sf::Time sec = timePassed.getElapsedTime();
	float fallVelocity = static_cast<float>(V0_FALL_SPEED + FALL_SPEED * sec.asMilliseconds()/2000);
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Up) == false || canJump == false) && player.getGlobalBounds().top + playerHeight < platform->posYMin())
	{
		player.move(0.f, fallVelocity);
	}
}

void Player::getPos()
{
	std::cout << "x = " << player.getPosition().x << '\n';
	std::cout << "y =  " << player.getPosition().y + playerHeight << '\n';;
}

bool Player::checkCollisionLeft()
{
	float x0 = 0.f;// teraz daje te wartosci na stale przez forward declaration i usuniecie dziedziczenia
	float xMax = WINDOW_WIDTH-1.f;//jw
	if (player.getGlobalBounds().left < x0 ) player.setPosition(sf::Vector2f({ x0 , player.getPosition().y}));
	if (player.getGlobalBounds().left > xMax-playerWidth) player.setPosition(sf::Vector2f({ xMax-playerWidth , player.getPosition().y }));
	
	return true;
}

bool Player::checkCollisionRight(float wall)
{

	if (player.getGlobalBounds().left > (wall-playerWidth))
	{
		player.setPosition(sf::Vector2f(wall-playerWidth , player.getPosition().y ));
	}

	return true;
}
//
bool Player::checkCollisionDown(float ground)
{

	float& groundRef = ground;
	if (player.getGlobalBounds().top > (ground + playerHeight))
	{

		player.setPosition(sf::Vector2f(player.getPosition().x, ground+playerHeight));


	}

	return true;
}




void Player::collisionWithObstacle(Obstacle* platform)
{
	//KOLIZJA DÓ£
	if (player.getGlobalBounds().top + playerHeight > platform->posYMin() - V0_FALL_SPEED//znak równoœci, dlatego, ¿e prêdkoœæ spadania V0_FALL_SPEED powodowa³a, ¿e klocek najpierw siê "zatapia³", a pó¿niej dzia³a³o dopiero "player.setposition..."
		&& player.getGlobalBounds().left + playerWidth > /*xBoundaryMIN*/ platform->posXMin() + MOVEMENT_SPEED
		&& player.getGlobalBounds().left < /*xBoundaryMAX*/platform->posXMax() - MOVEMENT_SPEED
		&& player.getGlobalBounds().top < /*yBoundaryMIN*/platform->posYMin())
	{
		player.setPosition(sf::Vector2f(player.getPosition().x, platform->posYMin() - playerHeight - V0_FALL_SPEED));//tutaj V0 FALL_SPEED jest offsetem jaki nadajê do ka¿dego styku gracza z platform¹, by siê nie zatapia³, prêdkoœæ powoduje zapadanie siê, im wiêksza tym wiêksze zatopienie
			
			isInAir(false);
			timePassed.restart();//TODO add coyote time
	}

	//Kolizja PRAWO
	else if (player.getGlobalBounds().left + playerWidth >=/* xBoundaryMIN*/platform->posXMin()
		&& player.getGlobalBounds().top + playerHeight > /*yBoundaryMIN*/platform->posYMin() + MOVEMENT_SPEED
		&& player.getGlobalBounds().top < /*yBoundaryMAX*/ platform->posYMax() - MOVEMENT_SPEED
		&& player.getGlobalBounds().left < /*xBoundaryMIN*/ platform->posXMin()	)
	{
		player.setPosition(sf::Vector2f(/*xBoundaryMIN*/platform->posXMin() - playerWidth - MOVEMENT_SPEED, player.getPosition().y));
		//cout << "PRAWO" << endl;
	}

	//Kolizja LEWO
	else if (player.getGlobalBounds().left  <=  /*xBoundaryMAX*/platform->posXMax()
		&& player.getGlobalBounds().top + playerHeight > /*yBoundaryMIN*/platform->posYMin() + MOVEMENT_SPEED
		&& player.getGlobalBounds().top < /*yBoundaryMAX*/platform->posYMax() - MOVEMENT_SPEED
		&& player.getGlobalBounds().left + playerWidth > /*xBoundaryMAX*/platform->posXMax())
	{
		player.setPosition(sf::Vector2f(/*xBoundaryMAX*/ platform->posXMax() + MOVEMENT_SPEED, player.getPosition().y));
		//cout << "LEWO" << endl;
	}

	//kolizja GÓRA
	else if (player.getGlobalBounds().top + playerHeight > /*yBoundaryMAX*/ platform->posYMax()
		&& player.getGlobalBounds().left + playerWidth > /*xBoundaryMIN */platform->posXMin() + MOVEMENT_SPEED
		&& player.getGlobalBounds().left < /*xBoundaryMAX */ platform->posXMax() - MOVEMENT_SPEED
		&& player.getGlobalBounds().top <= /*yBoundaryMAX*/platform->posYMax())
	{
		player.setPosition(sf::Vector2f(player.getPosition().x, /*yBoundaryMAX*/platform->posYMax() + JUMP_SPEED));
		canJump = false;
	}

}

void Player::teleport()
{	
	player.setPosition(sf::Vector2f{ startPosition });	
}

void Player::glowPlayer(bool active)
{	
	if (active)
	{
		uint8_t shellThickness = 5;
		sf::Vector2f shellDimenstionsW(playerWidth + shellThickness, shellThickness);
		sf::Vector2f shellDimenstionsH(playerHeight + shellThickness, shellThickness);

		shell[0].setPosition(player.getPosition().x - shellThickness, player.getPosition().y-shellThickness);
		shell[0].setSize(shellDimenstionsW);

		shell[1].setRotation(90);
		shell[1].setPosition(player.getPosition().x + playerWidth+shellThickness, player.getPosition().y-shellThickness);
		shell[1].setSize(shellDimenstionsH);

		shell[2].setPosition(player.getPosition().x, player.getPosition().y + playerHeight);
		shell[2].setSize(shellDimenstionsW);

		shell[3].setRotation(90);
		shell[3].setPosition(player.getPosition().x, player.getPosition().y);
		shell[3].setSize(shellDimenstionsH);

		for (int i = 0; i < 4; i++)
		{
			shell[i].setFillColor(sf::Color::Yellow);
		}
	}
	else
	{
		for (int i = 0; i < NUMBER_OF_SHELL; i++)
		{
			shell[i].setPosition(-80.f, -80.f);
		}
	}
	
}

//void Player::addItemToPlayer(sf::RectangleShape item)
//{
//	
//	itemCount++;//cyhba tego nie potrzebuje
//
//}


void Player::useItem(Score* potionVis, Score* scoreVis, Inventory* inventory, sf::Event &event, Item2* itemUsed)
{
	if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::C)
	{
		if (/*itemCount>0 &&*/inventory->getItemCount()>0 && inventory->getSwitchInv())
		{
			std::cout << "Player::useItem() is called" << '\n';
			//itemCount--;
			potionVis->usePotion();
			scoreVis->getScore(10);
			//itemUsed->useEffect();
			inventory->deleteItem(itemUsed);
		}
		else if (inventory->getItemCount() == 0)
		{
			std::cout << "Player::useItem() Brak odpowiedniego przedmiotu!" << '\n';
		}
	}
}



sf::RectangleShape Player::getShape()
{
	return player;
}

sf::RectangleShape Player::getShapeShell(int i)
{		
	//std::cout << "shell nr : " << i << '\n';
	return shell[i];
}

