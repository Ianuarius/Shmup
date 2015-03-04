/*
* HUD.cpp
*/

#include "HUD.h"

HUD::HUD(Window *window):
	window(window),
	weapons(window, "hud_icons_bw.png"),
	selected_weapon(window, "hud_icons.png", 20, 20),
	weapon_index(0),
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

	selected_weapon.setIndex(weapon_index);
}

HUD::~HUD()
{

}

void HUD::setWeapon(int weapondID)
{
	weapon_index = weapondID;
	selected_weapon.setIndex(weapon_index);
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

	char buffer[64];
	itoa(currentScore, buffer, 64);
	numberScore.print(window, buffer, 60, 10);

	itoa(highScore, buffer, 64);
	numberHighscore.print(window, buffer, 220, 10);

	weapons.render(48, 220);
	selected_weapon.render(48 + (weapon_index * 20), 220);
}

void HUD::show()
{
	isHidden = false;
}

void HUD::hide()
{
	isHidden = true;
}



