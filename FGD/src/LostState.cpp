#include <LostState.h>
#include <allegro.h>
#include <GameState.h>
#include <GameStateManager.h>
#include <BaseGame.h>
#include <MenuOptionsState.h>
#include <MenuInitialState.h>
#include <iostream>

using namespace std;

LostState::LostState(GameStateManager *game)
{
    this->game = game;

    this->init();

}

void LostState::init()
{


    this->background_image = load_bitmap("src\\Resources\\LostState\\background_lost.bmp",NULL);
    this->menu_initial = load_bitmap("src\\Resources\\LostState\\menu_initial_game.bmp",NULL);
    this->menu_initial_pressed = load_bitmap("src\\Resources\\LostState\\menu_initial_game_pressed.bmp",NULL);
    this->charge_game = load_bitmap("src\\Resources\\LostState\\charge_game.bmp",NULL);
    this->charge_game_pressed = load_bitmap("src\\Resources\\LostState\\charge_game_pressed.bmp",NULL);
    this->leave = load_bitmap("src\\Resources\\LostState\\leave_game.bmp",NULL);
    this->leave_pressed = load_bitmap("src\\Resources\\LostState\\leave_game_pressed.bmp",NULL);

    //set_mouse_sprite(mouse);

}

void LostState::getEvents()
{




}

void LostState::update()
{







}

void LostState::draw()
{


    masked_blit(this->background_image, this->game->getBuffer(), 0, 0, GameStateManager::SIZE_WINDOW_X /2 - 300, GameStateManager::SIZE_WINDOW_Y /2 -200, 600, 400);
    this->menuPressed();
    this->chargeGamePressed();
    this->leavePressed();

    blit(this->game->getBuffer(), screen, 0, 0, 0, 0, 800, 600);

}



void LostState::menuPressed()
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

void LostState::chargeGamePressed()
{

    if(mouse_x >= (250) && mouse_x <= (550) &&
       mouse_y >= (320) && mouse_y <= (370))
    {
        masked_blit(this->charge_game_pressed, this->game->getBuffer(), 0, 0, 250, 320, 300, 50);
        if(GameState::leftClick())
        {
            this->game->setRunning(false);
        }

    }
    else
    {
        masked_blit(this->charge_game, this->game->getBuffer(), 0, 0, 250, 320, 300, 50);
    }

}

void LostState::leavePressed()
{

    if(mouse_x >= (250) && mouse_x <= (550) &&
       mouse_y >= (390) && mouse_y <= (440))
    {
        masked_blit(this->leave_pressed, this->game->getBuffer(), 0, 0, 250, 390, 300, 50);
        if(GameState::leftClick())
        {
            this->game->setRunning(false);
        }

    }
    else
    {
        masked_blit(this->leave, this->game->getBuffer(), 0, 0, 250, 390, 300, 50);
    }

}
