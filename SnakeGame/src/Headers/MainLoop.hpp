#pragma once
#include "Snake.hpp"
#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <vector>

class Loop {
private:
	// pointer to window
	sf::RenderWindow* window;

	// dictionary of possible moves
	std::unordered_map<sf::Keyboard::Scancode, sf::Vector2f> moves;

	// dictionary of illegal moves according to the last move
	std::unordered_map<sf::Keyboard::Scancode, sf::Keyboard::Scancode> oppositeMove;

	// storing last key (move)
	sf::Keyboard::Scancode lastKey = sf::Keyboard::Scancode::Right;
public:
	// contruct
	Loop(sf::RenderWindow* Window);

	void Input(Snake* snake);
	void Update();
	void Render();
};