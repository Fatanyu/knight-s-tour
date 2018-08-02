#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <iostream>
#include <cstdlib>

/**
 * Classic A-H and 1-8 can not be used, so there are two numbers
 */
struct Coordinates
{
	int width;
	int height;
};

/**
 * Represents chessboard. It has no height/width validation
 * TODO check bad size combination
 */
class Board
{
	/**
	 * 2D matrix as chessboard
	 */
	std::vector<std::vector<int>> m_board;
	
	/**
	 * This is position where Knight actually is
	 */
	Coordinates m_actualPosition;

	/**
	 * WTF??
	 */
	int m_round;

	/**
	 *
	 */
	bool setPosition(Coordinates newPosition);
	
	/**
	 *
	 */
	void initBoard(int sizeWidth, int sizeHeight);

	/**
	 *
	 */
	int getWidth();

	/**
	 *
	 */
	int getHeight();

	/**
	 *
	 */
	void initPosition();

	/**
	 *
	 */
	bool positionExists(int moveWithWidth, int moveWithHeight);

	/**
	 *
	 */
	bool isEmpty(int newWidth, int newHeight);

	/**
	 *
	 */
	bool move();

	/**
	 *
	 */
	bool canMove();

	/**
	 *
	 */
	void initRand();

	/**
	 *
	 */
	int countNeighbours(int moveWithWidth, int moveWithHeight);

	/**
	 *
	 */
	bool neighbourExists(int moveWithWidth, int moveWithHeight, Coordinates potencialPosition);

	/**
	 * Simple getter which returns current position
	 */
	Coordinates getPosition();

public:

	/**
	 * Basic constructor
	 * @param sizeWidth Size of chessboard's width defined as integer (originally letters)
	 * @param sizeHeight Size of chessboard's height defined as integer (originally numbers)
	 */
	Board(int sizeWidth, int sizeHeight);

	/**
	 * Print chessboard with path to terminal
	 * TODO - fix spacing dynamically
	 */
	void printBoard();

	/**
	 * Find path by warnsdorff algorithms
	 * @return True when path has been found
	 */
	bool warnsdorff();
	
	/**
	 * Reset chessboard (sizes remain)
	 */
	void reset();
};












#endif
