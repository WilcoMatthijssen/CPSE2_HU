#include <fstream>
#include <vector>
#include <algorithm>
#include <map>
#include <iterator>
#include <array>
using namespace std;
/// @brief Class mainly meant for getting statistics from text file contents.
/// @author Wilco Matthijssen
class textFileVector {
private:
	vector<char> textFile;
public:
	/// @brief Construct the class by reading the file from filePath to a vector<char>.
	///
	/// @param filePath		path to file
	/// 
	textFileVector(string filePath) {
		readFileToVector(filePath);
	}

	/// @brief	Reads file to vector.
	///
	/// @param	filePath  Name of file to read.
	/// @return	void
	///
	void readFileToVector(string filePath) {
		ifstream file(filePath);
		if (!file.eof() && !file.fail()) {
			file.seekg(0, ios_base::end);
			streampos fileSize = file.tellg();
			textFile.resize(fileSize);

			file.seekg(0, ios_base::beg);
			file.read(&textFile[0], fileSize);
		}
		file.close();
	}

	/// @brief	Count the amount of '\n' in file.
	///
	/// @return	unsigned int
	///
	unsigned int lineCount() {
		return count(textFile.begin(), textFile.end(), '\n');
	}

	/// @brief	Apply std::tolower function on file
	///
	/// @return	void
	///
	void toLower() {
		for (auto& c : textFile) {
			c = tolower(c);
		}
	}

	/// @brief	Return vector containing all alphabetic characters and their frequency in file
	///
	/// @return	const vector<pair<char, int>>
	///
	const vector<pair<char, int>> letterCount() {
		vector<pair<char, int>> alphabeticVector;
		unsigned int n;
		for (char c = 'a'; c <= 'z'; ++c) {
			n =count(textFile.begin(), textFile.end(), c);
			alphabeticVector.push_back(pair<char,int>(c,n));
		}
		return alphabeticVector;
	}

	/// @brief	Cout letter frequency in file from high to low.
	///
	/// @return	void
	///
	void coutLetterFrequency() {
		toLower();
		vector<pair<char, int>> alphaPairs = letterCount();
		sort(alphaPairs.begin(), alphaPairs.end(), [](const auto& lhs, const auto& rhs)-> bool
			{
				return lhs.second > rhs.second;
			});
		cout << "Frequency of alphabetic characters in file." << endl;
		for (auto& c : alphaPairs) {
			cout <<c.second<<'\t'<< c.first<< endl;
		}
	}


	/// @brief	Map of all unique words and frequency in file.
	///
	/// @return		const map<string, int> 
	///
	const map<string, int> wordMap() {
		map<string, int> Map;
		string word{ "" };
		for (const char& c : textFile) {
			if (isalpha(c)) {
				word += c;
			}
			else if (word.length() > 0) {
				Map[word]++;
				
				word = "";
				
			}
		}
		return Map;
	}

	/// @brief	Cout the top 10 most frequent words in file
	///
	/// @return	void
	///
	void coutWordFrequency() {
		toLower();
		map<string, int> wordPairs = wordMap();
		pair<string, int> comparePair;
		cout << "The 10 most frequent words in file." << endl;
		for (uint_fast8_t i = 0; i < 10; ++i) {
			comparePair = { "nothing", 0 };
			for (auto& c : wordPairs) {
				if (comparePair.second <= c.second) {
					comparePair = c;
					
				}
			}
			wordPairs.erase(comparePair.first);
			cout << comparePair.first << "\t" << comparePair.second << endl;
			
		}
	}

	/// @brief	Amount of alpabetic chars in file.
	///
	/// @return	const unsigned int
	///
	const unsigned int alphabeticCount() {
		return count_if(textFile.begin(), textFile.end(), [](const char c) {return isalpha(c); });
	}

	/// @brief	Amount of chars in file
	///
	/// @return	const size_t	
	///
	const size_t size() {
		return textFile.size();
	}
};
