#include <SFML/Graphics.hpp>
#include <iostream>

int main() {
	// Create an Untitled Window 1200x600 that allows Resizing and Closing with Frame Rate Cap of 240
	sf::RenderWindow window(sf::VideoMode(1200, 600), "Untitled Project", sf::Style::Resize | sf::Style::Close);
	window.setFramerateLimit(240);

	// Create a 100x100 Rectangle in the Middle of the Screen
	sf::RectangleShape rec(sf::Vector2f(100.0f, 100.f));
	rec.setPosition(sf::Vector2f(600 - 50, 300 - 50));

	// run the program as long as the window is open
	while (window.isOpen()) 
	{
		// check all the window's events that were triggered since the last iteration of the loop
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close(); // "close requested" event: we close the window
				break;
			case sf::Event::Resized:
				printf("Width: %i, Height: %i\n", event.size.width, event.size.height);
				break;
			}
		}

		// clear the window with black color
		window.clear(sf::Color::Black);

		// Draw the Rectangle
		window.draw(rec);

		// Display everything
		window.display();
	}
	return 0;
}