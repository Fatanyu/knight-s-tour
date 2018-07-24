#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <iostream>
#include <cstdlib>

struct Coordinates
{
	int width;
	int height;
};

class Board
{
	std::vector<std::vector<int>> m_board;
	Coordinates m_actualPosition;
	int m_round;

	bool setPosition(Coordinates newPosition);
	void initBoard(int sizeWidth, int sizeHeight);
	int getWidth();
	int getHeight();
	void initPosition();
	bool positionExists(int moveWithWidth, int moveWithHeight);
	bool isEmpty(int newWidth, int newHeight);
	bool move();
	bool canMove();
	void initRand();
	int countNeighbours(int moveWithWidth, int moveWithHeight);
	bool neighbourExists(int moveWithWidth, int moveWithHeight, Coordinates potencialPosition);
	Coordinates getPosition();

public:
	Board(int sizeWidth, int sizeHeight);
	void printBoard();
	bool warnsdorff();
	void reset();
};












#endif
