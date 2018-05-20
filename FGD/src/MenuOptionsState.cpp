#include <MenuOptionsState.h>
#include <allegro.h>
#include <GameState.h>
#include <GameStateManager.h>
#include <BaseGame.h>
#include <MenuInitialState.h>

using namespace std;

MenuOptionsState::MenuOptionsState(GameStateManager *game)
{
    this->game = game;

    this->init();

}

void MenuOptionsState::init()
{

    this->background_image = load_bitmap("src\\Resources\\background_menu_initial.bmp",NULL);


    this->music = load_bitmap("src\\Resources\\music.bmp",NULL);
    this->music_pressed = load_bitmap("src\\Resources\\music_pressed.bmp",NULL);
    this->music_checked = load_bitmap("src\\Resources\\music_checked.bmp",NULL);
    this->music_pressed_checked = load_bitmap("src\\Resources\\music_checked_pressed.bmp",NULL);


    this->easy = load_bitmap("src\\Resources\\level_easy.bmp",NULL);
    this->easy_pressed = load_bitmap("src\\Resources\\level_easy_pressed.bmp",NULL);
    this->medium = load_bitmap("src\\Resources\\level_medium.bmp",NULL);
    this->medium_pressed = load_bitmap("src\\Resources\\level_medium_pressed.bmp",NULL);
    this->hard = load_bitmap("src\\Resources\\level_hard.bmp",NULL);
    this->hard_pressed = load_bitmap("src\\Resources\\level_hard_pressed.bmp",NULL);
    this->backk = load_bitmap("src\\Resources\\back.bmp",NULL);
    this->backk_pressed = load_bitmap("src\\Resources\\back_pressed.bmp",NULL);

    install_mouse();

    show_mouse(screen);

}

void MenuOptionsState::getEvents()
{



}

void MenuOptionsState::update()
{



}

void MenuOptionsState::draw()
{

    stretch_blit(this->background_image, this->game->getBuffer(), 0, 0, background_image->w, background_image->h, 0, 0, GameStateManager::SIZE_WINDOW_X, GameStateManager::SIZE_WINDOW_Y);

    musicPressed();
    difficultyPressed();
    backPressed();



    blit(this->game->getBuffer(), screen, 0, 0, 0, 0, 800, 600);

}


void MenuOptionsState::musicPressed()
{

    if(mouse_x >= (MIDDLE_SCREEN_X - 134) && mouse_x <= (MIDDLE_SCREEN_X + 134) &&
       mouse_y >= (MIDDLE_SCREEN_Y - 30) && mouse_y <= (MIDDLE_SCREEN_Y + 36))
    {
        if(!this->getSound()){
            masked_blit(this->music_pressed, this->game->getBuffer(), 0, 0, MIDDLE_SCREEN_X - 134, MIDDLE_SCREEN_Y - 30, 268, 66);
        }else{
            masked_blit(this->music_pressed_checked, this->game->getBuffer(), 0, 0, MIDDLE_SCREEN_X - 134, MIDDLE_SCREEN_Y - 30, 268, 66);
        }
        if(mouse_b & 1)
        {
            if(!this->getSound()){
                this->setSound(true);
            }else{
                this->setSound(false);
            }
        }
    }
    else
    {
        if(!this->getSound()){
            masked_blit(this->music, this->game->getBuffer(), 0, 0, MIDDLE_SCREEN_X - 134, MIDDLE_SCREEN_Y - 30, 268, 66);
        }else{
            masked_blit(this->music_checked, this->game->getBuffer(), 0, 0, MIDDLE_SCREEN_X - 134, MIDDLE_SCREEN_Y - 30, 268, 66);
        }
    }

}

void MenuOptionsState::difficultyPressed()
{

    if(mouse_x >= (MIDDLE_SCREEN_X - 134) && mouse_x <= (MIDDLE_SCREEN_X + 134) &&
       mouse_y >= (MIDDLE_SCREEN_Y + 50) && mouse_y <= (MIDDLE_SCREEN_Y + 116))
    {
        if (this->getDifficulty() == 1){
            masked_blit(this->easy_pressed, this->game->getBuffer(), 0, 0, MIDDLE_SCREEN_X - 134, MIDDLE_SCREEN_Y + 50, 268, 66);
        }else if (this->getDifficulty() == 2){
            masked_blit(this->medium_pressed, this->game->getBuffer(), 0, 0, MIDDLE_SCREEN_X - 134, MIDDLE_SCREEN_Y + 50, 268, 66);
        }else if (this->getDifficulty() == 3){
            masked_blit(this->hard_pressed, this->game->getBuffer(), 0, 0, MIDDLE_SCREEN_X - 134, MIDDLE_SCREEN_Y + 50, 268, 66);
        }

        if(mouse_b & 1)
        {
            if (this->getDifficulty() == 1){
                this->setDifficulty(2);
            }else if (this->getDifficulty() == 2){
                this->setDifficulty(3);
            }else if (this->getDifficulty() == 3){
                this->setDifficulty(1);
            }
        }

    }
    else
    {
        if (this->getDifficulty() == 1){
            masked_blit(this->easy, this->game->getBuffer(), 0, 0, MIDDLE_SCREEN_X - 134, MIDDLE_SCREEN_Y + 50, 268, 66);
        }else if (this->getDifficulty() == 2){
            masked_blit(this->medium, this->game->getBuffer(), 0, 0, MIDDLE_SCREEN_X - 134, MIDDLE_SCREEN_Y + 50, 268, 66);
        }else if (this->getDifficulty() == 3){
            masked_blit(this->hard, this->game->getBuffer(), 0, 0, MIDDLE_SCREEN_X - 134, MIDDLE_SCREEN_Y + 50, 268, 66);
        }

    }
}

void MenuOptionsState::backPressed()
{

    if(mouse_x >= (50) && mouse_x <= (264) &&
       mouse_y >= (510) && mouse_y <= (550))
    {
        masked_blit(this->backk_pressed, this->game->getBuffer(), 0, 0, 50, 510, 214, 40);
        if(mouse_b & 1)
        {
            this->game->popState();
        }

    }
    else
    {
        masked_blit(this->backk, this->game->getBuffer(), 0, 0, 50, 510, 214, 40);
    }

}

