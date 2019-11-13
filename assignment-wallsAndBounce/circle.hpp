#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include <SFML/Graphics.hpp>
#include "drawable.hpp"

class circle: public drawable{
private:
	sf::Vector2f speed;
public:
	circle(sf::Vector2f size, sf::Vector2f position, sf::Color color, sf::Vector2f speed):
		drawable(size, position, color),
		speed(speed)
		{}

	void draw( sf::RenderWindow & window ) override {
		sf::CircleShape circle;
		circle.setRadius(size.x/2);
		circle.setPosition(position);
		window.draw(circle);
	}

	void update(){
		oldPosition=position;
		position += speed;
	}

	void interact(){
		//speed.x*=-1;
		speed.y*=-1;
	}
};

#endif /* CIRCLE_HPP */