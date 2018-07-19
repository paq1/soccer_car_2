#include "car.hpp"

Car::Car() {
	this->texture.loadFromFile("assets/images/voiture/voiture1.png");
	this->sprite.setTexture(this->texture);
	this->position = sf::Vector2f(100, 280);
	this->sprite.setPosition(this->position);
	this->angle = 90.f;
	this->sprite.setRotation(this->angle);
}

Car::~Car() {

}

void Car::update() {
	

	this->sprite.setPosition(this->position);
}

void Car::draw(sf::RenderWindow *p_window) {
	p_window->draw(this->sprite);
}