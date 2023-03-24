#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>

class Background
{
public:

	Background();
	~Background();

	void drawTo(sf::RenderWindow& );
private:
	sf::Texture backgroundTexture;
	sf::Sprite backgroundSprite;
	sf::Vector2f initialPosition;


};