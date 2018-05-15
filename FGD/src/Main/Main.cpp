#include <allegro.h>
#include <BaseGame.h>
#include <GameStateManager.h>

int main()
{

    allegro_init();
    install_keyboard();

    GameStateManager game;

    game.pushState(new BaseGame(1));

    game.gameLoop();


    return 0;
}
END_OF_MAIN();
