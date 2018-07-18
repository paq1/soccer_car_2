#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

using namespace std;

int main(int argc, char ** argv) {
	// debut du programme
	cout << "program *************************** debut" << endl;
	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(shape);
		window.display();
	}
	cout << "program *************************** fin  " << endl;
	getchar();
	return EXIT_SUCCESS;
}