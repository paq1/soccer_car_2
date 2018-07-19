#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

#include "menu.hpp"
#include "stade.hpp"
#include "car.hpp"

using namespace std;

int main(int argc, char ** argv) {
	// debut du programme
	cout << "program *************************** debut" << endl;
	EtatProg etat_programme = etat_menu;
	Menu menu = Menu();
	Stade stade1 = Stade();
	Car voiture1 = Car();

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
			menu.update(etat_programme);
		}
		if (etat_programme == etat_jeu) {
			voiture1.update();
		}

		// dessin
		window.clear();
		if (etat_programme == etat_menu) {
			menu.draw(&window);
		}

		if (etat_programme == etat_jeu) {
			//window.draw(shape);
			stade1.draw(&window);
			voiture1.draw(&window);
		}
		window.display();
	}
	cout << "program *************************** fin  " << endl;
	getchar();
	return EXIT_SUCCESS;
}