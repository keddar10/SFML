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
#include "Item.h"
#include "Item2.h"
#include "Player.h"
#include "PotionHP.h"
#include "Obstacle.h"
#include "Score.h"



class Game
{
public:
	Game();
	//~Game();
	void Loop();


	static inline constexpr std::uint8_t NUMBER_OF_PLATFORMS = 14;//constexprt znaczy ze to jest sta³a w momencie kompilacji i jest tak sta³a ¿e ojeja, static to jest ¿e jak kompilator 
	//se kompiluje to ta zmienna nie jest powuiazana z obiektem tlyko z klaas, nie opitrzebuje do neij obiektu klasy Game tylko ona jest w tej klasie
	static inline constexpr std::uint8_t NUMBER_OF_ITEMS = 11;
private:
	
	sf::RenderWindow* window;
	Player* player;
	//std::unique_ptr<Player> player; to tomek mi coœ napisa³ ¿e nie trzeba robuiæ delete po new, ani new nawet 
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
	PotionHP* potionHP;
	//Player* shell;

	//Booster* timeVis;


};