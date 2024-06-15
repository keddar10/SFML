#pragma once
#include "Weapon.h"

class Player;

class Sword : public Weapon
{
public:
	Sword();
	~Sword();

	virtual void drawWeapon(sf::RenderWindow& window) override;
	virtual void stickToPlayer(Player*/*, Weapon&*/) override;
protected:

private:
	sf::RectangleShape sword;

};