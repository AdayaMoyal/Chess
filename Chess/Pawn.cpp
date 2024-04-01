#include <iostream>
#include "Pawn.h"

#define ONE_STEP 1
#define TWO_STEPS 2

Pawn::Pawn(int row, int col, int color, char type) : Piece(row, col, color, type) {
	this->_firstMove = false;//false if the pawn didnt move yet, true if it did move
}

Pawn::~Pawn()
{
	
}

Pawn* Pawn::copy()
{
	return (new Pawn(*this));
}

//return true if valid
bool Pawn::checkMove(int newRow, int newCol, Piece* board[SIZE_OF_ARRAY][SIZE_OF_ARRAY])
{
	int mul = -1;
	if (board[this->_row][this->_col]->GetColor() == WHITE)
	{
		mul = 1;
	}
	int move = newRow - this->_row;
	if (this->_firstMove == false)
	{
		this->_firstMove = true;
		if (move == TWO_STEPS * mul && this->_col == newCol)
		{
			return true;
		}
		else if (move == ONE_STEP * mul && this->_col == newCol && board[newRow][newCol] == nullptr)
		{
			return true;
		}
		else if (move == ONE_STEP * mul && abs(this->_col - newCol) == ONE_STEP && board[newRow][newCol] != nullptr)
		{
			return true;
		}
		return false;
	}
	if ((move == ONE_STEP * mul && this->_col == newCol && board[newRow][newCol] == nullptr) && checkIfEmpty(this->_row, newRow, this->_col, newCol, board))
	{
		return true;
	}
	else if (move == ONE_STEP * mul && abs(this->_col - newCol) == ONE_STEP && board[newRow][newCol] != nullptr)
	{
		return true;
	}
	return false;
}

bool Pawn::checkIfEmpty(int rowSrc, int rowDst, int colSrc, int colDst, Piece* board[SIZE_OF_ARRAY][SIZE_OF_ARRAY])
{
	if (rowDst == rowSrc + TWO_STEPS)
	{
		if (board[rowSrc + ONE_STEP][colDst] != nullptr)
		{
			return false;
		}
	}
	return true;
}
