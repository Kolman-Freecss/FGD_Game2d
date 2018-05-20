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

    this->background_image = load_bitmap("src\\Resources\\background_menuinitial.bmp",NULL);
    this->new_game = load_bitmap("src\\Resources\\new_game.bmp",NULL);
    this->new_game_pressed = load_bitmap("src\\Resources\\new_game_pressed.bmp",NULL);
    this->options = load_bitmap("src\\Resources\\options.bmp",NULL);
    this->options_pressed = load_bitmap("src\\Resources\\options_pressed.bmp",NULL);
    this->menu_initial = load_bitmap("src\\Resources\\menu_initial.bmp",NULL);
    this->menu_initial_pressed = load_bitmap("src\\Resources\\menu_initial_pressed.bmp",NULL);

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

    newGamePressed();
    optionsPressed();
    menuPressed();



    blit(this->game->getBuffer(), screen, 0, 0, 0, 0, 800, 600);

}


void MenuEscState::newGamePressed()
{

    if(mouse_x >= (MIDDLE_SCREEN_X - 134) && mouse_x <= (MIDDLE_SCREEN_X + 134) &&
       mouse_y >= (MIDDLE_SCREEN_Y - 30) && mouse_y <= (MIDDLE_SCREEN_Y + 36))
    {
        masked_blit(this->new_game_pressed, this->game->getBuffer(), 0, 0, MIDDLE_SCREEN_X - 134, MIDDLE_SCREEN_Y - 30, 268, 66);
        if(mouse_b & 1)
        {
            this->game->pushState(new BaseGame(this->getDifficulty(), game));
        }
    }
    else
    {
        masked_blit(this->new_game, this->game->getBuffer(), 0, 0, MIDDLE_SCREEN_X - 134, MIDDLE_SCREEN_Y - 30, 268, 66);
    }

}

void MenuEscState::optionsPressed()
{

    if(mouse_x >= (MIDDLE_SCREEN_X - 134) && mouse_x <= (MIDDLE_SCREEN_X + 134) &&
       mouse_y >= (MIDDLE_SCREEN_Y + 50) && mouse_y <= (MIDDLE_SCREEN_Y + 116))
    {
        masked_blit(this->options_pressed, this->game->getBuffer(), 0, 0, MIDDLE_SCREEN_X - 134, MIDDLE_SCREEN_Y + 50, 268, 66);
        if(mouse_b & 1)
        {
            this->game->pushState(new MenuOptionsGameState(this->game));
        }
    }
    else
    {
        masked_blit(this->options, this->game->getBuffer(), 0, 0, MIDDLE_SCREEN_X - 134, MIDDLE_SCREEN_Y + 50, 268, 66);
    }

}

void MenuEscState::menuPressed()
{

    if(mouse_x >= (MIDDLE_SCREEN_X - 134) && mouse_x <= (MIDDLE_SCREEN_X + 134) &&
       mouse_y >= (MIDDLE_SCREEN_Y + 130) && mouse_y <= (MIDDLE_SCREEN_Y + 196))
    {
        masked_blit(this->menu_initial_pressed, this->game->getBuffer(), 0, 0, MIDDLE_SCREEN_X - 134, MIDDLE_SCREEN_Y + 130, 268, 66);
        if(mouse_b & 1)
        {
            this->game->pushState(new MenuInitialState(this->game));
        }

    }
    else
    {
        masked_blit(this->menu_initial, this->game->getBuffer(), 0, 0, MIDDLE_SCREEN_X - 134, MIDDLE_SCREEN_Y + 130, 268, 66);
    }

}

