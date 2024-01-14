#include "MainLoop.hpp"

Loop::Loop(sf::RenderWindow* Window) : window(Window)
{
	// assigning keys to moves
	moves[sf::Keyboard::Scan::Down] = sf::Vector2f(0.f, 2.f);
	moves[sf::Keyboard::Scan::Up] = sf::Vector2f(0.f, -2.f);
	moves[sf::Keyboard::Scan::Right] = sf::Vector2f(2.f, 0.f);
	moves[sf::Keyboard::Scan::Left] = sf::Vector2f(-2.f, 0.f);

	// assigning the opposite of each move
	oppositeMove[sf::Keyboard::Scan::Down] = sf::Keyboard::Scan::Up;
	oppositeMove[sf::Keyboard::Scan::Up] = sf::Keyboard::Scan::Down;
	oppositeMove[sf::Keyboard::Scan::Right] = sf::Keyboard::Scan::Left;
	oppositeMove[sf::Keyboard::Scan::Left] = sf::Keyboard::Scan::Right;
}

void Loop::Input(Snake* snake) {
	sf::Event event;
	// processing sfml events
	while (window->pollEvent(event)) {
		switch (event.type) {
		case sf::Event::Closed: {
			window->close();
			break;
		}
		case sf::Event::Resized: {
			
			sf::FloatRect visibleArea(0.f, 0.f, event.size.width, event.size.height);
			window->setView(sf::View(visibleArea));
			break;
		}
		case sf::Event::KeyPressed: {
			// current key
			sf::Keyboard::Scancode currKey = event.key.scancode;

			// if the key entered is in the move directoring and is not an illegal move...
			if (moves.count(currKey) && currKey != oppositeMove[lastKey]) {
				// we update the snake's velocity
				snake->velocity = moves[event.key.scancode];

				// we also update the last key that was pressed
				lastKey = currKey;
			}
		}
		default:
			break;
		}
	}
}

void Loop::Update()
{
	window->clear(sf::Color::Black);
}

void Loop::Render()
{
	window->display();
}