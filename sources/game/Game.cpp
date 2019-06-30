#include "Game.hpp"

namespace fatanyu
{
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
            std::cout << "Give me Chessboard sizes\n";
            boardSize = this->askForBoardSize();
        }
        return boardSize;
    }

    void Game::startGame()
    {
        BoardSize boardSize = this->giveMeBoardSizes();

        this->m_board = new Chessboard(boardSize.getWidth(), boardSize.getHeight());

        // In case of fail, just reset and do it again
        // TODO random next step in case of multiple choices
        while (!m_board->warnsdorff())
        {
            m_board->reset();
        }

    }

    BoardSize Game::askForBoardSize()
    {
        BoardSize boardSize;
        boardSize.setWidth();
        boardSize.setHeight();
        boardSize.printSize();
        return boardSize;
    }
}