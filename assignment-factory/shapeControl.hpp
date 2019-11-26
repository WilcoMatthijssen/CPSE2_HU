#ifndef SHAPECONFIG_HPP
#define SHAPECONFIG_HPP
#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include "moveable.hpp"
#define ever (;;)
//	---SHAPECONTROL---
//	
//
class shapeControl {
private:
	const std::string configFile;
	std::vector<circle> circleShapes;
	std::vector<screenObject*> movingShapes;
	size_t selectedShapeIndex=0;
	
	screenObject *readScreenObject(std::ifstream & input) {
		sf::Vector2f position;
		std::string	 name;
		std::string path;
		float radius;
		sf::Vector2f size;
		uint_fast32_t color;
		input >> position.x >> position.y >> name;
		if (name == "circle") {
			input >> radius >> color;
			std::cout << "create " << name <<" "<< position.x << " " << position.y << " " << radius << " " << color<< std::endl;
			return new circle(radius, position, color);
		}
		else if (name == "rectangle") {
			input >> size.x >> size.y >> color;
			return new rectangle(size, position);
		}
		else if (name == "picture") {
			input >> size.x >> size.y >> path;
			return new picture(size, position, path);
		}
		else if(name == "") {
			throw 10;
			//throw endOfFile();
		}
		else {
			throw 11;
			//throw shapeUnknown(name);
		}
	}


	void loadShapesFromFile() {
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
		//movingShapes.push_back(new rectangle( sf::Vector2f{100, 100}, sf::Vector2f{ 100,100 }));
		inFile.close();
	}

	void storeShapesToFile() {
		std::cout << "store" << std::endl;
		std::ofstream openFile;
		openFile.open(configFile);
		for (auto& shape : movingShapes) {
			openFile << shape<<'/n';

		}
		openFile.close();
	}

	
	
public:
	shapeControl(const std::string configFile): configFile(configFile) {
		loadShapesFromFile();
	}

	~shapeControl() {
		//storeShapesToFile();
	}
	
	void selectShape(const sf::Vector2i target) {
		for (size_t i = 0; i < movingShapes.size(); ++i) {
			if (movingShapes[i]->contains(target)) {
				movingShapes[selectedShapeIndex]->deselect();
				movingShapes[i]->select();
				selectedShapeIndex = i;
			}
		}
	}
	void draw(sf::RenderWindow& window) {
		for (auto& shape : movingShapes) {
			shape->draw(window);
		}
	}
	void moveToSelectedShape(const sf::Vector2i target) {
		if (movingShapes.size() > 0) {
			movingShapes[selectedShapeIndex]->moveTo(target);
		}
	}
	
};



#endif /* SHAPECONFIG_HPP */