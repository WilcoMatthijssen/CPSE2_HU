#include <SFML/Graphics.hpp>
#include "TicTacToe.hpp"

int main() {
	sf::RenderWindow window{ sf::VideoMode{ 750, 750}, "SFML window" };
	tictactoe TTT(window);
	while (window.isOpen()) {
		window.clear(sf::Color::White);
		TTT.input(window);
		TTT.draw(window);
		TTT.checkForWinner();
		window.display();
		sf::sleep(sf::milliseconds(20));
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}
	}
}