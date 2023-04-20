#include "PotionHP.h"

PotionHP::PotionHP() 
{

}

PotionHP::PotionHP(sf::Vector2f (startPosition))
{
	std::cout << "PotionHP default itemName: "<<itemName << '\n';
	itemName = "Hp potionItem2";
	potionHP.setSize(defaultSize);
	potionHP.setFillColor(defaultColor);
	std::cout <<"potionHP itemName: " << itemName << '\n' << "potionHP.getsize().x " << potionHP.getSize().x << '\n';
	spawnItem(potionHP, startPosition);
}

PotionHP::~PotionHP()
{
	
}

sf::RectangleShape PotionHP::getShape()
{
	return potionHP;
}

sf::RectangleShape* PotionHP::getShapePtr()
{
	sf::RectangleShape* foo = &potionHP; //TODO ?
	return foo;
}

std::string PotionHP::getItemName()
{
	return itemName;
}
