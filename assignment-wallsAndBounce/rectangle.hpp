#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "drawable.hpp"
//	---MOVEABLE_RECTANGLE---
//	This class inherits the draw functionality from drawable and adds functions to make the rectangle moveable.
//
class moveable_rectangle : public drawable {
protected:
	sf::Vector2f old_position;
	sf::Texture texture;
public:
	moveable_rectangle(sf::Vector2f size, sf::Vector2f position, sf::Texture texture) :
		drawable(size, position),
		texture(texture),
		old_position(position)
	{
	}

	virtual const bool intersects(drawable& other) {
		return rectangle.getGlobalBounds().intersects(other.getBounds());
	}

	void draw(sf::RenderWindow& window)override {
		old_position = rectangle.getPosition();
		rectangle.setTexture(&texture);
		window.draw(rectangle);
	}

	void move(sf::Vector2f delta) {
		rectangle.setPosition(rectangle.getPosition() + delta);
	}

	void jump(sf::Vector2f target) {
		rectangle.setPosition(target);
	}

	void jump(const sf::Vector2i target) {
		jump(sf::Vector2f(
			static_cast<float>(target.x - (rectangle.getSize().x / 2)),
			static_cast<float>(target.y - (rectangle.getSize().x / 2))
		));
	}

	void revert_move() {
		rectangle.setPosition(old_position);
	}

};

#endif /* RECTANGLE_HPP */