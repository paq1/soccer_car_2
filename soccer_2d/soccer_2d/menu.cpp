#include "menu.hpp"

Menu::Menu() {
	this->texture.loadFromFile("assets/images/interface/menu_soccer_car.png");
	this->sprite.setTexture(this->texture);
}

Menu::~Menu() {

}

void Menu::draw(sf::RenderWindow *p_window) {
	p_window->draw(this->sprite);
}