#include <vector>
#include <string>
#include <map>


/// @brief Class mainly meant for getting statistics from text file contents.
/// @author Wilco Matthijssen
class textFileVector {
private:
	std::vector<char> textFile;
public:

	/// @brief Construct the class by reading the file from filePath to a vector<char>.
	///
	/// @param filePath		path to file
	/// 
	textFileVector(std::string filePath);

	/// @brief	Reads file to vector.
	///
	/// @param	filePath  Name of file to read.
	/// @return	void
	///
	void readFileToVector(std::string filePath);

	/// @brief	Count the amount of '\n' in file.
	///
	/// @return	unsigned int
	///
	const size_t lineCount();

	/// @brief	Apply std::tolower function on file
	///
	/// @return	void
	///
	void toLower();

	/// @brief	Return vector containing all alphabetic characters and their frequency in file
	///
	/// @return	const vector<pair<char, int>>
	///
	const std::vector<std::pair<char, int>> letterFrequency();

	/// @brief	Cout letter frequency in file from high to low.
	///
	/// @return	void
	///
	void coutLetterFrequency();


	/// @brief	Map of all unique words and frequency in file.
	///
	/// @return		const map<string, int> 
	///
	const std::map<std::string, int> wordFrequency();

	/// @brief	Cout the top 10 most frequent words in file
	///
	/// @return	void
	///
	void coutWordFrequency();

	/// @brief	Amount of alpabetic chars in file.
	///
	/// @return	const unsigned int
	///
	const size_t alphabeticCount();

	/// @brief	Amount of chars in file
	///
	/// @return	const size_t	
	///
	const size_t size();
};
