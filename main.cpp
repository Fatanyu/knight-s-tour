#include <iostream>
#include "board.hpp"
#include <memory>

//int main(int argc, char** argv)
int main(void)
{
	unsigned int boardSizeWidth = 0;
	unsigned int boardSizeHeight = 0;
	std::cout << "Give me Board sizes\nWidth:";
	std::cin >> boardSizeWidth;
	std::cout << "Height:";
	std::cin >> boardSizeHeight;
	std::cout << "W:" << boardSizeWidth << " H:" << boardSizeHeight << std::endl;
	
	std::unique_ptr<Board> board(new Board(boardSizeWidth,boardSizeHeight));

	// In case of fail, just reset and do it again
	// TODO random next step in case of multiple choices
	while(!board->warnsdorff()) board->reset();
	
	//board->printBoard();
	return 0;
}
