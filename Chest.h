#pragma once
//#include "Interactive.h"
#include <iostream>
#include "Player.h"

#include<SFML/Graphics.hpp>


class Chest //: public Interactive
{
public:
	Chest( sf::Vector2f, int);
	~Chest();
	void content(int);
	//void shapeOfObject( sf::Vector2f);
	void useOfObject();
	void drawChest(sf::RenderWindow& window, int );
	void action(Player*, int);
	sf::RectangleShape getShape(int);

	bool wasOpened(int);


	void passItem();


private:
	bool chestOpened[NUMBER_OF_CHESTS] = { false };//wszystkie wartoœci s¹ false
	sf::RectangleShape chest[NUMBER_OF_CHESTS];//musze chyba zrobiæ tablicê/wektor elementów chest? bo mogê otwieraæ ró¿ne skrzynie + ka¿de otwarcie powinno uniemo¿liwiæ ponowne jej otwarcie oraz powinno usun¹æ z niej item
	sf::Texture chestTexture;
	sf::Sprite chestSprite;
};