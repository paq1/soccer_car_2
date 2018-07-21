#ifndef _STADE_
#define _STADE_

#include <SFML/Graphics.hpp>
#include <iostream>

class Stade {
private:
	sf::Texture texture_stade;
	sf::Sprite sprite_stade;

	sf::Texture texture_ecran1;
	sf::Sprite sprite_ecran1;

	sf::Texture texture_affichage_imigame;
	sf::Sprite sprite_affichage_imigame;

	sf::Vector2f pos_imiko;
	bool gauche, droite;

	sf::Font police;
	sf::Text texte_pos_souris;
public:
	Stade();
	~Stade();

	void update(sf::RenderWindow*);
	void draw(sf::RenderWindow*);
};

#endif