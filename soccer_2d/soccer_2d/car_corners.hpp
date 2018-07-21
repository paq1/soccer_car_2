#ifndef _CAR_CORNERS_
#define _CAR_CORNERS_

#include <SFML/Graphics.hpp>

#define PI 3,141592
#define L 64 //largeur de la voiture
#define l 32 //hauteur de la voiture
#define D sqrt(pow(L/2, 2) + pow(l/2, 2)) 
// longueur de la demi diagonale
#define ALPHA atan(l/L) 
// angle  entre l'axe des x et la premiere diagonale

class Corners {
private:
	double corners[4][2];
public:
	Corners();
	~Corners();

	sf::Vector2f get_corner1();
	sf::Vector2f get_corner2();
	sf::Vector2f get_corner3();
	sf::Vector2f get_corner4();

	void set_corner1(sf::Vector2f);
	void set_corner2(sf::Vector2f);
	void set_corner3(sf::Vector2f);
	void set_corner4(sf::Vector2f);

	//Methods:
	sf::Vector2f give_corner(sf::Vector2f, double, int);

	void update(sf::Vector2f, double);
};

#endif