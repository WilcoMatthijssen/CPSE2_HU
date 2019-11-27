#ifndef PICTURE_HPP
#define PICTURE_HPP
#include "rectangle.hpp"
/// @brief Class for drawing pictures.
/// @author Wilco Matthijssen
class picture : public rectangle {
private:
	//sf::RectangleShape rectShape;
	sf::Texture texture;
	const std::string texturePath;
public:
	/// @brief Construct a picture object with given size and position and path.
	///
	/// @param size			Size of object.
	/// @param position		Position of object
	/// @param path			Path to texture file.
	/// 
	picture(const sf::Vector2f size, const sf::Vector2f position, const std::string texturePath);

	/// @brief	Select picture by setting the color to red.
	///
	/// @return	Void
	///
	void select()override;

	/// @brief	Draw picture to a sf::RenderWindow.
	///
	/// @param	window  sf::RenderWindow to draw picture on.
	/// @return	void
	///
	void draw(sf::RenderWindow& window) override;

	/// @brief	Creates a string what it is so it can be recreated.
	///
	/// @return	string	A string containing the position, type of screenObject, size and path to texture in that order.
	///
	const std::string whatAmI() override;
};

#endif /* PICTURE_HPP */