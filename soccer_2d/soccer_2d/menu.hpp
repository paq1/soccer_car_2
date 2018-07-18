#ifndef _MENU_
#define _MENU_

#include <SFML/Graphics.hpp>

class Menu {
private:
	sf::Texture texture;
	sf::Sprite sprite;
public:
	Menu();
	~Menu();

	void draw(sf::RenderWindow*);
};

#endif