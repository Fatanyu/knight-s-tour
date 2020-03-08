#pragma once

#include "BoardSize.hpp"
#include "IChessboard.hpp"

#include <vector>
#include <iostream>
#include <cstdlib>

namespace kaktus
{

    /**
     * Classic chessboard notation (A-H and 1-8) can not be used, so there are numbers instead of alphabet
     */
    struct Coordinates
    {
        int column;
        int row;
    };

    /**
     * Represents chessboard. It has no row/column validation => validation is via BoardSize::hasValidSize()
     */
    class Chessboard : public IChessboard
    {
    public:

        /**
         * Basic constructor
         * @param sizeColumn Size of chessboard's column defined as integer (originally letters)
         * @param sizeRow Size of chessboard's row defined as integer (originally numbers)
         */
        Chessboard(int sizeColumn, int sizeRow);

        /**
         * Basic constructor
         * @param boardSize Class containing board sizes
         */
        Chessboard(BoardSize boardSize);

        /**
         * Print chessboard with path to terminal
         * TODO - fix spacing dynamically
         */
        void printBoard() override;

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
         * This number represents moves count. Value can not be higher than chessboard.column * chessboard.row, exact match means solution.
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
         * @param sizeColumn New Chessboard column
         * @param sizeRow New Cheesboard row
         */
        void initBoard(int sizeColumn, int sizeRow);

        /**
         * Simple getter
         * @return Column size of the board. Returns zero when column is zero
         */
        int getColumn();

        /**
         * Simple getter
         * @return Row size of the chessboard
         */
        int getRow();

        /**
         * Sets random location of the Knight
         */
        void initPosition();

        /**
         * Check if position is inside chessboard
         * @return True when position is inside chessboard
         */
        bool positionExists(int moveWithColumn, int moveWithRow);

        /**
         * Checks if potencial position on chessboard is empty (is zero)
         * @param moveWithColumn Number which will be added to current position column
         * @param moveWithRow Number which will be added to current position row
         */
        bool isEmpty(int newColumn, int newRow);

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
         * @param moveWithColumn Number which will be added to current position column
         * @param moveWithRow Number which will be added to current position row
         * @return Final count of neighbours. Range of values is <0-8>
         */
        int countNeighbours(int moveWithColumn, int moveWithRow);

        /**
         * Check if potencial position has neighbour
         * @param moveWithColumn Number which will be added to potencial position column
         * @param moveWithRow Number which will be added to potencial position row
         * @return True when potencial position has neighbour
         */
        bool neighbourExists(int moveWithColumn, int moveWithRow, Coordinates potentialPosition);

        /**
         * Simple getter
         * @return Current position
         */
        Coordinates getPosition();

        /**
         * Check if new position is within chessboard range
         * @param moveWithColumn Number which will be added to current position column
         * @param moveWithRow Number which will be added to current position row
         * @return True when new column or new row is negative
         */
        bool isPotentialPositionNegative(int moveWithColumn, int moveWithRow);

        /**
         * Check if new position is within chessboard range
         * @param moveWithColumn Number which will be added to current position column
         * @param moveWithRow Number which will be added to current position row
         * @return True when new column or new row is greater then max sizes of chessboard
         */
        bool isPotencialPositionGreaterThanSize(int moveWithColumn, int moveWithRow);

        /**
         * Check if new neighbour position is within chessboard range
         * @param moveWithColumn Number which will be added to potencial position column
         * @param moveWithRow Number which will be added to potencial position row
         * @return True when new column or new row is negative
         */
        bool isNeighbourPositionNegative(int moveWithColumn, int moveWithRow, Coordinates potentialPosition);

        /**
         * Check if new neighbour position is within chessboard range
         * @param moveWithColumn Number which will be added to potencial position column
         * @param moveWithRow Number which will be added to potencial position row
         * @return True when new column or new row is greater then max sizes of chessboard
         */
        bool isNeighbourPositionGreaterThanSize(int moveWithColumn, int moveWithRow, Coordinates potentialPosition);
    };
}
