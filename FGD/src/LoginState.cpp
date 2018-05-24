#include <LoginState.h>
#include <allegro.h>
#include <GameState.h>
#include <GameStateManager.h>
#include <BaseGame.h>
#include <MenuOptionsState.h>
#include <MenuInitialState.h>
#include <iostream>

using namespace std;

LoginState::LoginState(GameStateManager *game)
{
    this->game = game;

    this->init();

}

void LoginState::init()
{

    this->checkRegister = false;

    this->logo = load_bitmap("src\\Resources\\LoginState\\shield_logo_all.bmp",NULL);
    this->background_image = load_bitmap("src\\Resources\\LoginState\\background_menu_initial.bmp",NULL);

    this->login_user_password = load_bitmap("src\\Resources\\LoginState\\recuadroUser_Pass.bmp",NULL);
    this->login_user_password_pressed = load_bitmap("src\\Resources\\LoginState\\recuadroUser_Pass_Pressed.bmp",NULL);
    this->enter = load_bitmap("src\\Resources\\LoginState\\enter.bmp",NULL);
    this->enter_pressed = load_bitmap("src\\Resources\\LoginState\\enter_pressed.bmp",NULL);
    this->finish = load_bitmap("src\\Resources\\LoginState\\terminar.bmp",NULL);
    this->finish_pressed = load_bitmap("src\\Resources\\LoginState\\terminar_pressed.bmp",NULL);
    this->register_user = load_bitmap("src\\Resources\\LoginState\\registrar.bmp",NULL);
    this->register_user_pressed = load_bitmap("src\\Resources\\LoginState\\registrar_pressed.bmp",NULL);
    this->cruz = load_bitmap("src\\Resources\\LoginState\\cruz.bmp",NULL);

    install_mouse();

    //set_mouse_sprite(mouse);
    show_mouse(screen);


       /* if(this->getSound()){
            if(!this->managerMusic.getMap1IsPlaying()){
                managerMusic.soundMap1();
            }
        }else{
            managerMusic.stopSoundBackground();
        }*/

}

void LoginState::getEvents()
{

    cruzPressed();







}

void LoginState::update()
{



}

void LoginState::draw()
{

    stretch_blit(this->background_image, this->game->getBuffer(), 0, 0, background_image->w, background_image->h, 0, 0, GameStateManager::SIZE_WINDOW_X, GameStateManager::SIZE_WINDOW_Y);


    masked_blit(this->logo, this->game->getBuffer(), 0, 0, MIDDLE_SCREEN_X - 100, MIDDLE_SCREEN_Y - 250, 200, 200);
    masked_blit(this->cruz, this->game->getBuffer(), 0, 0, 750, 0, 50, 50);

    userPressed();
    passwordPressed();
    if(!checkRegister){
        enterPressed();
        registerPressed();
    }else{
        finishPressed();
    }


    this->clickOut();



    blit(this->game->getBuffer(), screen, 0, 0, 0, 0, 800, 600);

}


void LoginState::userPressed()
{

    if((mouse_x >= (MIDDLE_SCREEN_X - 90) && mouse_x <= (MIDDLE_SCREEN_X + 90) &&
       mouse_y >= (MIDDLE_SCREEN_Y - 25) && mouse_y <= (MIDDLE_SCREEN_Y + 25))
       ||
       this->checkUser)
    {
        masked_blit(this->login_user_password_pressed, this->game->getBuffer(), 0, 0, MIDDLE_SCREEN_X - 90, MIDDLE_SCREEN_Y - 25, 180, 50);
        if((mouse_x >= (MIDDLE_SCREEN_X - 90) && mouse_x <= (MIDDLE_SCREEN_X + 90) &&
            mouse_y >= (MIDDLE_SCREEN_Y - 25) && mouse_y <= (MIDDLE_SCREEN_Y + 25))){
            if(GameState::leftClick())
            {
                this->checkPassword = false;
                this->checkUser = true;
            }
        }
    }
    else
    {
        masked_blit(this->login_user_password, this->game->getBuffer(), 0, 0, MIDDLE_SCREEN_X - 90, MIDDLE_SCREEN_Y - 25, 180, 50);
    }

}

