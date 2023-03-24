#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>
#include "DEFINITIONS.h"
//#include "Player.h"
#include <sstream>
#include <vector>

class Inventory
{
public:
	Inventory();
	~Inventory(); 

	void contains();
	void drawInv(sf::RenderWindow&);

	void showInv(sf::Event&);
	void addItem(std::string);
	void deleteItem();
	bool isItemNameUnique(/*std::string [],*/ int);
private:
	uint8_t slots = 10;

	sf::RectangleShape inventoryBackground;

	bool switchInv = false;

	sf::Text invVis;
	std::ostringstream showedInventory;
	static inline constexpr int maxItemAmount = 10;//maksymalna iloœæ itemów jak¹ mogê mieæ w plecaku, chyba ze to by by³ max typów itemów? pomysle
	sf::Text itemVis[maxItemAmount];
	std::ostringstream showedItem[maxItemAmount];

	int itemPositionInInventory = 30;

	int itemAmount = 0;
	int itemSlot = 0;
	int itemCount = 1;
	sf::Font arial;
	
	std::vector <std::ostringstream> content;//??

};
