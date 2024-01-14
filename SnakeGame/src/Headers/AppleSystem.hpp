#pragma once
#include "Apple.hpp"
#include "Snake.hpp"
#include <SFML/Graphics.hpp>
#include <unordered_set>

class AppleSystem {
private:
	sf::RenderWindow* window;
	std::unordered_set<Apple*> apples;
	Snake* snake;
	int appleNum;

	void NewApple();
public:
	AppleSystem(sf::RenderWindow* Window, Snake* CurrentSnake, int AppleNum);

	void Update();
};