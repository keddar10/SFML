#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include "Inventory.h"
// #include "Player.h"
#include "Chest.h"
//#include "Game.h"

/* forward declarations */
class Player;

class Item
{
public:
	Item(std::string, int);
	~Item();

	void attackItemList(std::string, float, float);
	void defenceItemList(std::string, float);
	void healItemList(std::string, float);
	void itemProperties();
	void spawnItem(Chest*, int );
	void grabItem(Player*, Score*, Inventory* );
	void throwItem(/* Score*, */Inventory*/*, sf::Event&*/);


	std::string getItemName();//to przekazuje do wskaünika inventory w funkcji Item::addItem()!

	//sf::RectangleShape getShape();

	void drawItem(sf::RenderWindow&);

	bool itemColledted[5] = { false };

	std::string strHealPotionS = "Heal Potion";
	std::string strManaPotionS = "Mana Potion";
	std::string strSpeedPotionS = "Speed Potion";
private:
	//float damage;
	//float defence;
	//float attackSpeed;
	//float weight;

	int healValue = 10;
	int manaValue = 10;
	int speedValue = 10;
	
	//std::vector <bool> itemCanBeUsed;

	//int numberOfPotions = 0;
	//sf::Font arial;
	//sf::Text potionVis;
	//std::ostringstream showedPotionsAmount;


	sf::RectangleShape potionS;
	sf::RectangleShape manaPotionS;

	std::string nameOfItem;

};