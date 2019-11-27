#include "circle.hpp"

circle::circle(const float size, const sf::Vector2f position, const uint32_t color) :
	circShape(size),
	color(color)
{
	circShape.setPosition(position);
	circShape.setFillColor(sf::Color::Color(color));
}
const std::string circle::whatAmI()  {
	std::string details;
	details	+= std::to_string(circShape.getPosition().x) + ' ';
	details += std::to_string(circShape.getPosition().y);
	details += " circle ";
	details += std::to_string(circShape.getRadius()) + ' ';
	details += std::to_string(color);
	return details;
}

void circle::select()  {
	circShape.setFillColor(sf::Color::Color(~color | 0xFF));
}

void circle::deselect()  {
	circShape.setFillColor(sf::Color::Color(color));
}

void circle::draw(sf::RenderWindow& window){
	window.draw(circShape);
}

void circle::moveTo(const sf::Vector2i target) {
	circShape.setPosition(sf::Vector2f(
		static_cast<float>(target.x - circShape.getRadius()),
		static_cast<float>(target.y - circShape.getRadius())
	));
}

const bool circle::contains(const sf::Vector2i target)  {
	return  circShape.getGlobalBounds().contains(sf::Vector2f(
		static_cast<float>(target.x),
		static_cast<float>(target.y)
	));
}
