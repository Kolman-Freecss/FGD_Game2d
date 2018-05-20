#include <BaseGame.h>
#include <vector>
#include <DAOMap.h>
#include <allegro.h>
#include <iostream>
#include <GameState.h>
#include <GameStateManager.h>
#include <MenuEscState.h>
#include <MenuInventarioState.h>

using namespace std;

/**
Carga el buffer sobre el que se printara todas las imagenes
y ademas instancia el DAOMap que el se encargara de rellenar las matrices que se printaran
*/
BaseGame::BaseGame(int difficult, GameStateManager *game)
{
    this->game = game;
    this->gameDificulty = difficult;

    this->init();

}


void BaseGame::init()
{

    DAOMap managerMaps = DAOMap(this->gameDificulty);
    this->activeMap = managerMaps.getMap(0);

    /**
    Cargamos la matriz de animaciones que tendra el player y instanciamos al jugador
    */
    BITMAP*** matrixAnimationsPlayer;
    matrixAnimationsPlayer = new BITMAP**[1];
    for(int i = 0; i < 12; i++){
        matrixAnimationsPlayer[i] = new BITMAP*[4];
    }

    //BITMAP *bitmapPlayer = load_bitmap("src\\Resources\\Player_Front_With_Sword.bmp",NULL);
    //matrixAnimationsPlayer[0][0] = bitmapPlayer; //*bitmapPlayer

    //TODO QUITAR
    //WALK
    matrixAnimationsPlayer[0][0] = load_bitmap("src\\Resources\\SKELETON1\\SWU1.bmp",NULL);
    matrixAnimationsPlayer[0][1] = load_bitmap("src\\Resources\\SKELETON1\\SWU2.bmp",NULL);
    matrixAnimationsPlayer[0][2] = load_bitmap("src\\Resources\\SKELETON1\\SWU1.bmp",NULL);
    matrixAnimationsPlayer[0][3] = load_bitmap("src\\Resources\\SKELETON1\\SWU4.bmp",NULL);

    matrixAnimationsPlayer[1][0] = load_bitmap("src\\Resources\\SKELETON1\\SWR1.bmp",NULL);
    matrixAnimationsPlayer[1][1] = load_bitmap("src\\Resources\\SKELETON1\\SWR2.bmp",NULL);
    matrixAnimationsPlayer[1][2] = load_bitmap("src\\Resources\\SKELETON1\\SWR1.bmp",NULL);
    matrixAnimationsPlayer[1][3] = load_bitmap("src\\Resources\\SKELETON1\\SWR4.bmp",NULL);

    matrixAnimationsPlayer[2][0] = load_bitmap("src\\Resources\\SKELETON1\\SWD1.bmp",NULL);
    matrixAnimationsPlayer[2][1] = load_bitmap("src\\Resources\\SKELETON1\\SWD2.bmp",NULL);
    matrixAnimationsPlayer[2][2] = load_bitmap("src\\Resources\\SKELETON1\\SWD1.bmp",NULL);
    matrixAnimationsPlayer[2][3] = load_bitmap("src\\Resources\\SKELETON1\\SWD4.bmp",NULL);

    matrixAnimationsPlayer[3][0] = load_bitmap("src\\Resources\\SKELETON1\\SWL1.bmp",NULL);
    matrixAnimationsPlayer[3][1] = load_bitmap("src\\Resources\\SKELETON1\\SWL2.bmp",NULL);
    matrixAnimationsPlayer[3][2] = load_bitmap("src\\Resources\\SKELETON1\\SWL1.bmp",NULL);
    matrixAnimationsPlayer[3][3] = load_bitmap("src\\Resources\\SKELETON1\\SWL4.bmp",NULL);

    //ATTACK
    matrixAnimationsPlayer[4][0] = load_bitmap("src\\Resources\\SKELETON1\\SAU1.bmp",NULL);
    matrixAnimationsPlayer[4][1] = load_bitmap("src\\Resources\\SKELETON1\\SAU2.bmp",NULL);
    matrixAnimationsPlayer[4][2] = load_bitmap("src\\Resources\\SKELETON1\\SAU3.bmp",NULL);
    matrixAnimationsPlayer[4][3] = load_bitmap("src\\Resources\\SKELETON1\\SAU4.bmp",NULL);

    matrixAnimationsPlayer[5][0] = load_bitmap("src\\Resources\\SKELETON1\\SAR1.bmp",NULL);
    matrixAnimationsPlayer[5][1] = load_bitmap("src\\Resources\\SKELETON1\\SAR2.bmp",NULL);
    matrixAnimationsPlayer[5][2] = load_bitmap("src\\Resources\\SKELETON1\\SAR3.bmp",NULL);
    matrixAnimationsPlayer[5][3] = load_bitmap("src\\Resources\\SKELETON1\\SAR4.bmp",NULL);

    matrixAnimationsPlayer[6][0] = load_bitmap("src\\Resources\\SKELETON1\\SAD1.bmp",NULL);
    matrixAnimationsPlayer[6][1] = load_bitmap("src\\Resources\\SKELETON1\\SAD2.bmp",NULL);
    matrixAnimationsPlayer[6][2] = load_bitmap("src\\Resources\\SKELETON1\\SAD3.bmp",NULL);
    matrixAnimationsPlayer[6][3] = load_bitmap("src\\Resources\\SKELETON1\\SAD4.bmp",NULL);

    matrixAnimationsPlayer[7][0] = load_bitmap("src\\Resources\\SKELETON1\\SAL1.bmp",NULL);
    matrixAnimationsPlayer[7][1] = load_bitmap("src\\Resources\\SKELETON1\\SAL2.bmp",NULL);
    matrixAnimationsPlayer[7][2] = load_bitmap("src\\Resources\\SKELETON1\\SAL3.bmp",NULL);
    matrixAnimationsPlayer[7][3] = load_bitmap("src\\Resources\\SKELETON1\\SAL4.bmp",NULL);

    //DIE
    matrixAnimationsPlayer[8][0] = load_bitmap("src\\Resources\\SKELETON1\\SDU1.bmp",NULL);
    matrixAnimationsPlayer[8][1] = load_bitmap("src\\Resources\\SKELETON1\\SDU2.bmp",NULL);
    matrixAnimationsPlayer[8][2] = load_bitmap("src\\Resources\\SKELETON1\\SDU3.bmp",NULL);
    matrixAnimationsPlayer[8][3] = load_bitmap("src\\Resources\\SKELETON1\\SDU4.bmp",NULL);

    matrixAnimationsPlayer[9][0] = load_bitmap("src\\Resources\\SKELETON1\\SDR1.bmp",NULL);
    matrixAnimationsPlayer[9][1] = load_bitmap("src\\Resources\\SKELETON1\\SDR2.bmp",NULL);
    matrixAnimationsPlayer[9][2] = load_bitmap("src\\Resources\\SKELETON1\\SDR3.bmp",NULL);
    matrixAnimationsPlayer[9][3] = load_bitmap("src\\Resources\\SKELETON1\\SDR4.bmp",NULL);

    matrixAnimationsPlayer[10][0] = load_bitmap("src\\Resources\\SKELETON1\\SDD1.bmp",NULL);
    matrixAnimationsPlayer[10][1] = load_bitmap("src\\Resources\\SKELETON1\\SDD2.bmp",NULL);
    matrixAnimationsPlayer[10][2] = load_bitmap("src\\Resources\\SKELETON1\\SDD3.bmp",NULL);
    matrixAnimationsPlayer[10][3] = load_bitmap("src\\Resources\\SKELETON1\\SDD4.bmp",NULL);

    matrixAnimationsPlayer[11][0] = load_bitmap("src\\Resources\\SKELETON1\\SDL1.bmp",NULL);
    matrixAnimationsPlayer[11][1] = load_bitmap("src\\Resources\\SKELETON1\\SDL2.bmp",NULL);
    matrixAnimationsPlayer[11][2] = load_bitmap("src\\Resources\\SKELETON1\\SDL1.bmp",NULL);
    matrixAnimationsPlayer[11][3] = load_bitmap("src\\Resources\\SKELETON1\\SDL4.bmp",NULL);

    //FIN QUITAR


    //player50x33
    this->player = Player(matrixAnimationsPlayer, 100, 20, 2, 20, 50, 50, 64, 75);
    //TODO
    this->player.setSelectedWeapon(new Weapon(100,1));


}

