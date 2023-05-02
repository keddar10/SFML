#pragma once

#include <iostream>
#include <sstream>
#include "Item2.h"

class PotionMP : public Item2
{
public:
	PotionMP();
	PotionMP(sf::Vector2f);
	~PotionMP();
	sf::RectangleShape* getShapePtr();
	sf::RectangleShape getShape();
	//std::string getItemName();
	void useEffect();
	void addItem(Player*, Inventory*);

	int setItemAmount();
	void getItemAmount();
	virtual void collectItem(/*Item2*,*/ Inventory*) override;

protected:
	int manaValue = 10;
	sf::RectangleShape potionMP;
	int itemAmount = 0;
};