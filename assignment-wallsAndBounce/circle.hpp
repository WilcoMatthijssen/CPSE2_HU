#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include "rectangle.hpp"
class moveable_circle : public moveable_rectangle {
private:
	sf::Vector2f speed;
public:
	moveable_circle(sf::Vector2f size, sf::Vector2f position, sf::Vector2f speed, sf::Texture texture) :
		moveable_rectangle(size, position, texture),
		speed(speed)
	{}

	void draw(sf::RenderWindow& window) override {
		old_position = position;
		sf::CircleShape circle;
		circle.setRadius(size.x / 2);
		circle.setPosition(position);
		circle.setTexture(&texture);
		window.draw(circle);
	}

	const bool intersects(drawable& other) override {
		sf::RectangleShape otherShape(other.size);
		otherShape.setPosition(other.position);

		sf::RectangleShape tempShape(sf::Vector2f{ size.x - 2, size.y });
		tempShape.setPosition(sf::Vector2f{ position.x + 1, position.y });
		if (tempShape.getGlobalBounds().intersects(otherShape.getGlobalBounds())) {
			speed.y *= -1;
			return true;
		}

		tempShape.setSize(sf::Vector2f{ size.x, size.y - 2 });
		tempShape.setPosition(sf::Vector2f{ position.x, position.y + 1 });
		if (tempShape.getGlobalBounds().intersects(otherShape.getGlobalBounds())) {
			speed.x *= -1;
			return true;
		}

		return false;
	}


	void update() {
		position += speed;
	}


};

#endif /* CIRCLE_HPP */