#include "Item2.h"

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

void Item2::collectItem(sf::RectangleShape* collectedItem/*, Player* player*/, Inventory* inventory)//TODO kazdy obiket ma swoj counter - naprawic
{
	collectedItem->setPosition(-200.f, -200.f);
	//std::cout << "Item2::collectItem" << '\n';
	inventory->addItem(this->getItemName());
	//itemAmountGlobal++;
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


