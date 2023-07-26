#include "PotionMP.h"
#include "Player.h"
#include "Inventory.h"
PotionMP::PotionMP()
{

}

PotionMP::PotionMP(sf::Vector2f(startPosition))
{
	itemName = "I_MP potion";
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

void PotionMP::useEffect()
{
	std::cout << "PotionMP::useEffect()\n";
}


void PotionMP::addItem(Player* player, Inventory* inventory)
{
	if (player->getShape().getGlobalBounds().intersects(potionMP.getGlobalBounds()))
	{
		//Item2::collectItem(getShapePtr(), inventory);
		collectItem(/*this,*/ inventory);
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

void PotionMP::collectItem(/*Item2* item,*/ Inventory* inventory)
{
	//item->getShape().setPosition(-200.f, -200.f);
	potionMP.setPosition(-200.f, -200.f);
	inventory->addItemToInventory(getItemName());
}
