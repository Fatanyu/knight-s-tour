#include "Game.hpp"

void Game::startGame()
{
	BoardSize boardSize = this->giveMeBoardSizes();
	
	this->m_board = new Board(boardSize.getWidth(), boardSize.getHeight());

	// In case of fail, just reset and do it again
	// TODO random next step in case of multiple choices
	while(!m_board->warnsdorff()) m_board->reset();
	
	//board->printBoard();
	return;
}

Game::Game()
{
	this->m_board = nullptr;
}

Game::~Game()
{
	delete this->m_board;
}

BoardSize Game::giveMeBoardSizes()
{
	BoardSize boardSize;
	while (!boardSize.hasValidSize())
	{
		std::cout << TextConstants::dashLine << std::endl;
		std::cout << "Give me Board sizes\n";
		boardSize = this->askForBoardSize();
	}
	return boardSize;
}

BoardSize Game::askForBoardSize()
{
	BoardSize boardSize;
	boardSize.setWidth();
	boardSize.setHeight();
	boardSize.printSize();
	return boardSize;
}