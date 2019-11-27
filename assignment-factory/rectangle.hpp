#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "screenObject.hpp"
/// @brief Class for drawing rectangles.
/// @author Wilco Matthijssen
class rectangle : public screenObject {
protected:
	sf::RectangleShape rectShape;
	const uint32_t color;
public:
	/// @brief Construct a rectangle object with given size and position (optional color).
	///
	/// @param size			Size of object.
	/// @param position		Position of object
	/// @param color		Color of object.
	/// 
	rectangle(const sf::Vector2f size, sf::Vector2f position, const uint32_t color = 0xFFFFFFFF);

	/// @brief	Creates a string what it is so it can be recreated.
	///
	/// @return	string	A string containing the position, type of screenObject, size and color in that order.
	///
	const std::string whatAmI()override;

	/// @brief	Draw rectangle to a sf::RenderWindow.
	///
	/// @param	window  sf::RenderWindow to draw rectangle on.
	/// @return	void
	///
	void draw(sf::RenderWindow& window)override;

	/// @brief	Select rectangle by inverting colors
	///
	/// @return	Void
	///
	void select()override;

	/// @brief	Deselect rectangle by returning colors to the original
	///
	/// @return	void
	///
	void deselect()override;

	/// @brief	Returns true if target is inside rectangle.
	///
	/// @param	target	x y location of target.
	/// @return const bool
	///
	const bool contains(const sf::Vector2i target)override;

	/// @brief	Move rectangle to target.
	///
	/// @param	target	 x y location of where to move rectangle to.
	/// @return void
	///
	void moveTo(const sf::Vector2i target)override;
};

#endif /* RECTANGLE_HPP */