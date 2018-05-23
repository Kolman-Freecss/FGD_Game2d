#include <MenuInventarioState.h>
#include <allegro.h>
#include <GameState.h>
#include <GameStateManager.h>
#include <BaseGame.h>
#include <MenuInitialState.h>
#include <vector>

using namespace std;

MenuInventarioState::MenuInventarioState(GameStateManager *game)
{
    this->game = game;

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
    //this->drawCharacteristicsSelectedWeapon();
    //this->drawMoney();

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

}

/**
Función que printa los stats del Player
*/
void MenuInventarioState::drawStatsPlayer()
{

   /* char *characteristics[] = {"Damage: \n",
                                "Speed: Probando",
                                };*/


    /*textout_right_ex(screen, font, "hola probando",
                       MIDDLE_SCREEN_X + 25, MIDDLE_SCREEN_Y + 40, makecol(0, 255, 255), -1);*/
}

/**
Función que printa el estado y la descripción del arma seleccionada
*/
void MenuInventarioState::drawCharacteristicsSelectedWeapon()
{

    vector<char*> characteristics;
    characteristics.push_back("Hola \n");
    characteristics.push_back("Probando \n");

    for(int i = 0; i < characteristics.size(); i++){
        textout_right_ex(screen, font, characteristics.at(i),
            MIDDLE_SCREEN_X + 25, MIDDLE_SCREEN_Y + 40, makecol(0, 255, 255), -1);
    }
}

/**
Función que printa el dinero del Player
*/
void MenuInventarioState::drawMoney()
{

    /*char *characteristics[] = {"Damage: \n",
                                "Speed: Probando",
                                };*/
    //char *characteristics = this->player.getInventory().getCurrentMoney();

//Justificarlo  a la izquierda
    /*textout_justify(screen, font, "dinero",
                       MIDDLE_SCREEN_X + 340, MIDDLE_SCREEN_Y + 134, makecol(0, 255, 255), -1);*/
}

