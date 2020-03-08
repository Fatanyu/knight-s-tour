#include <algorithms/WarnsdorffAlgorithm.hpp>
#include "Game.hpp"

namespace kaktus
{
    BoardSize Game::giveMeBoardSizes()
    {
        BoardSize boardSize;
        while (!boardSize.hasValidSize())
        {
            std::cout << TextConstants::dashLine << std::endl;
            std::cout << "Give me Chessboard sizes\n";
            boardSize = Game::askForBoardSize();
        }
        return boardSize;
    }

    void Game::startGame()
    {
        const BoardSize boardSize = Game::giveMeBoardSizes();

        m_board = std::make_unique<Chessboard>(boardSize.getColumn(), boardSize.getRow());

        // In case of fail, just reset and do it again
        // TODO random next step in case of multiple choices
        while (!m_board->run())
        {
            m_board->reset();
        }
//        kaktus::WarnsdorffAlgorithm warnsdorffAlgorithm(m_board);
//        while (!warnsdorffAlgorithm.run())
//        {
//            warnsdorffAlgorithm.reset();
//        }

    }

    BoardSize Game::askForBoardSize()
    {
        BoardSize boardSize;
        boardSize.setColumn();
        boardSize.setRow();
        boardSize.printSize();
        return boardSize;
    }
}