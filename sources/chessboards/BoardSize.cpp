#include "BoardSize.hpp"

namespace kaktus
{
    /**
     * Standard constructor. It inits values to zeros
     */
    BoardSize::BoardSize()
    {
        m_row = 0;
        m_column = 0;
    }

    /**
     * Validate instance values
     * Size without solutions (remember, this is true for column x row and row x column):
     * - 0x0, 1x1, 1x0, 2x1, 2x2
     * @return True when solution exists
     */
    bool BoardSize::hasRowOrColumnSmallerThanThree() const
    {
        return m_row < 3 || m_column < 3;
    }

    /**
     * Validate instance values
     * Size without solutions (remember, this is true for column x row and row x column):
     * - 3x1, 3x2, 3x3, 3x5, 3x6
     * @return True when solution exists
     */
    bool BoardSize::hasRowThreeAndHaveZeroSolutions() const
    {
        return m_row == 3 && (m_column == 1 || m_column == 2 || m_column == 3 || m_column == 5 || m_column == 6);
    }

    /**
     * Validate instance values
     * Size without solutions (remember, this is true for column x row and row x column):
     * - 3x1, 3x2, 3x3, 3x5, 3x6
     * @return True when solution exists
     */
    bool BoardSize::hasColumnThreeAndHaveZeroSolutions() const
    {
        return m_column == 3 && (m_row == 1 || m_row == 2 || m_row == 3 || m_row == 5 || m_row == 6);
    }

    /**
     * Validate instance values
     * Size without solutions (remember, this is true for column x row and row x column):
     * - 4x1, 4x2, 4x4
     * @return True when solution exists
     */
    bool BoardSize::hasRowFourAndHaveZeroSolutions() const
    {
        return m_row == 4 && (m_column == 1 || m_column == 2 || m_column == 4);
    }

    /**
     * Validate instance values
     * Size without solutions (remember, this is true for column x row and row x column):
     * - 4x1, 4x2, 4x4
     * @return True when solution exists
     */
    bool BoardSize::hasColumnFourAndHaveZeroSolutions() const
    {
        return m_column == 4 && (m_row == 1 || m_row == 2 || m_row == 4);
    }

    /**
     * Validate instance values by all means
     * Size without solutions (remember, this is true for column x row and row x column):
     *   - 0x0, 1x1, 1x0, 2x1, 2x2
     *   - 3x1, 3x2, 3x3, 3x5, 3x6
     *   - 4x1, 4x2, 4x4
     * @return True when solution exists
     */
    bool BoardSize::hasValidSize() const
    {
        // 0x0, 1x1, 1x0, 2x1, 2x2 and all minus values
        if (this->hasRowOrColumnSmallerThanThree())
        {
            return false;
        }

        // 3x1, 3x2, 3x3, 3x5, 3x6
        if (this->hasRowThreeAndHaveZeroSolutions())
        {
            return false;
        }

        // 1x3, 2x3, 3x3, 5x3, 6x3
        if (this->hasColumnThreeAndHaveZeroSolutions())
        {
            return false;
        }

        // 4x1, 4x2, 4x4
        if (this->hasRowFourAndHaveZeroSolutions())
        {
            return false;
        }

        // 1x4, 2x4, 4x4
        return !this->hasColumnFourAndHaveZeroSolutions();

    }

    /**
     * Simple setter
     * Gets value from user
     */
    void BoardSize::setColumn()
    {
        std::cout << "Columns:";
        std::cin >> this->m_column;
    }

    /**
     * Simple setter
     * Gets value from user
     */
    void BoardSize::setRow()
    {
        std::cout << "Rows:";
        std::cin >> m_row;
    }

    /**
     * Print board size to std::cout
     */
    void BoardSize::printSize() const
    {
        std::cout << TextConstants::dashLine << std::endl;
        std::cout << "Column set to:  " << m_column << std::endl;
        std::cout << "Row set to: " << m_row << std::endl;
        std::cout << TextConstants::dashLine << std::endl;
    }

    /**
     * Simple getter
     * @return current m_column value
     */
    int BoardSize::getColumn() const
    {
        return m_column;
    }

    /**
     * Simple getter
     * @return current m_row value
     */
    int BoardSize::getRow() const
    {
        return m_row;
    }
}