#pragma once
#include <SFML/Graphics.hpp>
#include <sstream>
#include "DEFINITIONS.h"
class Enemy;
class Player;
class Score;
class Obstacle;

class Booster// : public Enemy, public Player
{
public:
	Booster(int);
	//Booster(int);
	~Booster();

	void showTime(std::string,int, sf::Time, sf::Vector2f);

	void accel(Player* object );
	void destroy(Player* object, Enemy* enemy, Score* score);
	void slow(Player* object, Enemy* enemy, Obstacle* frame);
	void friendShots(Player* object, Enemy* enemy, Booster* helps, Booster* ptrShot, Score* score);
	void moveHelper();
	void moveShot(int);
	void helperShots();
	
	

	void drawBooster(sf::RenderWindow& window);

	void spawnBooster();
	void spawnDestroyer();
	void spawnSlower();
	void spawnFriendly();
	void spawnHelper(int);
	void spawnShot(Enemy* object, Booster* helps, int);


	float changeDirection(float& mov);

	sf::RectangleShape getHelperShape();
	sf::RectangleShape getShotShape(int);
	sf::RectangleShape getBoosterShape();
	

	void drawTime(sf::RenderWindow& window);

private:

	int timeDead = 4500;

	//parametry szybkoœci friendly: helpera i shota, dziele je przez number of enemies bo funkcja jest tyle razy wywo³ywana w Game.cpp w pêtli xD
	float movXHELP = 7.f/NUMBER_OF_ENEMIES;//default 7.f
	float movYHELP = movXHELP;
	float movXSHOT = 3.f/NUMBER_OF_ENEMIES;//default 3.f
	float movYSHOT = movXSHOT;
	
	bool boosterActive = false;
	bool boosterActiveDes = false;
	bool boosterActiveSlo = false;
	bool boosterActiveFri = false;

	bool killedByBullet[NUMBER_OF_ENEMIES] = { false, false };
	bool killedByTouch[NUMBER_OF_ENEMIES] = { false, false };

	bool boosterCanBeSpawned[4] = { true, true, true, true, };//bool od tego by accel, destroy, slow, friendly by³ zespawnowany po zebraniu



	//int cooldown = 2000;
	int cooldownAccelerator = 7000;//7s
	int cooldownDestroyer = 15000;//15s
	int cooldownSlower = 10000;//10s
	int cooldownFriendly = 30000;//30s

	uint8_t shellNo;

	std::ostringstream showedTime;

	sf::Text timeVis;

	sf::RectangleShape booster;
	sf::RectangleShape destroyer;
	sf::RectangleShape slower;
	sf::RectangleShape friendly;
	sf::RectangleShape helper;
	sf::RectangleShape shot[NUMBER_OF_SHOTS];

	sf::Clock timePassed;
	sf::Clock timePassedDes;
	sf::Clock timePassedSlo;
	sf::Clock timePassedSloShow;
	sf::Clock timePassedFri;
	sf::Clock timePassedFriShow;

	sf::Clock respawnTimeAcc;
	sf::Clock respawnTimeSlo;
	sf::Clock respawnTimeDes;
	sf::Clock respawnTimeFri;

	sf::Clock respawnTimeEnemy[NUMBER_OF_ENEMIES];
	sf::Clock respawnTimeEnemyShooted[NUMBER_OF_ENEMIES];

	sf::Font arial;

	sf::Texture accelTexture;
	sf::Sprite accelSprite;	
	sf::Texture destroyerTexture;
	sf::Sprite destroyerSprite;	
	sf::Texture slowerTexture;
	sf::Sprite slowerSprite;	
	sf::Texture friendlyTexture;
	sf::Sprite friendlySprite;	
	sf::Texture helperTexture;
	sf::Sprite helperSprite;
	sf::Texture shotTexture;
	sf::Sprite shotSprite[NUMBER_OF_SHOTS];

};