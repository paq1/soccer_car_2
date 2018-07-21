#include "car_corners.hpp"

Corners::Corners() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; i < 2; j++) {
			this->corners[i][j] = 0;
		}
	}
}
Corners::~Corners() {
	// rien a supprimer
}

#pragma region GETTERS
// donne le coin avant gauche
sf::Vector2f Corners::get_corner1() {
	return sf::Vector2f(this->corners[0][0],
		this->corners[0][1]);
}
// donne le coin avant droit
sf::Vector2f Corners::get_corner2() {
	return sf::Vector2f(this->corners[1][0],
		this->corners[1][1]);
}
// donne le coin arrière droit
sf::Vector2f Corners::get_corner3() {
	return sf::Vector2f(this->corners[2][0],
		this->corners[2][1]);
}
// donne le coin avant gauche
sf::Vector2f Corners::get_corner4() {
	return sf::Vector2f(this->corners[3][0],
		this->corners[3][1]);
}
#pragma endregion

#pragma region SETTERS
// modifie le coin avant gauche
void Corners::set_corner1(sf::Vector2f p_coin) {
	this->corners[0][0] = p_coin.x;
	this->corners[0][1] = p_coin.y;
}
// modifie le coin avant droit
void Corners::set_corner2(sf::Vector2f p_coin) {
	this->corners[1][0] = p_coin.x;
	this->corners[1][1] = p_coin.y;
}
// modifie le coin arrière droit
void Corners::set_corner3(sf::Vector2f p_coin) {
	this->corners[2][0] = p_coin.x;
	this->corners[2][1] = p_coin.y;
}
// modifie le coin avant gauche
void Corners::set_corner4(sf::Vector2f p_coin) {
	this->corners[3][0] = p_coin.x;
	this->corners[3][1] = p_coin.y;
}
#pragma endregion

sf::Vector2f Corners::give_corner(
	sf::Vector2f pos_car,
	double angle_car,
	int i
) {
	double theta = angle_car;
	if (i == 1) {
		theta = theta + ALPHA;
	}
	else if (i == 2) {
		theta = theta + PI - ALPHA;
	}
	return pos_car;
}

void Corners::update(sf::Vector2f pos_car, 
	double angle_car) {

}