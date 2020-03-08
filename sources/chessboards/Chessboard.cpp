#include "Chessboard.hpp"

namespace kaktus
{
    Chessboard::Chessboard(int sizeColumn, int sizeRow)
    {
        m_round = 1;
        this->initRand();
        this->initBoard(sizeColumn, sizeRow);
        this->initPosition();
    }

    Chessboard::Chessboard(BoardSize boardSize)
    {
        m_round = 1;
        this->initRand();
        this->initBoard(boardSize.getColumn(), boardSize.getRow());
        this->initPosition();
    }

    void Chessboard::reset()
    {
        m_round = 1;
        int column = this->getColumn();
        int row = this->getRow();
        m_board.clear();
        this->initBoard(column, row);
        this->initPosition();
    }


    void Chessboard::initRand()
    {
        srand(time(nullptr));
    }

    void Chessboard::initPosition()
    {
        //Coordinates position = {2,2};
        Coordinates position = {rand() % (this->getColumn() - 1), rand() % (this->getRow() - 1)};
//	std::cout << "Position set to: " << position.column << "," << position.row << std::endl;
        this->setPosition(position);
    }

    void Chessboard::initBoard(int sizeColumn, int sizeRow)
    {
        for (int indexRow = 0; indexRow < sizeRow; indexRow++)
        {
            std::vector<int> row;
            for (int indexColumn = 0; indexColumn < sizeColumn; indexColumn++)
            {
                row.push_back(0);
            }
            this->m_board.push_back(row);
        }
    }

