#include "Sword.h"
#include "Player.h"
#include <iostream>
Sword::Sword()
{
	sword.setSize(defaultSize);
	sword.setFillColor(sf::Color::Red);
	sword.setPosition(50.f, 50.f);
	std::cout << "Sword::Sword() made" << '\n';
}

Sword::~Sword()
{
	std::cout << "Sword::Sword() dest" << '\n';
}


void Sword::drawWeapon(sf::RenderWindow& window)
{
	window.draw(sword);
}

void Sword::stickToPlayer(Player* object/*, Weapon& sword*/)
{
	sword.setPosition(object->getShape().getGlobalBounds().left + object->getShape().getSize().x - 5.f, object->getShape().getGlobalBounds().top + object->getShape().getSize().y/2+7.f);
	sword.setRotation(-45.f);
}
