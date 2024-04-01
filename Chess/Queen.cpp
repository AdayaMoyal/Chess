#include <iostream>
#include "Queen.h"
#include "Bishop.h"
#include "Rook.h"


Queen::Queen(int row, int col, int color, char type) : Piece(row, col, color, type) {
}

Queen::~Queen()
{
	Piece::~Piece();
}

Queen* Queen::copy()
{
	return (new Queen(*this));
}

bool Queen::checkIfEmpty(int rowSrc, int rowDst, int colSrc, int colDst, Piece* board[SIZE_OF_ARRAY][SIZE_OF_ARRAY])
{
	Rook helperRook(this->_row, this->_col, this->_color, this->_type);
	Bishop helperBishop(this->_row, this->_col, this->_color, this->_type);
	bool returnFromRook = helperRook.checkIfEmpty(rowSrc, rowDst, colSrc, colDst, board);
	bool returnFromBishop = helperBishop.checkIfEmpty(rowSrc, rowDst, colSrc, colDst, board);
	return (returnFromRook == true || returnFromBishop == true);
}

//return true if the movement is valid
bool Queen::checkMove(int newRow, int newCol, Piece* board[SIZE_OF_ARRAY][SIZE_OF_ARRAY])
{
	Rook helperRook(this->_row, this->_col, this->_color, this->_type);
	Bishop helperBishop(this->_row, this->_col, this->_color, this->_type);
	bool returnFromRook = helperRook.checkMove(newRow, newCol, board);
	bool returnFromBishop = helperBishop.checkMove(newRow, newCol, board);
	return ((returnFromRook == true || returnFromBishop == true)&&checkIfEmpty(this->_row,newRow,this->_col,newCol,board));
}

