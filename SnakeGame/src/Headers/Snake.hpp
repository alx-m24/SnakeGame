#pragma once
#include "Body.hpp"
#include "GameEvents.hpp"
#include <cmath>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <vector>

class Snake {
public:
	sf::Vector2f position = sf::Vector2f(400, 300), velocity = sf::Vector2f(2, 0), lastV = sf::Vector2f(2, 0);
	std::vector<Body*> body;

	Snake(sf::RenderWindow* Window, unsigned int snakeSize);

	void newBodyPart();
	void update();
private:
	sf::RenderWindow* window;
	// direction change (position, velocity)
	std::map<std::pair<float, float>, std::pair<float, float>> directionChanges;
	void wallCollision();
	void BodyCollision(Body* curr);
};