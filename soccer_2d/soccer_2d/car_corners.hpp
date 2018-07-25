#ifndef _CAR_CORNERS_
#define _CAR_CORNERS_

#include <SFML/Graphics.hpp>
#include <iostream>

#define PI 3.141592
#define L 64. //largeur de la voiture
#define l 32. //hauteur de la voiture

class Corners {
private:
	double corners[4][2];
	
public:
	Corners();
	~Corners();

	sf::Vector2f get_corneri(int);

	void set_corner1(sf::Vector2f);
	void set_corner2(sf::Vector2f);
	void set_corner3(sf::Vector2f);
	void set_corner4(sf::Vector2f);

	//Methods:
	sf::Vector2f give_corner(sf::Vector2f, double, int);

	void update(sf::Vector2f, double);
};

#endif