#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <GUI/GUI.hpp>

int main()
{
	GUI::Window window;
	window.create(sf::VideoMode(sf::Vector2u(800, 600)), "premium gui", sf::Style::Close);
	
	std::optional<sf::Event> event;

	while (true)
	{
		event = window.pollEvent();
		if (event.has_value())
		{
			if (event->is<sf::Event::Closed>())
				break;
		}

		window.clear();
		window.display();
	}

	window.close();

	return 0;
}