void BaseGame::update()
{
    /**
    * MOVIMIENTO PLAYER
    */
    this->player.keyboard();

    /**
    * MOVIMIENTO ENEMIGOS
    */
    for (int i=0 ; i < this->activeMap.getVectorEnemies().size();i++){
        this->activeMap.getVectorEnemies().at(i)->update();
    }

    /**
     * check colisiones
     */
    this->collisionCheck();


    //TODO CAMBIAR A FUNCION
    // character attacking
    if (player.isAttacking()) {


        if (!player.isAttackChecked()) {


            for (int i = 0; i < this->activeMap.getVectorEnemies().size(); ++i) {
                if (player.attackCollision(this->activeMap.getVectorEnemies().at(i), player.getSelectedWeapon(),
                                           player.getDirection())) {
                    //HIT A ENEMIGO
                    //TODO CONTROL DAÑO A ENEMIGO
                    this->activeMap.getVectorEnemies().at(i)->wounded(&this->player);
                    cout << "HP" << this->activeMap.getVectorEnemies().at(i)->getHealth() << endl;
                    cout << "SHIELD" << this->activeMap.getVectorEnemies().at(i)->getShield() << endl;
                    cout << "ALIVE" << this->activeMap.getVectorEnemies().at(i)->isIsAlive() << endl;
                }
            }
            player.setAttackChecked(true);
        }
        player.attack();
    }
    //FIN character attacking


}

