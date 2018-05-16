#include <allegro.h>
#include <BaseGame.h>
#include <GameStateManager.h>
#include <GameState.h>
#include <MenuInitialState.h>

int main()
{


    /**
    Initialize the window and allegro
    */
    GameStateManager game;

    /**
    Load intro
    */
    //game.pushState(new BaseGame(1, &game));
game.pushState(new MenuInitialState(&game));
    /**
    Game loop
    */
    game.gameLoop();


    return 0;
}
END_OF_MAIN();
