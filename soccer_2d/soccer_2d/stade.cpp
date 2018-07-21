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

	// police d'ecriture
	if (!this->police.loadFromFile("assets/police/arial.ttf")) {
		//std::cout << "erreur de chargement de la police" << std::endl;
	}
		

	this->texte_pos_souris.setFont(this->police);
	this->texte_pos_souris.setCharacterSize(14);
	this->texte_pos_souris.setPosition(sf::Vector2f(0, 0));
	this->texte_pos_souris.setFillColor(sf::Color::Red);
}

Stade::~Stade() {

}

void Stade::update(sf::RenderWindow* p_window) {
	// if(this->droite)

	this->sprite_affichage_imigame.setPosition(this->pos_imiko);

	// on recuppere les coordonné de la souris
	sf::Vector2i pos_souris_global = sf::Mouse::getPosition(*p_window);
	std::string texte_souris = "pos mouse (" + std::to_string(
		pos_souris_global.x) + 
		" ," + std::to_string(pos_souris_global.y) + ")";
	this->texte_pos_souris.setString(texte_souris);
}

void Stade::draw(sf::RenderWindow* p_window) {
	p_window->draw(this->sprite_stade);
	p_window->draw(this->sprite_ecran1);
	p_window->draw(this->sprite_affichage_imigame);
	p_window->draw(this->texte_pos_souris);
}