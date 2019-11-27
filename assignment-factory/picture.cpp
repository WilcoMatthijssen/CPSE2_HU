#include "picture.hpp"
#include <iostream>
picture::picture(const sf::Vector2f size, const sf::Vector2f position, const std::string texturePath) :
	rectangle(size,position),
	texturePath(texturePath)
{
	
	//rectShape.setPosition(position);
	texture.loadFromFile(texturePath);
	rectShape.setTexture(&texture);
}

void picture::select() {
	rectShape.setFillColor(sf::Color::Red);
}

void picture::draw(sf::RenderWindow& window) {
	rectShape.setTexture(&texture);
	window.draw(rectShape);
}

const std::string picture::whatAmI() {
	std::string details;
	details += std::to_string(rectShape.getPosition().x) + ' ';
	details += std::to_string(rectShape.getPosition().y);
	details += " picture ";
	details += std::to_string(rectShape.getSize().x) + ' ';
	details += std::to_string(rectShape.getSize().y) + ' ';
	details += texturePath;
	return details;
}