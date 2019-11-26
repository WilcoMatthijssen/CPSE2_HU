#ifndef DRAWABLE_HPP
#define DRAWABLE_HPP
#include <SFML/Graphics.hpp>
//	---MOVEABLE_RECTANGLE---
//	This class creates a smfl shape which can be drawn to a sfml display
//
class drawable {
protected:
	sf::RectangleShape rectangle;
public:

	drawable(sf::Vector2f size, sf::Vector2f position, sf::Color color = sf::Color::White) :
		rectangle(size)
	{
		rectangle.setPosition(position);
		rectangle.setFillColor(color);
	}

	virtual void draw(sf::RenderWindow& window) {
		window.draw(rectangle);
	}
	virtual sf::FloatRect getBounds() {
		return rectangle.getGlobalBounds();
	}
};
#endif /* DRAWABLE_HPP */