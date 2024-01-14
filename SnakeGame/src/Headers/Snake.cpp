#include "Snake.hpp"

Snake::Snake(sf::RenderWindow* Window, unsigned int snakeSize) : window(Window)
{
	Body* newBody = new Body(position);
	newBody->setRadius(20);
	newBody->setOrigin(20, 20);

	body.push_back(newBody);

	for (int i = 0; i < snakeSize - 1; ++i)
	{
		newBodyPart();
	}

	body[0]->setFillColor(sf::Color::Red);
}

void Snake::newBodyPart()
{
	Body* lastBody = body[body.size() - 1];

	sf::Vector2f newBodyPartPos = lastBody->getPosition() - lastBody->v + sf::Vector2f(-15 * lastBody->v.x, -15 * lastBody->v.y);

	Body* newbody = new Body(sf::Vector2f(newBodyPartPos));

	newbody->v = lastBody->v;

	newbody->setFillColor(sf::Color::Green);
	newbody->setOrigin(20, 20);
	newbody->setRadius(20);

	body.push_back(newbody);
}

void Snake::update()
{
	std::pair<float, float> pos;
	std::pair<float, float> vel;

	if (lastV != velocity)
	{
		vel = { velocity.x, velocity.y };
		pos = { position.x, position.y };
		directionChanges[pos] = vel;
	}

	position += velocity;
	lastV = velocity;

	Body* main = body[0];
	main->move(velocity);
	window->draw(*main);

	wallCollision();

	for (int i = 1; i < body.size(); ++i)
	{
		Body* curr = body[i];

		
		pos = { curr->getPosition().x, curr->getPosition().y };
		vel = { curr->v.x, curr->v.y };

		if (directionChanges.find(pos) != directionChanges.end())
		{
			curr->v.x = directionChanges[pos].first;
			curr->v.y = directionChanges[pos].second;
			if (i == body.size() - 1) directionChanges.erase(pos);
		}
		curr->Update();

		BodyCollision(curr);

		window->draw(*curr);
	}
}

void Snake::wallCollision() {
	if (position.x <= 0 || position.y <= 0 || position.x >= window->getSize().x - 15 || position.y >= window->getSize().y - 15)
	{
		gameOver(window);
	}
}

void Snake::BodyCollision(Body* curr)
{
	// collision is true if sum of both radius is greater than disance between objects
	sf::Vector2f currPos = curr->getPosition();
	if (sqrt(pow(position.x - currPos.x, 2) + pow(position.y - currPos.y, 2)) < (body[0]->getRadius() + body[0]->getRadius() - 20))
	{
		gameOver(window);
	}
}
