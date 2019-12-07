#pragma once

#include <iostream>
#include "constants/TextConstants.hpp"

namespace fatanyu
{
    /**
     * Contains board sizes
     */
    class BoardSize
    {
    public:
        /**
         * Standard constructor. It inits values to zeros.
         */
        BoardSize();

        /**
         * Check given values
         * Size without solutions (remember, this is true for row x column and column x row):
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
        void setWidth();

        /**
         * Simple setter
         * Gets value from user
         */
        void setHeight();

        /**
         * Print board size to std::cout
         */
        void print() const;

        /**
         * Simple getter
         * @return current m_width value
         */
        int width() const;

        /**
         * Simple getter
          * @return current m_column value
         */
        int height() const;

    protected:
        /**
         * Board column - it can be used to init chessboard column
         * Do not use unsigned type!
         */
        int m_column;
        /**
         * Board column - it can be used to init chessboard column
         * Do not use unsigned type!
         */
        int m_width;

        /**
         * Validate instance values
         * Size without solutions (remember, this is true for row x column and column x row):
         * - 0x0, 1x1, 1x0, 2x1, 2x2
         * @return True when solution exists
         */
        bool hasHeightOrWidthSmallerThanThree() const;

        /**
         * Validate instance values
         * Size without solutions (remember, this is true for row x column and column x row):
         * - 3x1, 3x2, 3x3, 3x5, 3x6
         * @return True when solution exists
         */
        bool hasHeightThreeAndHaveZeroSolutions() const;

        /**
         * Validate instance values
         * Size without solutions (remember, this is true for row x column and column x row):
         * - 3x1, 3x2, 3x3, 3x5, 3x6
         * @return True when solution exists
         */
        bool hasWidthThreeAndHaveZeroSolutions() const;

        /**
         * Validate instance values
         * Size without solutions (remember, this is true for row x column and column x row):
         * - 4x1, 4x2, 4x4
         * @return True when solution exists
         */
        bool hasHeightFourAndHaveZeroSolutions() const;

        /**
         * Validate instance values
         * Size without solutions (remember, this is true for row x column and column x row):
         * - 4x1, 4x2, 4x4
         * @return True when solution exists
         */
        bool hasWidthFourAndHaveZeroSolutions() const;
    };
}