#include<iostream>
#include<cmath>
#include"Obstacle.h"
//#include"Player.h"
#include "DEFINITIONS.h"


Obstacle::Obstacle()
{
	leftB.setSize(sf::Vector2f{ 1.f, WINDOW_HEIGHT });
	leftB.setPosition(sf::Vector2f{ 0.f, 0.f });
	leftB.setFillColor(sf::Color::Red);

	rightB.setSize(sf::Vector2f{ 1.f, WINDOW_HEIGHT });
	rightB.setPosition(sf::Vector2f{ WINDOW_WIDTH-1, 0.f });
	rightB.setFillColor(sf::Color::Red);

	upB.setSize(sf::Vector2f{ WINDOW_WIDTH, 1.f });
	upB.setPosition(sf::Vector2f{ 0.f, 1.f });
	upB.setFillColor(sf::Color::Red);

	downB.setSize(sf::Vector2f{ 1.f, WINDOW_HEIGHT });
	downB.setPosition(sf::Vector2f{ 0.f, WINDOW_WIDTH });
	downB.setFillColor(sf::Color::Red);	
}

//OBRAMOWANIE KOSNTRUKTOR POLOZENIE 0.f X RED Z 1 ARGUMENTEM
Obstacle::Obstacle(float pos0)
{
	 
	platform.setSize(sf::Vector2f{ WINDOW_WIDTH, 1.f });
	platform.setPosition(sf::Vector2f{ 0.f, pos0 });
	platform.setFillColor(sf::Color::Red);
}

Obstacle::Obstacle(sf::Vector2f gH0, float length)
{
	platform.setSize(sf::Vector2f{ length, 25.f });
	//platform.setFillColor(sf::Color::Blue);
	platform.setPosition(gH0);	

	std::string spriteName;
	spriteName = "obrazki/platform/platform2.png";
	if (!platformTexture.loadFromFile(spriteName))
	{
		platform.setFillColor(sf::Color::Red);
		std::cout << "nie udalo sie zaladwac obrazka " << spriteName << '\n';
	}
	for (int i = 0; i<length/10;i++)
	{
		platformSprite[i].setOrigin(0.f, 8.f);//ósemka to miejsce wyrastania kwiatka na grafice, a wklejam grafikê, której y=0 jest wysokoœæ kwiatka
		platformSprite[i].setTexture(platformTexture);
		platformSprite[i].setPosition(platform.getPosition().x + 10 * i, platform.getPosition().y);
	}
}


Obstacle::~Obstacle()
{

}

void Obstacle::drawObstacle(sf::RenderWindow& window)
{
	for (int i = 0; i < maxNumOfSprites; i++)//nie wiem czy wywo³ywanie funkcji 13*127 razy jest ok xdddd
	{
		window.draw(platformSprite[i]);
	}
}


void Obstacle::drawBoundary(sf::RenderWindow& window)
{
	window.draw(leftB);
	window.draw(rightB);
	window.draw(upB);
	window.draw(downB);

}

float Obstacle::leftBoundary(float left)
{	
	return left;
}

float Obstacle::getLeftBPos()
{
	return leftB.getPosition().x;
}

float Obstacle::getRightBPos()
{
	return rightB.getPosition().x;
}



float Obstacle::posYMin()
{
	return platform.getPosition().y;	
}

float Obstacle::posYMax()
{
	return platform.getPosition().y+platform.getSize().y;
}

float Obstacle::posXMin()
{
	return platform.getPosition().x;	
}

float Obstacle::posXMax()
{
	return platform.getPosition().x+platform.getSize().x;
}


