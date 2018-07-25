#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

#include "menu.hpp"
#include "stade.hpp"
#include "car.hpp"
#include "balle.hpp"
#include "car_corners.hpp"

using namespace std;

int main(int argc, char ** argv) {
	// debut du programme
	cout << "program *************************** debut" << endl;
	EtatProg etat_programme = etat_menu;
	Menu menu = Menu();
	Stade stade1 = Stade();
	Car voiture1 = Car();
	Balle balle = Balle();
	Corners corners = Corners();

	sf::RenderWindow window(sf::VideoMode(1024, 600), "soccer 2d -- EvaM2101 -- paq1 --");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	// init variable temps
	sf::Clock clock;
	sf::Time temps_precedent;
	sf::Time temps_actuel;

	while (window.isOpen())
	{
		// gestion du temps
		temps_actuel = clock.getElapsedTime();

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		// mise a jour
		if (temps_actuel.asMilliseconds() - temps_precedent.asMilliseconds() > 30) {
			if (etat_programme == etat_menu) {
				menu.update(etat_programme);
			}
			if (etat_programme == etat_jeu) {
				voiture1.update();
				stade1.update(&window);
				corners.update(
					voiture1.get_position(),
					voiture1.get_angle()
				);
				balle.update(corners, voiture1.get_angle());
			}
			temps_precedent = temps_actuel;
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
			balle.draw(&window);
		}
		window.display();
	}
	cout << "program *************************** fin  " << endl;
	getchar();
	return EXIT_SUCCESS;
}