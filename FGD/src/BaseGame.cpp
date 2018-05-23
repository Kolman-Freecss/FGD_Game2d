#include <BaseGame.h>
#include <vector>
#include <DAOMap.h>
#include <allegro.h>
#include <iostream>
#include <GameState.h>
#include <GameStateManager.h>
#include <MenuEscState.h>
#include <MenuInventarioState.h>
#include <Music.h>
#include <Inventory.h>

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


    managerMaps = DAOMap(this->gameDificulty);
    this->activeMap = managerMaps.getMap(0);

    /**
    Cargamos la matriz de animaciones que tendra el player y instanciamos al jugador
    */
    BITMAP*** matrixAnimationsPlayer;
    matrixAnimationsPlayer = new BITMAP**[8];
    for(int i = 0; i < 8; i++){
        matrixAnimationsPlayer[i] = new BITMAP*[4];
    }

    //BITMAP *bitmapPlayer = load_bitmap("src\\Resources\\Player_Front_With_Sword.bmp",NULL);
    //matrixAnimationsPlayer[0][0] = bitmapPlayer; //*bitmapPlayer

    //TODO QUITAR
    //WALK
    matrixAnimationsPlayer[0][0] = load_bitmap("src\\Resources\\PLAYER1\\PWU1.bmp",NULL);
    matrixAnimationsPlayer[0][1] = load_bitmap("src\\Resources\\PLAYER1\\PWU2.bmp",NULL);
    matrixAnimationsPlayer[0][2] = load_bitmap("src\\Resources\\PLAYER1\\PWU1.bmp",NULL);
    matrixAnimationsPlayer[0][3] = load_bitmap("src\\Resources\\PLAYER1\\PWU4.bmp",NULL);

    matrixAnimationsPlayer[1][0] = load_bitmap("src\\Resources\\PLAYER1\\PWR1.bmp",NULL);
    matrixAnimationsPlayer[1][1] = load_bitmap("src\\Resources\\PLAYER1\\PWR2.bmp",NULL);
    matrixAnimationsPlayer[1][2] = load_bitmap("src\\Resources\\PLAYER1\\PWR1.bmp",NULL);
    matrixAnimationsPlayer[1][3] = load_bitmap("src\\Resources\\PLAYER1\\PWR4.bmp",NULL);

    matrixAnimationsPlayer[2][0] = load_bitmap("src\\Resources\\PLAYER1\\PWD1.bmp",NULL);
    matrixAnimationsPlayer[2][1] = load_bitmap("src\\Resources\\PLAYER1\\PWD2.bmp",NULL);
    matrixAnimationsPlayer[2][2] = load_bitmap("src\\Resources\\PLAYER1\\PWD1.bmp",NULL);
    matrixAnimationsPlayer[2][3] = load_bitmap("src\\Resources\\PLAYER1\\PWD4.bmp",NULL);

    matrixAnimationsPlayer[3][0] = load_bitmap("src\\Resources\\PLAYER1\\PWL1.bmp",NULL);
    matrixAnimationsPlayer[3][1] = load_bitmap("src\\Resources\\PLAYER1\\PWL2.bmp",NULL);
    matrixAnimationsPlayer[3][2] = load_bitmap("src\\Resources\\PLAYER1\\PWL1.bmp",NULL);
    matrixAnimationsPlayer[3][3] = load_bitmap("src\\Resources\\PLAYER1\\PWL4.bmp",NULL);

    //ATTACK
    matrixAnimationsPlayer[4][0] = load_bitmap("src\\Resources\\PLAYER1\\PAU1.bmp",NULL);
    matrixAnimationsPlayer[4][1] = load_bitmap("src\\Resources\\PLAYER1\\PAU2.bmp",NULL);
    matrixAnimationsPlayer[4][2] = load_bitmap("src\\Resources\\PLAYER1\\PAU3.bmp",NULL);
    matrixAnimationsPlayer[4][3] = load_bitmap("src\\Resources\\PLAYER1\\PAU4.bmp",NULL);

    matrixAnimationsPlayer[5][0] = load_bitmap("src\\Resources\\PLAYER1\\PAR1.bmp",NULL);
    matrixAnimationsPlayer[5][1] = load_bitmap("src\\Resources\\PLAYER1\\PAR2.bmp",NULL);
    matrixAnimationsPlayer[5][2] = load_bitmap("src\\Resources\\PLAYER1\\PAR3.bmp",NULL);
    matrixAnimationsPlayer[5][3] = load_bitmap("src\\Resources\\PLAYER1\\PAR4.bmp",NULL);

    matrixAnimationsPlayer[6][0] = load_bitmap("src\\Resources\\PLAYER1\\PAD1.bmp",NULL);
    matrixAnimationsPlayer[6][1] = load_bitmap("src\\Resources\\PLAYER1\\PAD2.bmp",NULL);
    matrixAnimationsPlayer[6][2] = load_bitmap("src\\Resources\\PLAYER1\\PAD3.bmp",NULL);
    matrixAnimationsPlayer[6][3] = load_bitmap("src\\Resources\\PLAYER1\\PAD4.bmp",NULL);

    matrixAnimationsPlayer[7][0] = load_bitmap("src\\Resources\\PLAYER1\\PAL1.bmp",NULL);
    matrixAnimationsPlayer[7][1] = load_bitmap("src\\Resources\\PLAYER1\\PAL2.bmp",NULL);
    matrixAnimationsPlayer[7][2] = load_bitmap("src\\Resources\\PLAYER1\\PAL3.bmp",NULL);
    matrixAnimationsPlayer[7][3] = load_bitmap("src\\Resources\\PLAYER1\\PAL4.bmp",NULL);
    //FIN QUITAR


    //player50x33
    //PLAYER FINAL
    this->player = Player(matrixAnimationsPlayer, 100, 20, 2, 20, 50, 50, 65, 73);
    //TODO
    BITMAP *swordOfPlayer = load_bitmap("src\\Resources\\Inventory\\sword.bmp",NULL);
    Weapon *weaponOfPlayer = new Weapon(100,1, swordOfPlayer, 46, 40);
    this->player.setSelectedWeapon(weaponOfPlayer);

    /**TEEEEEST**/
    int sizeTest = this->player.getInventory()->getObjectList().size();
    this->player.getInventory()->getObjectList().push_back(weaponOfPlayer);
    int sizeTest2 = this->player.getInventory()->getObjectList().size();
    this->player.getInventory()->getObjectList().push_back(new Object());
    int sizeTest3 = this->player.getInventory()->getObjectList().size();
    Inventory *aux = this->player.getInventory();
    aux->getObjectList().push_back(new Object());
    int sizeTest4 = aux->getObjectList().size();
    int sizeTest5 = this->player.getInventory()->getObjectList().size();

    if(!this->managerMusic.getMap1IsPlaying()){
        if(this->getSound()){
            managerMusic.soundMap1();
        }
    }



}

