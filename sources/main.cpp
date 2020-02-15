#include "game/Game.hpp"
#include "logging/Logger.hpp"

int main()
{

    try
    {
        kaktus::Logger logger;
        try
        {
            kaktus::Game newGame;
            newGame.startGame();
        }
        catch (std::exception &exception)
        {
            logger.critical("Leaving main with critical error");
        }
    }
    catch (std::exception &exception)
    {
        std::cerr << exception.what() << std::endl;
        return 1;
    }
    return 0;
}
