#include "Apple.hpp"

Apple::Apple(sf::Vector2f Position)
{
	this->setRadius(10);
	this->setOrigin(10, 10);
	this->setFillColor(sf::Color::Red);
	this->setPosition(Position);
	this->update();
}