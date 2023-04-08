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
	//int getItemCount(int);
	std::string getItemCount(int);
	//int increaseItemCount(int, int);
	int increaseItemCount(std::string);

	void setItemSlot(std::string, int);
	unsigned int getItemSlot(std::string);
	unsigned int getItemSlot(int);

	void resetItemSelector();

	void selectItem(sf::Event&);

	//void getItemSlot(std::string);
private:
	// maksymalna iloœæ itemów jak¹ mogê mieæ w plecaku, 
	// chyba ze to by by³ max typów itemów? pomysle
	
	static inline constexpr int maxItemAmount = 10;
	


	uint8_t slots = 10;

	sf::RectangleShape inventoryBackground;
	sf::RectangleShape inventoryIndex;

	bool switchInv = false;

	sf::Text invVis;
	std::ostringstream showedInventory;
	sf::Text itemVis[maxItemAmount];
	std::ostringstream showedItem[maxItemAmount];	

	sf::Text counterVis[maxItemAmount];
	std::ostringstream showedCounter[maxItemAmount];

	int itemPositionInInventory = 30;

	int itemAmount = 0;
	int itemSlot = 0;
	int itemCount[maxItemAmount] = { 0 };//wszystkie elementy tablicy s¹ równe 0, 0 element = healPotion, 1 element = manaPotion, 2 element = speedPotion
	int itemSelector = 1;
	int characterSize = 25;//to bym mogl dac globalnie nawet w definitions moze?
	sf::Font arial;
	
	std::vector <std::ostringstream> content;//??
	std::vector <std::string> strVec;
	std::vector <int> intVec;
};
