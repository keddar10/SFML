#pragma once
#include<SFML/Graphics.hpp>
#include <iostream>

class Interactive //ogólnie to na start mi przychdz¹ do g³owy takie obiektu: door i chest, a przy okazji chce zrobiæ dziedziczeniem, drzwi bêd¹ przenosiæ do lokacji, a skrzynia dawaæ itemy
{
public:
	//Interactive();//ten konstruktor zawsze wywo³a siê w funkcji pochodnej, dziedzicz¹cej z Interactive
	//chyba ze zrobie tak, ¿e w np. konstruktorze Chest() zrobie listê inicjalizacyjn¹, która bêdzie pobieraæ argumenty z konstruktora z argumentami, np. Interactive(int, int......)?
	// Chest(abc...) : Interactive(int, int)
	//{
	//}
	//~Interactive();
	void shapeOfObject(sf::RectangleShape, sf::Vector2f, sf::Vector2f, sf::Texture, sf::Sprite, std::string);
	void useOfObject();
	void drawInteractiveObject(sf::RenderWindow& window);


private:
	//sf::RectangleShape interactiteShape;//?
	
};
