#ifndef MOVEABLE_HPP
#define MOVEABLE_HPP

#include "drawable.hpp"

//	---MOVEABLE---
//	This class inherits the functionality from drawable and adds the ability to move.
//
class moveable : public drawable {
public:
	moveable(const sf::Vector2f size, sf::Vector2f position, const shapes shapeType) :
		drawable(position, size, shapeType)
	{}


	void moveTo(sf::Vector2f target) {
		position = target;
	}

	void moveTo(const sf::Vector2i target) {
		moveTo(sf::Vector2f(
			static_cast<float>(target.x - (size.x / 2)),
			static_cast<float>(target.y - (size.x / 2))
		));
	}
};
#endif /* MOVEABLE_HPP */