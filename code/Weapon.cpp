#include "Weapon.h"
#include "Player.h"
#include <iostream>
Weapon::Weapon()
{
	defaultWeapon.setSize(defaultSize);
	defaultWeapon.setFillColor(sf::Color::Cyan);
	defaultWeapon.setPosition(150.f, 50.f);
	std::cout << "Weapon::Weapon() made" << '\n';
}

Weapon::~Weapon()
{

	std::cout << "Weapon::Weapon() dest" << '\n';
}

void Weapon::stickToPlayer(Player* object/*, Weapon& defaultWeapon*/)
{
	//defaultWeapon.getShape().setPosition(object->getShape().getPosition());
}

sf::RectangleShape Weapon::getShape()
{
	return defaultWeapon;
}


