#include "Body.hpp"

Body::Body(sf::Vector2f Postion)
{
	this->setPosition(Postion);
	this->update();
}

void Body::Update()
{
	this->move(v);
}