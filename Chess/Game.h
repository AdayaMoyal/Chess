#pragma once
#include "Piece.h"
#include "Board.h"
#include "Pipe.h"
#include "King.h"

class Board;
class Game
{
private:
	Board* _Board;
	int _turn;
public:
	Game(std::string strBoard);
	~Game();
	int getTurn();
	Board* getBoard();
	void setTurnWhite();
	void setTurnBlack();
	void createMovementPoints(std::string movementFromFrontend, int& srcRow, int& srcCol, int& dstRow, int& dstCol);
	int checkEachTurn(std::string movementFromFrontend);
};
