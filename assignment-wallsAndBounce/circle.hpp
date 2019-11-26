#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include "rectangle.hpp"
class moveable_circle : public moveable_rectangle {
private:
	sf::CircleShape circle;
	sf::Vector2f speed;
public:
	moveable_circle(sf::Vector2f size, sf::Vector2f position, sf::Vector2f speed, sf::Texture texture) :
		moveable_rectangle(size, position, texture),
		circle(size.x / 2),
		speed(speed)
	{
		circle.setPosition(position);
		circle.setTexture(&texture);
	}

	void draw(sf::RenderWindow& window) override {
		old_position = circle.getPosition();
		circle.setTexture(&texture);
		window.draw(circle);
	}
	sf::FloatRect getBounds() override {
		return circle.getGlobalBounds();
	}
	const bool intersects(drawable& other) override {
		rectangle.setSize(sf::Vector2f{( circle.getRadius() * 2)-2 ,(circle.getRadius() * 2) });
		rectangle.setPosition(sf::Vector2f{ circle.getPosition().x + 1, circle.getPosition().y });
		if (rectangle.getGlobalBounds().intersects(other.getBounds())) {
			speed.y *= -1;
			return true;
		}
		
		rectangle.setSize(sf::Vector2f{ circle.getRadius()*2 ,( circle.getRadius()*2)-2 });
		rectangle.setPosition(sf::Vector2f{ circle.getPosition().x,  circle.getPosition().y + 1 });
		if (rectangle.getGlobalBounds().intersects(other.getBounds())) {
			speed.x *= -1;
			return true;
		}
		return false;
	}

	void update() {
		circle.setPosition(circle.getPosition() + speed);
	}
};

#endif /* CIRCLE_HPP */