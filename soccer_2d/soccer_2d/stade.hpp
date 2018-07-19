#ifndef _STADE_
#define _STADE_

#include <SFML/Graphics.hpp>

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
public:
	Stade();
	~Stade();

	void update();
	void draw(sf::RenderWindow*);
};

#endif