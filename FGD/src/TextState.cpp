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

    this->checkFirstText = false;
    this->nextText = 1;
    this->secondText = 0;
    this->checkSecondText = false;
    this->checkNextText = false;
    this->vectorBocadillo1Mapa.push_back("Pressiona el espai");
    this->vectorBocadillo1Mapa.push_back("Primer texto");
    this->vectorBocadillo1Mapa.push_back("Segundo texto");
    this->vectorBocadillo1Mapa.push_back("Tercer texto");
    this->vectorBocadillo1Mapa.push_back("Cuarto texto");


    this->bocadilloMap1 = load_bitmap("src\\Resources\\TextState\\bocadillo_texto.bmp",NULL);

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


    /**
    Si le pasan un 0 quiere decir que es el primer mapa el que esta llamando a la clase
    */
    if(this->callState == 0){
        masked_blit(this->bocadilloMap1, this->game->getBuffer(), 0, 0, 80, 266, 150, 113);
        this->managerMusic.soundMap1();
        this->animationBocadilloMap1();
    }

    blit(this->game->getBuffer(), screen, 0, 0, 0, 0, 800, 600);

}



void TextState::animationBocadilloMap1()
{

    if(!this->checkFirstText){
        textout_ex(this->game->getBuffer(), font, this->vectorBocadillo1Mapa.at(0),
                          90, 280, makecol(0, 0, 0), -1);

    }
    if(this->checkNextText){
        textout_ex(this->game->getBuffer(), font, this->vectorBocadillo1Mapa.at(nextText),
            90, 280, makecol(0, 0, 0), -1);
    }
    if(this->checkSecondText){
        textout_ex(this->game->getBuffer(), font, this->vectorBocadillo1Mapa.at(secondText),
                  90, 290, makecol(0, 0, 0), -1);
    }

    if(GameState::spacePress()){
            if(this->nextText >= this->vectorBocadillo1Mapa.size()){
                        this->game->popState();
            }
                if(!this->checkNextText){
                    this->secondText+=2;
                    this->checkNextText = true;
                    this->checkSecondText = false;

                    //El primer espacio ya borrara el primer texto
                    this->checkFirstText = true;
                }else if (this->checkNextText && !this->checkSecondText) {
                    if(this->secondText >= this->vectorBocadillo1Mapa.size()){
                            this->managerMusic.stopSoundMap1();
                            this->game->popState();
                    }
                    this->checkSecondText = true;

                }else{
                    this->nextText+=2;
                    this->checkNextText = false;
                    this->checkSecondText = false;
                }

    }


}
