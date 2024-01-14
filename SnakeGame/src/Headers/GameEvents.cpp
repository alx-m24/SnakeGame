#include "GameEvents.hpp"

void gameOver(sf::RenderWindow* window)
{
	// loading font from default windows font location
	sf::Font arial;
	arial.loadFromFile("C:/Windows/Fonts/Arial.ttf");

	sf::Text GameOver;
	GameOver.setString("Game Over");
	GameOver.setFont(arial);
	GameOver.setCharacterSize(64);
	GameOver.setFillColor(sf::Color::Red);
	GameOver.setPosition(window->getSize().x * 0.5f - 125, window->getSize().y * 0.5f - 100);

	window->draw(GameOver);
	window->display();

	sf::Clock myClock;
	myClock.restart();

	while (myClock.getElapsedTime().asSeconds() < 2.5);

	window->close();
}