#include "PotionMP.h"

PotionMP::PotionMP()
{

}

PotionMP::PotionMP(sf::Vector2f(startPosition))
{
	itemName = "MP potion";
	potionMP.setSize(defaultSize);
	potionMP.setFillColor(sf::Color::Blue);
	//std::cout << "potionMP itemName: " << itemName << '\n' << "potionMP.getsize().x " << potionMP.getSize().x << '\n';
	spawnItem(potionMP, startPosition);
}

PotionMP::~PotionMP()
{

}

sf::RectangleShape PotionMP::getShape()
{
	return potionMP;
}

sf::RectangleShape* PotionMP::getShapePtr()
{
	sf::RectangleShape* foo = &potionMP; //TODO ?
	return foo;
}

void PotionMP::effect()
{

}


void PotionMP::addItem(Player* player, Inventory* inventory)
{
	if (player->getShape().getGlobalBounds().intersects(potionMP.getGlobalBounds()))
	{
		collectItem(getShapePtr(), inventory);
		//setItemAmount();
		//getItemAmount();
	}

}

void PotionMP::getItemAmount()
{
	itemAmount++;
	//std::cout << "item " << itemName << " amount: " << itemAmountGlobal << '\n';
}

int PotionMP::setItemAmount()
{
	return itemAmount++;
}

//std::string PotionHP::getItemName()
//{
//	return itemName;
//}
