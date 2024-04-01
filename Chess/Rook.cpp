#include <iostream>
#include "Piece.h"
#include "Rook.h"

#define STEP 1

Rook::Rook(int row, int col, int color, char type) : Piece(row, col, color, type) {
}

Rook::~Rook()
{
	
}

Rook* Rook::copy()
{
	return (new Rook(*this));
}

//returns true if the rook is empty
bool Rook::checkIfEmpty(int rowSrc, int rowDst, int colSrc, int colDst, Piece* board[SIZE_OF_ARRAY][SIZE_OF_ARRAY])
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
	if (colDst == colSrc)
	{
		while (row != rowDst - addRow)
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
	else if (rowSrc == rowDst)
	{
		while (col != colDst - addCol)
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
}

bool Rook::checkMove(int newRow, int newCol, Piece* board[SIZE_OF_ARRAY][SIZE_OF_ARRAY])
{
	int currentRow = this->_row;
	int currentCol = this->_col;
	return(((this->_row == newRow && this->_col != newCol) || (this->_row != newRow && this->_col == newCol)) && (checkIfEmpty(currentRow,newRow,currentCol,newCol,board)));
}
