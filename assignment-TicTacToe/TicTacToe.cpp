#include "TicTacToe.hpp"

#include <vector>
#include <SFML/Graphics.hpp>
#include <array>
#include <iostream>


tictactoe::tictactoe(sf::RenderWindow& window) : pieceSize(window.getSize().x / 3) {
	board.loadFromFile("board.jpg");
	X.loadFromFile("X.png");
	O.loadFromFile("O.png");
}

void tictactoe::draw(sf::RenderWindow& window) {
	sf::RectangleShape piece(sf::Vector2f(pieceSize, pieceSize));
	sf::RectangleShape boardShape(sf::Vector2f(pieceSize * 3, pieceSize * 3));

	switch (winner) {
	case 'X':
		boardShape.setTexture(&X);
		window.draw(boardShape);
		return;
	case 'O':
		boardShape.setTexture(&O);
		window.draw(boardShape);
		return;
	default:
		boardShape.setTexture(&board);
		window.draw(boardShape);
	}

	for (auto& mov : moves) {
		if (mov.player == 'O') {
			piece.setPosition(mov.X * pieceSize, mov.Y * pieceSize);
			piece.setTexture(&O);
			window.draw(piece);
		}
		else {
			piece.setPosition(mov.X * pieceSize, mov.Y * pieceSize);
			piece.setTexture(&X);
			window.draw(piece);
		}
	}
}


void tictactoe::input(sf::RenderWindow& window) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
		reset();
	}
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		makeMove(window);
	}
	if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
		revertMove();
	}
}


void tictactoe::checkForWinner() {
	if (didCharWin('X')) {
		winner = 'X';
	}
	if (didCharWin('O')) {
		winner = 'O';
	}
}


bool tictactoe::didCharWin(char c) {
	int line0{ 0 };
	int line1{ 0 };
	int line2{ 0 };

	int row0{ 0 };
	int row1{ 0 };
	int row2{ 0 };

	int diagonal0{ 0 };
	int diagonal1{ 0 };

	for (const auto& mov : moves) {
		if (mov.player == c) {
			switch (mov.X) {
			case 0: { ++line0; break; }
			case 1: { ++line1; break; }
			case 2: { ++line2; break; }
			}
			switch (mov.Y) {
			case 0: { ++row0; break; }
			case 1: { ++row1; break; }
			case 2: { ++row2; break; }
			}
			if ((mov.X == 0 && mov.Y == 0) ||
				(mov.X == 1 && mov.Y == 1) ||
				(mov.X == 2 && mov.Y == 2)) {
				++diagonal0;
			}
			if ((mov.X == 2 && mov.Y == 0) ||
				(mov.X == 1 && mov.Y == 1) ||
				(mov.X == 0 && mov.Y == 2)) {
				++diagonal1;
			}
		}
	}
	if (line0 == 3 || line1 == 3 || line2 == 3 ||
		row0 == 3 || row1 == 3 || row2 == 3 ||
		diagonal0 == 3 || diagonal1 == 3) {
		return true;
	}
		return false;
}

void tictactoe::reset() {
	moves.clear();
	winner = '0';
}

void tictactoe::revertMove() {
	if (!moves.empty()) {
		if (canRevert) {
			moves.pop_back();
			if (player == 'X') { player = 'O'; }
			else { player = 'X'; }
			canRevert = false;
		}
	}
}

bool tictactoe::isMoveDuplicate(const Move& mov) {
	for (auto& i : moves) {
		if (i.X == mov.X && i.Y == mov.Y) {
			return true;
		}
	}
	return false;
}


bool tictactoe::isMoveAllowed(const Move& mov) {
	if (!isMoveDuplicate(mov) &&
		mov.X <= 2 &&
		mov.X >= 0 &&
		mov.Y <= 2 &&
		mov.Y >= 0) {
		return true;
	}
	return false;
}


void tictactoe::makeMove(sf::RenderWindow& window) {
	Move mov;
	sf::Vector2i mousePos = sf::Mouse::getPosition(window);
	mov.X = mousePos.x / pieceSize;
	mov.Y = mousePos.y / pieceSize;
	mov.player = player;
	if (isMoveAllowed(mov)) {
		moves.push_back(mov);
		if (player == 'X') { player = 'O'; }
		else { player = 'X'; }
		canRevert = true;
	}
}