void BaseGame::getEvents()
{

    if (GameState::keyI()){
            this->game->pushState(new MenuInventarioState(this->game));
    }
    if ( key[KEY_ESC] ) this->game->pushState(new MenuEscState(game));

    this->nextMap();

}

void BaseGame::update()
{
    /**
    * MOVIMIENTO PLAYER
    */
    this->player.keyboard();

    //this->artificialIntelligence();

    /**
    * MOVIMIENTO ENEMIGOS
    */


    this->artificialIntelligence();

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
                    cout << "HP " << this->activeMap.getVectorEnemies().at(i)->getHealth() << endl;
                    cout << "SHIELD " << this->activeMap.getVectorEnemies().at(i)->getShield() << endl;
                    cout << "ALIVE " << this->activeMap.getVectorEnemies().at(i)->isIsAlive() << endl;
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

        switch(i){

            /**
            Background y otros elementos
            */
            case 0: {
                        BITMAP *bitmapAmbient = matrix[i][0].getBitmapAmbient();
                        stretch_blit(bitmapAmbient, this->game->getBuffer(), 0, 0, bitmapAmbient->w, bitmapAmbient->h, 0, 0, GameStateManager::SIZE_WINDOW_X, GameStateManager::SIZE_WINDOW_Y);
                        break;
                    }
            /**
            Arboles
            */
            case 1: {
                        for(int j = 0; j < this->activeMap.getQuantTrees(); j++){
                            matrix[i][j].drawAmbient(this->game->getBuffer());
                        }
                        break;
                    }

            /**
            Casas
            */
            case 2: {
                        for(int j = 0; j < this->activeMap.getQuantHouses(); j++){
                            matrix[i][j].drawAmbient(this->game->getBuffer());
                        }
                        break;
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

void BaseGame::artificialIntelligence()
{

    vector<Enemy*> vectorE = this->activeMap.getVectorEnemies();
    for (int i = 0; i < vectorE.size(); i++){
            //Update de enemigo para luego printarlo
        if(vectorE.at(i)->detectionRadiusEnemy(&this->player)){

            int direction = this->directionIA(vectorE.at(i));

            if(direction == 0)
            {
                vectorE.at(i)->walkUP();
            }
            if(direction == 1)
            {
                vectorE.at(i)->walkRIGHT();
            }
            if(direction == 2)
            {
                vectorE.at(i)->walkDOWN();
            }
            if(direction == 3)
            {
                vectorE.at(i)->walkLEFT();
            }
        }else{
            this->activeMap.getVectorEnemies().at(i)->update();
        }
    }
}


int BaseGame::directionIA(Enemy *drawable)
{
            float angle = atan2(drawable->getY() - this->player.getY(), drawable->getX() - this->player.getX()) *180/3.14;
            float percent = 90;
            float endAngle;
            float startAngle = 0;
            int direction = 0;
            bool detected = false;
            while ( direction < 4 && !detected){
                switch (direction) {
                    //UP
                    case 0:
                        startAngle = 90-percent/2;
                        break;
                    //RIGHT
                    case 1:
                        startAngle = 180-percent/2;
                        break;
                    //DOWN
                    case 2:
                        startAngle = -90-percent/2;
                        break;
                    //LEFT
                    case 3:
                        startAngle = 0-percent/2;
                        break;
                    default:;
                }


                endAngle = percent + startAngle;
                //calcular si punto dentro de sector circulo
                if (angle >= startAngle && angle <= endAngle) {//calculo normal
                    return direction;
                }else if ((angle >= startAngle || angle <= startAngle*-1) && direction==1) {//calculo para derecha
                    return direction;
                }
                direction++;
            }
}


void BaseGame::nextMap()
{

    if(this->player.getX() == 750 && this->player.getY() == GameStateManager::SIZE_WINDOW_Y / 2)
        {
            this->activeMap = this->managerMaps.getMap(1);
        }

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
