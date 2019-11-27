#include <fstream>
#include <iostream>
#include "circle.hpp"
#include "rectangle.hpp"
#include "picture.hpp"
#include "shapeControl.hpp"
#define ever (;;)

screenObject* shapeControl::readScreenObject(std::ifstream& input) {
	sf::Vector2f position;
	std::string	 name;
	std::string path;
	float radius;
	sf::Vector2f size;
	uint_fast32_t color;
	input >> position.x >> position.y >> name;
	if (name == "circle") {
		input >> radius >> color;
		std::cout << "create " << name << " " << position.x << " " << position.y << " " << radius << " " << color << std::endl;
		return new circle(radius, position, color);
	}
	else if (name == "rectangle") {
		input >> size.x >> size.y >> color;
		return new rectangle(size, position, color);
	}
	else if (name == "picture") {
		input >> size.x >> size.y >> path;
		return new picture(size, position, path);
	}
	else if (name == "") {
		throw 10;
	}
	else {
		throw 11;
	}
}


void shapeControl::loadShapesFromFile() {
	std::cout << "load" << std::endl;

	std::ifstream inFile;
	inFile.open(configFile);
	for ever{
		try {
			movingShapes.push_back(readScreenObject(inFile));
		}

		catch (int e) {
			break;
		}
	}
	inFile.close();
}

void shapeControl::storeShapesToFile() {
	std::cout << "store" << std::endl;
	std::ofstream openFile;
	openFile.open(configFile);
	for (auto shape : movingShapes) {
		openFile << *shape << '\n';

	}
	openFile.close();
}




shapeControl::shapeControl(const std::string configFile) : configFile(configFile) {
	loadShapesFromFile();
}

shapeControl::~shapeControl() {
	storeShapesToFile();
}

void shapeControl::selectShape(const sf::Vector2i target) {
	for (size_t i = 0; i < movingShapes.size(); ++i) {
		if (movingShapes[i]->contains(target)) {
			movingShapes[selectedShapeIndex]->deselect();
			movingShapes[i]->select();
			selectedShapeIndex = i;
		}
	}
}

void shapeControl::draw(sf::RenderWindow& window) {
	for (auto& shape : movingShapes) {
		shape->draw(window);
	}
}

void shapeControl::moveSelectedShape(const sf::Vector2i target) {
	if (movingShapes.size() > 0) {
		movingShapes[selectedShapeIndex]->moveTo(target);
	}
}