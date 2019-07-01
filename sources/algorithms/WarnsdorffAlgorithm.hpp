#pragma once

#include "IKnightsTourAlgorithm.hpp"

namespace fatanyu
{
    class WarnsdorffAlgorithm : public IKnightsTourAlgorithm
    {
    public:
        WarnsdorffAlgorithm() = default;
        ~WarnsdorffAlgorithm() override = default;

        std::string getName() override;
        bool run(IChessboard chessboard) override;
    private:

    };
}