#include <iostream>
#include "King.h"

#define ONE_STEP 1
#define SIZE_OF_ARRAY 8
#define CHECKED 1
#define NOT_CHECKED 0

King::King(int row, int col, int color, char type) : Piece(row, col, color, type) {
}

King::~King()
{

}

King* King::copy()
{
	return (new King(*this));
}

bool King::checkMove(int newRow, int newCol, Piece* board[SIZE_OF_ARRAY][SIZE_OF_ARRAY])
{
	if (!(abs(this->_row - newRow) <= ONE_STEP) && (abs(this->_col - newCol) <= ONE_STEP))
	{
		return false;
	}
	else
	{
		return true;
	}
}

bool King::checkIfEmpty(int rowSrc, int rowDst, int colSrc, int colDst, Piece* board[SIZE_OF_ARRAY][SIZE_OF_ARRAY])
{
	return true;
}
