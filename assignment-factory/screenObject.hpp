#ifndef SCREENOBJECT_HPP
#define SCREENOBJECT_HPP
#include <SFML/Graphics.hpp>

/// @brief Base class for screen objects.
/// @author Wilco Matthijssen
class screenObject {
public:
	/// @brief virtual function for moving screenObject.
	///
	/// @param target  x y location of where to move object to.
	/// @return   Void
	///
	virtual void  moveTo(const sf::Vector2i location) = 0;

	/// @brief virtual function for checking if the location is inside a screenObject.
	///
	/// @param location  x y location of where to check if it is inside the object.
	/// @return   bool
	///
	virtual const bool contains(const sf::Vector2i location) = 0;

	/// @brief virtual function for drawing screenObjects to a sf::RenderWindow.
	///
	/// @param window Write screenObject to window
	/// @return   bool
	///
	virtual void  draw(sf::RenderWindow& window) = 0;

	/// @brief virtual function for selecting screenObjects.
	///
	/// @return   void
	///
	virtual void  select() = 0;


	/// @brief virtual function for deselecting screenObjects.
	///
	/// @return   void
	///
	virtual void  deselect() = 0;

	/// @brief virtual function for creating a string of what the screenObject is.
	///
	/// @return   std::string
	///
	virtual const std::string whatAmI();

	/// @brief Operator overload for screenobjects to ostream.
	///
	/// @return   std::ostream&
	///
	friend std::ostream& operator << (std::ostream& out, screenObject& shape);
};
#endif /* SCREENOBJECT_HPP */