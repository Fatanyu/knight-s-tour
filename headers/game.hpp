#pragma once 

#include "board.hpp"
#include <memory>

class Game
{
protected:
	Board *m_board;
public:
	/**
	 *
	 */
	void startGame();
	Game();
	~Game();
};