/*
* HUD.cpp
*/

#include "HUD.h"

HUD::HUD(Window *window):
	window(window),
	isHidden(false),
	currentScore(0),
	highScore(0),
	font("PressStart2P.ttf", 7),
	text_color("black"),
	score(),
	highscore()
{
	score.setFont(&font);
	score.setColor(text_color);

	highscore.setFont(&font);
	highscore.setColor(text_color);

	numberScore.setFont(&font);
	numberScore.setColor(text_color);

	numberHighscore.setFont(&font);
	numberHighscore.setColor(text_color);
}

HUD::~HUD()
{

}

void HUD::setWeapon(int weapondID)
{

}

void HUD::setScore(int score)
{
	score = 0;
	currentScore = score;
}

void HUD::render()
{
	if (isHidden)
	{
		return;
	}

	score.print(window, "SCORE", 10, 10);
	highscore.print(window, "HI SCORE", 150, 10);

	//numberScore.print(window, currentScore, 30, 10);
	//numberHighscore.print(window, highScore, 30, 10);
}

void HUD::show()
{
	isHidden = false;
}

void HUD::hide()
{
	isHidden = true;
}



