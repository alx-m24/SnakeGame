// External libraries
#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
// My headers
#include "Headers/MainLoop.hpp"
#include "Headers/AppleSystem.hpp"
#include "Headers/Snake.hpp"

int main() {
	// window settings
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;

	// creating window
	sf::RenderWindow window(sf::VideoMode(800, 600), "Snake Game", sf::Style::Default, settings);
	window.setVerticalSyncEnabled(true);
	// my main loop class
	Loop loop(&window);

	// snake class(pointer to window)
	Snake snake(&window, 5);

	// Use current time as seed for random generator
	srand(time(0));

	// Apple system
	AppleSystem appleSystem(&window, &snake, 2);

	// main loop
	while (window.isOpen())
	{
		// processing inputs(pointer to snake object)
		loop.Input(&snake);

		// updating window itself and snake
		loop.Update();
		snake.update();
		appleSystem.Update();

		// rendering all objects
		loop.Render();
	}

	return 0;
}