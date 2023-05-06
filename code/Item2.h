#pragma once

#include <iostream>
#include <sstream>

#include <SFML\Graphics.hpp>

#include "Inventory.h"


class Item2 
{
public:
	Item2();
	Item2(sf::RectangleShape);
	~Item2();

	void spawnItem(sf::RectangleShape&, sf::Vector2f);
	//void collectItem(sf::RectangleShape*/*, Player**/ , Inventory* );
	//virtual void addItem(Player*, Inventory*);
	virtual void collectItem(/*Item2*,*/ Inventory*);
	void deleteItem(sf::RectangleShape&);
	void drawItem(sf::RenderWindow&, sf::RectangleShape);


	std::string getItemName();
	virtual sf::RectangleShape getShape();
	virtual void useEffect();


protected:
	int itemAmountGlobal = 0;
	std::string itemName;
	sf::Vector2f defaultSize{ 20.f, 20.f };
	sf::Color defaultColor{ sf::Color::Magenta };
	sf::RectangleShape item2;
};