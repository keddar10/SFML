#include "Background.h"

Background::Background()
{
	initialPosition = { 0.f, 0.f };
	std::string spriteName;
	spriteName = "obrazki/background/background.png";
	if (!backgroundTexture.loadFromFile(spriteName))
	{
		std::cout << "nie udalo sie zaladwac obrazka: "<<spriteName << '\n';
	}

	backgroundSprite.setTexture(backgroundTexture);
	
	backgroundSprite.setPosition(initialPosition);
	//setCoinTexture();
}
Background::~Background()
{

}

void Background::drawTo(sf::RenderWindow& window)
{
	window.draw(backgroundSprite);
}