/*
This file servers as an example of how to use Pipe.h file.
It is recommended to use the following code in your project,
in order to read and write information from and to the Backend
*/

#include "Pipe.h"
#include "Game.h"
#include <iostream>
#include <thread>

using std::cout;
using std::endl;
using std::string;


void main()
{
	srand(time_t(NULL));


	Pipe p;
	bool isConnect = p.connect();

	string ans;
	while (!isConnect)
	{
		cout << "cant connect to graphics" << endl;
		cout << "Do you try to connect again or exit? (0-try again, 1-exit)" << endl;
		std::cin >> ans;

		if (ans == "0")
		{
			cout << "trying connect again.." << endl;
			Sleep(5000);
			isConnect = p.connect();
		}
		else
		{
			p.close();
			return;
		}
	}


	char msgToGraphics[1024];
	// msgToGraphics should contain the board string accord the protocol
	// YOUR CODE

	strcpy_s(msgToGraphics, "rnbkqbnrpppppppp################################PPPPPPPPRNBKQBNR0"); // just example...

	p.sendMessageToGraphics(msgToGraphics); // send the board string
	Game game(msgToGraphics);//message to the game
	// get message from graphics
	string msgFromGraphics = p.getMessageFromGraphics();


	while (msgFromGraphics != "quit")//should be if the king is checked
	{
		int answerFromBackend = game.checkEachTurn(msgFromGraphics);
		std::string answer = std::to_string(answerFromBackend);
		strcpy_s(msgToGraphics, answer.c_str()); // msgToGraphics should contain the result of the operation

		// return result to graphics
		p.sendMessageToGraphics(msgToGraphics);
		if (answerFromBackend == CHECK_ON_OPPONENT)
			break;
		// get message from graphics
		msgFromGraphics = p.getMessageFromGraphics();
	}

	p.close();
}

