#include <MenuInventarioState.h>
#include <allegro.h>
#include <GameState.h>
#include <GameStateManager.h>
#include <BaseGame.h>
#include <MenuInitialState.h>
#include <vector>
#include <Weapon.h>
#include <sstream>
#include <Player.h>
#include <stdio.h>
#include <string.h>
#include <Object.h>
#include <iostream>

using namespace std;

MenuInventarioState::MenuInventarioState(GameStateManager *game, Player *player)
{
    this->game = game;
    this->playerInventory = player;

    this->init();

}

void MenuInventarioState::init()
{

    this->background_image = load_bitmap("src\\Resources\\Inventario.bmp",NULL);
    this->player_image = load_bitmap("src\\Resources\\Inventory\\player_inventory.bmp",NULL);
    this->coin_gold = load_bitmap("src\\Resources\\Inventory\\coin_gold.bmp",NULL);
    this->pagination_1 = load_bitmap("src\\Resources\\Inventory\\pagination_1.bmp",NULL);
    this->pagination_2 = load_bitmap("src\\Resources\\Inventory\\pagination_2.bmp",NULL);


}

void MenuInventarioState::getEvents()
{

    if(mouse_x >= (MIDDLE_SCREEN_X + 154) && mouse_x <= (MIDDLE_SCREEN_X + 178) &&
    mouse_y >= (MIDDLE_SCREEN_Y + 124) && mouse_y <= (MIDDLE_SCREEN_Y + 148))
    {
        if(GameState::leftClick()){
            if(this->pagination == 2)
            {
                this->pagination = 1;
            }
        }
    }

    if(mouse_x >= (MIDDLE_SCREEN_X + 202) && mouse_x <= (MIDDLE_SCREEN_X + 228) &&
    mouse_y >= (MIDDLE_SCREEN_Y + 124) && mouse_y <= (MIDDLE_SCREEN_Y + 148))
    {
        if(GameState::leftClick()){
            if(this->pagination == 1)
            {
                this->pagination = 2;
            }
        }
    }

    if (GameState::keyI()) this->game->popState();

}

void MenuInventarioState::update()
{



}

void MenuInventarioState::draw()
{

    masked_blit(this->background_image, this->game->getBuffer(), 0, 0, MIDDLE_SCREEN_X, MIDDLE_SCREEN_Y - 200, 400, 400);
    //Player
    masked_blit(this->player_image, this->game->getBuffer(), 0, 0, MIDDLE_SCREEN_X + 50, MIDDLE_SCREEN_Y - 165, 73, 65);
    //Coin
    masked_blit(this->coin_gold, this->game->getBuffer(), 0,0, MIDDLE_SCREEN_X + 264, MIDDLE_SCREEN_Y + 129, 24, 18);

    this->drawPagination();
    this->drawObjects();
    this->drawCharacteristicsSelectedWeapon();
    this->drawStatsPlayer();
    this->drawMoney();

    show_mouse(this->game->getBuffer());
    blit(this->game->getBuffer(), screen, 0, 0, 0, 0, 800, 600);

}

void MenuInventarioState::drawPagination()
{
    if(pagination == 1){
        masked_blit(this->pagination_1, this->game->getBuffer(), 0,0, MIDDLE_SCREEN_X + 181, MIDDLE_SCREEN_Y + 123, 24, 22);
    }else
    {
        masked_blit(this->pagination_2, this->game->getBuffer(), 0,0, MIDDLE_SCREEN_X + 181, MIDDLE_SCREEN_Y + 123, 24, 22);
    }

}

/**
Función que printa los objetos del player en el inventario
*/
void MenuInventarioState::drawObjects()
{
    int posX = MenuInventarioState::MIDDLE_SCREEN_X + 100;
    int posXAux;
    int posY = MenuInventarioState::MIDDLE_SCREEN_Y - 226;
    int posYAux = posY;
    int i;
    if(this->pagination == 1){
        i = 0;
    }else if (this->pagination == 2){
        i = 11;
    }

    int sizeVector = this->playerInventory->getInventory()->bitmapsObjects.size();
    if(sizeVector >= i){
        for(int j = 0; j < 4; j++)
        {
            posYAux += 64;
            posXAux = posX;
            for( int a = 0; a < 3; a++)
            {
                posXAux += 70;
                BITMAP *imageToDraw = this->playerInventory->getInventory()->bitmapsObjects.at(i);
                int width = this->playerInventory->getInventory()->vectorWidth.at(i);
                //int width = this->playerInventory->getInventory()->objectList->at(i)->getWidth();
                int height = this->playerInventory->getInventory()->vectorHeight.at(i);

                masked_blit(imageToDraw, this->game->getBuffer(), 0,0, posXAux, posYAux, width, height);
                i++;
                if(i == sizeVector){
                    break;
                }

            }
            if(i == sizeVector){
                break;
            }
        }
      }


}

