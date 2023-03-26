#include<iostream>
#include "Enemy.h"
#include <algorithm>
#include <random>

Enemy::Enemy()
{

}
Enemy::Enemy(sf::Vector2f size, sf::Vector2f startPos, int i)
{
	
	enemy[i].setSize(size);
	enemy[i].setFillColor(sf::Color::Red);
	enemy[i].setPosition(startPos);

	
	
}

Enemy::Enemy(sf::Vector2f size,  int i)//size zawsze jako kwadrat!
{

	enemy[i].setSize(size);
	enemy[i].setFillColor(sf::Color::Red);

	spawnEnemy(i);

	std::string spriteName;
	spriteName = "obrazki/enemy/enemy40.png";
	
	if (!enemyTexture.loadFromFile(spriteName))
	{
		enemy[i].setFillColor(sf::Color::Red);
		std::cout << "nie udalo sie zaladwac obrazka "<<spriteName << '\n';
	}

	enemySprite[i].setTexture(enemyTexture);
	enemySprite[i].setPosition(enemy[i].getPosition().x, enemy[i].getPosition().y);
	float scaleX = size.x / 40.f;
	float scaleY = size.y / 40.f;
	enemySprite[i].setScale(scaleX, scaleY);
	enemySprite[i].setOrigin(19.f, 19.f);//obrazek ma 40x40, wiêc musze wpisaæ na sztywno, bo inaczej po skalowaniu mi siê przesuwa
}

void Enemy::moveEnemySprite(int i)
{
	enemySprite[i].setPosition(enemy[i].getPosition().x + enemy[i].getSize().x/2, enemy[i].getPosition().y + enemy[i].getSize().y/2);

	enemySprite[i].rotate(-enemyMovSpeed);
}

void Enemy::drawEnemy(sf::RenderWindow& window, int i)
{
	//window.draw(enemy[i]);
	window.draw(enemySprite[i]);
}

sf::RectangleShape Enemy::getShape(int i)
{
	return enemy[i];
}

float Enemy::changeDirection(float& mov)
{
	mov = -mov;
	return mov;
}





void Enemy::moveEnemy(int i)
{

	if (enemy[i].getGlobalBounds().left < 0.f || enemy[i].getGlobalBounds().left > WINDOW_WIDTH - enemy[i].getSize().x) changeDirection(movX[i]);
	if (enemy[i].getGlobalBounds().top < 0.f || enemy[i].getGlobalBounds().top > GROUND_HEIGHT - enemy[i].getSize().y) changeDirection(movY[i]);	
	
	enemy[i].setPosition(enemy[i].getPosition().x + movX[i], enemy[i].getPosition().y + movY[i]);
}


void Enemy::moveEnemy(int i, bool slowerActive)
{

	if (slowerActive == false)
	{
		if (enemy[i].getGlobalBounds().left < 0.f || enemy[i].getGlobalBounds().left > WINDOW_WIDTH - enemy[i].getSize().x) 
		{
			changeDirection(movX[i]);
		}

		if (enemy[i].getGlobalBounds().top < 0.f || enemy[i].getGlobalBounds().top > GROUND_HEIGHT - enemy[i].getSize().y) 
		{
			changeDirection(movY[i]);
		}

		enemy[i].setPosition(enemy[i].getPosition().x + movX[i], enemy[i].getPosition().y + movY[i]);
	}

	else
	{
		if (enemy[i].getGlobalBounds().left < 0.f || enemy[i].getGlobalBounds().left > WINDOW_WIDTH - enemy[i].getSize().x) 
		{
			changeDirection(movX[i]);
		}

		if (enemy[i].getGlobalBounds().top < 0.f || enemy[i].getGlobalBounds().top > GROUND_HEIGHT - enemy[i].getSize().y) 
		{
			changeDirection(movY[i]);
		}

		enemy[i].setPosition(enemy[i].getPosition().x + movX[i]/slowRatio, enemy[i].getPosition().y + movY[i]/slowRatio);
	}
}



void Enemy::spawnEnemy(int i)
{
	
	std::random_device startPos;
	std::uniform_real_distribution<float> rangeX(200.f, 1280.f - enemy[i].getSize().x);
	std::uniform_real_distribution<float> rangeY(100.f, GROUND_HEIGHT - enemy[i].getSize().y);

	enemy[i].setPosition(rangeX(startPos), rangeY(startPos));
	
}

bool Enemy::enemyCanBeSpawned(int digit)
{
	if (enemy[digit].getPosition().x < 0.f && enemy[digit].getPosition().y < 0.f)
	{
		return true;
	}
	else return false;
}



void Enemy::teleportEnemy(int digit)//musze przekazaæ tu argument w postaci takiej, jaki enemy ma byæ przeteleportowany
{	
	enemy[digit].setPosition(-5000.f, -5000.f);
}

void Enemy::enemyIsDead(int digit)
{
	sf::Time timePassedEnemyDead = enemyDead[digit].getElapsedTime();
		
	if (enemy[digit].getPosition().x < 0.f && timePassedEnemyDead.asMilliseconds() > timeDead)
	{
		spawnEnemy(digit);
	}
	else if (enemy[digit].getPosition().x > 0.f)
	{
		enemyDead[digit].restart();
	}
}

Enemy::~Enemy()
{
	
}