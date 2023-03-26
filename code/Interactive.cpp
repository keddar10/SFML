#include "Interactive.h"

//Interactive::Interactive()
//{
//
//}
//
//Interactive::~Interactive()
//{
//
//}

void Interactive::shapeOfObject(sf::RectangleShape shape, sf::Vector2f size, sf::Vector2f position, sf::Texture texture, sf::Sprite sprite, std::string spritePath)
{	
	shape.setSize(sf::Vector2f{size});//size = texture.getsize()?
	shape.setPosition(sf::Vector2f{ position });
	if (!texture.loadFromFile(spritePath))
	{
		shape.setFillColor(sf::Color::Red);
		std::cout << "nie udalo sie zaladwac obrazka " << spritePath << '\n';
	}
	

	sprite.setTexture(texture);
	sprite.setPosition(shape.getPosition().x, shape.getPosition().y);

}

void Interactive::useOfObject()
{
	//???????????
}

void Interactive::drawInteractiveObject(sf::RenderWindow& window)
{
	
}