#include<SFML/Graphics.hpp>
#include<iostream>
#include"MoCodeIsBad.h"
#include"frog.h"
#pragma comment(lib, "winmm.lib")
#include"cars.h"
using namespace std;

int main() {
	//game variables set up
	srand(time(NULL)); // seed rand
	bool keys[] = { false, false, false, false }; // used for user input

	//SFML boilerplate stuff
	sf::RenderWindow screen(sf::VideoMode(1000, 1000), "Frogger");
	frog player; //instantiate a frog

	int timer = 0;

	vector<car*> cars; // make a vector of pointers to car objects
	for (int i = 0; i<5; i++)
		for (int j = 0; j < 1; j++) {
			cars.push_back(new car(i * 400 + 100, j * 200 + 500, LEFT));
			cars.push_back(new car(i * 400 + 100, j * 200 + 300, LEFT));
			cars.push_back(new car(i * 400 + 100, j * 200 + 100, LEFT));
			cars.push_back(new car(i * 400 + 100, j * 200 + 700, LEFT));
			cars.push_back(new car(i * 300 + 200, j * 200 + 600, RIGHT));
			cars.push_back(new car(i * 300 + 200, j * 200 + 200, RIGHT));
			cars.push_back(new car(i * 300 + 200, j * 200 + 400, RIGHT));
		}


	while (screen.isOpen()) {//game loop############################################
		//input section
		sf::Event event;
		while (screen.pollEvent(event)) {//look for user input
			if (event.type == sf::Event::Closed) //check if game window is closed
				screen.close();
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
				keys[UP] = true;
			}
			else keys[UP] = false;

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
				keys[DOWN] = true;
			}
			else keys[DOWN] = false;

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
				keys[RIGHT] = true;
			}
			else keys[RIGHT] = false;

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
				keys[LEFT] = true;
			}
			else keys[LEFT] = false;
		}
		//physics section
		timer++;
		if (timer > 200) {
			player.jump(keys);
			timer = 0;
		}

		for (vector<car*>::iterator i = cars.begin(); i != cars.end(); i++)//walk through the vector
		{
			(*i)->move();

		}

		for (vector<car*>::iterator i = cars.begin(); i != cars.end(); i++)
		{
			if ((*i)->collide(player.xpos, player.ypos) == true) {
				player.ded();
			}

		}

		if (player.ypos < 50) {
			player.win();
		}

		//render section
		screen.clear();

		player.draw(screen);

		

		for (vector<car*>::iterator i = cars.begin(); i != cars.end(); i++)//walk through the vector
		{
			(*i)->draw(screen);

		}

		screen.display();


	}//end game loop#############################
	cout << "game over" << endl;
	return 0;

}
