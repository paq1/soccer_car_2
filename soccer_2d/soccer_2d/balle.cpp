#include "balle.hpp"

Balle::Balle() {

	

	this->position = sf::Vector2f(
		LARGEUR_FENETRE / 2,
		HAUTEUR_FENETRE / 2);
	this->angle = 0;
	this->rayon = 32;
	this->shape = sf::CircleShape(this->rayon);
	this->shape.setPosition(this->position);
	this->shape.setOrigin(
		this->rayon,
		this->rayon
	);
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

// donne le vecteur qui represente un cote de la voiture
// i est compris entre 1 et 4
sf::Vector2f Balle::car_side_vector(Corners p_corners, int i) {
	sf::Vector2f side_vector;
	if (i < 4) {
		float X = p_corners.get_corneri(i + 1).x
				 - p_corners.get_corneri(i).x;
		float Y = p_corners.get_corneri(i + 1).y
				 - p_corners.get_corneri(i).y;
		side_vector = sf::Vector2f(X, Y);
	}
	else {
		float X = p_corners.get_corneri(1).x
			- p_corners.get_corneri(4).x;
		float Y = p_corners.get_corneri(1).y
			- p_corners.get_corneri(4).y;
		side_vector = sf::Vector2f(X, Y);
	}
	return side_vector;
}

// donne le vecteur entre un coin de la voiture et le centre
// de la balle
// i est compris entre 1 et 4
sf::Vector2f Balle::car_ball_vector(Corners p_corners, int i) {
	float X = this->position.x - p_corners.get_corneri(i).x;
	float Y = this->position.y - p_corners.get_corneri(i).y;
	//std::cout << i << " : " << X << ", " << Y << std::endl;
	return sf::Vector2f(X, Y);
}

// Calcul le determinant des 2 vecteurs precedents
float Balle::determinant(sf::Vector2f p_car_vector, 
	sf::Vector2f p_ball_vector) {
	float det = p_ball_vector.x * p_car_vector.y
			  - p_car_vector.x * p_ball_vector.y;
	return det;
}

// Si le vecteur de la balle est à droite de celui de la voiture
// pour tous les côté alors la balle est à l'intérieur de la
// voiture
bool Balle::car_collide(Corners p_corners) {
	bool a_droite = true;
	for (int i = 1; i <= 4; i++) {
		float det = this->determinant(
			this->car_side_vector(p_corners, i),
			this->car_ball_vector(p_corners, i));
		if (det >= 0) {
			a_droite = false;
		}
	}
	return a_droite;
}

void Balle::update(Corners p_corners, double car_angle) {
	// reinitialise la baballe
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
		this->position = sf::Vector2f(
			LARGEUR_FENETRE / 2,
			HAUTEUR_FENETRE / 2
		);
		this->shape.setPosition(this->position);
	}
	
	if (car_collide(p_corners)) {
		std::cout << "COLLISION \n" << std::endl;
		this->position.x = this->position.x 
			+ 10 * cos(car_angle * PI / 180);
		this->position.y = this->position.y 
			+ 10 * sin(car_angle * PI / 180);
		this->shape.setPosition(this->position);
	}
}

void Balle::draw(sf::RenderWindow* p_window) {
	p_window->draw(this->shape);
}