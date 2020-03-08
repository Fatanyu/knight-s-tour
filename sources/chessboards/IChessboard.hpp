#pragma once

namespace kaktus
{
    /**
     * Classic chessboard notation (A-H and 1-8) can not be used, so there are numbers instead of alphabet
     */
    struct Coordinates
    {
        int column;
        int row;
    };

    class IChessboard
    {
    public:
        /**
         * @brief Print chessboard with path to terminal
         */
        virtual void printBoard() = 0;

        /**
         * @brief Reset chessboard (sizes remain)
         */
        virtual void reset() = 0;

        virtual ~IChessboard() = default;
        virtual int maxColumn() = 0;
        virtual int maxRow() = 0;
        /**
         * Check if position is inside chessboard
         * @return True when position is inside chessboard
         */
        virtual bool positionExists(int moveWithColumn, int moveWithRow) = 0;

        /**
         * Count neighbours for potential location
         * @param moveWithColumn Number which will be added to current position column
         * @param moveWithRow Number which will be added to current position row
         * @return Final count of neighbours. Range of values is <0-8>
         */
        virtual int countNeighbours(int moveWithColumn, int moveWithRow) = 0;

        virtual kaktus::Coordinates currentPosition() = 0;

        virtual bool setPosition(Coordinates coordinates) = 0;

        virtual bool run () = 0; // TODO remove

    };
}