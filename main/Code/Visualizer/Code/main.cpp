#include "PrecompiledHeader/pch.h"

int main()
{
	sf::RenderWindow window;
	window.create(sf::VideoMode(sf::Vector2u(600, 800)), "SFML Window");
	
	sf::sleep(sf::seconds(2));

	window.close();

	system("pause");
	return 0;
}
