#include "stade.hpp"

Stade::Stade() {
	// init position
	this->pos_imiko = sf::Vector2f(300, -5);

	this->droite = true;
	this->gauche = false;

	this->texture_stade.loadFromFile("assets/images/stade/stade_1.png");
	this->sprite_stade.setTexture(this->texture_stade);

	this->texture_affichage_imigame.loadFromFile(
		"assets/images/ecran_stade/soccer_affichage_imigame.png"
	);
	this->sprite_affichage_imigame.setTexture(
		this->texture_affichage_imigame
	);
	this->sprite_affichage_imigame.setPosition(this->pos_imiko);

	this->texture_ecran1.loadFromFile(
		"assets/images/ecran_stade/ecran_affichage_2.png"
	);
	this->sprite_ecran1.setTexture(
		this->texture_ecran1
	);
	this->sprite_ecran1.setPosition(sf::Vector2f(300, 0));
}

Stade::~Stade() {

}

void Stade::update() {
	// if(this->droite)

	this->sprite_affichage_imigame.setPosition(this->pos_imiko);
}

void Stade::draw(sf::RenderWindow* p_window) {
	p_window->draw(this->sprite_stade);
	p_window->draw(this->sprite_ecran1);
	p_window->draw(this->sprite_affichage_imigame);
}