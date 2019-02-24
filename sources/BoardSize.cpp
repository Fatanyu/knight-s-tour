#include "../headers/BoardSize.hpp"


/**
 *
 */
BoardSize::BoardSize()
{
	this->m_height = 0;
	this->m_width = 0;
}


/**
 *
 */
bool BoardSize::hasValidSize()
{
	return m_height > 0 && m_width > 0;
}

/**
 *
 */
void BoardSize::setWidth()
{
	std::cout << "Width:";
	std::cin >> this->m_width;
}

/**
 *
 */
void BoardSize::setHeight()
{
	std::cout << "Height:";
	std::cin >> this->m_height;
}

/**
 * Print board size to std::cout
 */
void BoardSize::printSize()
{
	std::cout << TextConstants::dashLine << std::endl;
	std::cout << "Width set to:  " << this->m_width << std::endl;
	std::cout << "Height set to: " << this->m_height << std::endl;
	std::cout << TextConstants::dashLine << std::endl;
}

/**
 *
 */
int BoardSize::getWidth()
{
	return this->m_width;
}

/**
 *
 */
int BoardSize::getHeight()
{
	return this->m_height;
}