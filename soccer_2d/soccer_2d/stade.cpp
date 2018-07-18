#include "stade.hpp"

Stade::Stade() {
	this->texture.loadFromFile("assets/images/stade/stade_1.png");
	this->sprite.setTexture(this->texture);
}

Stade::~Stade() {

}

void Stade::draw(sf::RenderWindow* p_window) {
	p_window->draw(this->sprite);
}