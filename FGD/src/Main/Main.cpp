#include <allegro.h>
#include <BaseGame.h>
#include <GameStateManager.h>
#include <GameState.h>

int main()
{


    /**
    Initialize the window and allegro
    */
    GameStateManager game;

    /**
    Load intro
    */
    game.pushState(new BaseGame(1, &game));

    /**
    Game loop
    */
    game.gameLoop();


    return 0;
}
END_OF_MAIN();