/**
Función que printa los stats del Player
*/
void MenuInventarioState::drawStatsPlayer()
{

    int posYAux = MIDDLE_SCREEN_Y - 50;

    textout_ex(this->game->getBuffer(), font, "Dano: ",
            MIDDLE_SCREEN_X + 25, posYAux, makecol(0, 0, 0), -1);

    std::stringstream stream;
    stream << this->playerInventory->getDamage();
    const char *damage = stream.str().c_str();

    textout_ex(this->game->getBuffer(), font, damage,
            MIDDLE_SCREEN_X + 25 + 42, posYAux, makecol(0, 0, 0), -1);


    posYAux += 14;

    textout_ex(this->game->getBuffer(), font, "Vida: ",
            MIDDLE_SCREEN_X + 25, posYAux, makecol(0, 0, 0), -1);

    std::stringstream streamHealth;
    streamHealth << this->playerInventory->getHealth();
    const char *health = streamHealth.str().c_str();

    textout_ex(this->game->getBuffer(), font, health,
            MIDDLE_SCREEN_X + 25 + 42, posYAux, makecol(0, 0, 0), -1);

}

/**
Función que printa el estado y la descripción del arma seleccionada
*/
void MenuInventarioState::drawCharacteristicsSelectedWeapon()
{

    int posX = MenuInventarioState::MIDDLE_SCREEN_X + 100;
    int posXAux;
    int posY = MenuInventarioState::MIDDLE_SCREEN_Y - 228;
    int posYAux = posY;
    int i = 0;
    int heightCuadrado = 44;
    int widthCuadrado = 50;

    /**
    Segun donde clickes te coje un objeto u otro
    */
    int sizeVector = this->playerInventory->getInventory()->bitmapsObjects.size();
    if(mouse_x >= (MIDDLE_SCREEN_X + 170) && mouse_x <= (MIDDLE_SCREEN_X + 360) &&
       mouse_y >= (MIDDLE_SCREEN_Y - 164) && mouse_y <= (MIDDLE_SCREEN_Y + 72)){
        //Siempre tendra la espada pero por un futuro cambio en ello
            if(sizeVector > 0){
                for(int j = 0; j < 4; j++)
                {
                    posYAux += 64;
                    posXAux = posX;
                    for( int a = 0; a < 3; a++)
                    {
                        posXAux += 70;

                        if(mouse_x >= posXAux && mouse_x <= posXAux + widthCuadrado &&
                            mouse_y >= posYAux && mouse_y <= posYAux + heightCuadrado){
                                if(GameState::leftClick())
                                    {
                                        this->selectedObject = i;
                                    }
                            }
                        i++;
                        if(i == sizeVector){
                            break;
                        }

                    }
                    if(i == sizeVector){
                        break;
                    }
                }
              }
       }


    int posYAux2 = MIDDLE_SCREEN_Y + 40;

    textout_ex(this->game->getBuffer(), font, "Dano: ",
            MIDDLE_SCREEN_X + 25, posYAux2, makecol(0, 0, 0), -1);

    std::stringstream stream;
    stream << this->playerInventory->getInventory()->vectorDamage.at(selectedObject);
    const char *damage = stream.str().c_str();

    textout_ex(this->game->getBuffer(), font, damage,
            MIDDLE_SCREEN_X + 25 + 42, posYAux2, makecol(0, 0, 0), -1);


    posYAux2 += 14;

    textout_ex(this->game->getBuffer(), font, "Velocidad: ",
            MIDDLE_SCREEN_X + 25, posYAux2, makecol(0, 0, 0), -1);

    std::stringstream streamAttackDistance;
    streamAttackDistance << this->playerInventory->getInventory()->vectorAttackDistance.at(selectedObject);
    const char *attackDistance = streamAttackDistance.str().c_str();

    textout_ex(this->game->getBuffer(), font, attackDistance,
            MIDDLE_SCREEN_X + 25 + 80, posYAux2, makecol(0, 0, 0), -1);


}

/**
Función que printa el dinero del Player
*/
void MenuInventarioState::drawMoney()
{


    std::stringstream x;
    x << this->playerInventory->getInventory()->getCurrentMoney();
    const char *characteristics = x.str().c_str();

        textout_ex(this->game->getBuffer(), font, characteristics,
                          MIDDLE_SCREEN_X + 292, MIDDLE_SCREEN_Y + 134, makecol(0, 0, 0), -1);

}

