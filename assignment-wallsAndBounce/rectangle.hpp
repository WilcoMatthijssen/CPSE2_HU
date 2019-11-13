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
	bool overlap(drawable & other){
		sf::RectangleShape tempShape (	size );
		tempShape.setPosition(position);
		sf::RectangleShape otherShape (	other.size );
		otherShape.setPosition(other.position);
		bool result =tempShape.getGlobalBounds().intersects(	otherShape.getGlobalBounds()	);
		return result;
	}
	
};

#endif /* RECTANGLE_HPP */