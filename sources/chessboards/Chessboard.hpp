#pragma once

#include "BoardSize.hpp"
#include "IChessboard.hpp"

#include <vector>
#include <iostream>
#include <cstdlib>

namespace kaktus
{
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
        Chessboard(int columns, int rows) : m_currentPosition({})
        {
            m_round = 1;
            initRand();
            initBoard(columns, rows);
            initPosition();
        }

        /**
         * Basic constructor
         * @param boardSize Class containing board sizes
         */
        explicit Chessboard(BoardSize boardSize) : m_currentPosition({})
        {
            m_round = 1;
            initRand();
            initBoard(boardSize.getColumn(), boardSize.getRow());
            initPosition();
        }

        /**
         * Print chessboard with path to terminal
         * TODO - fix spacing dynamically
         */
        void printBoard() override;

        /**
         * Find path by warnsdorff algorithms
         * @return True when path has been found
         */
        bool run() override;

        /**
         * Reset chessboard (sizes remain)
         */
        void reset() override;

        /**
         * Simple getter
         * @return Column size of the board. Returns zero when column is zero
         */
        int maxColumn() override;

        /**
         * Simple getter
         * @return Row size of the chessboard
         */
        int maxRow() override;

        /**
         * Check if position is inside chessboard
         * @return True when position is inside chessboard
         */
        bool positionExists(int moveWithColumn, int moveWithRow) override;

        /**
         * Count neighbours for potential location
         * @param moveWithColumn Number which will be added to current position column
         * @param moveWithRow Number which will be added to current position row
         * @return Final count of neighbours. Range of values is <0-8>
         */
        int countNeighbours(int moveWithColumn, int moveWithRow) override;

        Coordinates currentPosition() override
        {
            return m_currentPosition;
        }

        /**
         * Set new Knight's position
         * @param newPosition New Knight's position
         * @return True on successful move
         */
        bool setPosition(Coordinates newPosition) override;

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
         * Chessboard initialization. Create matrix and sets every position to zero
         * TODO checks
         * @param columns New Chessboard column
         * @param rows New Cheesboard row
         */
        void initBoard(int columns, int rows);

        /**
         * Sets random location of the Knight
         */
        void initPosition();

        /**
         * Checks if potential position on chessboard is empty (is zero)
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
        static void initRand()
        {
            srand(time(nullptr));
        }

        /**
         * Check if potential position has neighbour
         * @param moveWithColumn Number which will be added to potential position column
         * @param moveWithRow Number which will be added to potential position row
         * @return True when potential position has neighbour
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
        bool isPotentialPositionGreaterThanSize(int moveWithColumn, int moveWithRow);

        /**
         * Check if new neighbour position is within chessboard range
         * @param moveWithColumn Number which will be added to potential position column
         * @param moveWithRow Number which will be added to potential position row
         * @return True when new column or new row is negative
         */
        static bool isNeighbourPositionNegative(int moveWithColumn, int moveWithRow, Coordinates potentialPosition);

        /**
         * Check if new neighbour position is within chessboard range
         * @param moveWithColumn Number which will be added to potential position column
         * @param moveWithRow Number which will be added to potential position row
         * @return True when new column or new row is greater then max sizes of chessboard
         */
        bool isNeighbourPositionGreaterThanSize(int moveWithColumn, int moveWithRow, Coordinates potentialPosition);
    };
}