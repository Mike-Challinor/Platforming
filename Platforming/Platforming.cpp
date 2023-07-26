#include "stdafx.h"

#include "Game.h"

int main()
{
    //Init rand seed
    srand(static_cast<unsigned>(time(0)));

    Game game;

    while (game.getWindow().isOpen())
    {
        game.update();
        game.render();
    }

    //End application
    return 0;
}
