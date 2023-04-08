#pragma once
#include <iostream>


#include <SFML/Graphics.hpp>


class Coin
{
public:
	Coin(sf::Vector2f coinPos0);
	Coin(sf::Vector2f coinPos0, sf::Texture);
	Coin();
	void drawCoin(sf::RenderWindow &window);
	void teleportCoin();
	void setCoinTexture();
	void moveCoin(int);
	float changeDirection(float&);
	sf::RectangleShape getShape();
	~Coin();

private:
	sf::RectangleShape coin;
	sf::Texture coinTexture;
	sf::Sprite coinSprite;

	sf::Clock animationClock;
	
	
	float coinCenterLine = 0.f;
	int n = 0;
	float coinMS = 0.75f;
	float coinMoveYSpeed[NUMBER_OF_COINS] = { 0.8f*coinMS, coinMS };
};