void LoginState::passwordPressed()
{

    if((mouse_x >= (MIDDLE_SCREEN_X - 90) && mouse_x <= (MIDDLE_SCREEN_X + 90) &&
       mouse_y >= (MIDDLE_SCREEN_Y + 50) && mouse_y <= (MIDDLE_SCREEN_Y + 100))
       ||
       this->checkPassword)
    {
        masked_blit(this->login_user_password_pressed, this->game->getBuffer(), 0, 0, MIDDLE_SCREEN_X - 90, MIDDLE_SCREEN_Y + 50, 180, 50);
        if((mouse_x >= (MIDDLE_SCREEN_X - 90) && mouse_x <= (MIDDLE_SCREEN_X + 90) &&
            mouse_y >= (MIDDLE_SCREEN_Y + 50) && mouse_y <= (MIDDLE_SCREEN_Y + 100))){
            if(GameState::leftClick())
            {
                this->checkUser = false;
                this->checkPassword = true;
            }
        }
    }
    else
    {
        masked_blit(this->login_user_password, this->game->getBuffer(), 0, 0, MIDDLE_SCREEN_X - 90, MIDDLE_SCREEN_Y + 50, 180, 50);
    }

}

void LoginState::enterPressed()
{

    if(mouse_x >= (MIDDLE_SCREEN_X - 80) && mouse_x <= (MIDDLE_SCREEN_X + 80) &&
       mouse_y >= (MIDDLE_SCREEN_Y + 120) && mouse_y <= (MIDDLE_SCREEN_Y + 160))
    {
        masked_blit(this->enter_pressed, this->game->getBuffer(), 0, 0, MIDDLE_SCREEN_X - 80, MIDDLE_SCREEN_Y + 120, 160, 40);
        if(GameState::leftClick())
        {
            this->game->pushState(new MenuInitialState(game));
        }

    }
    else
    {
        masked_blit(this->enter, this->game->getBuffer(), 0, 0, MIDDLE_SCREEN_X - 80, MIDDLE_SCREEN_Y + 120, 160, 40);
    }

}

void LoginState::finishPressed()
{

    if(mouse_x >= (MIDDLE_SCREEN_X - 80) && mouse_x <= (MIDDLE_SCREEN_X + 80) &&
       mouse_y >= (MIDDLE_SCREEN_Y + 120) && mouse_y <= (MIDDLE_SCREEN_Y + 160))
    {
        masked_blit(this->finish_pressed, this->game->getBuffer(), 0, 0, MIDDLE_SCREEN_X - 80, MIDDLE_SCREEN_Y + 120, 160, 40);
        if(GameState::leftClick())
        {
            this->checkRegister = false;
        }

    }
    else
    {
        masked_blit(this->finish, this->game->getBuffer(), 0, 0, MIDDLE_SCREEN_X - 80, MIDDLE_SCREEN_Y + 120, 160, 40);
    }

}

void LoginState::registerPressed()
{

    if(mouse_x >= (MIDDLE_SCREEN_X - 80) && mouse_x <= (MIDDLE_SCREEN_X + 80) &&
       mouse_y >= (MIDDLE_SCREEN_Y + 180) && mouse_y <= (MIDDLE_SCREEN_Y + 220))
    {
        masked_blit(this->register_user_pressed, this->game->getBuffer(), 0, 0, MIDDLE_SCREEN_X - 80, MIDDLE_SCREEN_Y + 180, 160, 40);
        if(GameState::leftClick())
        {
            this->checkRegister = true;
        }

    }
    else
    {
        masked_blit(this->register_user, this->game->getBuffer(), 0, 0, MIDDLE_SCREEN_X - 80, MIDDLE_SCREEN_Y + 180, 160, 40);
    }

}

void LoginState::cruzPressed()
{
    if(mouse_x >= (750) && mouse_x <= (800) &&
       mouse_y >= (0) && mouse_y <= (50))
    {
        if(GameState::leftClick())
        {
            this->game->setRunning(false);
        }
    }
}

void LoginState::clickOut()
{
    if (mouse_x <= (MIDDLE_SCREEN_X - 90) || mouse_x >= (MIDDLE_SCREEN_X + 90) &&
         ((mouse_y <= (MIDDLE_SCREEN_Y - 25) || mouse_y >= (MIDDLE_SCREEN_Y + 25))
        ||
         ((mouse_y <= (MIDDLE_SCREEN_Y + 50) || mouse_y >= (MIDDLE_SCREEN_Y + 100))))){
        if(GameState::leftClick())
        {
                    this->checkPassword = false;
                    this->checkUser = false;
        }
    }
}
