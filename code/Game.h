#pragma once

#include <cstdint>


#include <iostream>
#include <memory>
#include <sstream>


#include <SFML/Graphics.hpp>

#include "DEFINITIONS.h"


class Background;
class Booster;
class Coin;
class Chest;
class Enemy;
class Inventory;
class Item2;
class Player;
class PotionHP;
class PotionMP;
class Obstacle;
class Score;
class Sword;
class Weapon;



class Game
{
public:
	Game();
	~Game();
	void Loop();
	//void itemEffect(Item2*, Player*);

	static inline constexpr std::uint8_t NUMBER_OF_PLATFORMS = 14;//constexprt znaczy ze to jest sta�a w momencie kompilacji i jest tak sta�a �e ojeja, static to jest �e jak kompilator 
	//se kompiluje to ta zmienna nie jest powuiazana z obiektem tlyko z klaas, nie opitrzebuje do neij obiektu klasy Game tylko ona jest w tej klasie
	static inline constexpr std::uint8_t NUMBER_OF_ITEMS = 11;
	static inline constexpr std::uint8_t NUMBER_OF_HP_POTIONS = 4;
	static inline constexpr std::uint8_t NUMBER_OF_MP_POTIONS = 2;
	//static inline constexpr std::uint8_t NUMBER_OF_ENEMIES = 2;
	//static inline constexpr std::uint8_t NUMBER_OF_COINS = 2;
private:
	
	sf::RenderWindow* window;
	Player* player;
	//std::unique_ptr<Player> player; //to tomek mi co� napisa� �e nie trzeba robui� delete po new, ani new nawet 
	Obstacle* platform[NUMBER_OF_PLATFORMS];
	Obstacle* boundary;
	Obstacle* ground;
	Obstacle* frame;
	Enemy* enemy[NUMBER_OF_ENEMIES];
	Coin* coin[NUMBER_OF_COINS];
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
	//Item* item[NUMBER_OF_ITEMS];
	Inventory* inventory;
	PotionHP* potionHP[NUMBER_OF_HP_POTIONS];
	PotionMP* potionMP[NUMBER_OF_MP_POTIONS];
	//Player* shell;

	//Booster* timeVis;
	//Weapon* weapon;
	Sword* sword;

};

//void itemEffect(Item2* item, Player* player)
//{
//
//}