#pragma once
#include <iostream>
#include "Piece.h"
#include "King.h"
#include "Queen.h"
#include "Pawn.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"

#define SIZE_OF_ARRAY 8
class King;

class Board
{
private:
	//Fields
	Piece* _board[SIZE_OF_ARRAY][SIZE_OF_ARRAY];
	std::string _strBoard;

public:
	Board(std::string strBoard);
	~Board();
	void createBoard();
	void updateStrBoard(int lastIndex, int newIndex);
	Piece* getPiece(int row, int col);
	void movePiecesOnBoard(int lastRow, int lastCol, int newRow, int newCol);
	void deletePiece(int row, int col);
	int checkMoves(int srcRow, int srcCol, int dstRow, int dstCol, int colorSrc);
	int checkOtherCodes(Piece* piece, int srcRow, int srcCol, int newRow, int newCol);
	King* getKing(int color);
	bool isChecked(King* king);
	bool checkColorTurn(Piece* currentPiece, int color);//check if the piece that is moving fits the color of the piece that should currently move
};
