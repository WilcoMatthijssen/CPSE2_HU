#ifndef SHAPECONFIG_HPP
#define SHAPECONFIG_HPP

#include <vector>
#include "screenObject.hpp"


/// @brief Class for controlling shapes.
/// @author Wilco Matthijssen
class shapeControl {
private:
	const std::string configFile;
	std::vector<screenObject*> movingShapes;
	size_t selectedShapeIndex=0;
	
	/// @brief	Read screenObject from ifstream.
	///
	/// @param	input Where to read screenObject out of.
	/// @return	screenObject* pointer of new screenObject.
	///
	screenObject* readScreenObject(std::ifstream& input);

	/// @brief Construct all shapes from configFile.
	/// 
	void loadShapesFromFile();

	/// @brief store all screenObject to a configFile
	///
	void storeShapesToFile();

public:
	/// @brief Construct all shapes from file.
	///
	/// @param configFile File path to file containing shape config
	/// 
	shapeControl(const std::string configFile);

	/// @brief Deconstruct by writing all screenObject to a file
	///
	~shapeControl();
	
	/// @brief	Select screenObjects.
	///
	/// @param	target x y position of object to select.
	/// @return	void
	///
	void selectShape(const sf::Vector2i target);

	/// @brief	Draw all screenObjects to window
	///
	/// @param	window  sf::RenderWindow to draw all screenObjects on.
	/// @return	void
	///
	void draw(sf::RenderWindow& window);

	/// @brief	Draw rectangle to a sf::RenderWindow.
	///
	/// @param	target  x y position of where to move selected shape to.
	/// @return	void
	///
	void moveSelectedShape(const sf::Vector2i target);
	
};



#endif /* SHAPECONFIG_HPP */