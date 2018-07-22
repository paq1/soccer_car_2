#include "car_corners.hpp"

Corners::Corners() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 2; j++) {
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
	const double ALPHA = atan(l / L);
	// angle  entre la direction de la voiture
	// et la premiere diagonale
	const double D = sqrt(pow(L / 2, 2) + pow(l / 2, 2));
	// longueur de la demi diagonale
	double theta = angle_car * PI / 180.;
	if (i == 1) {
		theta = theta - ALPHA;
	}
	else if (i == 2) {
		theta = theta + ALPHA;
	}
	else if (i == 3) {
		theta = theta + PI - ALPHA;
	}
	else if (i == 4) {
		theta = theta + PI + ALPHA;
	}
	float X = pos_car.x + D * cos(theta);
	float Y = pos_car.y + D * sin(theta);
	sf::Vector2f pos_corner = sf::Vector2f(X, Y);
	return pos_corner;
}

void Corners::update(sf::Vector2f pos_car, 
	double angle_car) {
	for (int i = 0; i < 4; i++) {
		sf::Vector2f pos_corner_i
			= give_corner(pos_car, angle_car, i + 1);
		this->corners[i][0] = pos_corner_i.x;
		this->corners[i][1] = pos_corner_i.y;
		//TEST
		//std::cout << this->corners[i][0];
		//std::cout << ", ";
		//std::cout << this->corners[i][1] << std::endl;
	}
	//std::cout << "\n";
	//std::cout << ALPHA << std::endl;
}
	