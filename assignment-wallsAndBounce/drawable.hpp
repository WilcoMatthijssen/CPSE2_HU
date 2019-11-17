#ifndef DRAWABLE_HPP
#define DRAWABLE_HPP
#include <SFML/Graphics.hpp>

class drawable {
public:
	sf::Vector2f position;
	const sf::Vector2f size;
	const sf::Color color;

	drawable(sf::Vector2f size, sf::Vector2f position, sf::Color color) :
		position(position),
		size(size),
		color(color)
	{}

	virtual void draw(sf::RenderWindow& window) {
		sf::RectangleShape renderShape(size);
		renderShape.setPosition(position);
		renderShape.setFillColor(color);
		window.draw(renderShape);
	}
};


#endif /* DRAWABLE_HPP */