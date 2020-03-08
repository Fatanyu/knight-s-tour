#pragma once

#include <memory>
#include "IKnightsTourAlgorithm.hpp"

namespace kaktus
{
    class WarnsdorffAlgorithm : public IKnightsTourAlgorithm
    {
    public:
        explicit WarnsdorffAlgorithm(const std::unique_ptr<kaktus::IChessboard>& chessboard) : m_chessboard(chessboard)
        {}
        ~WarnsdorffAlgorithm() override = default;

        std::string getName() override;
        bool run() override;

        void reset() override;

    private:
        bool move();
        int m_round = 1;
        const std::unique_ptr<IChessboard>& m_chessboard;
    };
}