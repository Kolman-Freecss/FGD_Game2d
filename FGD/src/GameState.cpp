#include "GameState.h"
#include <Timer.h>
#include <iostream>

using namespace std;

int GameState::difficulty = 1;
bool GameState::sound = true;
int GameState::timeClicked = 0;
int GameState::timePress = 0;

void GameState::setDifficulty(int difficulty)
{

    this->difficulty = difficulty;

}

int GameState::getDifficulty()
{

    return this->difficulty;

}

void GameState::setSound(bool sound)
{

    this->sound = sound;

}

bool GameState::getSound()
{

    return this->sound;

}

bool GameState::leftClick()
{
    if((mouse_b & 1) && (Timer::getTime()-20 > this->timeClicked))
    {
        this->timeClicked = Timer::getTime();
        return true;
    }
    return false;
}

bool GameState::keyI()
{
    if((key[KEY_I]) && (Timer::getTime()-10 > this->timeClicked))
    {
        this->timeClicked = Timer::getTime();
        return true;
    }
    return false;
}

char* GameState::generalKeyboard()
{
    char *characterInput = new char();
    if(Timer::getTime()-10 > this->timePress){

        if(key[KEY_A]){ characterInput = "a"; cout << "a";}
        if(key[KEY_B]) characterInput = "b";
        if(key[KEY_C]) characterInput = "c";
        if(key[KEY_D]) characterInput = "d";
        if(key[KEY_E]) characterInput = "e";
        if(key[KEY_F]) characterInput = "f";
        if(key[KEY_G]) characterInput = "g";
        if(key[KEY_H]) characterInput = "h";
        if(key[KEY_I]) characterInput = "i";
        if(key[KEY_J]) characterInput = "j";
        if(key[KEY_K]) characterInput = "k";
        if(key[KEY_L]) characterInput = "l";
        if(key[KEY_M]) characterInput = "m";
        if(key[KEY_N]) characterInput = "n";
        if(key[KEY_O]) characterInput = "o";
        if(key[KEY_P]) characterInput = "p";
        if(key[KEY_Q]) characterInput = "q";
        if(key[KEY_R]) characterInput = "r";
        if(key[KEY_S]) characterInput = "s";
        if(key[KEY_T]) characterInput = "t";
        if(key[KEY_U]) characterInput = "u";
        if(key[KEY_V]) characterInput = "v";
        if(key[KEY_W]) characterInput = "w";
        if(key[KEY_Y]) characterInput = "y";
        if(key[KEY_Z]) characterInput = "z";


        this->timePress = Timer::getTime();
    }

    return characterInput;
}
