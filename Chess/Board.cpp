#include <iostream>
#include "Board.h"
#include "King.h"
#include "Piece.h"


#define STR_BOARD "rnbkqbnrpppppppp################################PPPPPPPPRNBKQBNR"
#define WHITE_KING 'K'
#define WHITE_QUEEN 'Q'
#define WHITE_ROOK 'R'
#define WHITE_KNIGHT 'N'
#define WHITE_BISHOP 'B'
#define WHITE_PAWN 'P'
#define BLACK_KING 'k'
#define BLACK_QUEEN 'q'
#define BLACK_ROOK 'r'
#define BLACK_KNIGHT 'n'
#define BLACK_BISHOP 'b'
#define BLACK_PAWN 'p'
#define EMPTY '#'
#define LAST_PLACE_SIZE 7
#define BLACK 1
#define PROPER_MOVE 0

Board::Board(std::string strBoard)
{
	this->_strBoard = strBoard;
	createBoard();
}

Board::~Board()
{

}

void Board::createBoard()
{
	std::cout << "create board";
	std::cout << "length: " << this->_strBoard.length() << std::endl;
	char currentChar = ' ';
	int row = 0;
	int col = 0;
	for (int i = 0; i < this->_strBoard.length(); i++)
	{
		currentChar = this->_strBoard[i];
		row = LAST_PLACE_SIZE - i / SIZE_OF_ARRAY;
		col = i % SIZE_OF_ARRAY;
		switch (currentChar)
		{
		case WHITE_KING:
			this->_board[row][col] = new King(row, col, WHITE, WHITE_KING);
			break;
		case BLACK_KING:
			this->_board[row] [col] = new King(row, col, BLACK, BLACK_KING);
			break;
		case WHITE_QUEEN:
			this->_board[row][col] = new Queen(row, col, WHITE, WHITE_QUEEN);
			break;
		case BLACK_QUEEN:
			this->_board[row][col] = new Queen(row, col, BLACK, BLACK_QUEEN);
			break;
		case WHITE_BISHOP:
			this->_board[row][col] = new Bishop(row, col, WHITE, WHITE_BISHOP);
			break;
		case BLACK_BISHOP:
			this->_board[row][col] = new Bishop(row, col, BLACK, BLACK_BISHOP);
			break;
		case WHITE_KNIGHT:
			this->_board[row][col] = new Knight(row, col, WHITE, WHITE_KNIGHT);
			break;
		case BLACK_KNIGHT:
			this->_board[row][col] = new Knight(row, col, BLACK, BLACK_KNIGHT);
			break;
		case WHITE_ROOK:
			this->_board[row][col] = new Rook(row, col, WHITE, WHITE_ROOK);
			break;
		case BLACK_ROOK:
			this->_board[row][col] = new Rook(row, col, BLACK, BLACK_ROOK);
			break;
		case WHITE_PAWN:
			this->_board[row][col] = new Pawn(row, col, WHITE, WHITE_PAWN);
			break;
		case BLACK_PAWN:
			this->_board[row][col] = new Pawn(row, col, BLACK, BLACK_PAWN);
			break;
		case EMPTY:
			this->_board[row][col] = nullptr;
			break;
		}
	}
}

void Board::updateStrBoard(int lastIndex, int newIndex)
{
	this->_strBoard[newIndex] = this->_strBoard[lastIndex];//Changing pieces
	this->_strBoard[lastIndex] = EMPTY;
}

Piece* Board::getPiece(int row, int col)
{
	return this->_board[row][col];
}

void Board::deletePiece(int row, int col)
{
	delete this->_board[row][col];
}

void Board::movePiecesOnBoard(int lastRow, int lastCol, int newRow, int newCol)
{
	int lastIndex = (LAST_PLACE_SIZE - lastRow) * SIZE_OF_ARRAY + lastCol;
	int newIndex = (LAST_PLACE_SIZE - newRow) * SIZE_OF_ARRAY + newCol;
	updateStrBoard(lastIndex, newIndex);//update string
	this->_board[lastRow][lastCol]->setRow(newRow);
	this->_board[lastRow][lastCol]->setCol(newCol);
	if (this->_board[newRow][newCol] != nullptr)
	{
		deletePiece(newRow, newCol);//eating the piece in this place
	}
	this->_board[newRow][newCol] = this->_board[lastRow][lastCol];//move to the new place
	this->_board[lastRow][lastCol] = nullptr;//empty place created
}

