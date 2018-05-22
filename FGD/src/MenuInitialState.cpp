#include <MenuInitialState.h>
#include <allegro.h>
#include <GameState.h>
#include <GameStateManager.h>
#include <BaseGame.h>
#include <MenuOptionsState.h>

using namespace std;

MenuInitialState::MenuInitialState(GameStateManager *game)
{
    this->game = game;

    this->init();

}

void MenuInitialState::init()
{

    this->logo = load_bitmap("src\\Resources\\shield_logo_all.bmp",NULL);
    this->background_image = load_bitmap("src\\Resources\\background_menu_initial.bmp",NULL);
    this->new_game = load_bitmap("src\\Resources\\new_game.bmp",NULL);
    this->new_game_pressed = load_bitmap("src\\Resources\\new_game_pressed.bmp",NULL);
    this->options = load_bitmap("src\\Resources\\options.bmp",NULL);
    this->options_pressed = load_bitmap("src\\Resources\\options_pressed.bmp",NULL);
    this->leave = load_bitmap("src\\Resources\\leave.bmp",NULL);
    this->leave_pressed = load_bitmap("src\\Resources\\leave_pressed.bmp",NULL);

    install_mouse();

    //set_mouse_sprite(mouse);
    show_mouse(screen);


        if(this->getSound()){
            if(!this->managerMusic.getMap1IsPlaying()){
                managerMusic.soundMap1();
            }
        }else{
            managerMusic.stopSoundBackground();
        }

}

void MenuInitialState::getEvents()
{



}

void MenuInitialState::update()
{



}

void MenuInitialState::draw()
{

    stretch_blit(this->background_image, this->game->getBuffer(), 0, 0, background_image->w, background_image->h, 0, 0, GameStateManager::SIZE_WINDOW_X, GameStateManager::SIZE_WINDOW_Y);


    masked_blit(this->logo, this->game->getBuffer(), 0, 0, MIDDLE_SCREEN_X - 100, MIDDLE_SCREEN_Y - 250, 200, 200);
    newGamePressed();
    optionsPressed();
    leavePressed();



    blit(this->game->getBuffer(), screen, 0, 0, 0, 0, 800, 600);

}


void MenuInitialState::newGamePressed()
{

    if(mouse_x >= (MIDDLE_SCREEN_X - 134) && mouse_x <= (MIDDLE_SCREEN_X + 134) &&
       mouse_y >= (MIDDLE_SCREEN_Y - 30) && mouse_y <= (MIDDLE_SCREEN_Y + 36))
    {
        masked_blit(this->new_game_pressed, this->game->getBuffer(), 0, 0, MIDDLE_SCREEN_X - 134, MIDDLE_SCREEN_Y - 30, 268, 66);
        if(GameState::leftClick())
        {
            this->game->pushState(new BaseGame(this->getDifficulty(), game));
        }
    }
    else
    {
        masked_blit(this->new_game, this->game->getBuffer(), 0, 0, MIDDLE_SCREEN_X - 134, MIDDLE_SCREEN_Y - 30, 268, 66);
    }

}

void MenuInitialState::optionsPressed()
{

    if(mouse_x >= (MIDDLE_SCREEN_X - 134) && mouse_x <= (MIDDLE_SCREEN_X + 134) &&
       mouse_y >= (MIDDLE_SCREEN_Y + 50) && mouse_y <= (MIDDLE_SCREEN_Y + 116))
    {
        masked_blit(this->options_pressed, this->game->getBuffer(), 0, 0, MIDDLE_SCREEN_X - 134, MIDDLE_SCREEN_Y + 50, 268, 66);
        if(GameState::leftClick())
        {
            this->game->pushState(new MenuOptionsState(this->game));
        }
    }
    else
    {
        masked_blit(this->options, this->game->getBuffer(), 0, 0, MIDDLE_SCREEN_X - 134, MIDDLE_SCREEN_Y + 50, 268, 66);
    }

}

void MenuInitialState::leavePressed()
{

    if(mouse_x >= (MIDDLE_SCREEN_X - 134) && mouse_x <= (MIDDLE_SCREEN_X + 134) &&
       mouse_y >= (MIDDLE_SCREEN_Y + 130) && mouse_y <= (MIDDLE_SCREEN_Y + 196))
    {
        masked_blit(this->leave_pressed, this->game->getBuffer(), 0, 0, MIDDLE_SCREEN_X - 134, MIDDLE_SCREEN_Y + 130, 268, 66);
        if(GameState::leftClick())
        {
            this->game->setRunning(false);
        }

    }
    else
    {
        masked_blit(this->leave, this->game->getBuffer(), 0, 0, MIDDLE_SCREEN_X - 134, MIDDLE_SCREEN_Y + 130, 268, 66);
    }

}

