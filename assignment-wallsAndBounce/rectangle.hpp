#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "drawable.hpp"
//	---MOVEABLE_RECTANGLE---
//	This class inherits the draw functionality from drawable and adds functions to make the rectangle moveable.
//
class moveable_rectangle : public drawable {
protected:
	sf::Vector2f old_position;
	const sf::Texture texture;
public:
	moveable_rectangle(sf::Vector2f size, sf::Vector2f position, sf::Texture texture) :
		drawable(size, position),
		texture(texture),
		old_position(position)
	{}

	virtual const bool intersects(drawable& other) {
		sf::RectangleShape tempShape(size);
		tempShape.setPosition(position);
		sf::RectangleShape otherShape(other.size);
		otherShape.setPosition(other.position);
		return tempShape.getGlobalBounds().intersects(otherShape.getGlobalBounds());
	}

	void draw(sf::RenderWindow& window)override {
		old_position = position;
		sf::RectangleShape renderShape(size);
		renderShape.setPosition(position);
		renderShape.setTexture(&texture);
		window.draw(renderShape);
	}

	void move(sf::Vector2f delta) {
		position += delta;
	}

	void jump(sf::Vector2f target) {
		position = target;
	}

	void jump(const sf::Vector2i target) {
		jump(sf::Vector2f(
			static_cast<float>(target.x - (size.x / 2)),
			static_cast<float>(target.y - (size.x / 2))
		));
	}

	void revert_move() {
		position = old_position;
	}

};

#endif /* RECTANGLE_HPP */