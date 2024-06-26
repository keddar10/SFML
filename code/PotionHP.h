#pragma once

#include <iostream>
#include <sstream>
#include <SFML/Graphics.hpp>
#include "Item2.h"

class Player;
class Item2;
class Inventory;

class PotionHP : public Item2
{
public:
	PotionHP();
	PotionHP(sf::Vector2f);
	~PotionHP();
	sf::RectangleShape* getShapePtr();
	virtual sf::RectangleShape getShape() override;
	//std::string getItemName();
	virtual void useEffect() override;
	void addItem( Player*, Inventory*, Item2*);

	int setItemAmount();
	void getItemAmount();
	virtual void collectItem(/*Item2*,*/ Inventory*) override;

protected:
	int healValue = 10;
	sf::RectangleShape potionHP;
private:
	int itemAmount = 0;
};