#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include "Inventory.h"
#include "Player.h"
#include "Chest.h"
//#include "Game.h"

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

	std::string getItemName();

	//sf::RectangleShape getShape();

	void drawItem(sf::RenderWindow&);

	bool itemColledted[5] = { false };

private:
	//float damage;
	//float defence;
	//float attackSpeed;
	//float weight;

	int healValue = 10;
	int manaValue = 10;
	
	std::vector <bool> itemCanBeUsed;

	//int numberOfPotions = 0;
	//sf::Font arial;
	//sf::Text potionVis;
	//std::ostringstream showedPotionsAmount;


	sf::RectangleShape potionS;
	sf::RectangleShape manaPotionS;

	std::string strPotionS = "Heal Potion";
	std::string nameOfItem;

};