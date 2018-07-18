#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

#include "menu.hpp"

using namespace std;

enum EtatProg {etat_menu, etat_jeu};

int main(int argc, char ** argv) {
	// debut du programme
	cout << "program *************************** debut" << endl;
	EtatProg etat_programme = etat_menu;
	Menu menu = Menu();

	sf::RenderWindow window(sf::VideoMode(1024, 600), "soccer 2d -- EvaM2101 -- paq1 --");
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

		// mise a jour
		if (etat_programme == etat_menu) {
		}

		// dessin
		window.clear();
		window.draw(shape);

		if (etat_programme == etat_menu) {
			menu.draw(&window);
		}

		window.display();
	}
	cout << "program *************************** fin  " << endl;
	getchar();
	return EXIT_SUCCESS;
}