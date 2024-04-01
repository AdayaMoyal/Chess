#pragma once
#include <iostream>

#define PROPER_MOVE 0
#define CHECK_ON_OPPONENT 1
#define NO_PIECE_OF_CURRENT_IN_SRC 2
#define PIECE_IN_DST 3
#define CHECK_ON_CURRENT 4
#define INVALID_INDEX 5
#define ILLEGAL_MOVEMENT 6
#define SAME_SRC_AND_DST 7
#define CHECKED 8
#define WHITE 0
#define SIZE_OF_ARRAY 8
#define MIN_PLACE 0
#define MAX_PLACE 7

class Piece
{
protected:
	//Fields
	int _row;
	int _col;
	int _color;
	char _type;
public:
	Piece(int row, int col, int color, char type);
	virtual Piece* copy() = 0;
	~Piece(); //question for Adaya- what should the destructor be?
	int getRow();
	int getCol();
	int GetColor();
	char GetType();
	void setRow(int newRow);
	void setCol(int newCol);
	void setColor(int newColor);
	void setType(char newType);
	virtual bool checkMove(int newRow, int newCol, Piece* board[SIZE_OF_ARRAY][SIZE_OF_ARRAY]) = 0;
	bool checkIfEnemy(Piece& otherPiece);//function return true if it is the enemy- false if it is not the enemy
	virtual bool checkIfEmpty(int rowSrc, int rowDst, int colSrc, int colDst, Piece* board[SIZE_OF_ARRAY][SIZE_OF_ARRAY]) = 0;
};