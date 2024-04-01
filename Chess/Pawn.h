#pragma once
#include <iostream>
#include "Piece.h"
#include "Board.h"

class Board;
class Pawn : public Piece
{
private:
	bool _firstMove;
public:
	Pawn(int row, int col, int color, char type);
	~Pawn();
	virtual Pawn* copy();
	virtual bool checkMove(int newRow, int newCol, Piece* board[SIZE_OF_ARRAY][SIZE_OF_ARRAY]);
	virtual bool checkIfEmpty(int rowSrc, int rowDst, int colSrc, int colDst, Piece* board[SIZE_OF_ARRAY][SIZE_OF_ARRAY]);
};
