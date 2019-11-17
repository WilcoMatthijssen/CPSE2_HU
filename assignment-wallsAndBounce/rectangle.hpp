#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include <SFML/Graphics.hpp>
#include "drawable.hpp"

class moveable_rectangle : public drawable {
protected:
	sf::Vector2f oldPosition;
	const sf::Texture texture;
public:
	moveable_rectangle(sf::Vector2f size, sf::Vector2f position, sf::Color color, sf::Texture texture) :
		drawable(size, position, color),
		texture(texture)
	{}

	virtual const bool collides(drawable& other) {
		sf::RectangleShape tempShape(size);
		tempShape.setPosition(position);
		sf::RectangleShape otherShape(other.size);
		otherShape.setPosition(other.position);
		bool result = tempShape.getGlobalBounds().intersects(otherShape.getGlobalBounds());
		return result;
	}
	void draw(sf::RenderWindow& window)override {
		sf::RectangleShape renderShape(size);
		renderShape.setPosition(position);
		renderShape.setTexture(&texture);
		window.draw(renderShape);

	}
	void move(sf::Vector2f delta) {
		oldPosition = position;
		position += delta;
	}

	void jump(sf::Vector2f target) {
		oldPosition = position;
		position = target;
	}

	void jump(const sf::Vector2i target) {
		jump(sf::Vector2f(
			static_cast<float>(target.x - (size.x / 2)),
			static_cast<float>(target.y - (size.x / 2))
		));
	}





	void revert_move() {
		position = oldPosition;
	}

};

#endif /* RECTANGLE_HPP */