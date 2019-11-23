#ifndef SHAPECONFIG_HPP
#define SHAPECONFIG_HPP
#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include "moveable.hpp"


//	---SHAPECONTROL---
//	
//
class shapeControl {
private:
	const std::string configFile;
	std::vector<std::string> comments;
	std::vector<circle> circleShapes;
	std::vector<moveable*> movingShapes;
	size_t selectedShapeIndex=0;
	
	void loadShapesFromFile() {
		std::cout << "load" << std::endl;
		//load shapes from file
		//vector emplace_back()
		std::string tekst;
		std::ifstream inFile;
		sf::Vector2f size{ 100,100 };
		sf::Vector2f position{ 100,100 };
		inFile.open(configFile);
		char c;
		while (inFile.get(c)) {
			switch (c) {
			case '<':
				break;
			}
		}
		while (getline(inFile, tekst)) {
			if (tekst == "circle") {
				tekst.erase();
				while (getline(inFile, tekst)) {
					if (tekst == "size") {
						std::cout << "size" << std::endl;
					}
					if (tekst == "position") {
						std::cout << "position" << std::endl;
					}
					if (tekst == "end") {
						std::cout << "end" << std::endl;
						break;
					}
					size += { 10, 10 };

					tekst.erase();
				}
				circleShapes.push_back(circle(size,position));
				std::cout << circleShapes.size() << std::endl;
				movingShapes.push_back(&circleShapes[circleShapes.size()-1]);
			}
			comments.push_back(tekst);
		}
		inFile.close();
		std::cout << std::endl;
		//&circle(sf::Vector2f{ 100,100 }, sf::Vector2f{ 100,100 })
		//circleShapes.push_back(circle(sf::Vector2f{ 100,100 }, sf::Vector2f{ 100,100 }));
		//circleShapes.push_back(circle(sf::Vector2f{ 100,100 }, sf::Vector2f{ 100,100 }));
		//movingShapes.push_back(&circleShapes[0]);
		//movingShapes.push_back(&circleShapes[1]);

		

	}
	void storeShapesToFile() {
		std::cout << "store" << std::endl;
		//store shapes to file
		std::ofstream openFile;
		openFile.open(configFile);
		
		for (auto& comment : comments) {
			std::cout << comment << std::endl;
			openFile << comment<<"\n";
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
		for (size_t i = 0; i < circleShapes.size(); ++i) {
			if (circleShapes[i].contains(target)) {
				circleShapes[selectedShapeIndex].deselect();
				circleShapes[i].select();
				selectedShapeIndex = i;
			}
		}
	}
	void draw(sf::RenderWindow& window) {
		for (auto& shape : circleShapes) {
			shape.draw(window);
		}
	}
	void moveToSelectedShape(const sf::Vector2i target) {
		if (circleShapes.size() > 0) {
			circleShapes[selectedShapeIndex].moveTo(target);
		}
	}
	
};

#endif /* SHAPECONFIG_HPP */