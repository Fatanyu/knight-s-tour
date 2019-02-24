#pragma once

#include <iostream>
#include "TextConstants.hpp"

/**
 * Contains board sizes
 */
class BoardSize
{
	int m_height;
	int m_width;
	
public:
	/**
	 * Standard constructor. It inits values to zeros
	 */
	BoardSize();
	
	/**
	 * Check if board sizes are valid
	 * @return True when solution exists 
	 */
	bool hasValidSize();
	
	/**
	 *
	 */
	void setWidth();
	
	/**
	 *
	 */
	void setHeight();
	
	/**
	 * Print board size to std::cout
	 */
	void printSize();
	
	/**
	 *
	 */
	int getWidth();
	
	/**
	 *
	 */
	int getHeight();
};