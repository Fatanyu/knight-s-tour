#include <cassert>
#include "Chessboard.hpp"

namespace kaktus
{
    void Chessboard::reset()
    {
        m_round = 1;
        int column = maxColumn();
        int row = maxRow();
        m_board.clear();
        initBoard(column, row);
        initPosition();
    }

    void Chessboard::initPosition()
    {
        Coordinates position = {rand() % (maxColumn() - 1), rand() % (maxRow() - 1)};
        setPosition(position);
    }

    void Chessboard::initBoard(int columns, int rows)
    {
        for (int indexRow = 0; indexRow < rows; indexRow++)
        {
            std::vector<int> row;
            row.reserve(columns);
            for (int indexColumn = 0; indexColumn < columns; indexColumn++)
            {
                row.push_back(0);
            }
            m_board.push_back(row);
        }
    }

    void Chessboard::printBoard()
    {
        for (auto &row : m_board)
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
        int minValue = 5000;
        int identifier = -1;
        if (positionExists(2, 1))
        {
            int count = countNeighbours(2, 1);
            if (count < minValue)
            {
                minValue = count;
                identifier = 1;
            }
        }
        if (positionExists(1, 2))
        {
            int count = countNeighbours(1, 2);
            if (count < minValue)
            {
                minValue = count;
                identifier = 2;
            }
        }

        if (positionExists(-2, 1))
        {
            int count = countNeighbours(-2, 1);
            if (count < minValue)
            {
                minValue = count;
                identifier = 3;
            }
        }
        if (positionExists(-1, 2))
        {
            int count = countNeighbours(-1, 2);
            if (count < minValue)
            {
                minValue = count;
                identifier = 4;
            }
        }

        if (positionExists(-2, -1))
        {
            int count = countNeighbours(-2, -1);
            if (count < minValue)
            {
                minValue = count;
                identifier = 5;
            }
        }
        if (positionExists(-1, -2))
        {
            int count = countNeighbours(-1, -2);
            if (count < minValue)
            {
                minValue = count;
                identifier = 6;
            }
        }

        if (positionExists(1, -2))
        {
            int count = countNeighbours(1, -2);
            if (count < minValue)
            {
                minValue = count;
                identifier = 7;
            }
        }
        if (positionExists(2, -1))
        {
            int count = countNeighbours(2, -1);
            if (count < minValue)
            {
                minValue = count;
                identifier = 8;
            }
        }

        if (identifier == -1)
        {
            return false;
        }

        Coordinates newPosition{m_currentPosition.column, m_currentPosition.row};
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
                assert(false); // when this happen, there is a mistake
                break;

        }
        setPosition(newPosition);
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

        if (neighbourExists(2, 1, potentialPosition))
        {
            freePositionCounter++;
        }
        if (neighbourExists(1, 2, potentialPosition))
        {
            freePositionCounter++;
        }
        if (neighbourExists(-2, 1, potentialPosition))
        {
            freePositionCounter++;
        }
        if (neighbourExists(-1, 2, potentialPosition))
        {
            freePositionCounter++;
        }
        if (neighbourExists(-2, -1, potentialPosition))
        {
            freePositionCounter++;
        }
        if (neighbourExists(-1, -2, potentialPosition))
        {
            freePositionCounter++;
        }
        if (neighbourExists(1, -2, potentialPosition))
        {
            freePositionCounter++;
        }
        if (neighbourExists(2, -1, potentialPosition))
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

    bool Chessboard::isPotentialPositionGreaterThanSize(int moveWithColumn, int moveWithRow)
    {
        return (m_currentPosition.column + moveWithColumn) >= maxColumn() ||
               (m_currentPosition.row + moveWithRow) >= maxRow();
    }

    bool Chessboard::positionExists(int moveWithColumn, int moveWithRow)
    {
        if (isPotentialPositionNegative(moveWithColumn, moveWithRow))
        {
            return false;
        }
        if (isPotentialPositionGreaterThanSize(moveWithColumn, moveWithRow))
        {
            return false;
        }

        return isEmpty(m_currentPosition.column + moveWithColumn, m_currentPosition.row + moveWithRow);
    }

    bool Chessboard::isNeighbourPositionNegative(int moveWithColumn, int moveWithRow, Coordinates potentialPosition)
    {
        return (potentialPosition.column + moveWithColumn) < 0 || (potentialPosition.row + moveWithRow) < 0;
    }

    bool
    Chessboard::isNeighbourPositionGreaterThanSize(int moveWithColumn, int moveWithRow, Coordinates potentialPosition)
    {
        return potentialPosition.column + moveWithColumn >= maxColumn() ||
               potentialPosition.row + moveWithRow >= maxRow();
    }

    bool Chessboard::neighbourExists(int moveWithColumn, int moveWithRow, Coordinates potentialPosition)
    {
        if (isNeighbourPositionNegative(moveWithColumn, moveWithRow, potentialPosition))
        {
            return false;
        }
        if (isNeighbourPositionGreaterThanSize(moveWithColumn, moveWithRow, potentialPosition))
        {
            return false;
        }

        return isEmpty(potentialPosition.column + moveWithColumn, potentialPosition.row + moveWithRow);
    }

    bool Chessboard::setPosition(Coordinates newPosition)
    {
        m_currentPosition.column = newPosition.column;
        m_currentPosition.row = newPosition.row;
        m_board.at(m_currentPosition.row).at(m_currentPosition.column) = m_round++;
        return true;
    }

    bool Chessboard::run()
    {
        while (m_round <= (maxRow() * maxColumn()))
        {
            if (!move())
            {
                return false;
            }
        }

        printBoard();
        return true;
    }

    int Chessboard::maxColumn()
    {
        if (maxRow() == 0)
        {
            return 0;
        }
        else
        {
            return m_board.at(0).size();
        }
    }

    int Chessboard::maxRow()
    {
        return m_board.size();
    }
}