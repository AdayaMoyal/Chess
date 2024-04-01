#include <iostream>
#include "Game.h"
#include "Board.h"
#include "Piece.h"

#define WHITE_TURN 0
#define BLACK_TURN 1
#define A_IN_ASCII 97
#define ONE_IN_ASCII 49
#define PLACE_OF_SRC_ROW 1
#define PLACE_OF_SRC_COL 0
#define PLACE_OF_DST_ROW 3
#define PLACE_OF_DST_COL 2

Game::Game(std::string strBoard)
{
	std::cout << "called Game function initilazer" << std::endl;
	this->_Board = new Board(strBoard);
	this->_turn = WHITE_TURN; //White starts
}

Game::~Game()
{

}

int Game::getTurn()
{
	return this->_turn;
}

Board* Game::getBoard()
{
	return this->_Board;
}

void Game::setTurnWhite()
{
	this->_turn = WHITE_TURN;
}

void Game::setTurnBlack()
{
	this->_turn = BLACK_TURN;
}

void Game::createMovementPoints(std::string movementFromFrontend, int& srcRow, int& srcCol, int& dstRow, int& dstCol)
{
	srcRow = int(movementFromFrontend[PLACE_OF_SRC_ROW]) - ONE_IN_ASCII;
	srcCol = int(movementFromFrontend[PLACE_OF_SRC_COL]) - A_IN_ASCII;
	dstRow = int(movementFromFrontend[PLACE_OF_DST_ROW]) - ONE_IN_ASCII;
	dstCol = int(movementFromFrontend[PLACE_OF_DST_COL]) - A_IN_ASCII;
}



int Game::checkEachTurn(std::string movementFromFrontend)
{
	int srcRow = 0;
	int srcCol = 0;
	int dstRow = 0;
	int dstCol = 0;
	createMovementPoints(movementFromFrontend, srcRow, srcCol, dstRow, dstCol);
	int check_move_answer =  _Board->checkMoves(srcRow, srcCol, dstRow, dstCol,this->_turn);
	if (check_move_answer == PROPER_MOVE)
	{
		if (this->_turn == WHITE_TURN)
			this->_turn = BLACK_TURN;
		else
			this->_turn = WHITE_TURN;
	}
	return check_move_answer;
}
