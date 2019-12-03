#ifndef TICTACTOE_HPP
#define TICTACTOE_HPP

#include <vector>
#include <SFML/Graphics.hpp>
#include <array>


/// @brief Struct for storing moves in tic-tac-toe
/// @author Wilco Matthijssen
struct Move {
	int X;
	int Y;
	char player;
};

/// @brief Class for playing tic-tac-toe
/// @author Wilco Matthijssen
class tictactoe {
private:
	std::vector<Move> moves;
	unsigned int pieceSize;
	char winner{ '0' };
	char player{ 'X' };
	bool canRevert{ false };
	sf::Texture X;
	sf::Texture O;
	sf::Texture board;
	
public:
	/// @brief Construct a tic-tac-toe game
	///
	/// @param window	Used for getting size of pieces
	/// 
	tictactoe(sf::RenderWindow& window);


	/// @brief	Draw tictactoe game to a sf::RenderWindow.
	///
	/// @param	window  sf::RenderWindow to draw game on.
	/// @return	void
	///
	void draw(sf::RenderWindow& window);

	/// @brief	Read input and execute corresponding moves.
	///
	/// @param	window  To get mouse position from.
	/// @return	void
	///
	void input(sf::RenderWindow& window);

	/// @brief	Check if somebody won
	///
	/// @return	void
	///
	void checkForWinner();

private:
	/// @brief		If char c won return true.
	///
	/// @param	c	Char to check for in game.
	/// @return	bool
	///
	bool didCharWin(char c);


	/// @brief	Clear moves made and winner to nobody
	///
	/// @return	void
	///
	void reset();

	/// @brief	Reverts last move made if possible
	///
	/// @return	void
	///
	void revertMove();

	/// @brief	Return true if given Move is duplicate.
	///
	/// @param	mov		Move to check if not duplicate.
	/// @return	bool
	///
	bool isMoveDuplicate(const Move& mov);

	/// @brief	Return true if move allowed.
	///
	/// @param	mov		Move to check if allowed.
	/// @return	bool
	///
	bool isMoveAllowed(const Move& mov);

	/// @brief	Get position from mouse and try to make a move in tictactoe game.
	///
	/// @param	window		Window to get mouse position from.
	/// @return	void
	///
	void makeMove(sf::RenderWindow& window);

};

#endif /*TICTACTOE_HPP */