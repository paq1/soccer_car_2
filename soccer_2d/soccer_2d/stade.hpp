#ifndef _STADE_
#define _STADE_

#include <SFML/Graphics.hpp>

class Stade {
private:
	sf::Texture texture;
	sf::Sprite sprite;
public:
	Stade();
	~Stade();

	void draw(sf::RenderWindow*);
};

#endif