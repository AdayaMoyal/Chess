#pragma once
#include <iostream>
#include "Piece.h"
#include "Board.h"
#define SIZE_OF_ARRAY 8

class Board;
class Knight : public Piece
{
public:
	Knight(int row, int col, int color, char type);
	~Knight();
	virtual Knight* copy();
	virtual bool checkMove(int newRow, int newCol, Piece* board[SIZE_OF_ARRAY][SIZE_OF_ARRAY]);
	virtual bool checkIfEmpty(int rowSrc, int rowDst, int colSrc, int colDst, Piece* board[SIZE_OF_ARRAY][SIZE_OF_ARRAY]);
};
