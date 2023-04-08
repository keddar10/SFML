#include "Chest.h"


Chest::Chest(sf::Vector2f position, int i)
{
	sf::Vector2f chestSize;
	chestSize={ 70.f, 45.f };
	chest[i].setSize(chestSize);//size = texture.getsize()?
	chest[i].setPosition(sf::Vector2f{position});
	std::string spritePath;
	spritePath = "...";
	if (!chestTexture.loadFromFile(spritePath))
	{
		chest[i].setFillColor(sf::Color::Red);
		std::cout << "nie udalo sie zaladwac obrazka " << spritePath << '\n';
	}

	chestSprite.setTexture(chestTexture);
	chestSprite.setPosition(chest[i] .getPosition().x, chest[i].getPosition().y);

}

Chest::~Chest()
{

}

void Chest::content(int i)
{
	if (chestOpened[i] == true)
	{

	}
}

bool Chest::wasOpened(int i)
{
	/*
	if (chestOpened[i] == true)
	{
		//std::cout << "wasOpenedChest: " << i << '\n';
		return true;
	}
	*/
	return chestOpened[i];
}


sf::RectangleShape Chest::getShape(int i)
{
	return chest[i];
}

void Chest::drawChest(sf::RenderWindow& window, int i)
{
	
	window.draw(chest[i]);
}

void Chest::action(Player* player, int i)
{
	
	if (player->getShape().getGlobalBounds().intersects(chest[i].getGlobalBounds()) && sf::Keyboard::isKeyPressed(sf::Keyboard::X) && chestOpened[i] == false)
	{
		std::cout << "skrzynia zostala otwarta!" << '\n';
		chestOpened[i] = true;
		wasOpened(i);
		chest[i].setFillColor(sf::Color::Yellow);
	}
	else if (player->getShape().getGlobalBounds().intersects(chest[i].getGlobalBounds()) && sf::Keyboard::isKeyPressed(sf::Keyboard::X) && chestOpened[i] == true)//TODO event keyreleased?
	{
		std::cout << "skrzynia jest pusta!" << '\n';
	}
}