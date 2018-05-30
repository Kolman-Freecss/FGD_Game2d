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

    this->background_image = load_bitmap("src\\Resources\\Menu_game_options\\background_menu_esc.bmp",NULL);
    this->music = load_bitmap("src\\Resources\\Menu_game_options\\music.bmp",NULL);
    this->music_pressed = load_bitmap("src\\Resources\\Menu_game_options\\music_pressed.bmp",NULL);
    this->music_check = load_bitmap("src\\Resources\\Menu_game_options\\music_checked.bmp",NULL);
    this->music_pressed_check = load_bitmap("src\\Resources\\Menu_game_options\\music_checked_pressed.bmp",NULL);
    this->returnn = load_bitmap("src\\Resources\\Menu_game_options\\return.bmp",NULL);
    this->return_pressed = load_bitmap("src\\Resources\\Menu_game_options\\return_pressed.bmp",NULL);

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

    musicPressed();
    returnPressedF();



    blit(this->game->getBuffer(), screen, 0, 0, 0, 0, 800, 600);

}


void MenuOptionsGameState::musicPressed()
{

    if(mouse_x >= (MIDDLE_SCREEN_X - 134) && mouse_x <= (MIDDLE_SCREEN_X + 134) &&
       mouse_y >= (MIDDLE_SCREEN_Y - 180) && mouse_y <= (MIDDLE_SCREEN_Y - 114))
    {

        if(!Music::checkMusicOrNot){
            masked_blit(this->music_pressed, this->game->getBuffer(), 0, 0, MIDDLE_SCREEN_X - 134, MIDDLE_SCREEN_Y - 180, 268, 66);
        }else{
            masked_blit(this->music_pressed_check, this->game->getBuffer(), 0, 0, MIDDLE_SCREEN_X - 134, MIDDLE_SCREEN_Y - 180, 268, 66);
        }
        if(GameState::leftClick())
        {
            if(!Music::checkMusicOrNot){
                this->setSound(true);
                Music::checkMusicOrNot = true;
            }else{
                this->setSound(false);
                managerMusic.stopAllSounds();
                Music::checkMusicOrNot = false;
            }
        }
    }
    else
    {
        if(!this->getSound()){
            masked_blit(this->music, this->game->getBuffer(), 0, 0, MIDDLE_SCREEN_X - 134, MIDDLE_SCREEN_Y - 180, 268, 66);
        }else{
            masked_blit(this->music_check, this->game->getBuffer(), 0, 0, MIDDLE_SCREEN_X - 134, MIDDLE_SCREEN_Y - 180, 268, 66);
        }
    }

}

void MenuOptionsGameState::returnPressedF()
{

    if(mouse_x >= (MIDDLE_SCREEN_X - 134) && mouse_x <= (MIDDLE_SCREEN_X + 134) &&
       mouse_y >= (MIDDLE_SCREEN_Y + 114) && mouse_y <= (MIDDLE_SCREEN_Y + 170))
    {
        masked_blit(this->return_pressed, this->game->getBuffer(), 0, 0, MIDDLE_SCREEN_X - 134, MIDDLE_SCREEN_Y + 114, 268, 66);
        if(GameState::leftClick())
        {

            this->game->popState();
        }

    }
    else
    {
        masked_blit(this->returnn, this->game->getBuffer(), 0, 0, MIDDLE_SCREEN_X - 134, MIDDLE_SCREEN_Y + 114, 268, 66);
    }

}

