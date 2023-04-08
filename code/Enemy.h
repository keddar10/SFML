#pragma once
#include<SFML/Graphics.hpp>
#include"Obstacle.h"
#include "DEFINITIONS.h"
//#include "Player.h"
#include "Score.h"
#include <iostream>
class Enemy
{
public:
	
	Enemy(sf::Vector2f size, sf::Vector2f startPos, int);
	Enemy(sf::Vector2f size, int);
	Enemy();
	void drawEnemy(sf::RenderWindow &window, int);
	
	void moveEnemy(int);
	void moveEnemy(int, bool);
	float changeDirection(float&);
	~Enemy();

	sf::RectangleShape getShape(int);

	void teleportEnemy(int);

	void spawnEnemy(int );

	bool enemyCanBeSpawned(int );
	void enemyIsDead(int);

	void changeEnemyMovementSpeed(float*);
	void changeEnemyMovementSpeed();



	float returnMovSpeed(float);

	void learnReferences(float*);

	void moveEnemySprite(int);
	
	//static inline constexpr std::uint8_t NUMBER_OF_ENEMIES = 2;
	//friend void Booster::slow(Player* object, Enemy* enemy);


protected:

	float enemyMovSpeed = 4.f;
	float* ptrEnemyMovSpeed = &enemyMovSpeed;

	uint8_t slowRatio = 2;

	float movX[NUMBER_OF_ENEMIES] = { *ptrEnemyMovSpeed+3 , *ptrEnemyMovSpeed-1 };
	float movY[NUMBER_OF_ENEMIES] = { *ptrEnemyMovSpeed+1 , *ptrEnemyMovSpeed+2 };	

	//TODO zrobiæ funkcje do zmiany predkoœci emeny poprzez referencje nie do enemyMovSpeed tylko bezpoœrednie do movX[0] lub [1]? 
	
	float timeDead = 4500;
	

	sf::RectangleShape enemy[NUMBER_OF_ENEMIES];
	
	sf::Clock durationEn;
	sf::Clock enemyDead[NUMBER_OF_ENEMIES];


	sf::Time timepassed = durationEn.getElapsedTime();
	
	sf::Texture enemyTexture;
	sf::Sprite enemySprite[NUMBER_OF_ENEMIES];

};
