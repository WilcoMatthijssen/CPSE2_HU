# CPSE2_HU
assingments make for the subject CPSE_HU Hogeschool Utrecht

![](https://upload.wikimedia.org/wikipedia/commons/1/18/ISO_C%2B%2B_Logo.svg)


## [STL](https://github.com/WilcoMatthijssen/CPSE2_HU/tree/master/assignment-STL)
Analyze a .txt file using the standard library of cpp.
```cpp
// Cout what this assignment is about.
std::string message = "Standard library";
std::cout<< message << std::endl;
``` 
* * * *


## [TicTacToe](https://github.com/WilcoMatthijssen/CPSE2_HU/tree/master/assignment-TicTacToe)
Create a tic tac toe game using the [command pattern](https://en.wikipedia.org/wiki/Command_pattern).
```cpp
// Single piece containing the location it's placed and who placed it.
struct piece {
	uint_fast8_t X;
	uint_fast8_t Y;
	char player;
};
// contains all pieces placed on the tictactoe board.
std::vector<piece> pieces
```
* * * *

## [Factory](https://github.com/WilcoMatthijssen/CPSE2_HU/tree/master/assignment-factory)
Create different types of shapes using the [factory pattern](https://en.wikipedia.org/wiki/Factory_method_pattern) and read/store them in a json file.
```cpp
// An example of how a function with a factory pattern can look like.
std::shared_ptr<shape> drawables::factory(types & type){
    switch(type){
        // Create and return a shared_ptr of a circle shape.
        case types::CIRCLE: {
            return std::make_shared<circleShape>;
        }

        // Create and return a shared_ptr of a square shape.
        case types::SQUARE:{
            return std::make_shared<squareShape>;
        }

        // Create and return a shared_ptr of the base class as default
        default:{
            return std::make_shared<shape>;
        }
            
    }
}
```
* * * *

## [WallsAndBounce](https://github.com/WilcoMatthijssen/CPSE2_HU/tree/master/assignment-wallsAndBounce)
Create a simple simulation of a ball moving between 4 walls and a square that you an move yourself.
```cpp
// An example to show what is done in this assignment
int main(){
    //Loop this until the window is closed
    while(window.isOpen()){

        //Update ball 
        ball.update();
        
        //move square to mouse position
        square.setPosition(mousePosition);

        //Draw shapes to window
        window.draw(ball);
        window.draw(square);

        // close the window if the close button is pressed.
        if(closeButton == pressed){
            window.close();
        }
    }
    return EXIT_SUCCES;
}

```
* * * *





## Built with
* [SFML](https://github.com/SFML/SFML) -Used for 2D graphics.
* [JSONCPP](https://github.com/open-source-parsers/jsoncpp) -JSON parser used.
