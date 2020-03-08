#pragma once

#include <chessboards/IChessboard.hpp>
#include <string>

namespace kaktus
{
    class IKnightsTourAlgorithm
    {
    public:
        virtual ~IKnightsTourAlgorithm() = default;

        virtual std::string getName() = 0;

        virtual bool run() = 0;

        virtual void reset() = 0;
    };
}