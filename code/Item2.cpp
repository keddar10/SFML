#include "Item2.h"

#include "Inventory.h"


Item2::Item2()
{
	itemName = "default";
}

Item2::Item2(sf::RectangleShape itemShape)
{
	//itemShape.setSize(defaultSize);
	//itemShape.setFillColor(sf::Color::Magenta);
	
}
Item2::~Item2()
{

}

void Item2::spawnItem(sf::RectangleShape& spawnedItem, sf::Vector2f startPosition)
{
	spawnedItem.setPosition(startPosition);
	
}

//void Item2::collectItem(sf::RectangleShape* collectedItem/*, Player* player*/, Inventory* inventory)//TODO kazdy obiket ma swoj counter - naprawic - edit (02.05) naprawione?
//{//TODO zrobic te funkcje wirtualna i daæ do ka¿dej klasy, wydaje mi sie ze tak bêdzie najlepiej, argumentem jest zawsze referencja z klasy, np PotionHP& pt_ref etc., moze to naprawi countery?
//	//albo mo¿e argumentem bêdzie ref item2& it_ref?
//	collectedItem->setPosition(-200.f, -200.f);
//	//std::cout << "Item2::collectItem" << '\n';
//	inventory->addItemToInventory(this->getItemName());
//	//itemAmountGlobal++;
//}
//void Item2::addItem(Player* player, Inventory* inventory, Item2* addedItem)
//{
//	if (player->getShape().getGlobalBounds().intersects(potionHP.getGlobalBounds()))
//	{
//		//Item2::collectItem(getShapePtr(), inventory);
//		collectItem(addedItem, inventory);
//		std::cout << "addItemPotionHP\n";
//		//setItemAmount();
//		//getItemAmount();
//	}
//
//}
void Item2::collectItem(/*Item2* item,*/ Inventory* inventory) //virtual void
{
	//item->getShape().setPosition(-200.f, -200.f);
	item2.setPosition(-200.f, -200.f);
	inventory->addItemToInventory(getItemName());
}



void Item2::deleteItem(sf::RectangleShape& deletedItem)
{

}

void Item2::drawItem(sf::RenderWindow& window, sf::RectangleShape drawedItem)
{
	window.draw(drawedItem);
}

std::string Item2::getItemName()
{
	return itemName;
}

sf::RectangleShape Item2::getShape()
{
	return item2;
}

void Item2::useEffect()
{
	std::cout << "Item2::useEffect()\n";
}


