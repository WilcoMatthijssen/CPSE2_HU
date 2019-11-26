#include <iostream>
#include <SFML/Graphics.hpp>

#include "shapeControl.hpp"
#include <array>

int main(int argc, char* argv[]) {
	uint_fast16_t sizeX = 1800;
	uint_fast16_t sizeY = 1000;
	sf::RenderWindow window{ sf::VideoMode{ sizeX, sizeY }, "SFML window" };
	shapeControl control("configFile.txt");

	std::cout << "Starting factory assignment by Wilco" << std::endl;
	while (window.isOpen()) {
		window.clear();

		
		//vec[0]->draw(window);
		
		if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
			control.selectShape(sf::Mouse::getPosition(window));
			
			
		}
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			control.moveToSelectedShape(sf::Mouse::getPosition(window));
			//std::cout << "move" << std::endl;
		}
		
		control.draw(window);
		
		window.display();
		sf::sleep(sf::milliseconds(20));
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}
	}

	std::cout << "Terminating application\n";
	return 0;
}