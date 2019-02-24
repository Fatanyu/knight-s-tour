#include "../headers/game.hpp"

void Game::startGame()
{
	unsigned int boardSizeWidth = 0;
	unsigned int boardSizeHeight = 0;
	std::cout << "Give me Board sizes\nWidth:";
	std::cin >> boardSizeWidth;
	std::cout << "Height:";
	std::cin >> boardSizeHeight;
	std::cout << "W:" << boardSizeWidth << " H:" << boardSizeHeight << std::endl;
	
	this->m_board = new Board(boardSizeWidth,boardSizeHeight);

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