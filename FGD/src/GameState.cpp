#include "GameState.h"
#include <Timer.h>


int GameState::difficulty = 1;
bool GameState::sound = true;
int GameState::timeClicked = 0;

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
