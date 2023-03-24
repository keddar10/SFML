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
	bool chestOpened[NUMBER_OF_CHESTS] = { false };//wszystkie warto�ci s� false
	sf::RectangleShape chest[NUMBER_OF_CHESTS];//musze chyba zrobi� tablic�/wektor element�w chest? bo mog� otwiera� r�ne skrzynie + ka�de otwarcie powinno uniemo�liwi� ponowne jej otwarcie oraz powinno usun�� z niej item
	sf::Texture chestTexture;
	sf::Sprite chestSprite;
};