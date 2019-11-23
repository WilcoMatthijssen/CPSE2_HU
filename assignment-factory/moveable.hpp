#ifndef MOVEABLE_HPP
#define MOVEABLE_HPP
#include <SFML/Graphics.hpp>

//	---MOVEABLE---
//	This class creates a shape which can be drawn and moved.
class moveable {
protected:
	const sf::Vector2f size;
	sf::Vector2f position;
	bool selected=true;
public:
	moveable(const sf::Vector2f size, sf::Vector2f position) :
		position(position),
		size(size)
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
	virtual void draw(sf::RenderWindow& window) = 0;
	virtual void select() = 0;
	virtual void deselect() = 0;
	virtual bool contains(const sf::Vector2f target) = 0;
	virtual bool contains(const sf::Vector2i target) = 0;
};

//	---CIRCLE---
//	This class inherits the functionality from moveable and makes the shape a circle.
class circle : public moveable {
private:
	sf::CircleShape shape;
	sf::Color color;
public:
	circle(const sf::Vector2f size, sf::Vector2f position, sf::Color color = sf::Color::White) :
		moveable(size, position),
		shape(size.x/2),
		color(color)
	{}
	void select() override {
		shape.setOutlineColor(sf::Color::Red);
		shape.setOutlineThickness(size.x / 10);
	}
	void deselect() override {
		shape.setOutlineColor(sf::Color::White);
	}
	void draw(sf::RenderWindow& window) override {
		shape.setPosition(position);
		window.draw(shape);
	}
	bool contains(const sf::Vector2f target) override{
		//sf::CircleShape shape(size.x / 2);
		//shape.setPosition(position);
		return  shape.getGlobalBounds().contains(target);

		
	}

	bool contains(const sf::Vector2i target) override {
		return contains(sf::Vector2f(
			static_cast<float>(target.x ),
			static_cast<float>(target.y )
		));
	}
	
};

//	---RECTANGLE---
//	This class inherits the functionality from moveable and makes the shape a rectangle.
class rectangle : public moveable {
private:
	sf::RectangleShape shape;
	const sf::Color color;

public:
	rectangle(const sf::Vector2f size, const sf::Vector2f position, const sf::Color color = sf::Color::White) :
		moveable(size, position),
		shape(size),
		color(color)
	{}
	void select() override {
		shape.setOutlineColor(sf::Color::Red);
	}
	void deselect() override {
		shape.setOutlineColor(color);
	}
	void draw(sf::RenderWindow& window) override {
		shape.setPosition(position);
		window.draw(shape);
	}

};

//	---LINE---
//	This class inherits the functionality from moveable and makes the shape a line.
class line : public moveable {
private:
	sf::RectangleShape shape;
	const sf::Color color;

public:
	line(const sf::Vector2f size, const sf::Vector2f position, const sf::Color color = sf::Color::White) :
		moveable(size, position),
		shape(size),
		color(color)
	{}
	void select() override {
		shape.setOutlineColor(sf::Color::Red);
	}
	void deselect() override {
		shape.setOutlineColor(color);
	}
	void draw(sf::RenderWindow& window) override {
		shape.setPosition(position);
		window.draw(shape);
	}

};

//	---PICTURE---
//	This class inherits the functionality from moveable and makes the shape a picture.
class picture : public moveable {
private:
	sf::RectangleShape shape;
	const sf::Texture texture;
	const sf::Color color;
public:
	picture(const sf::Vector2f size, const sf::Vector2f position, const sf::Texture texture, const sf::Color color = sf::Color::White) :
		moveable(size, position),
		shape(size),
		texture(texture),
		color(color)
	{
		shape.setTexture(&texture);
	}
	void select() override {
		shape.setOutlineColor(sf::Color::Red);
	}
	void deselect() override {
		shape.setOutlineColor(color);
	}
	void draw(sf::RenderWindow& window) override {
		shape.setPosition(position);
		window.draw(shape);
	}

};

#endif /* MOVEABLE_HPP */