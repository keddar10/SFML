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

void Item2::spawnItem(sf::RectangleShape& spawnedItem)
{
	
}

void Item2::collectItem(sf::RectangleShape&)
{

}

void Item2::deleteItem(sf::RectangleShape& deletedItem)
{

}

void Item2::drawItem(sf::RenderWindow& window, sf::RectangleShape drawedItem)
{
	window.draw(drawedItem);
}

