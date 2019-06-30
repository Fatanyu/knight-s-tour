#include "BoardSize.hpp"

namespace fatanyu
{
/**
 * Standard constructor. It inits values to zeros
 */
    BoardSize::BoardSize()
    {
        this->m_height = 0;
        this->m_width = 0;
    }

/**
 * Validate instance values
 * Size without solutions (remember, this is true for width x height and height x width):
 * - 0x0, 1x1, 1x0, 2x1, 2x2
 * @return True when solution exists
 */
    bool BoardSize::hasHeightOrWidthSmallerThanThree() const
    {
        return m_height < 3 || m_width < 3;
    }

/**
 * Validate instance values
 * Size without solutions (remember, this is true for width x height and height x width):
 * - 3x1, 3x2, 3x3, 3x5, 3x6
 * @return True when solution exists
 */
    bool BoardSize::hasHeightThreeAndHaveZeroSolutions() const
    {
        return m_height == 3 && (m_width == 1 || m_width == 2 || m_width == 3 || m_width == 5 || m_width == 6);
    }

/**
 * Validate instance values
 * Size without solutions (remember, this is true for width x height and height x width):
 * - 3x1, 3x2, 3x3, 3x5, 3x6
 * @return True when solution exists
 */
    bool BoardSize::hasWidthThreeAndHaveZeroSolutions() const
    {
        return m_width == 3 && (m_height == 1 || m_height == 2 || m_height == 3 || m_height == 5 || m_height == 6);
    }

/**
 * Validate instance values
 * Size without solutions (remember, this is true for width x height and height x width):
 * - 4x1, 4x2, 4x4
 * @return True when solution exists
 */
    bool BoardSize::hasHeightFourAndHaveZeroSolutions() const
    {
        return m_height == 4 && (m_width == 1 || m_width == 2 || m_width == 4);
    }

/**
 * Validate instance values
 * Size without solutions (remember, this is true for width x height and height x width):
 * - 4x1, 4x2, 4x4
 * @return True when solution exists
 */
    bool BoardSize::hasWidthFourAndHaveZeroSolutions() const
    {
        return m_width == 4 && (m_height == 1 || m_height == 2 || m_height == 4);
    }

/**
 * Validate instance values by all means
 * Size without solutions (remember, this is true for width x height and height x width):
 *   - 0x0, 1x1, 1x0, 2x1, 2x2
 *   - 3x1, 3x2, 3x3, 3x5, 3x6
 *   - 4x1, 4x2, 4x4
 * @return True when solution exists
 */
    bool BoardSize::hasValidSize() const
    {
        // 0x0, 1x1, 1x0, 2x1, 2x2 and all minus values
        if (this->hasHeightOrWidthSmallerThanThree())
        { return false; }

        // 3x1, 3x2, 3x3, 3x5, 3x6
        if (this->hasHeightThreeAndHaveZeroSolutions())
        { return false; }

        // 1x3, 2x3, 3x3, 5x3, 6x3
        if (this->hasWidthThreeAndHaveZeroSolutions())
        { return false; }

        // 4x1, 4x2, 4x4
        if (this->hasHeightFourAndHaveZeroSolutions())
        { return false; }

        // 1x4, 2x4, 4x4
        if (this->hasWidthFourAndHaveZeroSolutions())
        { return false; }

        return true;
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
        std::cin >> this->m_height;
    }

/**
 * Print board size to std::cout
 */
    void BoardSize::printSize() const
    {
        std::cout << TextConstants::dashLine << std::endl;
        std::cout << "Width set to:  " << this->m_width << std::endl;
        std::cout << "Height set to: " << this->m_height << std::endl;
        std::cout << TextConstants::dashLine << std::endl;
    }

/**
 * Simple getter
 * @return current m_width value
 */
    int BoardSize::getWidth() const
    {
        return this->m_width;
    }

/**
 * Simple getter
 * @return current m_height value
 */
    int BoardSize::getHeight() const
    {
        return this->m_height;
    }
}