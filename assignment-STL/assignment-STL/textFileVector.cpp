#include "textFileVector.hpp"
#include <iterator>
#include <algorithm>
#include <iostream>
#include <fstream>

textFileVector::textFileVector(std::string filePath) {
	readFileToVector(filePath);
}


void textFileVector::readFileToVector(std::string filePath) {
	std::ifstream file(filePath);
	if (!file.eof() && !file.fail()) {   //check if file not empty or failed to open
		file.seekg(0, std::ios_base::end); //set "cursor" at the end of file
		std::streampos fileSize = file.tellg(); //get the position of "cursor" in file
		textFile.resize(fileSize);		//resize vector to size of file

		file.seekg(0, std::ios_base::beg); //set "cursor"to begin of file
		file.read(&textFile[0], fileSize); //read file to vector
	}
	file.close();
}


const size_t textFileVector::lineCount() {
	return std::count(textFile.begin(), textFile.end(), '\n');
}


void textFileVector::toLower() {
	for (auto& c : textFile) {
		c = tolower(c);
	}
}


const std::vector<std::pair<char, int>> textFileVector::letterFrequency() {
	std::vector<std::pair<char, int>> alphaVector;
	size_t n;
	for (char c = 'a'; c <= 'z'; ++c) {
		n = std::count(textFile.begin(), textFile.end(), c);
		alphaVector.push_back(std::pair<char, int>(c, n));
	}
	return alphaVector;
}


void textFileVector::coutLetterFrequency() {
	toLower();
	std::vector<std::pair<char, int>> alphaPairs = letterFrequency();
	std::sort(alphaPairs.begin(), alphaPairs.end(), [](const auto& lhs, const auto& rhs)-> bool
		{
			return lhs.second > rhs.second;
		});
	std::cout << "Frequency of alphabetic characters in file." << std::endl;
	for (auto& c : alphaPairs) {
		std::cout << c.second << '\t' << c.first << std::endl;
	}
}



const std::map<std::string, int> textFileVector::wordFrequency() {
	std::map<std::string, int> Map;
	std::string word{ "" };
	for (const char& c : textFile) {
		if (isalpha(c)) {
			word += c;
		}
		else if (word.length() > 0) {
			//https://en.cppreference.com/w/cpp/language/value_initialization
			++Map[word];
			word = "";

		}
	}
	return Map;
}


void textFileVector::coutWordFrequency() {
	toLower();
	std::map<std::string, int> wordPairs = wordFrequency();
	std::pair<std::string, int> comparePair;
	std::cout << "The 10 most frequent words in file." << std::endl;
	for (uint_fast8_t i = 0; i < 10; ++i) {
		comparePair = { "nothing", 0 };
		for (auto& c : wordPairs) {
			if (comparePair.second <= c.second) {
				comparePair = c;

			}
		}
		wordPairs.erase(comparePair.first);
		std::cout << comparePair.first << "\t" << comparePair.second << std::endl;

	}
}

const size_t textFileVector::alphabeticCount() {
	return count_if(textFile.begin(), textFile.end(), [](const char c) {return isalpha(c); });
}


const size_t textFileVector::size() {
	return textFile.size();
}