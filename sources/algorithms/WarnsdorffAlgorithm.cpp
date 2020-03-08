#include "WarnsdorffAlgorithm.hpp"

std::string kaktus::WarnsdorffAlgorithm::getName()
{
    return std::string();
}

bool kaktus::WarnsdorffAlgorithm::run()
{
    while (m_round <= (m_chessboard->maxRow() * m_chessboard->maxColumn()))
    {
        if (!move())
        {
            return false;
        }
    }

    m_chessboard->printBoard();
    return true;
}

bool kaktus::WarnsdorffAlgorithm::move()
{
    //std::array<int,8> counts{0};
    //int maxValue = -1;
    int minValue = 5000;
    int identifier = -1;
    if (m_chessboard->positionExists(2, 1))
    {
        int count = m_chessboard->countNeighbours(2, 1);
        if (count < minValue)
        {
            minValue = count;
            identifier = 1;
        }
    }
    if (m_chessboard->positionExists(1, 2))
    {
        int count = m_chessboard->countNeighbours(1, 2);
        if (count < minValue)
        {
            minValue = count;
            identifier = 2;
        }
    }

    if (m_chessboard->positionExists(-2, 1))
    {
        int count = m_chessboard->countNeighbours(-2, 1);
        if (count < minValue)
        {
            minValue = count;
            identifier = 3;
        }
    }
    if (m_chessboard->positionExists(-1, 2))
    {
        int count = m_chessboard->countNeighbours(-1, 2);
        if (count < minValue)
        {
            minValue = count;
            identifier = 4;
        }
    }

    if (m_chessboard->positionExists(-2, -1))
    {
        int count = m_chessboard->countNeighbours(-2, -1);
        if (count < minValue)
        {
            minValue = count;
            identifier = 5;
        }
    }
    if (m_chessboard->positionExists(-1, -2))
    {
        int count = m_chessboard->countNeighbours(-1, -2);
        if (count < minValue)
        {
            minValue = count;
            identifier = 6;
        }
    }

    if (m_chessboard->positionExists(1, -2))
    {
        int count = m_chessboard->countNeighbours(1, -2);
        if (count < minValue)
        {
            minValue = count;
            identifier = 7;
        }
    }
    if (m_chessboard->positionExists(2, -1))
    {
        int count = m_chessboard->countNeighbours(2, -1);
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

    Coordinates newPosition{m_chessboard->currentPosition().column, m_chessboard->currentPosition().row};
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
            assert(false);
            break; //TODO throw error

    }
    m_chessboard->setPosition(newPosition);
    //printBoard();
    return true;
}

void kaktus::WarnsdorffAlgorithm::reset()
{
    m_chessboard->reset();
    m_round = 0;
}


