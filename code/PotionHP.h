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
	void useEffect();
	void addItem( Player* player, Inventory* inventory);

	int setItemAmount();
	void getItemAmount();

protected:
	int healValue = 10;
	sf::RectangleShape potionHP;
private:
	int itemAmount = 0;
};