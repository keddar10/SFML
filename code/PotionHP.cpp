#include "PotionHP.h"

PotionHP::PotionHP() : Item2::Item2(potionHP)
{

}

PotionHP::PotionHP(sf::Vector2f (startPosition))
{
	std::cout << "PotionHP default itemName: "<<itemName << '\n';
	itemName = "Hp potionItem2";
	potionHP.setSize(defaultSize);
	potionHP.setFillColor(defaultColor);
	std::cout <<"potionHP itemName: " << itemName << '\n' << "potionHP.getposition().x " << potionHP.getPosition().x << '\n' << "potionHP.getsize().x " << potionHP.getSize().x << '\n';

}

PotionHP::~PotionHP()
{
	
}

sf::RectangleShape PotionHP::getShape()
{
	return potionHP;
}
