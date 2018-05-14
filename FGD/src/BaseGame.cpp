#include <BaseGame.h>
#include <vector>
#include <DAOMap.h>
#include <allegro.h>
#include <iostream>

using namespace std;

/**
Carga el buffer sobre el que se printara todas las imagenes
y ademas instancia el DAOMap que el se encargara de rellenar las matrices que se printaran
*/
BaseGame::BaseGame(int difficult)
{
    /**
    Crea la pantalla y buffer donde printaremos el contenido
    */
    this->createBuffer();

    DAOMap managerMaps = DAOMap(difficult);
    this->activeMap = managerMaps.getMap(0);
}

void BaseGame::chargeGame()
{
    /**
    Cargamos la matriz de animaciones que tendra el player y instanciamos al jugador
    */
    BITMAP*** matrixAnimationsPlayer;
    matrixAnimationsPlayer = new BITMAP**[1];
    for(int i = 0; i < 1; i++){
        matrixAnimationsPlayer[i] = new BITMAP*[1];
    }
    BITMAP *bitmapPlayer = load_bitmap("src\\Resources\\Player_Front_With_Sword.bmp",NULL);
    matrixAnimationsPlayer[0][0] = bitmapPlayer; //*bitmapPlayer

    this->player = Player(matrixAnimationsPlayer, 100, 20, 10, 20, 50, 50, 50, 33);


}

void BaseGame::update()
{
    //this->chargeGame();
//if el mapa es 1
    /**
    Movimiento player
    */
    this->player.keyboard();

    /**
     * check colisiones
     */
     //colision con enemigos
    for (int i = 0; i < this->activeMap.getVectorEnemies().size(); ++i) {
        if (this->player.collision(this->activeMap.getVectorEnemies().at(i))){
            this->player.setX(this->player.getAX()) ;
            this->player.setY(this->player.getAY()) ;
        }
    }
    //colision enemigos con enemigos
    for (int i = 0; i < this->activeMap.getVectorEnemies().size(); ++i) {
        for (int j = 0; j < this->activeMap.getVectorEnemies().size(); ++j) {
            if (i!=j){
                if (this->activeMap.getVectorEnemies().at(i)->collision(this->activeMap.getVectorEnemies().at(j))){
                    cout << "ENEMY col detect" << i;
                    this->activeMap.getVectorEnemies().at(i)->setX(this->activeMap.getVectorEnemies().at(i)->getAX());
                    this->activeMap.getVectorEnemies().at(i)->setY(this->activeMap.getVectorEnemies().at(i)->getAY());


                }
            }
        }
        if (this->activeMap.getVectorEnemies().at(i)->collision(&this->player)){
            cout << "ENEMY col detect" << i;
            this->activeMap.getVectorEnemies().at(i)->setX(this->activeMap.getVectorEnemies().at(i)->getAX());
            this->activeMap.getVectorEnemies().at(i)->setY(this->activeMap.getVectorEnemies().at(i)->getAY());


        }
    }



    /**
     * mostrar en pantalla
     */
    this->printGame();


}

/**
Printa todo el contenido de la pantalla (Enemigos, Ambiente, Player)
*/
void BaseGame::printGame()
{
    Drawable **matrix = this->activeMap.getAmbientMatrix();
    int lengthMatrix = this->activeMap.getQuantElementsOfAmbient();


    for(int i = 0; i < lengthMatrix; i++){
        for(int j = 0; j < lengthMatrix; j++){

            BITMAP *bitmapAmbient = matrix[i][j].getBitmapAmbient();

            if(i == 0 && j == 0){
                stretch_blit(bitmapAmbient, this->buffer, 0, 0, bitmapAmbient->w, bitmapAmbient->h, 0, 0, this->SIZE_WINDOW_X, this->SIZE_WINDOW_Y);
            }
            else{
                matrix[i][j].draw(this->buffer);
            }
        }
    }

    /**
    Printa todo el vector de Enemigos en pantalla
    */
    vector<Enemy*> vectorE = this->activeMap.getVectorEnemies();
    for (int i = 0; i < vectorE.size(); i++){
            //Update de enemigo para luego printarlo
        vectorE.at(i)->update();
        vectorE.at(i)->draw(this->buffer);
    }


    this->player.draw(this->buffer);

    blit(this->buffer, screen, 0, 0, 0, 0, 800, 600);



}

void BaseGame::createBuffer()
{
    set_color_depth(24);

    set_gfx_mode(GFX_AUTODETECT_WINDOWED, SIZE_WINDOW_X, SIZE_WINDOW_Y, 0, 0);

    this->buffer = create_bitmap(SIZE_WINDOW_X, SIZE_WINDOW_Y);

    clear_to_color(buffer, 0xaaaaaa);
}
