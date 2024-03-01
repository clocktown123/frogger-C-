#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>
#include"MoCodeIsBad.h"
using namespace std;


class car{
private: // can only be seen/used by class members
	float xpos;
	float ypos;
	int blue = rand() % 100 + 200;
	int green = rand() % 100 + 200;
	int directionG; //right

public:
	car(int x, int y, int direction);
	float returnX() { return xpos; } //small enough to define here instead of .cpp file
	float returnY() { return ypos; }
	void draw(sf::RenderWindow& winow);
	void move();
	bool collide(int x, int y);
	void printInfo() { cout << "I an a car and my pos is " << xpos << "," << ypos << endl; }

};
