#ifndef MOVEABLE_HPP
#define MOVEABLE_HPP
#include <SFML/Graphics.hpp>
#include <string>
//	---MOVEABLE---
//	This class creates a shape which can be drawn and moved.
class screenObject {
public:
	virtual void  moveTo(const sf::Vector2i location)		= 0;
	virtual const bool contains(const sf::Vector2i location)= 0;
	virtual void  draw(sf::RenderWindow& window)			= 0;
	virtual void  select()	= 0;
	virtual void  deselect()= 0;
	
};

class rectangle: public screenObject{
protected:
	sf::RectangleShape rectShape;
	const sf::Color color;
public:
	rectangle(const sf::Vector2f size, sf::Vector2f position, const sf::Color color = sf::Color::White) :
		rectShape(size),
		color(color)
	{
		rectShape.setPosition(position);
		rectShape.setOutlineThickness(5);
	}
	rectangle(sf::Vector2f position) {
		rectShape.setPosition(position);
	}
	void moveTo(const sf::Vector2i target) override{
		rectShape.setPosition(sf::Vector2f(
			static_cast<float>(target.x - (rectShape.getSize().x / 2)),
			static_cast<float>(target.y - (rectShape.getSize().x / 2))
		));
	}

	void draw(sf::RenderWindow& window) override {
		window.draw(rectShape);
	}

	void select() override{
		rectShape.setOutlineColor(sf::Color::Red);	
	}

	void deselect() override{
		rectShape.setOutlineColor(color);
	}

	const bool contains(const sf::Vector2i target) override{
		return  rectShape.getGlobalBounds().contains(sf::Vector2f(
			static_cast<float>(target.x),
			static_cast<float>(target.y)
		));
	}


};

//	---CIRCLE---
//	This class inherits the functionality from moveable and makes the shape a circle.
class circle: public screenObject {
private:
	sf::CircleShape circShape;
	const uint_fast32_t color;
public:
	circle(const float size, const sf::Vector2f position, const uint_fast32_t color= 0xFF00FFFF):
		circShape(size),
		color(color)
	{
		circShape.setPosition(position);
		circShape.setFillColor(sf::Color::Color(color));
		circShape.setOutlineThickness(5);
		circShape.setOutlineColor(sf::Color::Color(color));
		
	}


	void draw(sf::RenderWindow& window) override {
		window.draw(circShape);
	}

	void select() override {
		circShape.setOutlineColor(sf::Color::Red);
	}

	void deselect() override{
		circShape.setOutlineColor(sf::Color::Color(color));
	}
	const bool contains(const sf::Vector2i target) override {
		return  circShape.getGlobalBounds().contains(sf::Vector2f(
			static_cast<float>(target.x),
			static_cast<float>(target.y)
		));
	}

	void moveTo(const sf::Vector2i target) override {
		circShape.setPosition(sf::Vector2f(
			static_cast<float>(target.x - circShape.getRadius()),
			static_cast<float>(target.y - circShape.getRadius())
		));
	}

	
};





//	---PICTURE---
//	This class inherits the functionality from moveable and makes the shape a picture.
class picture : public rectangle {
private:
	sf::Texture texture;
public:
	picture(const sf::Vector2f size, const sf::Vector2f position, const std::string path) :
		rectangle(size,position)
		
	{	
		texture.loadFromFile(path);
		rectShape.setTexture(&texture);
	}
	picture(const sf::Vector2f position):
		rectangle(position)
	{	}
	void draw(sf::RenderWindow& window) override {
		rectShape.setTexture(&texture);
		window.draw(rectShape);
	}

};

#endif /* MOVEABLE_HPP */