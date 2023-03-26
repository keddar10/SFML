#include "Player.h"
//#include "Obstacle.h"

//float jumpSpeed = 8.f;
const float groungHeight = 600.f; 

const float playerWidth = 30.f;
const float playerHeight = 50.f;

sf::Vector2f startPosition({ 150.f, 75.f });
//wielkoœæ, kolor i punkt pocz¹tkowy gracza
Player::Player() 
{
	//sf::Color color(255, 20, 147);
	player.setSize(sf::Vector2f({ playerWidth,playerHeight }));
	player.setFillColor(sf::Color::Green);
	player.setPosition(sf::Vector2f({startPosition })); 
} 

Player::~Player()
{

}


//tylko jak chce wy³¹czyæ skakanie
void Player::movementPlayerNoGravity()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		player.move(-movSpeed, 0.f);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{

		player.move(movSpeed, 0.f);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		player.move(0.f, movSpeed);
	}	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		player.move(0.f, -movSpeed);
	}
}

void Player::movementPlayer(bool accelActive)
{
	if (accelActive == false)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			player.move(-movSpeed, 0.f);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			player.move(movSpeed, 0.f);
		}



	}
	else
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			player.move(-boosterRatio*movSpeed, 0.f);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			player.move(boosterRatio*movSpeed, 0.f);
		}		

	}
}

void Player::drawTo(sf::RenderWindow& window) 
{

	for (int i = 0; i<4;i++)
	{
		window.draw(shell[i]);
	}
	window.draw(player); 
}

//wy³¹czam te metode w mainie, bo jej nie potrzebuje
void Player::moveDown(sf::Vector2f distance)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		player.move(distance);
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
	float fallVelocity = V0_FALL_SPEED + FALL_SPEED * sec.asMilliseconds()/2000;
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
	
	float x0 = leftB.getPosition().x;
	float xMax = rightB.getPosition().x;
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
			timePassed.restart();
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

void Player::glowPlayer(bool digit)
{	
	if (digit == true)
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

void Player::getItem(sf::RectangleShape item)
{
	
	itemCount++;

}


void Player::useItem(Score* potionVis, Score* scoreVis, Inventory* inventory, sf::Event &event)
{
	if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::C)
	{
		if (itemCount>0 )
		{
			//std::cout << "Player::useItem() is called" << '\n';
			itemCount--;
			potionVis->usePotion();
			scoreVis->getScore(10);
			
			inventory->deleteItem();

		}
		else
		{
			std::cout << "Brak odpowiedniego przedmiotu!" << '\n';
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

