#include <iostream>
#include "Piece.h"
#include "Knight.h"

#define ONE_STEP 1
#define TWO_STEPS 2

Knight::Knight(int row, int col, int color, char type) : Piece(row, col, color, type) {
}

Knight::~Knight()
{
	Piece::~Piece();
}

Knight* Knight::copy()
{
	return (new Knight(*this));
}
 
//return true if movement is valid
bool Knight::checkMove(int newRow, int newCol, Piece* board[SIZE_OF_ARRAY][SIZE_OF_ARRAY])
{
	return ((abs(this->_row - newRow) == TWO_STEPS && (abs(this->_col - newCol) == ONE_STEP) || (abs(this->_row - newRow) == ONE_STEP && abs(this->_col - newCol) == TWO_STEPS)));
}

bool Knight::checkIfEmpty(int rowSrc, int rowDst, int colSrc, int colDst, Piece* board[SIZE_OF_ARRAY][SIZE_OF_ARRAY])
{
	return true;
}
