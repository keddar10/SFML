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

}

void PotionHP::addItem( Player* player, Inventory* inventory)
{
	if (player->getShape().getGlobalBounds().intersects(potionHP.getGlobalBounds()))
	{
		collectItem(getShapePtr(), inventory);
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
