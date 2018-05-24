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
    this->player_image = load_bitmap("src\\Resources\\player_inventory.bmp",NULL);
    this->coin_gold = load_bitmap("src\\Resources\\Inventory\\coin_gold.bmp",NULL);
    this->pagination_1 = load_bitmap("src\\Resources\\Inventory\\pagination_1.bmp",NULL);
    this->pagination_2 = load_bitmap("src\\Resources\\Inventory\\pagination_2.bmp",NULL);

    install_mouse();

    show_mouse(screen);

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
    masked_blit(this->player_image, this->game->getBuffer(), 0, 0, MIDDLE_SCREEN_X + 50, MIDDLE_SCREEN_Y - 165, 52, 100);
    //Coin
    masked_blit(this->coin_gold, this->game->getBuffer(), 0,0, MIDDLE_SCREEN_X + 264, MIDDLE_SCREEN_Y + 129, 24, 18);

    this->drawPagination();
    this->drawObjects();
    this->drawCharacteristicsSelectedWeapon();
    this->drawStatsPlayer();
    this->drawMoney();

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
    int i = 0;

    int sizeVector = this->playerInventory->getInventory()->getObjectListPtr()->size();
    if(sizeVector > 0){
        for(int j = 0; j < 4; j++)
        {
            posYAux += 64;
            posXAux = posX;
            for( int a = 0; a < 3; a++)
            {
                posXAux += 70;
                BITMAP *imageToDraw = this->playerInventory->getInventory()->bitmapsObjects.at(i);
                int width = this->playerInventory->getInventory()->getObjectListPtr()->at(i)->getWidth();
                int height = this->playerInventory->getInventory()->getObjectListPtr()->at(i)->getHeight();

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

    /*std::stringstream stream;
    stream << this->playerInventory->getDamage();
    const char *damage = stream.str().c_str();


   vector<char*>* characteristics = new vector<char *>();
    characteristics->push_back("Dano: "  );
    int lenghtDamage = 20;

    char* conversion = strdup(damage);
    characteristics->push_back(conversion);

    characteristics->push_back("Velocidad: ");
    int posYAux = MIDDLE_SCREEN_Y - 50;

    int size1 = characteristics->size();

    //strcpy(characteristics->at(0), damage);

    for(int i = 0; i < characteristics->size(); i++){
        if(i%2 == 0){
            textout_ex(this->game->getBuffer(), font, characteristics->at(i),
                            MIDDLE_SCREEN_X + 25, posYAux, makecol(0, 0, 0), -1);
        }else{
            textout_ex(this->game->getBuffer(), font, characteristics->at(i),
                            MIDDLE_SCREEN_X + 25 + lenghtDamage, posYAux, makecol(0, 0, 0), -1);
        }

        if(i%2 != 0){
            posYAux += 14;
        }
    }*/


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

    vector<char*> characteristics;
    characteristics.push_back("Dano: " );
    characteristics.push_back("Velocidad: ");
    int posYAux = MIDDLE_SCREEN_Y + 40;

    for(int i = 0; i < characteristics.size(); i++){
        textout_ex(this->game->getBuffer(), font, characteristics.at(i),
                          MIDDLE_SCREEN_X + 25, posYAux, makecol(0, 0, 0), -1);
        posYAux += 14;
    }
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

