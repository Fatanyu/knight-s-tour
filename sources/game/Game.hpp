#pragma once

#include "chessboards/Chessboard.hpp"
#include <memory>
#include <iostream>

namespace kaktus
{
    class Game
    {
    public:
        Game() = default;

        ~Game() = default;

        /**
         *
         */
        void startGame();

    protected:
        std::unique_ptr<IChessboard> m_board; //TODO use IChessboard

        static BoardSize giveMeBoardSizes();

        static BoardSize askForBoardSize();
    };
}