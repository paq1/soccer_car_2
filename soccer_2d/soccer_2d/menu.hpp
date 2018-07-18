#ifndef _MENU_
#define _MENU_

#include <SFML/Graphics.hpp>

enum EtatProg { etat_menu, etat_jeu };

class Menu {
private:
	sf::Texture texture;
	sf::Sprite sprite;
public:
	Menu();
	~Menu();

	void update(EtatProg&);
	void draw(sf::RenderWindow*);
};

#endif