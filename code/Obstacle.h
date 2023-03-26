#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>
#include<vector>
//#include "Game.h"


class Obstacle
{
public:
	Obstacle();
	Obstacle(sf::Vector2f gH0, float);
	Obstacle(float pos0);
	

	~Obstacle();

	void drawObstacle(sf::RenderWindow &window);
	void drawBoundary(sf::RenderWindow& window/*, sf::VertexArray &boundary*/);
	
	float posYMin(/*sf::Vector2f gH0, float*/);
	float posYMax(/*sf::Vector2f gH0, float*/);

	float posXMin(/*sf::Vector2f gH0, float*/);
	float posXMax(/*sf::Vector2f gH0, float*/);

	void setPlatformSprite(float);

	void isColliding();

	float leftBoundary(float);

	sf::RectangleShape getShape();
	
protected:

	sf::RectangleShape platform;
	sf::RectangleShape leftB;
	sf::RectangleShape rightB;
	sf::RectangleShape upB;
	sf::RectangleShape downB;


	sf::Texture platformTexture;
	
	static inline constexpr std::uint8_t maxNumOfSprites = 127;
	//sf::Sprite platformSprite[];
	//std::vector <sf::Sprite> platformSpriteArr;
	//sf::Sprite platformSprite[Game::NUMBER_OF_PLATFORMS][100];
	sf::Sprite platformSprite[maxNumOfSprites];
	
	
	
	
};

