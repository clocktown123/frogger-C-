#include "frog.h"
#include"MoCodeIsBad.h"
#include"SFML/Graphics.hpp"
#pragma comment(lib, "winmm.lib")
#include"Windows.h"

//constructer: fills in all the needed class variables
frog::frog() {
	xpos = 500;
	ypos = 900;
	lives = 5;
	xVel = 0;
	yVel = 0;
}

void frog::jump(bool* keys) {
	if (keys[UP] == true)
		yVel = -50;
	else if (keys[DOWN] == true)
		yVel = 50;
	//else
		//yVel = 0;
	else if (keys[RIGHT] == true)
		xVel = 50;
	else if (keys[LEFT] == true)
		xVel = -50;
	else {
		yVel = 0;
		xVel = 0;
	}
	ypos += yVel;
	xpos += xVel;
}

void frog::draw(sf::RenderWindow& window) {
	sf::RectangleShape FrogPic(sf::Vector2f(20, 20));
	FrogPic.setFillColor(sf::Color(50, 200, 50));
	FrogPic.setPosition(xpos, ypos);
	window.draw(FrogPic);
}
void frog::ded() {
	//play explosion sound here
	Beep(500, 500);
	//maybe add explosion animation eventually :D
	lives--;
	xpos = 500;
	ypos = 954;
}

void frog::win() {
	//play explosion sound here
	//PlaySound(TEXT("Win(Frogger).WAV"), NULL, SND_LOOP | SND_ASYNC);
	cout << "win" << endl;
	//maybe add explosion animation eventually :D
	lives--;
	xpos = 500;
	ypos = 954;
}
