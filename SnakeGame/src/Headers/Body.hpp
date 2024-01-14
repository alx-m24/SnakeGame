#pragma once
#include <SFML/Graphics.hpp>

class Body : public sf::CircleShape {
public:
	sf::Vector2f v = sf::Vector2f(2, 0);

	Body(sf::Vector2f Position);
	void Update();
};