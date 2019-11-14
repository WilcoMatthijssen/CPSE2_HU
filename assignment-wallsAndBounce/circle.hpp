#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include <SFML/Graphics.hpp>
#include "drawable.hpp"

class circle: public drawable{
private:
	sf::Vector2f speed;
	sf::Image emoji;
public:
	circle(sf::Vector2f size, sf::Vector2f position, sf::Color color, sf::Vector2f speed):
		drawable(size, position, color),
		speed(speed)
		{//emoji.loadFromMemory("C:/Users/Wilco_Laptop/Desktop/v2cpse2-examples/03-08-array-of-actions/emoji.png",22000);
		}

	void draw( sf::RenderWindow & window ) override {
		sf::CircleShape circle;
		circle.setRadius(size.x/2);
		circle.setPosition(position);
		sf::Texture texture;
		if(!texture.loadFromFile("C:/Users/Wilco_Laptop/Desktop/v2cpse2-examples/03-08-array-of-actions/emoji.png")){
			std::cout<<"failed"<<std::endl;
		}
		circle.setTexture(&texture);
		window.draw(circle);
	}
	bool overlap(drawable & other){
		bool result=false;
		sf::RectangleShape tempShape;
		sf::RectangleShape otherShape (	other.size );
		otherShape.setPosition(other.position);
		
		tempShape.setSize (sf::Vector2f{ 90, 100 }	 );
		tempShape.setPosition(sf::Vector2f{ position.x+10, position.y });
		if( tempShape.getGlobalBounds().intersects(	otherShape.getGlobalBounds()) ){
			speed.y*=-1;
			result=true;
			moveBack();
		}

		
		tempShape.setSize (sf::Vector2f{ 105,75}	 );
		tempShape.setPosition(sf::Vector2f{ position.x, position.y+25 });
		if( tempShape.getGlobalBounds().intersects(	otherShape.getGlobalBounds()) ){
			speed.x*=-1;
			result=true;
			moveBack();
		}
		return result;



	
	}

	
	void update(){
		oldPosition=position;
		position += speed;
	}

	
};

#endif /* CIRCLE_HPP */