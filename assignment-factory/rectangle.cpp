#include "rectangle.hpp"

rectangle::rectangle(const sf::Vector2f size, sf::Vector2f position, const uint32_t color) :
	rectShape(size),
	color(color)
{
	rectShape.setPosition(position);
	rectShape.setFillColor(sf::Color::Color(color));
}

void rectangle::moveTo(const sf::Vector2i target){
	rectShape.setPosition(sf::Vector2f(
		static_cast<float>(target.x - (rectShape.getSize().x / 2)),
		static_cast<float>(target.y - (rectShape.getSize().x / 2))
	));
}

void rectangle::draw(sf::RenderWindow& window){
	window.draw(rectShape);
}

void rectangle::select(){
	rectShape.setFillColor(sf::Color::Color(~color | 0xFF));
}

void rectangle::deselect(){
	rectShape.setFillColor(sf::Color::Color(color));
}

const bool rectangle::contains(const sf::Vector2i target){
	return  rectShape.getGlobalBounds().contains(sf::Vector2f(
		static_cast<float>(target.x),
		static_cast<float>(target.y)
	));
}

const std::string rectangle::whatAmI(){
	std::string details;
	details += std::to_string(rectShape.getPosition().x) + ' ';
	details += std::to_string(rectShape.getPosition().y);
	details += " rectangle ";
	details += std::to_string(rectShape.getSize().x) + ' ';
	details += std::to_string(rectShape.getSize().y) + ' ';
	details += std::to_string(color);
	return details;
}