#ifndef DRAWABLE_HPP
#define DRAWABLE_HPP
#include <SFML/Graphics.hpp>

class drawable{
protected:
public:
	sf::Vector2f position;
	sf::Vector2f size;
	sf::Color color;
	sf::Vector2f oldPosition;

	drawable(sf::Vector2f size, sf::Vector2f position, sf::Color color):
	position(position),
	size(size),
	color(color)
	{}

	bool overlap(drawable & other){
		sf::RectangleShape tempShape (	size );
		tempShape.setPosition(position);
		sf::RectangleShape otherShape (	other.size );
		otherShape.setPosition(other.position);
		bool result =tempShape.getGlobalBounds().intersects(	otherShape.getGlobalBounds()	);
		return result;
	}

	void move( sf::Vector2f delta ){
		oldPosition=position;
		position += delta;
	}

	void jump( sf::Vector2f target ){
		oldPosition=position;
		position = target;
	}

	void jump( sf::Vector2i target ){
	jump( sf::Vector2f( 
		static_cast< float >( target.x-(size.x/2) ), 
		static_cast< float >( target.y-(size.x/2) )
		));
	}

	void moveBack(){
		position=oldPosition;
	}
	
	virtual void draw(sf::RenderWindow & window ) =0;
};


#endif /* DRAWABLE_HPP */