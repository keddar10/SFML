#include <iostream>
#include "Score.h"





Score::Score()
: score(0)
, deaths(0)
, potions(0)// tak moge sobie inicjalizowaæ jakieœ zmienne, to sie naztywa lista inicjalizacyjna kosntruktora, one moga byæ w jednej linii tam gdzie Score::Score(),  
//a mo¿na je daæ ni¿ej dla przejrzystoœci
{
	arial.loadFromFile("arial.ttf");
		
	showedScore << "Score: 0";
	showedDeath << "Deaths: 0";
	showedPotions << "Potions: 0";
	//sf::Text scoreVis;
	scoreVis.setCharacterSize(30);
	scoreVis.setPosition(100.f, 620.f);
	scoreVis.setFont(arial);
	scoreVis.setString(showedScore.str());

	deathVis.setCharacterSize(30);
	deathVis.setPosition(400.f, 620.f);
	deathVis.setFont(arial);
	deathVis.setString(showedDeath.str());	
	
	potionVis.setCharacterSize(30);
	potionVis.setPosition(100.f, 680.f);
	potionVis.setFont(arial);
	potionVis.setString(showedPotions.str());		
}


void Score::getScore()
{	
	score++;
	showedScore.str("");
	showedScore << "Score: " << score << '\n';
	scoreVis.setString(showedScore.str());
	//std::cout << "Score: " << score << '\n';
}

void Score::getScore(int add)
{

	score+=add;
	showedScore.str("");
	showedScore << "Score: " << score << '\n';
	scoreVis.setString(showedScore.str());
	//std::cout << "Score: " << score << '\n';

}




void Score::drawScore(sf::RenderWindow& window)
{
	window.draw(scoreVis);
	window.draw(deathVis);
	window.draw(potionVis);
}

void Score::getDeath()
{
	deaths++;
	if (score>4)
	{
		score -= 5;
	}
	else
	{
		score = 0;
	}

	showedScore.str("");
	showedScore << "Score: " << score << '\n';
	scoreVis.setString(showedScore.str());

	showedDeath.str("");
	showedDeath << "Deaths: " << deaths << '\n';
	deathVis.setString(showedDeath.str());
	//std::cout << "Deaths: " << deaths << '\n';

}

void Score::getPotion()
{
	potions++;
	showedPotions.str("");
	showedPotions << "Potions: " << potions << '\n';
	potionVis.setString(showedPotions.str());
}

void Score::usePotion()
{
	potions--;
	showedPotions.str("");
	showedPotions << "Potions: " << potions << '\n';
	potionVis.setString(showedPotions.str());
}

Score::~Score()
{

}