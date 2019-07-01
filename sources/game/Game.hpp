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
        std::shared_ptr<Chessboard> m_board; //TODO use IChessboard

        static BoardSize giveMeBoardSizes();

        static BoardSize askForBoardSize();
    };
}
