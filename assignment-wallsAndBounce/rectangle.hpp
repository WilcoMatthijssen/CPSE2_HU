#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "drawable.hpp"
class moveable_rectangle : public drawable {
protected:
	sf::Vector2f new_position;
	const sf::Texture texture;
public:
	moveable_rectangle(sf::Vector2f size, sf::Vector2f position,  sf::Texture texture) :
		drawable(size, position),
		texture(texture),
		new_position(position)
	{}

	virtual const bool collides(drawable& other) {
		sf::RectangleShape tempShape(size);
		tempShape.setPosition(new_position);
		sf::RectangleShape otherShape(other.size);
		otherShape.setPosition(other.position);
		bool result = tempShape.getGlobalBounds().intersects(otherShape.getGlobalBounds());
		return result;
	}

	void draw(sf::RenderWindow& window)override {
		position = new_position;
		sf::RectangleShape renderShape(size);
		renderShape.setPosition(new_position);
		renderShape.setTexture(&texture);
		window.draw(renderShape);
	}

	void move(sf::Vector2f delta) {
		new_position += delta;
	}

	void jump(sf::Vector2f target) {
		new_position = target;
	}

	void jump(const sf::Vector2i target) {
		jump(sf::Vector2f(
			static_cast<float>(target.x - (size.x / 2)),
			static_cast<float>(target.y - (size.x / 2))
		));
	}

	void revert_move() {
		new_position = position;
	}

};

#endif /* RECTANGLE_HPP */