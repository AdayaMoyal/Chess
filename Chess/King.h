#pragma once
#include <iostream>
#include "Piece.h"
#include "Board.h"
 
class Board;
class King : public Piece
{
public:
	King(int row, int col, int color, char type);
	~King();
	virtual King* copy();
	virtual bool checkMove(int newRow, int newCol, Piece* board[SIZE_OF_ARRAY][SIZE_OF_ARRAY]);
	virtual bool checkIfEmpty(int rowSrc, int rowDst, int colSrc, int colDst, Piece* board[SIZE_OF_ARRAY][SIZE_OF_ARRAY]);
};
