#include <MenuOptionsGameState.h>
#include <allegro.h>
#include <GameState.h>
#include <GameStateManager.h>
#include <BaseGame.h>
#include <MenuInitialState.h>

using namespace std;

MenuOptionsGameState::MenuOptionsGameState(GameStateManager *game)
{
    this->game = game;

    this->init();

}

void MenuOptionsGameState::init()
{

    this->background_image = load_bitmap("src\\Resources\\background_menuinitial.bmp",NULL);
    this->new_game = load_bitmap("src\\Resources\\new_game.bmp",NULL);
    this->new_game_pressed = load_bitmap("src\\Resources\\new_game_pressed.bmp",NULL);
    this->options = load_bitmap("src\\Resources\\options.bmp",NULL);
    this->options_pressed = load_bitmap("src\\Resources\\options_pressed.bmp",NULL);
    this->leave = load_bitmap("src\\Resources\\leave.bmp",NULL);
    this->leave_pressed = load_bitmap("src\\Resources\\leave_pressed.bmp",NULL);

    install_mouse();

    show_mouse(screen);

}

void MenuOptionsGameState::getEvents()
{



}

void MenuOptionsGameState::update()
{



}

void MenuOptionsGameState::draw()
{

    masked_blit(this->background_image, this->game->getBuffer(), 0, 0, MIDDLE_SCREEN_X - 200, MIDDLE_SCREEN_Y - 200, 400, 400);

    newGamePressed();
    optionsPressed();
    leavePressed();



    blit(this->game->getBuffer(), screen, 0, 0, 0, 0, 800, 600);

}


void MenuOptionsGameState::newGamePressed()
{

    if(mouse_x >= (MIDDLE_SCREEN_X - 134) && mouse_x <= (MIDDLE_SCREEN_X + 134) &&
       mouse_y >= (MIDDLE_SCREEN_Y - 30) && mouse_y <= (MIDDLE_SCREEN_Y + 36))
    {
        masked_blit(this->new_game_pressed, this->game->getBuffer(), 0, 0, MIDDLE_SCREEN_X - 134, MIDDLE_SCREEN_Y - 30, 268, 66);
        if(mouse_b & 1)
        {
            this->game->pushState(new BaseGame(1, game));
        }
    }
    else
    {
        masked_blit(this->new_game, this->game->getBuffer(), 0, 0, MIDDLE_SCREEN_X - 134, MIDDLE_SCREEN_Y - 30, 268, 66);
    }

}

void MenuOptionsGameState::optionsPressed()
{

    if(mouse_x >= (MIDDLE_SCREEN_X - 134) && mouse_x <= (MIDDLE_SCREEN_X + 134) &&
       mouse_y >= (MIDDLE_SCREEN_Y + 50) && mouse_y <= (MIDDLE_SCREEN_Y + 116))
    {
        masked_blit(this->options_pressed, this->game->getBuffer(), 0, 0, MIDDLE_SCREEN_X - 134, MIDDLE_SCREEN_Y + 50, 268, 66);
        if(mouse_b & 1)
        {
            this->game->popState();
        }
    }
    else
    {
        masked_blit(this->options, this->game->getBuffer(), 0, 0, MIDDLE_SCREEN_X - 134, MIDDLE_SCREEN_Y + 50, 268, 66);
    }

}

void MenuOptionsGameState::leavePressed()
{

    if(mouse_x >= (MIDDLE_SCREEN_X - 134) && mouse_x <= (MIDDLE_SCREEN_X + 134) &&
       mouse_y >= (MIDDLE_SCREEN_Y + 130) && mouse_y <= (MIDDLE_SCREEN_Y + 196))
    {
        masked_blit(this->leave_pressed, this->game->getBuffer(), 0, 0, MIDDLE_SCREEN_X - 134, MIDDLE_SCREEN_Y + 130, 268, 66);
        if(mouse_b & 1)
        {
            this->game->popState();
        }

    }
    else
    {
        masked_blit(this->leave, this->game->getBuffer(), 0, 0, MIDDLE_SCREEN_X - 134, MIDDLE_SCREEN_Y + 130, 268, 66);
    }

}

