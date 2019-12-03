#include <iostream>
#include "textFileVector.hpp"


/// @brief Implementation of textFileVector class
/// @author Wilco Matthijssen
int main() {
	//Create textFileVector object by giving a filename to load into vector
	textFileVector bible("bible.txt");

	//Uses of functions in class.
	std::cout << "The file contains " << bible.size() << " characters." << std::endl;
	std::cout << "The file contains " << bible.alphabeticCount() << " alphabetic characters" << std::endl;
	bible.coutWordFrequency();
	bible.coutLetterFrequency();
}