#ifndef MOVEABLE_HPP
#define MOVEABLE_HPP
#include <SFML/Graphics.hpp>
#include <string>
/// @brief Base class for screen objects.
/// @author Wilco Matthijssen
class screenObject {
public:
	virtual void  moveTo(const sf::Vector2i location)		= 0;
	virtual const bool contains(const sf::Vector2i location)= 0;
	virtual void  draw(sf::RenderWindow& window)			= 0;
	virtual void  select()	= 0;
	virtual void  deselect()= 0;
	virtual const std::string whatAmI() { return "am nothing"; };
	friend std::ostream& operator << (std::ostream& out, screenObject& shape)
	{
		out << shape.whatAmI();
		return out;
	}
	
};
/// @brief Class for drawing rectangles.
/// @author Wilco Matthijssen
class rectangle: public screenObject{
protected:
	sf::RectangleShape rectShape;
	const uint_fast32_t color;
public:
	/// @brief Construct a rectangle object with given size and position (optional color).
	///
	/// @param size			Size of object.
	/// @param position		Position of object
	/// @param color		Color of object.
	/// 
	rectangle(const sf::Vector2f size, sf::Vector2f position, const uint_fast32_t color = 0xFFFFFFFF) :
		rectShape(size),
		color(color)
	{
		rectShape.setPosition(position);
		rectShape.setFillColor(sf::Color::Color(color));
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
		rectShape.setOutlineColor(sf::Color::Color(~color | 0xFF));
	}

	void deselect() override{
		rectShape.setOutlineColor(sf::Color::Color(color));
	}

	const bool contains(const sf::Vector2i target) override{
		return  rectShape.getGlobalBounds().contains(sf::Vector2f(
			static_cast<float>(target.x),
			static_cast<float>(target.y)
		));
	}


};

/// @brief Class for drawing circles.
/// @author Wilco Matthijssen
class circle: public screenObject {
private:
	sf::CircleShape circShape;
	const uint_fast32_t color;
public:
	/// @brief Construct a circle object with given size and position (optional color).
	///
	/// @param size			Size of object.
	/// @param position		Position of object
	/// @param color		Color of object.
	/// 
	circle(const float size, const sf::Vector2f position, const uint_fast32_t color= 0xFFFFFFFF):
		circShape(size),
		color(color)
	{
		circShape.setPosition(position);
		circShape.setFillColor(sf::Color::Color(color));
	}
	const std::string whatAmI() override {
		std::string sentence = std::to_string(circShape.getPosition().x) + ' ';
		sentence += std::to_string(circShape.getPosition().y);
		sentence += " circle ";
		sentence += std::to_string(circShape.getRadius())+' ';
		sentence += std::to_string(color);
		return sentence;
	}
	/*	out << shape.getPosition().x << ' '<<shape.getPosition().y;
		out << ' ' << "string";
		out << ' ' << shape.getRadius();
		out << ' ' << shape.getColor();
		return out;
	}*/
	
	
	void draw(sf::RenderWindow& window) override {
		window.draw(circShape);
	}

	void select() override {
		circShape.setFillColor(sf::Color::Color(~color | 0xFF));
	}

	void deselect() override{
		circShape.setFillColor(sf::Color::Color(color));
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





/// @brief Class for drawing pictures.
/// @author Wilco Matthijssen
class picture : public rectangle {
private:
	sf::Texture texture;
public:
	/// @brief Construct a rectangle object with given size and position and path.
	///
	/// @param size			Size of object.
	/// @param position		Position of object
	/// @param path			Path to texture file.
	/// 
	picture(const sf::Vector2f size, const sf::Vector2f position, const std::string path) :
		rectangle(size,position)
		
	{	
		texture.loadFromFile(path);
		rectShape.setTexture(&texture);
	}

	void select() override{
		rectShape.setFillColor(sf::Color::Red);
	}
	void draw(sf::RenderWindow& window) override {
		rectShape.setTexture(&texture);
		window.draw(rectShape);
	}

};

#endif /* MOVEABLE_HPP */