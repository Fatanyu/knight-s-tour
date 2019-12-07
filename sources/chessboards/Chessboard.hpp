#pragma once

#include "BoardSize.hpp"
#include "IChessboard.hpp"

#include <vector>
#include <iostream>
#include <cstdlib>

namespace fatanyu
{
    /**
     * Represents chessboard. It has no column/row validation => validation is via BoardSize::hasValidSize()
     */
    class Chessboard : public IChessboard
    {
    public:

        /**
         * Basic constructor
         * @param sizeWidth Size of chessboard's row defined as integer (originally letters)
         * @param sizeHeight Size of chessboard's column defined as integer (originally numbers)
         */
        Chessboard(int sizeWidth, int sizeHeight);

        /**
         * Basic constructor
         * @param boardSize Class containing board sizes
         */
        Chessboard(BoardSize boardSize);

        /**
         * Print chessboard with path to terminal
         * TODO - fix spacing dynamically
         */
        void print() override;

        /**
         * Find path by warnsdorff algorithms
         * @return True when path has been found
         */
        bool warnsdorff();

        /**
         * Reset chessboard (sizes remain)
         */
        void reset() override;
    protected:
        /**
         * 2D matrix as chessboard
         */
        std::vector<std::vector<int>> m_board;

        /**
         * This is position where Knight stands
         */
        Coordinates m_currentPosition;

        /**
         * This number represents moves count. Value can not be higher than chessboard.row * chessboard.column, exact match means solution.
         */
        int m_round;

        /**
         * Set new Knight's position
         * @param newPosition New Knight's position
         * @return True on successful move
         */
        bool setPosition(Coordinates newPosition);

        /**
         * Chessboard initialization. Create matrix and sets every position to zero
         * TODO checks
         * @param sizeWidth New Chessboard row
         * @param sizeHeight New Cheesboard column
         */
        void initBoard(int sizeWidth, int sizeHeight);

        /**
         * Simple getter
         * @return Width size of the board. Returns zero when row is zero
         */
        int getWidth();

        /**
         * Simple getter
         * @return Height size of the chessboard
         */
        int getHeight();

        /**
         * Sets random location of the Knight
         */
        void initPosition();

        /**
         * Check if position is inside chessboard
         * @return True when position is inside chessboard
         */
        bool positionExists(int moveWithWidth, int moveWithHeight);

        /**
         * Checks if potencial position on chessboard is empty (is zero)
         * @param moveWithWidth Number which will be added to current position row
         * @param moveWithHeight Number which will be added to current position column
         */
        bool isEmpty(int newWidth, int newHeight);

        /**
         * Move Knight to the new position.
         * New position must have the least count of the neighbours.
         * When multiple positions have same neighbours count then first (TODO random) neighbour will be new position.
         * @return True when move has been done.
         */
        bool move();

        /**
         * Check if move can be done
         * @return True when new position exists (move can be done)
         */
        bool canMove();

        /**
         * Reset number generator
         */
        void initRand();

        /**
         * Count neighbours for potencial location
         * @param moveWithWidth Number which will be added to current position row
         * @param moveWithHeight Number which will be added to current position column
         * @return Final count of neighbours. Range of values is <0-8>
         */
        int countNeighbours(int moveWithWidth, int moveWithHeight);

        /**
         * Check if potencial position has neighbour
         * @param moveWithWidth Number which will be added to potencial position row
         * @param moveWithHeight Number which will be added to potencial position column
         * @return True when potencial position has neighbour
         */
        bool neighbourExists(int moveWithWidth, int moveWithHeight, Coordinates potentialPosition);

        /**
         * Simple getter
         * @return Current position
         */
        Coordinates getPosition();

        /**
         * Check if new position is within chessboard range
         * @param moveWithWidth Number which will be added to current position row
         * @param moveWithHeight Number which will be added to current position column
         * @return True when new row or new column is negative
         */
        bool isPotentialPositionNegative(int moveWithWidth, int moveWithHeight);

        /**
         * Check if new position is within chessboard range
         * @param moveWithWidth Number which will be added to current position row
         * @param moveWithHeight Number which will be added to current position column
         * @return True when new row or new column is greater then max sizes of chessboard
         */
        bool isPotencialPositionGreaterThanSize(int moveWithWidth, int moveWithHeight);

        /**
         * Check if new neighbour position is within chessboard range
         * @param moveWithWidth Number which will be added to potencial position row
         * @param moveWithHeight Number which will be added to potencial position column
         * @return True when new row or new column is negative
         */
        bool isNeighbourPositionNegative(int moveWithWidth, int moveWithHeight, Coordinates potentialPosition);

        /**
         * Check if new neighbour position is within chessboard range
         * @param moveWithWidth Number which will be added to potencial position row
         * @param moveWithHeight Number which will be added to potencial position column
         * @return True when new row or new column is greater then max sizes of chessboard
         */
        bool isNeighbourPositionGreaterThanSize(int moveWithWidth, int moveWithHeight, Coordinates potentialPosition);
    };
}
