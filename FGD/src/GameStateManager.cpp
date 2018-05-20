#include <GameStateManager.h>
#include <allegro.h>
#include <GameState.h>
#include <BaseGame.h>
#include <iostream>
#include <Timer.h>

using namespace std;

GameStateManager::GameStateManager()
{

    this->createBuffer();

}

GameStateManager::~GameStateManager()
{
    while(!states.empty()){
        popState();
    }
}

void GameStateManager::pushState(GameState* state)
{

    states.push_back(state);


}


void GameStateManager::popState()
{
    //states.back(); //sure?
    //delete states.back();
    states.pop_back();

}

GameState* GameStateManager::getCurrentState()
{
    if(states.empty()){
        return 0;
    }else{
        return states.back();
    }
}

void GameStateManager::gameLoop()
{

    while(this->isRunning()){
        Timer::timerTIC();

        /**
        Si no hay ningun estado en el vector de estados directamente se salta las acciones que siguen
        y vuelve a ejecutar el bucle
        */
        /*if(this->getCurrentState() == nullptr){
            continue;
        }*/

        this->getCurrentState()->getEvents();

        this->getCurrentState()->update();

        //clear_bitmap(this->buffer);

        this->getCurrentState()->draw();

        rest(10);

        // tecla de salida
        //if ( key[KEY_ESC] ) this->runLoop = false;

    }

}


void GameStateManager::createBuffer()
{
    /**
    Iniciamos el allegro
    */
    allegro_init();
    install_keyboard();


    /**
    Config pantalla
    */
    set_color_depth(24);

    set_gfx_mode(GFX_AUTODETECT_WINDOWED, SIZE_WINDOW_X, SIZE_WINDOW_Y, 0, 0);

    this->buffer = create_bitmap(SIZE_WINDOW_X, SIZE_WINDOW_Y);

    clear_to_color(buffer, 0xaaaaaa);
}



////////////////////////// GET & SETTERS ////////////////////////////////

bool GameStateManager::isRunning()
{
    return this->runLoop;
}

BITMAP* GameStateManager::getBuffer()
{
    return this->buffer;
}

void GameStateManager::setRunning(bool runLoop)
{
    this->runLoop = runLoop;
}
