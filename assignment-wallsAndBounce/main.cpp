#include <iostream>
#include <functional>
#include <SFML/Graphics.hpp>
#include "drawable.hpp"
#include "circle.hpp"
#include "rectangle.hpp"
#include <array>
class action {
private:
	std::function< bool() > condition;
	std::function< void() > work;
public:
	action(
		std::function< bool() > condition,
		std::function< void() > work
	) : condition(condition),
		work(work)
	{}

	action(
		sf::Keyboard::Key key,
		std::function< void() > work
	) :
		condition(
			[key]()->bool { return sf::Keyboard::isKeyPressed(key); }
		),
		work(work)
	{}

	action(
		sf::Mouse::Button button,
		std::function< void() > work
	) :
		condition(
			[button]()->bool { return sf::Mouse::isButtonPressed(button); }
		),
		work(work)
	{}

	action(
		bool b,
		std::function< void() > work
	) :
		condition(
			[b]()->bool { return true; }
		),
		work(work)
	{}

	void operator()() {
		if (condition()) {
			work();
		}
	}
};




int main(int argc, char* argv[]) {
	std::string boxTextureFile = "B.png";
	std::string ballTextureFile = "emoji.png";
	float sizeX = 1000;
	float sizeY = 500;
	float width = 10;
	std::cout << "Starting application 01-05 array of actions\n";

	sf::RenderWindow window{ sf::VideoMode{ unsigned int(sizeX), unsigned int(sizeY) }, "SFML window" };

	sf::Texture textureB;
	textureB.loadFromFile(boxTextureFile);
	moveable_rectangle box(sf::Vector2f{ 100, 100 }, sf::Vector2f{ 300,	200 }, textureB);

	sf::Texture textureEmoji;
	textureEmoji.loadFromFile(ballTextureFile);
	moveable_circle ball(sf::Vector2f{ 100, 100 }, sf::Vector2f{ 200,	100 }, sf::Vector2f{ -1,	-1 }, textureEmoji);

	drawable upperWall{ sf::Vector2f{ width, sizeY }, sf::Vector2f{ 0,	0  }, sf::Color::Cyan };
	drawable lowerWall{ sf::Vector2f{ width, sizeY}, sf::Vector2f{ sizeX-width,0  }, sf::Color::Magenta };
	drawable leftWall{ sf::Vector2f{ sizeX, width }, sf::Vector2f{ 0,	sizeY-width}, sf::Color::Red };
	drawable rightWall{ sf::Vector2f{ sizeX, width }, sf::Vector2f{ 0,	0  }, sf::Color::Blue };

	std::array<drawable*, 6> walls{ {
		&ball,
		&upperWall,
		&lowerWall,
		&leftWall,
		&rightWall,
		&box
	} };

	action actions[] = {
		action(sf::Keyboard::Left,  [&]() { box.move(sf::Vector2f(-1.0,  0.0)); }),
		action(sf::Keyboard::Right, [&]() { box.move(sf::Vector2f(+1.0,  0.0)); }),
		action(sf::Keyboard::Up,    [&]() { box.move(sf::Vector2f(0.0, -1.0)); }),
		action(sf::Keyboard::Down,  [&]() { box.move(sf::Vector2f(0.0, +1.0)); }),
		action(sf::Mouse::Left,     [&]() { box.jump(sf::Mouse::getPosition(window)); })
	
	};

	while (window.isOpen()) {
		for (auto& action : actions) {
			action();
		}
		window.clear();

		ball.update();
		for (auto& shape : walls) {
			if (box.getBounds() != shape->getBounds()
				&& box.intersects(*shape)) {
				box.revert_move();
			}
			if (ball.getBounds() != shape->getBounds()
				&& ball.intersects(*shape)) {
				// ball.revert_move();
			}
			shape->draw(window);
		}






		window.display();
		sf::sleep(sf::milliseconds(2));
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