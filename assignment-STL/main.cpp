#include <iostream>
#include "textFileVector.hpp"

using namespace std;

int main() {
	cout << "hello" << endl;
	textFileVector bible("bible.txt");
	cout << "The file contains " << bible.size() << " characters." << endl;
	cout << "The file contains " << bible.alphabeticCount() << " alphabetic characters" << endl;
	bible.coutWordFrequency();
	bible.coutLetterFrequency();
}