#pragma once

#include <iostream>
#include <sstream>
#include "Item2.h"

class PotionHP : public Item2
{
public:
	PotionHP();
	PotionHP(sf::Vector2f);
	~PotionHP();
	sf::RectangleShape* getShapePtr();
	sf::RectangleShape getShape();
	std::string getItemName();

	

protected:
	int healValue = 10;
	sf::RectangleShape potionHP;
};