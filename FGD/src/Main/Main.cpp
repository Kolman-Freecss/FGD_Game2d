#include <allegro.h>
#include <BaseGame.h>
#include <GameStateManager.h>
#include <GameState.h>

int main()
{

   /* allegro_init();
    install_keyboard();*/

    GameStateManager game;

    game.pushState(new BaseGame(1, &game));

    game.gameLoop();


    return 0;
}
END_OF_MAIN();
