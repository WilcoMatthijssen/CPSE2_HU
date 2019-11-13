#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include <SFML/Graphics.hpp>
#include "drawable.hpp"

class circle: public drawable{
private:
	sf::Vector2f speed;
public:
	circle(sf::Vector2f size, sf::Vector2f position, sf::Color color, sf::Vector2f speed):
		drawable(size, position, color),
		speed(speed)
		{}

	void draw( sf::RenderWindow & window ) override {
		sf::CircleShape circle;
		circle.setRadius(size.x/2);
		circle.setPosition(position);
		window.draw(circle);
	}
	void overlap(drawable & other){
		sf::RectangleShape tempShape;
		sf::RectangleShape otherShape (	other.size );
		otherShape.setPosition(other.position);
		
		tempShape.setSize (sf::Vector2f{ 75, 10 }	 );
		tempShape.setPosition(sf::Vector2f{ position.x+25, position.y });
		if( tempShape.getGlobalBounds().intersects(	otherShape.getGlobalBounds()) ){
			speed.y*=-1;
			moveBack();
			std::cout<<"1"<<std::endl;
		}

		tempShape.setSize  (sf::Vector2f{ 75, 10 }	 );
		tempShape.setPosition(sf::Vector2f{ position.x+25, position.y+90 });
		if( tempShape.getGlobalBounds().intersects(	otherShape.getGlobalBounds()) ){
			speed.y*=-1;
			std::cout<<"2"<<std::endl;
			moveBack();
		}

		tempShape.setSize  (sf::Vector2f{ 10,75 }	 );
		tempShape.setPosition(sf::Vector2f{ position.x+91, position.y+25 });
		if( tempShape.getGlobalBounds().intersects(otherShape.getGlobalBounds()) ){
			speed.x*=-1;
			moveBack();
			std::cout<<"3"<<std::endl; 
			
		}

		
		tempShape.setSize (sf::Vector2f{ 10,75}	 );
		tempShape.setPosition(sf::Vector2f{ position.x, position.y+25 });
		if( tempShape.getGlobalBounds().intersects(	otherShape.getGlobalBounds()) ){
			speed.x*=-1;
			std::cout<<"4"<<std::endl;
			moveBack();
		}



	
	}

	
	void update(){
		oldPosition=position;
		position += speed;
	}

	
};

#endif /* CIRCLE_HPP */