#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include <SFML/Graphics.hpp>
#include "rectangle.hpp"


class moveable_circle : public moveable_rectangle {
private:
	sf::Vector2f speed;
public:
	moveable_circle(sf::Vector2f size, sf::Vector2f position, sf::Color color, sf::Vector2f speed, sf::Texture texture) :
		moveable_rectangle(size, position, color, texture),
		speed(speed)
	{}

	void draw(sf::RenderWindow& window) override {
		sf::CircleShape circle;
		circle.setRadius(size.x / 2);
		circle.setPosition(position);

		circle.setTexture(&texture);
		window.draw(circle);
	}
	const bool collides(drawable& other) override {
		sf::RectangleShape tempShape;
		sf::RectangleShape otherShape(other.size);
		otherShape.setPosition(other.position);

		tempShape.setSize(sf::Vector2f{ 90, 100 });
		tempShape.setPosition(sf::Vector2f{ position.x + 10, position.y });
		if (tempShape.getGlobalBounds().intersects(otherShape.getGlobalBounds())) {
			speed.y *= -1;
			return true;
			
		}


		tempShape.setSize(sf::Vector2f{ 110,75 });
		tempShape.setPosition(sf::Vector2f{ position.x-5, position.y + 25 });
		if (tempShape.getGlobalBounds().intersects(otherShape.getGlobalBounds())) {
			speed.x *= -1;
			return true;
		}
		return false;

	}


	void update() {
		oldPosition = position;
		position += speed;
	}


};

#endif /* CIRCLE_HPP */