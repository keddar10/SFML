#pragma once
#include<SFML/Graphics.hpp>
#include <sstream>
#include <iostream>
#include <vector>

#include"Obstacle.h"
#include "DEFINITIONS.h"
#include "Enemy.h"
#include "Coin.h"
#include "Score.h"
#include "Inventory.h"
//#include "Item.h"


class Player : public Obstacle
{
public:

	Player();
	Player(int);
	
	void drawTo(sf::RenderWindow &window);

	void movementPlayerNoGravity();
	void movementPlayer(bool);
	void moveToRight(sf::Vector2f distance);
	void moveToLeft();
	void moveToRight();
	void moveDown(sf::Vector2f distance);
	void jump();
	float time();
	float isJumping();
	void gravity(sf::Vector2f distance);
	void gravity(Obstacle *platform);
	bool checkCollisionLeft();
	bool checkCollisionRight(float);
	bool checkCollisionDown(float);
	void glowPlayer(bool);
	void isInAir(bool);

	void getPos();
	void checkPosition();
	void collisionWithObstacle(Obstacle *platform);
	~Player();
	void teleport();

	void drawScore(sf::RenderWindow &window);

	//std::vector <sf::RectangleShape> inventory;
	//std::vector <bool> canBeUsed;//?
	void getItem(sf::RectangleShape);
	void useItem( Score*, Score*, Inventory*, sf::Event& );

	sf::RectangleShape getShape();
	sf::RectangleShape getShapeShell(int );

protected:
	static inline constexpr std::uint8_t NUMBER_OF_SHELL = 4;

	float jumpHeight = 0.f;
	float jumpRange = 190.f;

	int itemCount = 0;

	bool canJump = true;

	float movSpeed = 6.5f;
	sf::RectangleShape player;

	sf::RectangleShape shell[NUMBER_OF_SHELL];


	sf::Clock timePassed;


	float boosterRatio = 1.6f;

//	sf::Event itemIsUsed;

	
};
