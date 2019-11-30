#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <array>
#include <bitset>
class Move {
public:
	int X;
	int Y;
	char player;
};
using namespace std;

class tictactoe {
private: //ALL
	std::vector<Move> moves;
	unsigned int pieceSize;
	char winner{ '0' };
public:
	tictactoe(sf::RenderWindow& window): pieceSize(window.getSize().x/3) { }


	void draw(sf::RenderWindow& window) {
		sf::RectangleShape piece(sf::Vector2f(pieceSize, pieceSize));
		sf::Texture X;
		X.loadFromFile("X.png");
		sf::Texture O;
		O.loadFromFile("O.png");
		if (winner == 'X') {
			piece.setSize(sf::Vector2f(pieceSize *3, pieceSize*3));
			piece.setTexture(&X);
			window.draw(piece);
			return;
		}
		if (winner == 'O') {
			piece.setSize(sf::Vector2f(pieceSize * 3, pieceSize * 3));
			piece.setTexture(&O);
			window.draw(piece);
			return;
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
	bool didCharWin(char c) {
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
		if (line0 == 3	|| line1 == 3	|| line2 == 3	||
			row0 == 3	|| row1 == 3	|| row2 == 3	||
			diagonal0 == 3 || diagonal1 ==3) {
			return true;
		}
		
		return false;
	}
	void checkForWinner() {
		if (didCharWin('X')) {
			winner = 'X';
		}
		if (didCharWin('O')) {
			winner = 'O';
		}

	}


private: //input funcions
	char player{ 'X' };
	bool canRevert{ false };
	void reset() {
		moves.clear();
		winner = '0';
	}
	void revertMove() {
		if (!moves.empty()) {
			if (canRevert){
				moves.pop_back();
				if (player == 'X') { player = 'O'; }
				else { player = 'X'; }
				canRevert = false;
			}
		}
	}
	bool isMoveDuplicate(const Move & mov) {
		for (auto& i : moves) {
			if (i.X == mov.X && i.Y == mov.Y) {
				return true;
			}
		}
		return false;
	}
	bool isMoveAllowed(const Move&  mov) {
		if (!isMoveDuplicate(mov) &&
			mov.X <= 2 &&
			mov.X >= 0 &&
			mov.Y <= 2 &&
			mov.Y >= 0) {
			return true;
		}
		return false;
	}
	void makeMove(sf::RenderWindow& window) {
		Move mov;
		sf::Vector2i mousePos = sf::Mouse::getPosition(window);
		mov.X = mousePos.x / pieceSize;
		mov.Y = mousePos.y / pieceSize;
		mov.player=player;
		if (isMoveAllowed(mov)) {
			moves.push_back(mov);
			if (player == 'X') { player = 'O'; }
			else{ player = 'X'; }
			canRevert = true;
		}
	}
public:
	void input(sf::RenderWindow& window) {
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

	
};
int main() {
	sf::RenderWindow window{ sf::VideoMode{ 750, 750}, "SFML window" };
	tictactoe TTT(window);
	while (window.isOpen()) {
		window.clear(sf::Color::White);
		TTT.input(window);
		TTT.draw(window);
		TTT.checkForWinner();
		window.display();
		sf::sleep(sf::milliseconds(20));
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}
	}
}