#pragma once

#include "chessboards/Chessboard.hpp"
#include <memory>
#include <iostream>

namespace fatanyu
{
    class Game
    {
    public:
        Game();
        ~Game();

        /**
         *
         */
        void startGame();

    protected:
        Chessboard *m_board; //TODO use IChessboard

        BoardSize giveMeBoardSizes();

        static BoardSize askForBoardSize();
    };
}
