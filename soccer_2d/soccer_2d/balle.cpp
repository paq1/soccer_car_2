#include "balle.hpp"

Balle::Balle() {
	this->position = sf::Vector2f(
		LARGEUR_FENETRE / 2,
		HAUTEUR_FENETRE / 2);
	this->angle = 0;
	this->rayon = 32;
	this->shape = sf::CircleShape(this->rayon);
	this->R = 255;
	this->V = 255;
	this->B = 255;
	this->shape.setFillColor(
		sf::Color(this->R, this->V, this->B)
	);
	this->d = 10;
}

Balle::~Balle() {
	// rien a supprimer
}

sf::Vector2f Balle::get_pos() {
	return this->position;
}
double Balle::get_angle() {
	return this->angle;
}

void Balle::set_pos(sf::Vector2f p_pos) {
	this->position = p_pos;
}
void Balle::set_angle(double p_angle) {
	this->angle = p_angle;
}

void Balle::update() {

}

void Balle::draw(sf::RenderWindow* p_window) {
	p_window->draw(this->shape);
}