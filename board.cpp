#include "board.hpp"

Board::Board(int sizeWidth, int sizeHeight)
{
	this->m_round = 1;
	this->initRand();
	this->initBoard(sizeWidth,sizeHeight);
	this->initPosition();
	//this->printBoard();
}
void Board::reset()
{
	this->m_round = 1;
	int width = this->getWidth();
	int height = this->getHeight();
	this->m_board.clear();
	this->initBoard(width, height);
	this->initPosition();
}


void Board::initRand()
{
	srand(time(NULL));
}

void Board::initPosition()
{
	//Coordinates position = {2,2};
	Coordinates position = {rand()%(this->getWidth()-1),rand()%(this->getHeight()-1)};
//	std::cout << "Position set to: " << position.width << "," << position.height << std::endl;
	this->setPosition(position);
}

void Board::initBoard(int sizeWidth, int sizeHeight)
{
	for(int indexHeight = 0; indexHeight < sizeHeight; indexHeight++)
	{
		std::vector<int> row;
		for(int indexWidth = 0; indexWidth < sizeWidth; indexWidth++)
		{
			row.push_back(0);
		}
		this->m_board.push_back(row);
	}
}

void Board::printBoard()
{
	for(auto row : this->m_board)
	{
		for(auto cell : row)
		{
			if(cell < 10)
				std::cout << cell << "   ";
			else if (cell < 100)
				std::cout << cell << "  ";
			else 
				std::cout << cell << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

Coordinates Board::getPosition()
{
	return this->m_actualPosition;
}

bool Board::move()
{
	//std::array<int,8> counts{0};
	//int maxValue = -1;
	int minValue = 5000;
	int identifier = -1;
	if(this->positionExists(2,1))
	{
		int count = this->countNeighbours(2,1);
		if(count < minValue)
		{
			minValue = count;
			identifier = 1;
		}
	}
	if(this->positionExists(1,2))
	{
		int count = this->countNeighbours(1,2);
		if(count < minValue)
		{
			minValue = count;
			identifier = 2;
		}
	}

	if(this->positionExists(-2,1))
	{
		int count = this->countNeighbours(-2,1);
		if(count < minValue)
		{
			minValue = count;
			identifier = 3;
		}
	}
	if(this->positionExists(-1,2))
	{
		int count = this->countNeighbours(-1,2);
		if(count < minValue)
		{
			minValue = count;
			identifier = 4;
		}
	}

	if(this->positionExists(-2,-1))
	{
		int count = this->countNeighbours(-2,-1);
		if(count < minValue)
		{
			minValue = count;
			identifier = 5;
		}
	}
	if(this->positionExists(-1,-2))
	{
		int count = this->countNeighbours(-1,-2);
		if(count < minValue)
		{
			minValue = count;
			identifier = 6;
		}
	}

	if(this->positionExists(1,-2))
	{
		int count = this->countNeighbours(1,-2);
		if(count < minValue)
		{
			minValue = count;
			identifier = 7;
		}
	}
	if(this->positionExists(2,-1))
	{
		int count = this->countNeighbours(2,-1);
		if(count < minValue)
		{
			minValue = count;
			identifier = 8;
		}
	}
	//std::cout << "1" << std::endl;
	if(identifier == -1) return false;
	//std::cout << "2" << std::endl;

	Coordinates newPosition{this->m_actualPosition.width, this->m_actualPosition.height};
	switch(identifier)
	{
		case 1:
			newPosition.width += 2;
			newPosition.height+= 1;
			break;
		case 2:
			newPosition.width += 1;
			newPosition.height+= 2;
			break;
		case 3:
			newPosition.width +=-2;
			newPosition.height+= 1;
			break;
		case 4:
			newPosition.width +=-1;
			newPosition.height+= 2;
			break;
		case 5:
			newPosition.width +=-2;
			newPosition.height+=-1;
			break;
		case 6:
			newPosition.width +=-1;
			newPosition.height+=-2;
			break;
		case 7:
			newPosition.width += 1;
			newPosition.height+=-2;
			break;
		case 8:
			newPosition.width += 2;
			newPosition.height+=-1;
			break;

	}
	this->setPosition(newPosition);
	//printBoard();
	return true;
}

int Board::countNeighbours(int moveWithWidth, int moveWithHeight)
{
	int count = 0;
	Coordinates potencialPosition = {this->m_actualPosition.width + moveWithWidth,this->m_actualPosition.height + moveWithHeight};

	if(this->neighbourExists(2,1,potencialPosition)) count++;
	if(this->neighbourExists(1,2,potencialPosition)) count++;
	if(this->neighbourExists(-2,1,potencialPosition)) count++;
	if(this->neighbourExists(-1,2,potencialPosition)) count++;
	if(this->neighbourExists(-2,-1,potencialPosition)) count++;
	if(this->neighbourExists(-1,-2,potencialPosition)) count++;
	if(this->neighbourExists(1,-2,potencialPosition)) count++;
	if(this->neighbourExists(2,-1,potencialPosition)) count++;
	return count;
}

bool Board::isEmpty(int newWidth, int newHeight)
{
	if(this->m_board.at(newHeight).at(newWidth) != 0)
		return false;
	else return true;
}

bool Board::isPotencialPositionNegative(int moveWithWidth, int moveWithHeight)
{
	return (this->m_actualPosition.width + moveWithWidth) < 0 || (this->m_actualPosition.height + moveWithHeight) < 0;
}

bool Board::isPotencialPositionGreaterThanSize(int moveWithWidth, int moveWithHeight)
{
	return (this->m_actualPosition.width + moveWithWidth) >= this->getWidth() || (this->m_actualPosition.height + moveWithHeight) >= this->getHeight();
}

bool Board::positionExists(int moveWithWidth, int moveWithHeight)
{
	if(this->isPotencialPositionNegative(moveWithWidth, moveWithHeight))
		return false;
	if(this->isPotencialPositionGreaterThanSize(moveWithWidth, moveWithHeight))
		return false;
	
	if(this->isEmpty(this->m_actualPosition.width + moveWithWidth,this->m_actualPosition.height + moveWithHeight)) 
		return true;
	else return false;
}

bool Board::isNeighbourPositionNegative(int moveWithWidth, int moveWithHeight, Coordinates potencialPosition)
{
	return (potencialPosition.width + moveWithWidth) < 0 || (potencialPosition.height + moveWithHeight) < 0;
}

bool Board::isNeighbourPositionGreaterThanSize(int moveWithWidth, int moveWithHeight, Coordinates potencialPosition)
{
	return potencialPosition.width + moveWithWidth >= this->getWidth() || potencialPosition.height + moveWithHeight >= this->getHeight();
}

bool Board::neighbourExists(int moveWithWidth, int moveWithHeight, Coordinates potencialPosition)
{
	if(this->isNeighbourPositionNegative(moveWithWidth, moveWithHeight, potencialPosition))
		return false;
	if(this->isNeighbourPositionGreaterThanSize(moveWithWidth, moveWithHeight, potencialPosition))
		return false;

	if(this->isEmpty(potencialPosition.width + moveWithWidth,potencialPosition.height + moveWithHeight)) 
		return true;
	else return false;
}

bool Board::setPosition(Coordinates newPosition)
{
	//if(newPosition.height < this->getHeight() && newPosition.width < this->getWidth())
	//{
		this->m_actualPosition.width = newPosition.width;
		this->m_actualPosition.height = newPosition.height;
		this->m_board.at(this->m_actualPosition.height).at(this->m_actualPosition.width) = this->m_round++;
		return true;
	//}
	//else
	//	return false;
}

bool Board::warnsdorff()
{
	//this->printBoard();
	//std::cout << "Width" << getWidth() << std::endl;
	//std::cout << "Height" << getHeight() << std::endl;
	//	std::cout << std::endl;
	while(this->m_round <= (this->getHeight()*this->getWidth()))
	{
	//  std::cout << m_round++ << std::endl;
		if(!this->move()) return false;
	//	break;
	//	this->printBoard();
	}

	this->printBoard();
	return true;
}

int Board::getWidth()
{
	if(this->getHeight() == 0) return 0;
	else return this->m_board.at(0).size();
}
int Board::getHeight()
{
	return this->m_board.size();
}