King* Board::getKing(int color)
{
	for (int i = 0; i < SIZE_OF_ARRAY; i++)
	{
		for (int j = 0; j < SIZE_OF_ARRAY; j++) 
		{
			if (this->_board[i][j] != nullptr)
			{
				if ((this->_board[i][j]->GetType() == WHITE_KING || this->_board[i][j]->GetType() == BLACK_KING) && this->_board[i][j]->GetColor() == color)
				{
					King* king = new King(this->_board[i][j]->getRow(), this->_board[i][j]->getCol(), this->_board[i][j]->GetColor(), this->_board[i][j]->GetType());
					return king;
				}
			}
		}
	}
}

bool Board::isChecked(King* king)
{
	int row = 0;
	int col = 0;
	Piece* piece = nullptr;
	Piece* currentPieceSrc = nullptr;
	for (int i = 0; i < SIZE_OF_ARRAY; i++)
	{
		for (int j = 0; j < SIZE_OF_ARRAY; j++)
		{
			row = i;//Updating the current row
			col = j;//Updating the current col
			piece = _board[row][col];
			if (piece != nullptr)
			{
				currentPieceSrc = getPiece(row, col);
				currentPieceSrc = currentPieceSrc->copy();
				if (king->checkIfEnemy(*currentPieceSrc) && (currentPieceSrc->checkMove(king->getRow(), king->getCol(), _board) == true) && !(king->getRow() == row && king->getCol() == col))
				{//checking if piece is an enemy, if the piece is able to move to the kings place and if the piece is not the king.
					return true;
				}
			}
		}
	}
	return false;
}


int Board::checkOtherCodes(Piece* piece, int srcRow, int srcCol, int newRow, int newCol)
{ 
	int currentRow = 0;
	int currentCol = 0;
	if (_board[srcRow][srcCol] == nullptr)
	{
		return NO_PIECE_OF_CURRENT_IN_SRC;
	}
	currentRow = piece->getRow();
	currentCol = piece->getCol();
	if (_board[newRow][newCol] != nullptr)
	{
		if ((_board[currentRow][currentCol]->GetColor() == WHITE && _board[newRow][newCol]->GetColor() == WHITE) || (_board[currentRow][currentCol]->GetColor() != WHITE && _board[newRow][newCol]->GetColor() != WHITE))
		{
			return PIECE_IN_DST;
		}
	}
	if (newRow > MAX_PLACE || newRow < MIN_PLACE || newCol > MAX_PLACE || newCol < MIN_PLACE)
	{
		return INVALID_INDEX;
	}
	if (currentRow == newRow && currentCol == newCol)
	{
		return SAME_SRC_AND_DST;
	}
	movePiecesOnBoard(srcRow, srcCol, newRow, newCol);
	King* king = nullptr;
	if (piece->GetColor() == WHITE)
	{
		king = getKing(BLACK);
	}
	else
	{
		king = getKing(WHITE);
	}
	if (isChecked(king))
	{
		return CHECK_ON_OPPONENT;
	}
	king = getKing(piece->GetColor());
	if (isChecked(king))
	{
		return CHECK_ON_CURRENT;
	}
	return PROPER_MOVE;
}

//return true if the piece is in the color it should be, else otherwise
bool Board::checkColorTurn(Piece* currentPiece,int color)//check if the piece that is moving fits the color of the piece that should currently move
{
	return currentPiece->GetColor() == color;
}

int Board::checkMoves(int srcRow, int srcCol, int dstRow, int dstCol,int colorSrc)
{
	int movement_code = ILLEGAL_MOVEMENT;
	bool valid_move = true;
	Piece* currentPieceSrc = getPiece(srcRow, srcCol);
	if (currentPieceSrc != nullptr)
	{
		if (!checkColorTurn(currentPieceSrc, colorSrc))
			return NO_PIECE_OF_CURRENT_IN_SRC;
		valid_move = currentPieceSrc->checkMove(dstRow, dstCol, _board);//return true if valid,false if the movement is invalid
	}
	if (valid_move)
	{
		movement_code = checkOtherCodes(currentPieceSrc, srcRow, srcCol, dstRow, dstCol);
	}
	return movement_code;
}
