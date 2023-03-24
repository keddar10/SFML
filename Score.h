#pragma once
#include <SFML/Graphics.hpp>
#include <sstream>


class Score
{

public:
	Score();
	
	void getScore();
	void getScore(int);
	void drawScore(sf::RenderWindow &window);
	void getDeath();
	void getPotion();//lub item w przysz³oœci mo¿e?
	void usePotion();//lub item w przysz³oœci mo¿e?

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
