#include "Item.h"

#include "Player.h"

Item::Item(std::string itemDestination, int size)
{
	if (itemDestination == "heal" /*&& size == 1*/)
	{
		nameOfItem = strHealPotionS;
		healValue = size * healValue;
		//std::cout <<"healValue: "<< healValue << '\n';

		potionS.setSize({ 10.f, 10.f });
		potionS.setFillColor(sf::Color::Red);
		potionS.setPosition(size*100.f, size*100.f);
	}
	else if (itemDestination == "mana")
	{
		nameOfItem = strManaPotionS;
		manaValue = size * manaValue;

		potionS.setSize({ 25.f, 25.f });
		potionS.setFillColor(sf::Color::Blue);
		potionS.setPosition(size * 120.f, size * 120.f);
	}
	else if (itemDestination == "speed")
	{
		nameOfItem = strSpeedPotionS;
		speedValue = size * speedValue;

		potionS.setSize({ 17.f, 17.f });
		potionS.setFillColor(sf::Color::Yellow);
		potionS.setPosition(size * 120.f, 550.f);
	}
	else
	{
		std::cout<<"item "<<itemDestination<<" rozmiar: "<<size << " nie istnieje!" << '\n';
	}
}

std::string Item::getItemName()
{
	return nameOfItem;
}

Item::~Item()
{
	std::cout << "umrzylem itememem" << '\n';
}



void Item::spawnItem(Chest* chestObject, int i)
{
	if (chestObject->wasOpened(i) == true && itemColledted[0] == false)
	{
		potionS.setPosition(400.f, 550.f);
		potionS.setPosition(500.f, 550.f);
		//std::cout << "ItemSpawnItem: " << '\n';
	}
}

void Item::attackItemList(std::string itemName, float damage, float attackSpeed)
{

}

void Item::defenceItemList(std::string itemName, float defence)
{

}
void Item::healItemList(std::string itemName, float healValue)
{

}

void Item::grabItem(Player* object, Score* potionVis, Inventory* inventory)
{

	if (object->getShape().getGlobalBounds().intersects(potionS.getGlobalBounds()))
	{
		//std::cout << "Item::grabItem zebrano: " << getItemName() << '\n';
		potionS.setPosition(-50.f, -50.f);
		itemColledted[0] = true;
		object->getItem(potionS);
		potionVis->getPotion();
		inventory->addItem(getItemName());
		
	}
}

void Item::throwItem(/*Score* potionVis, */Inventory* inventory/*, sf::Event &event*/)
{
	inventory->deleteItem();
}
//sf::RectangleShape Item::getShape()
//{
//	return potionS;
//}

void Item::drawItem(sf::RenderWindow& window)
{
	window.draw(potionS);
}