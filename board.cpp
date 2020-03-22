#include <iostream>
#include "board.h"
using std::cout;

enum class Colour {
	White,
	Black
};

enum class Piece {
	Pawn,
	Knight,
	Bishop,
	Rook,
	Queen,
	King
};

Board::Board() {
	cout << "Board constructor\n";
	InitBoard();
}

void Board::InitBoard() {
	cout << "Initialising board\n";
	squares[0][0] = { Colour::White, Piece::Rook };
	squares[0][1] = { Colour::White, Piece::Knight };
	squares[0][2] = { Colour::White, Piece::Bishop };
	squares[0][3] = { Colour::White, Piece::Queen };
	squares[0][4] = { Colour::White, Piece::King };
	squares[0][5] = { Colour::White, Piece::Bishop };
	squares[0][6] = { Colour::White, Piece::Knight };
	squares[0][7] = { Colour::White, Piece::Rook };
	for (int i = 0; i < 8; i++) {
		squares[1][i] = { Colour::White, Piece::Pawn };
	}
	squares[7][0] = { Colour::Black, Piece::Rook };
	squares[7][1] = { Colour::Black, Piece::Knight };
	squares[7][2] = { Colour::Black, Piece::Bishop };
	squares[7][3] = { Colour::Black, Piece::Queen };
	squares[7][4] = { Colour::Black, Piece::King };
	squares[7][5] = { Colour::Black, Piece::Bishop };
	squares[7][6] = { Colour::Black, Piece::Knight };
	squares[7][7] = { Colour::Black, Piece::Rook };
	for (int i = 0; i < 8; i++) {
		squares[6][i] = { Colour::White, Piece::Pawn };
	}

}

void Board::Print() {
	std::cout << "Printing board\n";
	cout << "+---------------+\n";
	for (int i = 7; i >= 0; i--) {
		cout << "|";
		for (int j = 0; j < 8; j++) {
			cout << SquareToChar(i, j) << "|";
		}
		cout << "\n";
	}
	cout << "+---------------+";
}

char Board::SquareToChar(int row, int column) {
	char result = ' ';
	switch (squares[row][column].piece) {
	case Piece::Pawn:
		result = 'p';
		break;
	case Piece::Knight:
		result = 'n';
		break;
	case Piece::Bishop:
		result = 'b';
		break;
	case Piece::Rook:
		result = 'r';
		break;
	case Piece::Queen:
		result = 'q';
		break;
	case Piece::King:
		result = 'k';
		break;
	}
	if (squares[row][column].colour == Colour::Black)
		result = toupper(result);
	return result;
}