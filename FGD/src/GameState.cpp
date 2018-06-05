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

bool GameState::spacePress()
{
    if((key[KEY_SPACE]) && (Timer::getTime()-10 > this->timePress))
    {
        this->timePress = Timer::getTime();
        return true;
    }
    return false;
}

void GameState::generalKeyboard(int userOrPass)
{
    char *characterInput = new char();
    bool checkPress = false;
    if(Timer::getTime()-5 > this->timePress){

        if(key[KEY_A]) {characterInput = "a"; checkPress = true;}
        if(key[KEY_B]) {characterInput = "b"; checkPress = true;}
        if(key[KEY_C]) {characterInput = "c"; checkPress = true;}
        if(key[KEY_D]) {characterInput = "d"; checkPress = true;}
        if(key[KEY_E]) {characterInput = "e"; checkPress = true;}
        if(key[KEY_F]) {characterInput = "f"; checkPress = true;}
        if(key[KEY_G]) {characterInput = "g"; checkPress = true;}
        if(key[KEY_H]) {characterInput = "h"; checkPress = true;}
        if(key[KEY_I]) {characterInput = "i"; checkPress = true;}
        if(key[KEY_J]) {characterInput = "j"; checkPress = true;}
        if(key[KEY_K]) {characterInput = "k"; checkPress = true;}
        if(key[KEY_L]) {characterInput = "l"; checkPress = true;}
        if(key[KEY_M]) {characterInput = "m"; checkPress = true;}
        if(key[KEY_N]) {characterInput = "n"; checkPress = true;}
        if(key[KEY_O]) {characterInput = "o"; checkPress = true;}
        if(key[KEY_P]) {characterInput = "p"; checkPress = true;}
        if(key[KEY_Q]) {characterInput = "q"; checkPress = true;}
        if(key[KEY_R]) {characterInput = "r"; checkPress = true;}
        if(key[KEY_S]) {characterInput = "s"; checkPress = true;}
        if(key[KEY_T]) {characterInput = "t"; checkPress = true;}
        if(key[KEY_U]) {characterInput = "u"; checkPress = true;}
        if(key[KEY_V]) {characterInput = "v"; checkPress = true;}
        if(key[KEY_W]) {characterInput = "w"; checkPress = true;}
        if(key[KEY_Y]) {characterInput = "y"; checkPress = true;}
        if(key[KEY_0]) {characterInput = "0"; checkPress = true;}
        if(key[KEY_1]) {characterInput = "1"; checkPress = true;}
        if(key[KEY_2]) {characterInput = "2"; checkPress = true;}
        if(key[KEY_3]) {characterInput = "3"; checkPress = true;}
        if(key[KEY_4]) {characterInput = "4"; checkPress = true;}
        if(key[KEY_5]) {characterInput = "5"; checkPress = true;}
        if(key[KEY_6]) {characterInput = "6"; checkPress = true;}
        if(key[KEY_7]) {characterInput = "7"; checkPress = true;}
        if(key[KEY_8]) {characterInput = "8"; checkPress = true;}
        if(key[KEY_9]) {characterInput = "9"; checkPress = true;}

        if(key[KEY_BACKSPACE]){
            if(userOrPass == 1){
                if(this->charUserInput->size() > 0){
                    this->charUserInput->pop_back();
                }
            }else if(userOrPass == 2){
                if(this->charPasswordInput->size() > 0){
                    this->charPasswordInput->pop_back();
                }
            }
        }else if(userOrPass == 1 && checkPress && this->charUserInput->size() < this->maxLength){
            this->charUserInput->push_back(characterInput);
        }else if(userOrPass == 2 && checkPress && this->charPasswordInput->size() < this->maxLength){
            this->charPasswordInput->push_back(characterInput);
        }


        this->timePress = Timer::getTime();
    }

}
