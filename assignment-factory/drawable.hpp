#ifndef DRAWABLE_HPP
#define DRAWABLE_HPP
#include <SFML/Graphics.hpp>
enum class shapes{ 
	rectangle, 
	circle, 
	picture 
};
//	---DRAWABLE---
//	This class creates a shape which can be drawn on an sfml window.
//
class drawable {
protected:

	const shapes shapeType;
	const sf::Texture texture;
	const sf::Vector2f size;
	sf::Vector2f position;



	void drawPicture(sf::RenderWindow& window) {
		sf::RectangleShape renderShape(size);
		renderShape.setPosition(position);
		window.draw(renderShape);
	}
	void drawRectangle(sf::RenderWindow& window) {
		sf::RectangleShape renderShape(size);
		renderShape.setPosition(position);
		window.draw(renderShape);
	}
	void drawCircle(sf::RenderWindow& window) {
		sf::CircleShape circle;
		circle.setRadius(size.x / 2);
		circle.setPosition(position);
		window.draw(circle);
	}
public:
	drawable(const sf::Vector2f size, sf::Vector2f position, const shapes shapeType) :
		position(position),
		size(size),
		shapeType(shapeType)
	{}

	void draw(sf::RenderWindow& window) {
		switch (shapeType) {
		case  shapes::rectangle: {
			drawRectangle(window);
			break;
		}
		case  shapes::circle: {
			drawCircle(window);
			break;
		}
		case  shapes::picture: {
			drawPicture(window);
			break;
		}
		}
	}

};
#endif /* DRAWABLE_HPP */