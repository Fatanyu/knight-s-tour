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
	 * 
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
	 * Simple getter
	 * @return Width size of the board. Returns zero when width is zero
	 */
	int getWidth();

	/**
	 * Simple getter
	 * @return Height size of the chessboard
	 */
	int getHeight();

	/**
	 * Sets random location of the Knight
	 */
	void initPosition();

	/**
	 *
	 */
	bool positionExists(int moveWithWidth, int moveWithHeight);

	/**
	 * Checks if potencial position is empty
	 * @param moveWithWidth Number which will be added to current position width
	 * @param moveWithHeight Number which will be added to current position height
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
	 * Reset number generator
	 */
	void initRand();

	/**
	 * Count neighbours for potencial location
	 * @param moveWithWidth Number which will be added to current position width
	 * @param moveWithHeight Number which will be added to current position height
	 * @return Final count of neighbours. Range of values is <0-8>
	 */
	int countNeighbours(int moveWithWidth, int moveWithHeight);

	/**
	 * Check if potencial position has neighbour
	 * @param moveWithWidth Number which will be added to potencial position width
	 * @param moveWithHeight Number which will be added to potencial position height
	 * @return True when potencial position has neighbour 
	 */
	bool neighbourExists(int moveWithWidth, int moveWithHeight, Coordinates potencialPosition);

	/**
	 * Simple getter
	 * @return Current position
	 */
	Coordinates getPosition();

	/**
	 * Check if new position is within chessboard range
	 * @param moveWithWidth Number which will be added to current position width
	 * @param moveWithHeight Number which will be added to current position height
	 * @return True when new width or new height is negative
	 */
	bool isPotencialPositionNegative(int moveWithWidth, int moveWithHeight);

	/**
	 * Check if new position is within chessboard range
	 * @param moveWithWidth Number which will be added to current position width
	 * @param moveWithHeight Number which will be added to current position height
	 * @return True when new width or new height is greater then max sizes of chessboard
	 */
	bool isPotencialPositionGreaterThanSize(int moveWithWidth, int moveWithHeight);

	/**
	 * Check if new neighbour position is within chessboard range
	 * @param moveWithWidth Number which will be added to potencial position width
	 * @param moveWithHeight Number which will be added to potencial position height
	 * @return True when new width or new height is negative
	 */
	bool isNeighbourPositionNegative(int moveWithWidth, int moveWithHeight, Coordinates potencialPosition);

	/**
	 * Check if new neighbour position is within chessboard range
	 * @param moveWithWidth Number which will be added to potencial position width
	 * @param moveWithHeight Number which will be added to potencial position height
	 * @return True when new width or new height is greater then max sizes of chessboard
	 */
	bool isNeighbourPositionGreaterThanSize(int moveWithWidth, int moveWithHeight, Coordinates potencialPosition);


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
