#ifndef _BALLE_
#define _BALLE_

#include <SFML/Graphics.hpp>
#include "car_corners.hpp"

#define HAUTEUR_FENETRE 600
#define LARGEUR_FENETRE 1024

class Balle {
private:
	sf::Vector2f position;
	double angle;
	sf::CircleShape shape;
	int R;
	int V;
	int B;
	int rayon;
	int d;
public:
	Balle();
	~Balle();

	sf::Vector2f get_pos();
	double get_angle();

	void set_pos(sf::Vector2f);
	void set_angle(double);

	void update(Corners, double);
	void draw(sf::RenderWindow*);

	// Methods
	sf::Vector2f car_side_vector(Corners, int);
	sf::Vector2f car_ball_vector(Corners, int);
	float determinant(sf::Vector2f, sf::Vector2f);
	bool car_collide(Corners);
};

#endif // !_BALLE_