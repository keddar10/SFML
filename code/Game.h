#pragma once

#include <cstdint>


#include <iostream>
#include <memory>
#include <sstream>


#include <SFML/Graphics.hpp>

#include "Background.h"
#include "Booster.h"
#include "Coin.h"
#include "Chest.h"
#include "DEFINITIONS.h"
#include "Enemy.h"
#include "Interactive.h"
#include "Inventory.h"
#include "Player.h"
#include "Item.h"
#include "Obstacle.h"
#include "Score.h"



class Game
{
public:
	Game();
	//~Game();
	void Loop();


	static inline constexpr std::uint8_t NUMBER_OF_PLATFORMS = 14;//
	static inline constexpr std::uint8_t NUMBER_OF_ITEMS = 6;
private:
	
	sf::RenderWindow* window;
	Player* player;
	
	Obstacle* platform[NUMBER_OF_PLATFORMS];
	Obstacle* boundary;
	Obstacle* ground;
	Enemy* enemy[NUMBER_OF_ENEMIES];
	Coin* coin[2];
	Score* scoreVis;

	Booster* booster;
	Booster* destroyer;
	Booster* slower;
	Booster* friendly;
	Booster* helper;
	//Booster* shot[NUMBER_OF_SHOTS];
	Booster* shot;
	Background* background;
	Chest* chest[NUMBER_OF_CHESTS];
	Item* item[NUMBER_OF_ITEMS];
	Inventory* inventory;
	//Player* shell;

	//Booster* timeVis;


};