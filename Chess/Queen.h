#pragma once
#include <iostream>
#include "Piece.h"
#include "Board.h"

class Board;
class Queen : public Piece
{
public:
	Queen(int row, int col, int color, char type);
	~Queen();
	virtual Queen* copy();
	virtual bool checkMove(int newRow, int newCol, Piece* board[SIZE_OF_ARRAY][SIZE_OF_ARRAY]);
	virtual bool checkIfEmpty(int rowSrc, int rowDst, int colSrc, int colDst, Piece* board[SIZE_OF_ARRAY][SIZE_OF_ARRAY]);
};
