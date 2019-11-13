#include <iostream>
#include <functional>
#include <SFML/Graphics.hpp>
#include "drawable.hpp"
#include "circle.hpp"
#include "rectangle.hpp"

// C:\mingw64\bin\g++.exe -g c:\Users\Wilco\Desktop\GITHUB\v2cpse2-examples\03-08-array-of-actions\main.cpp -o c:\Users\Wilco\Desktop\GITHUB\v2cpse2-examples\03-08-array-of-actions\main.exe -IC:/SFML-2.5.1/include -lsfml-system -LC:/SFML-2.5.1/lib -lsfml-graphics -lsfml-window '-I C:/Users/Wilco/Desktop/GITHUB/v2cpse2-examples/01-02-static-ball' ; ./main
class action {
private:
	std::function< bool() > condition;
	std::function< void() > work;
public:
	action(
	   std::function< bool() > condition, 
	   std::function< void() > work
	) : condition( condition ), 
		work( work ) 
	{}

	action(
		sf::Keyboard::Key key,
		std::function< void() > work
	) :
		condition(
			[ key ]()->bool { return sf::Keyboard::isKeyPressed( key ); }
		),
		work(work)
	{}

	action(
		sf::Mouse::Button button,
		std::function< void() > work
	) :
		condition(
			[ button ]()->bool { return sf::Mouse::isButtonPressed( button ); }
		),
		work(work)
	{}

	void operator()(){
		if( condition() ){
			work();
		}
	}
};







int main( int argc, char *argv[] ){
	std::cout << "Starting application 01-05 array of actions\n";

	sf::RenderWindow window{ sf::VideoMode{ 640, 480 }, "SFML window" };

	rectangle leftWall(		sf::Vector2f{ 10, 480 },	sf::Vector2f{ 0,	0 	},		sf::Color::Cyan	);
	rectangle rightWall(	sf::Vector2f{ 10, 480 },	sf::Vector2f{ 630,	0 	},		sf::Color::Magenta	);
	rectangle bottomWall(	sf::Vector2f{ 640, 10 },	sf::Vector2f{ 0,	470	},		sf::Color::Red	);
	rectangle upperWall(	sf::Vector2f{ 640, 10 },	sf::Vector2f{ 0,	0 	},		sf::Color::Blue	);
	rectangle box(	sf::Vector2f{ 100, 100 },	sf::Vector2f{ 300,	200 },		sf::Color::Green	);
	circle ball(	sf::Vector2f{ 100, 100 },	sf::Vector2f{ 100,	100 },		sf::Color::Green	,sf::Vector2f{ 1,	-1 });

	std::array<drawable*, 4> staticShapes={ 
		&leftWall, 
		&rightWall, 
		&bottomWall, 
		&upperWall
	};

	action actions[] = {
		action( sf::Keyboard::Left,  [&](){ box.move( sf::Vector2f( -1.0,  0.0 )); }),
		action( sf::Keyboard::Right, [&](){ box.move( sf::Vector2f( +1.0,  0.0 )); }),
		action( sf::Keyboard::Up,    [&](){ box.move( sf::Vector2f(  0.0, -1.0 )); }),
		action( sf::Keyboard::Down,  [&](){ box.move( sf::Vector2f(  0.0, +1.0 )); }),
		action( sf::Mouse::Left,     [&](){ box.jump( sf::Mouse::getPosition( window )); })
	};

	while (window.isOpen()) {
		for( auto & action : actions ){
			action();
		}
		window.clear();

		//		MAAK KLEINER
		//-----------------------------
		if(box.overlap(ball)){
			box.moveBack();
		}
		box.draw(window);
		ball.update();
		if(ball.overlap(box) ){
			ball.moveBack();
			ball.interact();
		}
		ball.draw(window);
		//-----------------------------

		for( auto & shape : staticShapes){
			if(box.overlap(*shape)){	box.moveBack();	}
			if(ball.overlap(*shape)){	ball.moveBack();	ball.interact(); }
			shape->draw(window);
		}

		window.display();
		sf::sleep( sf::milliseconds( 20 ));
        sf::Event event;		
	    while( window.pollEvent(event) ){
			if( event.type == sf::Event::Closed ){
				window.close();
			}
		}	
	}

	std::cout << "Terminating application\n";
	return 0;
}

