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
    this->menu_initial = load_bitmap("src\\Resources\\WinState\\menu_initial_game.bmp",NULL);
    this->menu_initial_pressed = load_bitmap("src\\Resources\\WinState\\menu_initial_game_pressed.bmp",NULL);
    this->leave = load_bitmap("src\\Resources\\WinState\\leave_game.bmp",NULL);
    this->leave_pressed = load_bitmap("src\\Resources\\WinState\\leave_game_pressed.bmp",NULL);

    //install_mouse();

    //set_mouse_sprite(mouse);
    //show_mouse(screen);

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
    this->menuPressed();
    this->leavePressed();

    show_mouse(this->game->getBuffer());
    blit(this->game->getBuffer(), screen, 0, 0, 0, 0, 800, 600);

}



void WinState::menuPressed()
{

    if(mouse_x >= (250) && mouse_x <= (550) &&
       mouse_y >= (250) && mouse_y <= (300))
    {
        masked_blit(this->menu_initial_pressed, this->game->getBuffer(), 0, 0, 250, 250, 300, 50);
        if(GameState::leftClick())
        {
            this->game->pushState(new MenuInitialState(this->game));
        }

    }
    else
    {
        masked_blit(this->menu_initial, this->game->getBuffer(), 0, 0, 250, 250, 300, 50);
    }

}

void WinState::leavePressed()
{

    if(mouse_x >= (250) && mouse_x <= (550) &&
       mouse_y >= (320) && mouse_y <= (370))
    {
        masked_blit(this->leave_pressed, this->game->getBuffer(), 0, 0, 250, 320, 300, 50);
        if(GameState::leftClick())
        {
            this->game->setRunning(false);
        }

    }
    else
    {
        masked_blit(this->leave, this->game->getBuffer(), 0, 0, 250, 320, 300, 50);
    }

}
