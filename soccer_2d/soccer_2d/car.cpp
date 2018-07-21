#include "car.hpp"

Car::Car() {
	this->texture.loadFromFile("assets/images/voiture/voiture1.png");
	this->sprite.setTexture(this->texture);
	this->position = sf::Vector2f(100, 280);
	this->velocity = sf::Vector2f(0, 0);
	this->sprite.setPosition(this->position);
	this->angle = 90.f;
	this->sprite.setRotation(this->angle);
	this->sprite.setOrigin(16, 32);
}

Car::~Car() {

}

void Car::update() {
	this->deplacement();
}

void Car::draw(sf::RenderWindow *p_window) {
	p_window->draw(this->sprite);
}

void Car::deplacement() {
	const float vitesse_max = 0.5f;
	sf::Vector2f ancienne_position = this->position;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		this->angle += 5;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
		this->angle -= 5;
	}
	this->sprite.setRotation(this->angle);

	// deplacement de base (pour les tests des collisions)
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
		if (this->position.x > 0 && this->position.x < 1024 && this->position.y > 0 &&
			this->position.y < 600) {
			this->position.x += (10 * cos(degre_to_radian(this->angle - 90)));
			this->position.y += (10 * sin(degre_to_radian(this->angle - 90)));
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		if (this->position.x > 0 && this->position.x < 1024 && this->position.y > 0 &&
			this->position.y < 600) {
			this->position.x -= (10 * cos(degre_to_radian(this->angle - 90)));
			this->position.y -= (10 * sin(degre_to_radian(this->angle - 90)));
		}
	}

	if (!(this->position.x > 0 && this->position.x < 1024 && this->position.y > 0 &&
		this->position.y < 600)) {
		this->position = ancienne_position;
	}

	// Amelioration du deplacement du vehicule
	
	/*

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
		//if(abs(this->velocity.x) < 0.5)
			this->velocity.x += (10 * cos(degre_to_radian(this->angle - 90))) / 10000.f;
		
		//if (abs(this->velocity.y) < 0.5)
			this->velocity.y += (10 * sin(degre_to_radian(this->angle - 90))) / 10000.f;
	}
	else {
		this->velocity = sf::Vector2f(0, 0);
	}

	if (this->position.x > 0 && this->position.x < 1024 && this->position.y > 0 &&
		this->position.y < 600) {
		this->position += this->velocity;
	}
	else {
		
		
		this->position = ancienne_position;


		// this->velocity = sf::Vector2f(0, 0);
	}

	*/
	
	this->sprite.setPosition(this->position);
}

double degre_to_radian(double p_angle) {
	return p_angle * 3.14159265 / 180;
}