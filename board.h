#pragma once

enum class Colour;

enum class Piece;

struct Square {
	Colour colour;
	Piece piece;
};

class Board {
public:
	Board();
	void Print();
private:
	void InitBoard();
	Square squares [8][8];
	char SquareToChar(int row, int column);
};