#include "BoardSize.hpp"

namespace fatanyu
{
    /**
     * Standard constructor. It inits values to zeros
     */
    BoardSize::BoardSize()
    {
        m_column = 0;
        m_width = 0;
    }

    /**
     * Validate instance values
     * Size without solutions (remember, this is true for row x column and column x row):
     * - 0x0, 1x1, 1x0, 2x1, 2x2
     * @return True when solution exists
     */
    bool BoardSize::hasHeightOrWidthSmallerThanThree() const
    {
        return m_column < 3 || m_width < 3;
    }

    /**
     * Validate instance values
     * Size without solutions (remember, this is true for row x column and column x row):
     * - 3x1, 3x2, 3x3, 3x5, 3x6
     * @return True when solution exists
     */
    bool BoardSize::hasHeightThreeAndHaveZeroSolutions() const
    {
        return m_column == 3 && (m_width == 1 || m_width == 2 || m_width == 3 || m_width == 5 || m_width == 6);
    }

    /**
     * Validate instance values
     * Size without solutions (remember, this is true for row x column and column x row):
     * - 3x1, 3x2, 3x3, 3x5, 3x6
     * @return True when solution exists
     */
    bool BoardSize::hasWidthThreeAndHaveZeroSolutions() const
    {
        return m_width == 3 && (m_column == 1 || m_column == 2 || m_column == 3 || m_column == 5 || m_column == 6);
    }

    /**
     * Validate instance values
     * Size without solutions (remember, this is true for row x column and column x row):
     * - 4x1, 4x2, 4x4
     * @return True when solution exists
     */
    bool BoardSize::hasHeightFourAndHaveZeroSolutions() const
    {
        return m_column == 4 && (m_width == 1 || m_width == 2 || m_width == 4);
    }

    /**
     * Validate instance values
     * Size without solutions (remember, this is true for row x column and column x row):
     * - 4x1, 4x2, 4x4
     * @return True when solution exists
     */
    bool BoardSize::hasWidthFourAndHaveZeroSolutions() const
    {
        return m_width == 4 && (m_column == 1 || m_column == 2 || m_column == 4);
    }

    /**
     * Validate instance values by all means
     * Size without solutions (remember, this is true for row x column and column x row):
     *   - 0x0, 1x1, 1x0, 2x1, 2x2
     *   - 3x1, 3x2, 3x3, 3x5, 3x6
     *   - 4x1, 4x2, 4x4
     * @return True when solution exists
     */
    bool BoardSize::hasValidSize() const
    {
        return !(hasHeightOrWidthSmallerThanThree() ||
                hasHeightThreeAndHaveZeroSolutions() ||
                hasWidthThreeAndHaveZeroSolutions() ||
                hasHeightFourAndHaveZeroSolutions() ||
                hasWidthFourAndHaveZeroSolutions());
    }

    /**
     * Simple setter
     * Gets value from user
     */
    void BoardSize::setWidth()
    {
        std::cout << "Width:";
        std::cin >> this->m_width;
    }

    /**
     * Simple setter
     * Gets value from user
     */
    void BoardSize::setHeight()
    {
        std::cout << "Height:";
        std::cin >> m_column;
    }

    /**
     * Print board size to std::cout
     */
    void BoardSize::print() const
    {
        std::cout << TextConstants::dashLine << std::endl;
        std::cout << "Width set to:  " << m_width << std::endl;
        std::cout << "Height set to: " << m_column << std::endl;
        std::cout << TextConstants::dashLine << std::endl;
    }

    /**
     * Simple getter
     * @return current m_width value
     */
    int BoardSize::width() const
    {
        return m_width;
    }

    /**
     * Simple getter
     * @return current m_column value
     */
    int BoardSize::height() const
    {
        return m_column;
    }
}