#pragma once

#include "Coordinates.hpp"

#include <set>

namespace fatanyu
{
    /**
     *
     */
    class IChessboard
    {
    public:
        /**
         *
         * @param coordinates
         * @return
         */
        virtual bool placeFigure(const Coordinates &coordinates) = 0;
        /**
         *
         * @param coordinates
         * @return
         */
        virtual bool removeFigure(const Coordinates &coordinates) = 0;
        virtual std::set<Coordinates> neighbours(const Coordinates &coordinates) = 0;
        /**
         * @brief Print chessboard to terminal
         */
        virtual void print() = 0;

        /**
         * @brief Reset chessboard (sizes remain)
         */
        virtual void reset() = 0;

        virtual ~IChessboard() = default;
    };
}