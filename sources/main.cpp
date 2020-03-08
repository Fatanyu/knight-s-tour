#include "game/Game.hpp"

int main()
{
    try
    {
            kaktus::Game newGame;
            newGame.startGame();
    }
    catch (std::exception &exception)
    {
        std::cerr << exception.what() << std::endl;
        return 1;
    }
    return 0;
}
