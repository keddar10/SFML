#pragma once
#include <sstream>

#include <SFML/Graphics.hpp>


class Score
{

public:
	Score();
	
	void getScore();
	void getScore(int);
	void drawScore(sf::RenderWindow &window);
	void getDeath();
	void getPotion();//lub item w przysz�o�ci mo�e?
	void usePotion();//lub item w przysz�o�ci mo�e?

	~Score();

private:
	int score;
	int deaths;
	int potions;

	std::ostringstream showedScore;
	std::ostringstream showedDeath;
	std::ostringstream showedPotions;

	sf::Text deathVis;
	sf::Text scoreVis;
	sf::Text potionVis;
	
	sf::Font arial;
	
};
