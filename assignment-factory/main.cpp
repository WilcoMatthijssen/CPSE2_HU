#include <iostream>
#include <SFML/Graphics.hpp>
#include "drawable.hpp"
#include "moveable.hpp"
#include "shapeControl.hpp"
#include <array>

int main(int argc, char* argv[]) {
	uint_fast16_t sizeX = 500;
	uint_fast16_t sizeY = 500;
	sf::RenderWindow window{ sf::VideoMode{ sizeX, sizeY }, "SFML window" };
	shapeControl config("configFile.txt");

	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	
	std::cout << "Starting factory assignment by Wilco" << std::endl;
	while (window.isOpen()) {
		window.clear();

		config.moveToSelectedShape(sf::Mouse::getPosition(window));
		config.draw(window);
		config.selectShape(0);

	
		window.draw(shape);


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