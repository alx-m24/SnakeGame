#include "AppleSystem.hpp"

AppleSystem::AppleSystem(sf::RenderWindow* Window, Snake* CurrentSnake, int AppleNum) : window(Window), appleNum(AppleNum), snake(CurrentSnake)
{
	while (AppleNum)
	{
		NewApple();
		--AppleNum;
	}
}

void AppleSystem::NewApple()
{
	sf::Vector2i winSize = sf::Vector2i(window->getSize());
	sf::Vector2f newPos = sf::Vector2f(rand() % winSize.x, rand() % winSize.y);
	Apple* newApple = new Apple(newPos);
	apples.insert(newApple);
	window->draw(*newApple);
}

void AppleSystem::Update()
{
	while (apples.size() < appleNum)
	{
		NewApple();
	}

	for (Apple* apple : apples)
	{
		// collision is true if sum of both radius is greater than disance between objects
		Body* main = snake->body[0];
		sf::Vector2f currPos = apple->getPosition();
		sf::Vector2f mainPos = main->getPosition();
		if (sqrt(pow(mainPos.x - currPos.x, 2) + pow(mainPos.y - currPos.y, 2)) < (main->getRadius() + apple->getRadius()))
		{
			snake->newBodyPart();
			apples.erase(apple);
			break;
		}
		else window->draw(*apple);
	}
}
