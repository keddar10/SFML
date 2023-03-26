#include <random>


#include "DEFINITIONS.h"


#include "Coin.h"

//Coin::Coin(sf::Vector2f coinPos0)
//{
//	coin.setSize(sf::Vector2f{ 20.f, 20.f });
//	coin.setFillColor(sf::Color::Yellow);
//	coin.setPosition(coinPos0);
//}
Coin::Coin(/*sf::Vector2f coinPos0*/)
{
	std::string spriteName;
	spriteName = "obrazki/coin/coin0.png";
	if (!coinTexture.loadFromFile(spriteName))
	{
		coin.setFillColor(sf::Color::Yellow);
		std::cout << "nie udalo sie zaladwac obrazka coin" << '\n';
	}
	
	coinSprite.setTexture(coinTexture);
	coin.setSize(sf::Vector2f{ 20.f, 20.f });
	//coin.setPosition(coinPos0);	
	teleportCoin();
	//coinSprite.setPosition(coinPos0);
	coinSprite.setPosition(coin.getPosition().x, coin.getPosition().y);
	//setCoinTexture();
}

void Coin::setCoinTexture()
{
	sf::Time timePassedCoinAnimation = animationClock.getElapsedTime();
	int changeFrameTime = 150;

	std::string spriteName;
	if(timePassedCoinAnimation.asMilliseconds() > changeFrameTime)
	{
		if (n > 11)
		{
			n = 0;
		}
		std::string path = "obrazki/coin/coin";
		std::string format= ".png";

		std::string nToString = std::to_string(n);

		spriteName = path + nToString + format;
		n++;
		if (!coinTexture.loadFromFile(spriteName))
		{
			coin.setFillColor(sf::Color::Yellow);
			std::cout << "nie udalo sie zaladwac obrazka coin" << '\n';
		}
		animationClock.restart();
	}
	
	coinSprite.setTexture(coinTexture);
	coinSprite.setPosition(coin.getPosition().x, coin.getPosition().y);

}

void Coin::moveCoin(int digit)
{
	coin.move(0.f, coinMoveYSpeed[digit]);
	float offset = 20.f;
	if (coin.getPosition().y < coinCenterLine - offset || coin.getPosition().y > coinCenterLine + offset)
	{
		changeDirection(coinMoveYSpeed[digit]);
	}
}

float Coin::changeDirection(float& mov)
{
	mov = - mov;
	return mov;
}



void Coin::drawCoin(sf::RenderWindow &window)
{
	window.draw(coinSprite);
	//window.draw(coin);
}

sf::RectangleShape Coin::getShape()
{
	return coin;
}

void Coin::teleportCoin()
{

	std::random_device pos;
	std::uniform_real_distribution<float> rangeX(0, 1280 - coin.getSize().x);
	std::uniform_real_distribution<float> rangeY(0, GROUND_HEIGHT - coin.getSize().y);
	coin.setPosition(rangeX(pos), rangeY(pos));//dziala i nie powtarza mi pozycji nawet jak zbiorê 2 pod rz¹d szybko
	coinCenterLine = coin.getPosition().y;
	coinSprite.setPosition(coin.getPosition().x, coin.getPosition().y);
}


Coin::~Coin()
{
	
}