/**
Printa todo el contenido de la pantalla (Enemigos, Ambiente, Player)
*/
void BaseGame::draw()
{
    Drawable **matrix = this->activeMap.getAmbientMatrix();
    int lengthMatrix = this->activeMap.getQuantElementsOfAmbient();

    for(int i = 0; i < lengthMatrix; i++){
        for(int j = 0; j < 2; j++){

            BITMAP *bitmapAmbient = matrix[i][j].getBitmapAmbient();

            if(i == 0 && j == 0){
                stretch_blit(bitmapAmbient, this->game->getBuffer(), 0, 0, bitmapAmbient->w, bitmapAmbient->h, 0, 0, GameStateManager::SIZE_WINDOW_X, GameStateManager::SIZE_WINDOW_Y);
            }
            else{
                matrix[i][j].drawAmbient(this->game->getBuffer());
            }
        }
    }

    /**
    Printa todo el vector de Enemigos en pantalla
    */
    vector<Enemy*> vectorE = this->activeMap.getVectorEnemies();
    for (int i = 0; i < vectorE.size(); i++){
            //Update de enemigo para luego printarlo

        vectorE.at(i)->draw(this->game->getBuffer());
    }


    this->player.draw(this->game->getBuffer());

    blit(this->game->getBuffer(), screen, 0, 0, 0, 0, 800, 600);



}


void BaseGame::getEvents()
{

    if (key[KEY_I]) this->game->pushState(new MenuInventarioState(this->game));
    if ( key[KEY_ESC] ) this->game->pushState(new MenuEscState(game));

}

void BaseGame::collisionCheck() {
    colPlayerWithEnemies();
    colPlayerWithAmbient();
    colEnemies();
    colEnemiesWithAmbient();
}

void BaseGame::colPlayerWithEnemies() {
    for (int i = 0; i < this->activeMap.getVectorEnemies().size(); ++i) {
        if (this->player.collision(this->activeMap.getVectorEnemies().at(i))){
            //TODO
            this->player.setX(this->player.getAX()) ;
            this->player.setY(this->player.getAY()) ;
        }
    }
}

void BaseGame::colPlayerWithAmbient(){
    //TODO CAMBIAR MAS ADELANTE

    for (int i=0;i<1;i++){
        for (int j=0;j<2;j++) {
            if (i!=0 || j!=0) {
                if (player.collision(&this->activeMap.getAmbientMatrix()[i][j])){
                    //TODO
                    this->player.setX(this->player.getAX());
                    this->player.setY(this->player.getAY());

                }
            }
        }
    }
}


void BaseGame::colEnemies(){
    for (int i = 0; i < this->activeMap.getVectorEnemies().size(); ++i) {
        for (int j = 0; j < this->activeMap.getVectorEnemies().size(); ++j) {
            if (i!=j){
                if (this->activeMap.getVectorEnemies().at(i)->collision(this->activeMap.getVectorEnemies().at(j))){
                    //TODO
                    this->activeMap.getVectorEnemies().at(i)->setX(this->activeMap.getVectorEnemies().at(i)->getAX());
                    this->activeMap.getVectorEnemies().at(i)->setY(this->activeMap.getVectorEnemies().at(i)->getAY());
                }
            }
        }
        //col enemy with player
        if (this->activeMap.getVectorEnemies().at(i)->collision(&this->player)){
            //TODO
            this->activeMap.getVectorEnemies().at(i)->setX(this->activeMap.getVectorEnemies().at(i)->getAX());
            this->activeMap.getVectorEnemies().at(i)->setY(this->activeMap.getVectorEnemies().at(i)->getAY());
        }
    }

}
void BaseGame::colEnemiesWithAmbient(){
    for (int p = 0; p < this->activeMap.getVectorEnemies().size(); ++p) {
        for (int i = 0; i < 1; i++) {
            for (int j = 0; j < 2; j++) {
                if (i != 0 || j != 0) {
                    if (this->activeMap.getVectorEnemies().at(p)->collision(&this->activeMap.getAmbientMatrix()[i][j])) {
                        //TODO CAMBIAR FUNCION VOLVER ATRAS DE CHARACTER
                        this->activeMap.getVectorEnemies().at(p)->setX(this->activeMap.getVectorEnemies().at(p)->getAX());
                        this->activeMap.getVectorEnemies().at(p)->setY(this->activeMap.getVectorEnemies().at(p)->getAY());
                    } else {

                    }
                }

            }
        }
    }
}
