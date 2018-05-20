#include <MenuEscState.h>
#include <allegro.h>
#include <GameState.h>
#include <GameStateManager.h>
#include <BaseGame.h>
#include <MenuInitialState.h>
#include <MenuOptionsGameState.h>

using namespace std;

MenuEscState::MenuEscState(GameStateManager *game)
{
    this->game = game;

    this->init();

}

void MenuEscState::init()
{

    this->background_image = load_bitmap("src\\Resources\\Menu_esc\\background_menu_esc.bmp",NULL);
    this->options = load_bitmap("src\\Resources\\Menu_esc\\options_esc.bmp",NULL);
    this->options_pressed = load_bitmap("src\\Resources\\Menu_esc\\options_esc_pressed.bmp",NULL);
    this->save_game = load_bitmap("src\\Resources\\Menu_esc\\guardar_partida.bmp",NULL);
    this->save_game_pressed = load_bitmap("src\\Resources\\Menu_esc\\guardar_partida_pressed.bmp",NULL);
    this->menu_initial = load_bitmap("src\\Resources\\Menu_esc\\menu_initial_game.bmp",NULL);
    this->menu_initial_pressed = load_bitmap("src\\Resources\\Menu_esc\\menu_initial_game_pressed.bmp",NULL);
    this->leave_game = load_bitmap("src\\Resources\\Menu_esc\\leave_game.bmp",NULL);
    this->leave_game_pressed = load_bitmap("src\\Resources\\Menu_esc\\leave_game_pressed.bmp",NULL);
    this->back_game = load_bitmap("src\\Resources\\Menu_esc\\return_game.bmp",NULL);
    this->back_game_pressed = load_bitmap("src\\Resources\\Menu_esc\\return_game_pressed.bmp",NULL);


    install_mouse();

    show_mouse(screen);

}

void MenuEscState::getEvents()
{



}

void MenuEscState::update()
{



}

void MenuEscState::draw()
{

    masked_blit(this->background_image, this->game->getBuffer(), 0, 0, MIDDLE_SCREEN_X - 200, MIDDLE_SCREEN_Y - 200, 400, 400);

    optionsPressed();
    saveGamePressed();
    menuPressed();
    leavePressed();
    backPressed();



    blit(this->game->getBuffer(), screen, 0, 0, 0, 0, 800, 600);

}


void MenuEscState::optionsPressed()
{

    if(mouse_x >= (MIDDLE_SCREEN_X - 150) && mouse_x <= (MIDDLE_SCREEN_X + 150) &&
       mouse_y >= (MIDDLE_SCREEN_Y - 180) && mouse_y <= (MIDDLE_SCREEN_Y - 130))
    {
        masked_blit(this->options_pressed, this->game->getBuffer(), 0, 0, MIDDLE_SCREEN_X - 150, MIDDLE_SCREEN_Y - 180, 300, 50);
        if(mouse_b & 1)
        {
            this->game->pushState(new MenuOptionsGameState(this->game));
        }
    }
    else
    {
        masked_blit(this->options, this->game->getBuffer(), 0, 0, MIDDLE_SCREEN_X - 150, MIDDLE_SCREEN_Y - 180, 300, 50);
    }

}

void MenuEscState::saveGamePressed()
{

    if(mouse_x >= (MIDDLE_SCREEN_X - 150) && mouse_x <= (MIDDLE_SCREEN_X + 150) &&
       mouse_y >= (MIDDLE_SCREEN_Y - 110) && mouse_y <= (MIDDLE_SCREEN_Y - 60))
    {
        masked_blit(this->save_game_pressed, this->game->getBuffer(), 0, 0, MIDDLE_SCREEN_X - 150, MIDDLE_SCREEN_Y - 110, 300, 50);
        if(mouse_b & 1)
        {
            //TO DO
        }
    }
    else
    {
        masked_blit(this->save_game, this->game->getBuffer(), 0, 0, MIDDLE_SCREEN_X - 150, MIDDLE_SCREEN_Y - 110, 300, 50);
    }

}


void MenuEscState::menuPressed()
{

    if(mouse_x >= (MIDDLE_SCREEN_X - 150) && mouse_x <= (MIDDLE_SCREEN_X + 150) &&
       mouse_y >= (MIDDLE_SCREEN_Y - 40) && mouse_y <= (MIDDLE_SCREEN_Y + 10))
    {
        masked_blit(this->menu_initial_pressed, this->game->getBuffer(), 0, 0, MIDDLE_SCREEN_X - 150, MIDDLE_SCREEN_Y - 40, 300, 50);
        if(mouse_b & 1)
        {
            this->game->pushState(new MenuInitialState(this->game));
        }

    }
    else
    {
        masked_blit(this->menu_initial, this->game->getBuffer(), 0, 0, MIDDLE_SCREEN_X - 150, MIDDLE_SCREEN_Y - 40, 300, 50);
    }

}

void MenuEscState::leavePressed()
{

    if(mouse_x >= (MIDDLE_SCREEN_X - 150) && mouse_x <= (MIDDLE_SCREEN_X + 150) &&
       mouse_y >= (MIDDLE_SCREEN_Y + 30) && mouse_y <= (MIDDLE_SCREEN_Y + 80))
    {
        masked_blit(this->leave_game_pressed, this->game->getBuffer(), 0, 0, MIDDLE_SCREEN_X - 150, MIDDLE_SCREEN_Y + 30, 300, 50);
        if(mouse_b & 1)
        {
            this->game->setRunning(false);
        }

    }
    else
    {
        masked_blit(this->leave_game, this->game->getBuffer(), 0, 0, MIDDLE_SCREEN_X - 150, MIDDLE_SCREEN_Y + 30, 300, 50);
    }

}

void MenuEscState::backPressed()
{

    if(mouse_x >= (MIDDLE_SCREEN_X - 150) && mouse_x <= (MIDDLE_SCREEN_X + 150) &&
       mouse_y >= (MIDDLE_SCREEN_Y + 120) && mouse_y <= (MIDDLE_SCREEN_Y + 170))
    {
        masked_blit(this->back_game_pressed, this->game->getBuffer(), 0, 0, MIDDLE_SCREEN_X - 150, MIDDLE_SCREEN_Y + 120, 300, 50);
        if(mouse_b & 1)
        {
            this->game->popState();
        }

    }
    else
    {
        masked_blit(this->back_game, this->game->getBuffer(), 0, 0, MIDDLE_SCREEN_X - 150, MIDDLE_SCREEN_Y + 120, 300, 50);
    }

}

