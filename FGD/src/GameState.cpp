#include "GameState.h"



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
