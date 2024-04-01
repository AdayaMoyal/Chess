#include <iostream>
#include "Piece.h"

#define ENEMY true
#define SAME false

Piece::Piece(int row, int col, int color, char type)
{
	this->_row = row;
	this->_col = col;
	this->_color = color;
	this->_type = type;
}

Piece::~Piece()
{

}

int Piece::getRow()
{
	return this->_row;
}

int Piece::getCol()
{
	return this->_col;
}

int Piece::GetColor()
{
	return this->_color;
}

char Piece::GetType()
{
	return this->_type;
}


void Piece::setRow(int newRow)
{
	this->_row = newRow;
}

void Piece::setCol(int newCol)
{
	this->_col = newCol;
}

void Piece::setColor(int newColor)
{
	this->_color = newColor;
}

void Piece::setType(char newType)
{
	this->_type = newType;
}

bool Piece::checkIfEnemy(Piece& otherPiece)
{
	if ((this->_color == WHITE && otherPiece.GetColor() != WHITE) || (this->_color != WHITE && otherPiece.GetColor() == WHITE))
	{
		return ENEMY;
	}
	return SAME;
}