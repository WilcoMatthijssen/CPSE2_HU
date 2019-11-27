#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include "screenObject.hpp"
/// @brief Class for drawing circles.
/// @author Wilco Matthijssen
class circle : public screenObject {
private:
	sf::CircleShape circShape;
	const uint32_t color;
public:
	/// @brief Construct a circle object with given size and position (optional color).
	///
	/// @param size			Size of object.
	/// @param position		Position of object
	/// @param color		Color of object.
	/// 
	circle(const float size, const sf::Vector2f position, const uint32_t color = 0xFFFFFFFF);

	/// @brief	Creates a string what it is so it can be recreated.
	///
	/// @return	string	A string containing the position, type of screenObject, radius and color in that order.
	///
	const std::string whatAmI()override;


	/// @brief	Draw circle to a sf::RenderWindow.
	///
	/// @param	window  sf::RenderWindow to draw circle on.
	/// @return	void
	///
	void draw(sf::RenderWindow& window)override;


	/// @brief	Select circle by inverting colors
	///
	/// @return	Void
	///
	void select()override;


	/// @brief	Deselect circle by returning colors to the original
	///
	/// @return	void
	///
	void deselect()override;

	/// @brief	Returns true if target is inside circle.
	///
	/// @param	target	x y location of target.
	/// @return const bool
	///
	const bool contains(const sf::Vector2i target)override;


	/// @brief	Move circle to target.
	///
	/// @param	target	 x y location of where to move circle to.
	/// @return void
	///
	void moveTo(const sf::Vector2i target)override;

};
#endif /* CIRCLE_HPP */