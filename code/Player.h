#pragma once


#include <SFML/Graphics.hpp>

#include "DEFINITIONS.h"

#include "Obstacle.h"
#include "Enemy.h"
#include "Coin.h"
#include "Score.h"
#include "Inventory.h"

/* forward declarations */
class Item;

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

	void setPlayerTexturePosition();

	void getPos();
	void checkPosition();
	void collisionWithObstacle(Obstacle *platform);
	~Player();
	void teleport();

	void setAnimationLeft(float);
	void setAnimationRight(float);

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

	const float groungHeight = 600.f;

	const float playerWidth = 30.f;
	const float playerHeight = 50.f;
	float movSpeed = 6.5f;
	float boosterRatio = 1.6f;

	int itemCount = 0;
	int n = 0;
	bool canJump = true;

	sf::RectangleShape player;

	sf::RectangleShape shell[NUMBER_OF_SHELL];

	sf::Sprite playerSprite;
	sf::Texture playerTexture;
	//sf::Sprite playerSpriteTest;
	//sf::Texture playerTextureTest;

	sf::Clock timePassed;
	sf::Clock animationClockPlayer;



//	sf::Event itemIsUsed;

	
};
