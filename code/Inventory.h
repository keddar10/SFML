#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>
#include "DEFINITIONS.h"
//#include "Player.h"
//#include <Bits.h>

#include <algorithm>
#include <sstream>
#include <vector>
class Item2;

class Inventory
{
public:
	Inventory();
	~Inventory(); 

	void contains();
	void drawInv(sf::RenderWindow&);

	void showInv(sf::Event&);
	void addItemToInventory(std::string);
	void replaceItemNames();
	void substractItemAmount(int);
	void deleteItem(Item2*);
	bool isItemNameUnique(/*std::string [],*/ int);
	//int getItemCountInString(int);
	std::string getItemCountInString(int);
	//int increaseItemCount(int, int);
	//int decreaseItemCount(std::string);
	void decreaseItemCount(std::string );
	int increaseItemCount(std::string);

	void setItemSlot(std::string, int);
	unsigned int getItemSlot(std::string);
	unsigned int getItemSlot(int);
	bool getSwitchInv();
	void resetItemSelector();

	int getItemCountInInt(std::string);

	void selectItem(sf::Event&);
	int getItemCount();
	void showItemSelectorValue();
	
	//void getItemSlot(std::string);
private:
	// maksymalna ilo�� item�w jak� mog� mie� w plecaku, 
	// chyba ze to by by� max typ�w item�w? pomysle
	
	static inline constexpr int maxItemAmount = 10;
	


	//uint8_t slots = 10;

	sf::RectangleShape inventoryBackground;
	sf::RectangleShape inventoryIndex;

	bool switchInv = false;

	sf::Text invVis;
	std::ostringstream showedInventory;
	sf::Text itemVis[maxItemAmount];
	std::ostringstream showedItem[maxItemAmount];	

	sf::Text counterVis[maxItemAmount];
	std::ostringstream showedCounter[maxItemAmount];

	int itemVerticalDistanceInInventory = 30;

	int itemAmount = 0;//to jest ilo�� UNIKALNYCH item�w
	int itemSlot = 0;//to jest pozycja w ekwipunku, przedmiot jest pierwszy, drugi itd.
	//int itemCount[maxItemAmount] = { 0 };//wszystkie elementy tablicy s� r�wne 0, itemCount to tablica int�w, itemCount[i] to aktualnie zebrany item, warto�ci przypisane do tablicy to ilo�� sztuk danego itemu
	int itemSelector = 1;//pomaga przy wy�wietlaniu i wybieraniu/u�ywaniu itp item�w w wy�wietlonym ekwipunku, zmieniam z 1 na 0
	int characterSize = 25;//to bym mogl dac globalnie nawet w definitions moze?
	sf::Font arial;
	
	std::vector <std::ostringstream> content;//??
	std::vector <std::string> strVec;
	std::vector <int> intVec;
	std::vector <int> itemCount/*Vec*/;
};
