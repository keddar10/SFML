#include "PotionHP.h"

PotionHP::PotionHP() 
{

}

PotionHP::PotionHP(sf::Vector2f (startPosition))
{
	itemName = "Hp potion";
	potionHP.setSize(defaultSize);
	potionHP.setFillColor(sf::Color::Red);
	//std::cout <<"potionHP itemName: " << itemName << '\n' << "potionHP.getsize().x " << potionHP.getSize().x << '\n';
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

void PotionHP::useEffect()
{
	std::cout << "PotionHP::useEffect()\n";
}

void PotionHP::addItem( Player* player, Inventory* inventory, Item2* addedItem)
{
	if (player->getShape().getGlobalBounds().intersects(addedItem->getShape().getGlobalBounds()))
	{
		//Item2::collectItem(getShapePtr(), inventory);
		collectItem(inventory);
		//setItemAmount();
		//getItemAmount();
	}

}

void PotionHP::getItemAmount()
{
	//std::cout << "item " << itemName << " amount: " << itemAmount << '\n';
	itemAmount++;
	//std::cout << "amount globalHP: " << itemAmountGlobal << '\n';
}

int PotionHP::setItemAmount()
{
	return itemAmountGlobal++;
}

//std::string PotionHP::getItemName()
//{
//	return itemName;
//}

void PotionHP::collectItem(/*Item2* item,*/ Inventory* inventory)//virtual void
{
	//item->getShape().setPosition(-200.f, -200.f);
	potionHP.setPosition(-200.f, -200.f);
	inventory->addItemToInventory(getItemName());
}
