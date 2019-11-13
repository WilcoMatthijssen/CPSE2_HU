#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include <SFML/Graphics.hpp>
#include "drawable.hpp"

class rectangle: public drawable{
public:
	rectangle(sf::Vector2f size, sf::Vector2f position, sf::Color color ):
	drawable( size, position, color)
	{}

	void draw(sf::RenderWindow & window ) override {
		sf::RectangleShape wallShape (	size );
		wallShape.setPosition(position);
		wallShape.setFillColor(color);
		window.draw(wallShape);
	}
	
};

#endif /* RECTANGLE_HPP */