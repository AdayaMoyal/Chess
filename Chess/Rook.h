#pragma once
#include "Piece.h"
#include "Board.h"

class Rook : public Piece
{
public:
	Rook(int row, int col, int color, char type);
	~Rook();
	virtual Rook* copy();
	virtual bool checkMove(int newRow, int newCol, Piece* board[SIZE_OF_ARRAY][SIZE_OF_ARRAY]);
	virtual bool checkIfEmpty(int rowSrc, int rowDst, int colSrc, int colDst, Piece* board[SIZE_OF_ARRAY][SIZE_OF_ARRAY]);
};
