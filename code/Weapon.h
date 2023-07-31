#pragma once

#include <SFML\Graphics.hpp>

class Player;

class Weapon
{
public:
	Weapon();
	~Weapon();
	virtual void drawWeapon(sf::RenderWindow&) = 0;
	virtual void stickToPlayer(Player*/*, Weapon&*/) = 0;
	virtual sf::RectangleShape getShape();

protected:
	sf::Vector2f defaultSize = { 49.f, 5.f };
	sf::RectangleShape defaultWeapon;
};