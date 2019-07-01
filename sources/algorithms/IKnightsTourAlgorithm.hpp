#pragma once

#include <chessboards/IChessboard.hpp>
#include <string>

namespace fatanyu
{
    class IKnightsTourAlgorithm
    {
    public:
        virtual ~IKnightsTourAlgorithm() = default;

        virtual std::string getName() = 0;

        virtual bool run(IChessboard chessboard) = 0;
    };
}