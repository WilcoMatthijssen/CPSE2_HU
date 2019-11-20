#ifndef SHAPECONFIG_HPP
#define SHAPECONFIG_HPP

#include <vector>
#include "moveable.hpp"
#include "drawable.hpp"

//	---SHAPECONTROL---
//	
//
class shapeControl {
private:
	const std::string configFile;
	std::vector<drawable> staticShapes;
	std::vector<moveable> movingShapes;
	size_t selectedShapeIndex=0;
	
	void loadShapesFromFile(const std::string & fileName) {
		//load shapes from file
		//vector emplace_back()
	}
	void storeShapesToFile(const std::string& fileName) {
		//store shapes to file
	}
	void drawMoveables(sf::RenderWindow& window) {
		for (auto& shape : movingShapes) {
			shape.draw(window);
		}
	}
	void drawDrawables(sf::RenderWindow& window) {
		for (auto& shape : staticShapes) {
			shape.draw(window);
		}
	}
	
public:
	shapeControl(const std::string configFile) {
		loadShapesFromFile(configFile);
	}

	~shapeControl() {
		loadShapesFromFile(configFile);
	}
	
	void selectShape(const size_t shapeIndex) {
		/*
		//(condition) ? (if_true) : (if_false)
		(shapeIndex > movingShapes.size()) ?
			selectedShapeIndex = shapeIndex :
			selectedShapeIndex = movingShapes.size();
			*/
		if (shapeIndex > movingShapes.size()) {
			selectedShapeIndex = shapeIndex;
		}
		else {
			selectedShapeIndex = movingShapes.size();
		}
	}
	void draw(sf::RenderWindow& window) {
		drawDrawables(window);
		drawMoveables(window);
	}
	void moveToSelectedShape(const sf::Vector2i target) {
		if (movingShapes.size() > 0) {
			movingShapes[selectedShapeIndex].moveTo(target);
		}
	}
	
};

#endif /* SHAPECONFIG_HPP */