    void Chessboard::printBoard()
    {
        for (auto &row : this->m_board)
        {
            for (auto cell : row)
            {
                if (cell < 10)
                {
                    std::cout << cell << "   ";
                }
                else if (cell < 100)
                {
                    std::cout << cell << "  ";
                }
                else
                {
                    std::cout << cell << " ";
                }
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }

    Coordinates Chessboard::getPosition()
    {
        return m_currentPosition;
    }

    bool Chessboard::move()
    {
        //std::array<int,8> counts{0};
        //int maxValue = -1;
        int minValue = 5000;
        int identifier = -1;
        if (this->positionExists(2, 1))
        {
            int count = this->countNeighbours(2, 1);
            if (count < minValue)
            {
                minValue = count;
                identifier = 1;
            }
        }
        if (this->positionExists(1, 2))
        {
            int count = this->countNeighbours(1, 2);
            if (count < minValue)
            {
                minValue = count;
                identifier = 2;
            }
        }

        if (this->positionExists(-2, 1))
        {
            int count = this->countNeighbours(-2, 1);
            if (count < minValue)
            {
                minValue = count;
                identifier = 3;
            }
        }
        if (this->positionExists(-1, 2))
        {
            int count = this->countNeighbours(-1, 2);
            if (count < minValue)
            {
                minValue = count;
                identifier = 4;
            }
        }

        if (this->positionExists(-2, -1))
        {
            int count = this->countNeighbours(-2, -1);
            if (count < minValue)
            {
                minValue = count;
                identifier = 5;
            }
        }
        if (this->positionExists(-1, -2))
        {
            int count = this->countNeighbours(-1, -2);
            if (count < minValue)
            {
                minValue = count;
                identifier = 6;
            }
        }

        if (this->positionExists(1, -2))
        {
            int count = this->countNeighbours(1, -2);
            if (count < minValue)
            {
                minValue = count;
                identifier = 7;
            }
        }
        if (this->positionExists(2, -1))
        {
            int count = this->countNeighbours(2, -1);
            if (count < minValue)
            {
                minValue = count;
                identifier = 8;
            }
        }
        //std::cout << "1" << std::endl;
        if (identifier == -1)
        {
            return false;
        }
        //std::cout << "2" << std::endl;

        Coordinates newPosition{this->m_currentPosition.column, this->m_currentPosition.row};
        switch (identifier)
        {
            case 1:
                newPosition.column += 2;
                newPosition.row += 1;
                break;
            case 2:
                newPosition.column += 1;
                newPosition.row += 2;
                break;
            case 3:
                newPosition.column += -2;
                newPosition.row += 1;
                break;
            case 4:
                newPosition.column += -1;
                newPosition.row += 2;
                break;
            case 5:
                newPosition.column += -2;
                newPosition.row += -1;
                break;
            case 6:
                newPosition.column += -1;
                newPosition.row += -2;
                break;
            case 7:
                newPosition.column += 1;
                newPosition.row += -2;
                break;
            case 8:
                newPosition.column += 2;
                newPosition.row += -1;
                break;
            default:
                break; //TODO throw error

        }
        this->setPosition(newPosition);
        //printBoard();
        return true;
    }

    int Chessboard::countNeighbours(int moveWithColumn, int moveWithRow)
    {
        int freePositionCounter = 0;
        Coordinates potentialPosition = {
                m_currentPosition.column + moveWithColumn,
                m_currentPosition.row + moveWithRow
        };

        if (this->neighbourExists(2, 1, potentialPosition))
        {
            freePositionCounter++;
        }
        if (this->neighbourExists(1, 2, potentialPosition))
        {
            freePositionCounter++;
        }
        if (this->neighbourExists(-2, 1, potentialPosition))
        {
            freePositionCounter++;
        }
        if (this->neighbourExists(-1, 2, potentialPosition))
        {
            freePositionCounter++;
        }
        if (this->neighbourExists(-2, -1, potentialPosition))
        {
            freePositionCounter++;
        }
        if (this->neighbourExists(-1, -2, potentialPosition))
        {
            freePositionCounter++;
        }
        if (this->neighbourExists(1, -2, potentialPosition))
        {
            freePositionCounter++;
        }
        if (this->neighbourExists(2, -1, potentialPosition))
        {
            freePositionCounter++;
        }
        return freePositionCounter;
    }

    bool Chessboard::isEmpty(int newColumn, int newRow)
    {
        return m_board.at(newRow).at(newColumn) == 0;
    }

    bool Chessboard::isPotentialPositionNegative(int moveWithColumn, int moveWithRow)
    {
        return (m_currentPosition.column + moveWithColumn) < 0 ||
               (m_currentPosition.row + moveWithRow) < 0;
    }

    bool Chessboard::isPotencialPositionGreaterThanSize(int moveWithColumn, int moveWithRow)
    {
        return (this->m_currentPosition.column + moveWithColumn) >= this->getColumn() ||
               (this->m_currentPosition.row + moveWithRow) >= this->getRow();
    }

    bool Chessboard::positionExists(int moveWithColumn, int moveWithRow)
    {
        if (this->isPotentialPositionNegative(moveWithColumn, moveWithRow))
        {
            return false;
        }
        if (this->isPotencialPositionGreaterThanSize(moveWithColumn, moveWithRow))
        {
            return false;
        }

        return this->isEmpty(m_currentPosition.column + moveWithColumn, m_currentPosition.row + moveWithRow);
    }

    bool Chessboard::isNeighbourPositionNegative(int moveWithColumn, int moveWithRow, Coordinates potentialPosition)
    {
        return (potentialPosition.column + moveWithColumn) < 0 || (potentialPosition.row + moveWithRow) < 0;
    }

    bool
    Chessboard::isNeighbourPositionGreaterThanSize(int moveWithColumn, int moveWithRow, Coordinates potentialPosition)
    {
        return potentialPosition.column + moveWithColumn >= this->getColumn() ||
               potentialPosition.row + moveWithRow >= this->getRow();
    }

    bool Chessboard::neighbourExists(int moveWithColumn, int moveWithRow, Coordinates potentialPosition)
    {
        if (this->isNeighbourPositionNegative(moveWithColumn, moveWithRow, potentialPosition))
        {
            return false;
        }
        if (this->isNeighbourPositionGreaterThanSize(moveWithColumn, moveWithRow, potentialPosition))
        {
            return false;
        }

        return this->isEmpty(potentialPosition.column + moveWithColumn, potentialPosition.row + moveWithRow);
    }

    bool Chessboard::setPosition(Coordinates newPosition)
    {
        this->m_currentPosition.column = newPosition.column;
        this->m_currentPosition.row = newPosition.row;
        this->m_board.at(this->m_currentPosition.row).at(this->m_currentPosition.column) = this->m_round++;
        return true;
    }

    bool Chessboard::warnsdorff()
    {
        while (this->m_round <= (this->getRow() * this->getColumn()))
        {
            if (!this->move())
            {
                return false;
            }
        }

        this->printBoard();
        return true;
    }

    int Chessboard::getColumn()
    {
        if (this->getRow() == 0)
        {
            return 0;
        }
        else
        {
            return this->m_board.at(0).size();
        }
    }

    int Chessboard::getRow()
    {
        return this->m_board.size();
    }
}