#include <TextState.h>
#include <allegro.h>
#include <GameState.h>
#include <GameStateManager.h>
#include <BaseGame.h>
#include <MenuOptionsState.h>
#include <MenuInitialState.h>
#include <iostream>

using namespace std;

TextState::TextState(GameStateManager *game, int callState)
{
    this->game = game;
    //El estado que tendra esta clase al pasarse segun que integer
    this->callState = callState;

    this->init();

}

void TextState::init()
{

    this->vectorBocadillo1Mapa.push_back("Hola juego");
    this->nextText = 0;
    this->vectorBocadillo1Mapa.push_back("Segundo texto");


    //this->bocadilloMap1 = load_bitmap("src\\Resources\\WinState\\background_win.bmp",NULL);

    install_mouse();

    //set_mouse_sprite(mouse);
    show_mouse(screen);

}

void TextState::getEvents()
{




}

void TextState::update()
{







}

void TextState::draw()
{



    if(this->callState == 0){
        this->animationBocadilloMap1();
    }

    blit(this->game->getBuffer(), screen, 0, 0, 0, 0, 800, 600);

}



void TextState::animationBocadilloMap1()
{
    //Para que no se salga del bocadillo de texto




    //for(int i = 0; i < this->vectorBocadillo1Mapa->size(); i++){


    textout_ex(this->game->getBuffer(), font, this->vectorBocadillo1Mapa.at(nextText),
                      200, 400, makecol(0, 0, 0), -1);

    if(GameState::spacePress()){
            this->nextText++;
            if(this->nextText >= this->vectorBocadillo1Mapa.size()){
                this->game->popState();
            }
    }

    //}


    /*int posYAux = MIDDLE_SCREEN_Y - 50;

    textout_ex(this->game->getBuffer(), font, "Hola este es el juego ",
            MIDDLE_SCREEN_X + 25, posYAux, makecol(0, 0, 0), -1);

    std::stringstream stream;
    stream << this->playerInventory->getDamage();
    const char *damage = stream.str().c_str();

    textout_ex(this->game->getBuffer(), font, damage,
            MIDDLE_SCREEN_X + 25 + 42, posYAux, makecol(0, 0, 0), -1);


    posYAux += 14;*/


}
