#pragma once

#include <iostream>
#include "constants/TextConstants.hpp"

namespace kaktus
{
    /**
     * Contains board sizes
     */
    class BoardSize
    {
    public:
        /**
         * Standard constructor. It inits values to zeros
         */
        BoardSize();

        /**
         * Check given values
         * Size without solutions (remember, this is true for column x row and row x column):
         *   - 0x0, 1x1, 1x0, 2x1, 2x2
         *   - 3x1, 3x2, 3x3, 3x5, 3x6
         *   - 4x1, 4x2, 4x4
         * @return True when solution exists
         */
        bool hasValidSize() const;

        /**
         * Simple setter
         * Gets value from user
         */
        void setColumn();

        /**
         * Simple setter
         * Gets value from user
         */
        void setRow();

        /**
         * Print board size to std::cout
         */
        void printSize() const;

        /**
         * Simple getter
         * @return current m_column value
         */
        int getColumn() const;

        /**
         * Simple getter
          * @return current m_row value
         */
        int getRow() const;

    protected:
        /**
         * Board row - it can be used to init chessboard row
         * Do not use unsigned type!
         */
        int m_row;
        /**
         * Board row - it can be used to init chessboard row
         * Do not use unsigned type!
         */
        int m_column;

        /**
         * Validate instance values
         * Size without solutions (remember, this is true for column x row and row x column):
         * - 0x0, 1x1, 1x0, 2x1, 2x2
         * @return True when solution exists
         */
        bool hasRowOrColumnSmallerThanThree() const;

        /**
         * Validate instance values
         * Size without solutions (remember, this is true for column x row and row x column):
         * - 3x1, 3x2, 3x3, 3x5, 3x6
         * @return True when solution exists
         */
        bool hasRowThreeAndHaveZeroSolutions() const;

        /**
         * Validate instance values
         * Size without solutions (remember, this is true for column x row and row x column):
         * - 3x1, 3x2, 3x3, 3x5, 3x6
         * @return True when solution exists
         */
        bool hasColumnThreeAndHaveZeroSolutions() const;

        /**
         * Validate instance values
         * Size without solutions (remember, this is true for column x row and row x column):
         * - 4x1, 4x2, 4x4
         * @return True when solution exists
         */
        bool hasRowFourAndHaveZeroSolutions() const;

        /**
         * Validate instance values
         * Size without solutions (remember, this is true for column x row and row x column):
         * - 4x1, 4x2, 4x4
         * @return True when solution exists
         */
        bool hasColumnFourAndHaveZeroSolutions() const;
    };
}