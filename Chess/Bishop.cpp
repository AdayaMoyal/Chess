#include <iostream>
#include "Bishop.h"

#define ONE_STEP 1

Bishop::Bishop(int row, int col, int color, char type) : Piece(row, col, color, type) {
}

Bishop::~Bishop()
{

}

Bishop* Bishop::copy()
{
	return (new Bishop (*this));
}

//return true if it is emtpy
bool Bishop::checkIfEmpty(int rowSrc, int rowDst, int colSrc, int colDst, Piece* board[SIZE_OF_ARRAY][SIZE_OF_ARRAY])
{
	int addRow = 0;
	int addCol = 0;
	int row = rowSrc;
	int col = colSrc;
	if (rowSrc < rowDst)
		addRow = 1;
	else if (rowSrc > rowDst)
		addRow = -1;
	if (colSrc < colDst)
		addCol = 1;
	else if (colSrc > colDst)
		addCol = -1;
	while (row != rowDst - addRow && col != colDst - addCol)
	{
		row += addRow;
		col += addCol;
		if (board[row][col] != nullptr)
		{
			return false;
		}
	}
	return true;
}

//return true if the movement is valid, false otherwise
bool Bishop::checkMove(int newRow, int newCol, Piece* board[SIZE_OF_ARRAY][SIZE_OF_ARRAY])
{
	int currentRow = this->_row;
	int currentCol = this->_col;
	return ((abs(currentRow - newRow) == abs(currentCol - newCol)) && checkIfEmpty(currentRow, newRow, currentCol, newCol, board));//movement of bishop
}
