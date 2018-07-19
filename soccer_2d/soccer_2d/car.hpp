#ifndef _CAR_
#define _CAR_

#include <SFML/Graphics.hpp>

class Car {
private:
	sf::Texture texture;
	sf::Sprite  sprite;

	sf::Vector2f position;
	double angle;
public:
	Car();
	~Car();

	void update();
	void draw(sf::RenderWindow*);
};

#endif