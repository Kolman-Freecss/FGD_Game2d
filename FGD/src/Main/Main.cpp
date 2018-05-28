#include <allegro.h>
#include <BaseGame.h>
#include <GameStateManager.h>
#include <GameState.h>
#include <MenuInitialState.h>
#include <LoginState.h>
#include <WinState.h>
#include <LostState.h>

int main()
{


    /**
    Initialize the window and allegro
    */
    GameStateManager game;

    /**
    Load intro
    */
    game.pushState(new LostState(&game));
    /**
    Game loop
    */
    game.gameLoop();


    return 0;
}
END_OF_MAIN();
