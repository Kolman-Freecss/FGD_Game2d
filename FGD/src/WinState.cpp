#include <WinState.h>
#include <allegro.h>
#include <GameState.h>
#include <GameStateManager.h>
#include <BaseGame.h>
#include <MenuOptionsState.h>
#include <MenuInitialState.h>
#include <iostream>

using namespace std;

WinState::WinState(GameStateManager *game)
{
    this->game = game;

    this->init();

}

void WinState::init()
{


    this->background_image = load_bitmap("src\\Resources\\WinState\\background_win.bmp",NULL);

    install_mouse();

    //set_mouse_sprite(mouse);
    show_mouse(screen);

}

void WinState::getEvents()
{




}

void WinState::update()
{







}

void WinState::draw()
{


    masked_blit(this->background_image, this->game->getBuffer(), 0, 0, GameStateManager::SIZE_WINDOW_X /2 - 300, GameStateManager::SIZE_WINDOW_Y /2 -200, 600, 400);



    blit(this->game->getBuffer(), screen, 0, 0, 0, 0, 800, 600);

}
