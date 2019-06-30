#pragma once

namespace fatanyu
{
    class IChessboard
    {
    public:
        /**
         * @brief Print chessboard with path to terminal
         */
        virtual void printBoard() = 0;

        /**
         * @brief Reset chessboard (sizes remain)
         */
        virtual void reset() = 0;

        virtual ~IChessboard() = default;
    };
}