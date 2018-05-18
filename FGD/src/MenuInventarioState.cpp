#include <MenuInventarioState.h>
#include <allegro.h>
#include <GameState.h>
#include <GameStateManager.h>
#include <BaseGame.h>
#include <MenuInitialState.h>

using namespace std;

MenuInventarioState::MenuInventarioState(GameStateManager *game)
{
    this->game = game;

    this->init();

}

void MenuInventarioState::init()
{

    this->background_image = load_bitmap("src\\Resources\\Inventario.bmp",NULL);
    this->player = load_bitmap("src\\Resources\\player_inventory.bmp",NULL);

    install_mouse();

    show_mouse(screen);

}

void MenuInventarioState::getEvents()
{

    if (key[KEY_I]) this->game->popState();

}

void MenuInventarioState::update()
{



}

void MenuInventarioState::draw()
{

    masked_blit(this->background_image, this->game->getBuffer(), 0, 0, MIDDLE_SCREEN_X, MIDDLE_SCREEN_Y - 200, 400, 400);
    //Player
    masked_blit(this->player, this->game->getBuffer(), 0, 0, MIDDLE_SCREEN_X + 50, MIDDLE_SCREEN_Y - 165, 52, 100);



    blit(this->game->getBuffer(), screen, 0, 0, 0, 0, 800, 600);

}

