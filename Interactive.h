#pragma once
#include<SFML/Graphics.hpp>
#include <iostream>

class Interactive //og�lnie to na start mi przychdz� do g�owy takie obiektu: door i chest, a przy okazji chce zrobi� dziedziczeniem, drzwi b�d� przenosi� do lokacji, a skrzynia dawa� itemy
{
public:
	//Interactive();//ten konstruktor zawsze wywo�a si� w funkcji pochodnej, dziedzicz�cej z Interactive
	//chyba ze zrobie tak, �e w np. konstruktorze Chest() zrobie list� inicjalizacyjn�, kt�ra b�dzie pobiera� argumenty z konstruktora z argumentami, np. Interactive(int, int......)?
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
