#pragma once
#include<SFML/Graphics.hpp>
#pragma comment(lib, "winmm.lib")
#include<iostream>
using namespace std;

class frog{
private: // can only be seen/used by class members
	
	int lives;
	float xVel;
	float yVel;

public: // can be seen/used by anything in the program
	float xpos;
	float ypos;
	frog(); // constructor 
	void draw(sf::RenderWindow& window); // & returns the address of the pointer
	void jump(bool* keys);// * returns the value of the pointer
	float returnX() { return xpos; } //small enough to define here instead of .cpp file
	float returnY() { return ypos; }
	void ded();
	void win();
	int returnLives() { return lives; }
	void printInfo() { cout << "I am a frog and my position is" << xpos << "," << ypos << endl; } // for testing

};
