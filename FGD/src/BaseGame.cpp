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
#include <WinState.h>
#include <TextState.h>
#include <Drawable.h>
#include <LostState.h>

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
    this->bossDetected = false;

}

BaseGame::~BaseGame()
{
    this->cleanUp();
}


void BaseGame::init()
{

    /**
    Quitamos la musica del menu
    */
    this->managerMusic.stopSoundMenu();

    this->checkTextNpc = true;
    managerMaps = new DAOMap(this->gameDificulty);
    this->activeMap = new Map();
    this->activeMap = managerMaps->getMap(0);

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

    this->player = Player(matrixAnimationsPlayer, 100, 20, 4, 100, 50, 330, 65, 73);
    //TODO
    BITMAP *swordOfPlayer = load_bitmap("src\\Resources\\Inventory\\sword.bmp",NULL);
    Weapon *weaponOfPlayer = new Weapon(100,1, swordOfPlayer, 46, 40);
    this->player.setSelectedWeapon(weaponOfPlayer);

    /**Nuevo formato**/
    this->player.getInventory()->vectorAttackDistance.push_back(100);
    this->player.getInventory()->vectorDamage.push_back(1);
    this->player.getInventory()->bitmapsObjects.push_back(load_bitmap("src\\Resources\\Inventory\\sword.bmp",NULL));
    this->player.getInventory()->vectorWidth.push_back(46);
    this->player.getInventory()->vectorHeight.push_back(40);
    this->player.getInventory()->vectorAttackDistance.push_back(200);
    this->player.getInventory()->vectorDamage.push_back(4);
    this->player.getInventory()->bitmapsObjects.push_back(load_bitmap("src\\Resources\\Inventory\\sword.bmp",NULL));
    this->player.getInventory()->vectorWidth.push_back(46);
    this->player.getInventory()->vectorHeight.push_back(40);
    this->player.getInventory()->objectList->push_back(weaponOfPlayer);

    /*if(!this->managerMusic.getMap1IsPlaying()){
        if(this->getSound()){
            managerMusic.soundMap1();
        }
    }*/



}

void BaseGame::getEvents()
{

    if (GameState::keyI()){
            this->game->pushState(new MenuInventarioState(this->game, &this->player));
    }
    if ( key[KEY_ESC] ) this->game->pushState(new MenuEscState(game));

    if(Music::checkMusicOrNot){
        this->playMusic();
    }
    this->nextMap();
    this->previousMap();
    this->winGame();

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
    this->artificialIntelligence();

    /**
     * check colisiones
     */
    this->collisionCheck();


    //TODO CAMBIAR A FUNCION
    // character attacking
    if (player.isAttacking()) {

        player.attack();
        if (!player.isAttackChecked()) {


            for (int i = 0; i < this->activeMap->getVectorEnemies().size(); ++i) {
                if (player.attackCollision(this->activeMap->getVectorEnemies().at(i), player.getSelectedWeapon(),
                                           player.getDirection())) {
                    //HIT A ENEMIGO
                    //TODO CONTROL DAÑO A ENEMIGO
                    bool isKilled = this->activeMap->getVectorEnemies().at(i)->wounded(&this->player);
                    if (isKilled){
                        //inicio animacion de muerte
                        this->activeMap->getVectorEnemies().at(i)->activeBitmap[1] = 0;

                        player.setExperience(player.getExperience()+ 100) ;
                        cout << "+exp " << player.getExperience() << endl;
                        player.getInventory()->addMoney((rand()%1000)+1);

                        Weapon *weapon = this->activeMap->getVectorEnemies().at(i)->randomizeDrop();
                        this->player.getInventory()->vectorAttackDistance.push_back(weapon->getAttackDistance());
                        this->player.getInventory()->vectorDamage.push_back(weapon->getDamage());
                        this->player.getInventory()->bitmapsObjects.push_back(load_bitmap("src\\Resources\\Inventory\\sword.bmp",NULL));
                        this->player.getInventory()->vectorWidth.push_back(46);
                        this->player.getInventory()->vectorHeight.push_back(40);

                        player.getInventory()->getObjectListPtr()->push_back(weapon);

                        //delete this->activeMap->getVectorEnemies().at(i);

                        /*Enemy *auxSwift = this->activeMap->getVectorEnemies().at(i);
                        for(int j = 0; j < this->activeMap->getVectorEnemies().size(); j++){

                        }*/

                        cout << "vector size " << player.getInventory()->getObjectListPtr()->size();
                    }
                }
            }
            player.setAttackChecked(true);
        }

    }
    //FIN character attacking

}

/**
Printa todo el contenido de la pantalla (Enemigos, Ambiente, Player)
*/
void BaseGame::draw()
{

    Drawable **matrix = this->activeMap->getAmbientMatrix();
    int lengthMatrix = this->activeMap->getQuantElementsOfAmbient();

    BITMAP *bitmapAmbient = matrix[0][0].getBitmapAmbient();
    stretch_blit(bitmapAmbient, this->game->getBuffer(), 0, 0, bitmapAmbient->w, bitmapAmbient->h, 0, 0, GameStateManager::SIZE_WINDOW_X, GameStateManager::SIZE_WINDOW_Y);



    this->player.draw(this->game->getBuffer());


    /**
    Printa todo el vector de Enemigos en pantalla
    */
    vector<Enemy*> vectorE = this->activeMap->getVectorEnemies();
    /**
    Ordenamos el vector de enemigos por Y de menor a mayor para arreglar las colisiones
    */
    for(int a = 0; a < vectorE.size(); a++){
        for(int b = 0; b < vectorE.size()-1; b++){
                if(vectorE.at(b)->getY() > vectorE.at(b+1)->getY()){
                    Enemy *aux = vectorE.at(b);
                    vectorE.at(b) = vectorE.at(b+1);
                    vectorE.at(b+1) = aux;
                }
        }
    }


    for (int i = 0; i < vectorE.size(); i++){

        vectorE.at(i)->draw(this->game->getBuffer());
        drawEnemyHUD(vectorE.at(i));
    }








    /**
    Print Ambient
    */
    for(int i = 0; i < lengthMatrix; i++){

        switch(i){

            /**
            Background y otros elementos
            */
            case 0: {

                        for(int j = 1; j < this->activeMap->getQuantOtherElements(); j++){
                                matrix[i][j].drawAmbient(this->game->getBuffer());
                        }
                        break;
                    }
            /**
            Arboles
            */
            case 1: {
                        for(int j = 0; j < this->activeMap->getCol1Quantity(); j++){
                            matrix[i][j].drawAmbient(this->game->getBuffer());
                        }
                        break;
                    }

            /**
            Casas
            */
            case 2: {
                        for(int j = 0; j < this->activeMap->getCol2Quantity(); j++){
                            matrix[i][j].drawAmbient(this->game->getBuffer());
                        }
                        break;
                    }
            /**
            Casas
            */
            case 3: {
                        for(int j = 0; j < this->activeMap->getCol3Quantity(); j++){
                            matrix[i][j].drawAmbient(this->game->getBuffer());
                        }
                        break;
                    }
            /**
            Casas
            */
            case 4: {
                        for(int j = 0; j < this->activeMap->getCol4Quantity(); j++){
                            matrix[i][j].drawAmbient(this->game->getBuffer());
                        }
                        break;
                    }
            /**
            Casas
            */
            case 5: {
                        for(int j = 0; j < this->activeMap->getCol5Quantity(); j++){
                            matrix[i][j].drawAmbient(this->game->getBuffer());
                        }
                        break;
                    }
            /**
            Casas
            */
            case 6: {
                        for(int j = 0; j < this->activeMap->getCol6Quantity(); j++){
                            matrix[i][j].drawAmbient(this->game->getBuffer());
                        }
                        break;
                    }
        }
    }


    /**
    Printa todo el vector de Enemigos en pantalla
    */
 /*   vector<Enemy*> vectorE = this->activeMap->getVectorEnemies();
    for (int i = 0; i < vectorE.size(); i++){

        vectorE.at(i)->draw(this->game->getBuffer());
        drawEnemyHUD(vectorE.at(i));
    }*/

    /**
    Printa Enemigos en pantalla si no hay colision
    */
    for (int i = 0; i < vectorE.size(); i++){
        /**
        Si no tiene colision con otro enemigo lo printa
        */
       /* */
        /**
        Si no tiene colision con ambiente lo printa
        */
        if(!vectorE.at(i)->checkCollision){
                if(!vectorE.at(i)->checkCollisionWithOCharacther){
                    vectorE.at(i)->draw(this->game->getBuffer());
                    drawEnemyHUD(vectorE.at(i));
                }


    }
    vectorE.at(i)->checkCollision = false;
        vectorE.at(i)->checkCollisionWithOCharacther = false;
    }



    if(!player.checkCollision){
        this->player.draw(this->game->getBuffer());

    }
    player.checkCollision = false;




    drawHUD();

    /**
    Esta llamada seria para mostrar por primera y unica vez la presentación del juego
    */
    if(this->checkTextNpc){
        if(this->managerMusic.isPlayingMap1){
            this->managerMusic.stopAllSounds();
        }
        this->game->pushState(new TextState(this->game, 0));
        this->checkTextNpc = false;
    }


    blit(this->game->getBuffer(), screen, 0, 0, 0, 0, 800, 600);



}

void BaseGame::artificialIntelligence()
{

    vector<Enemy*> vectorE = this->activeMap->getVectorEnemies();
    for (int i = 0; i < vectorE.size(); i++){
        if (vectorE.at(i)->isIsAlive()){
            if(vectorE.at(i)->detectionRadiusEnemy(&this->player) ){

                if (this->activeMap->numMap == 5){
                    vectorE.at(i)->setDetectionRadius(2000);
                    this->bossDetected = true;

                }

                if (vectorE.at(i)->attackCollision(&this->player, vectorE.at(i)->getSelectedWeapon(), vectorE.at(i)->getDirection())) {

                    if (rand()%100 < 10 && !vectorE.at(i)->isAttacking()){
                        vectorE.at(i)->setAttackChecked(false);
                        vectorE.at(i)->setAttacking(true);
                    }
                    if (vectorE.at(i)->isAttacking()){
                        vectorE.at(i)->attack();
                    }
                    if (!vectorE.at(i)->isAttackChecked()) {
                        vectorE.at(i)->setAttackChecked(true);
                        if (player.wounded(vectorE.at(i))) {
                            this->drawHUD();
                            //GAME OVER LOST
                            this->managerMusic.stopAllSounds();
                            this->game->pushState(new LostState(this->game));
                        }
                    }
                }else{
                    int direction = this->directionIA(vectorE.at(i));

                    if(direction == Drawable::UP) {
                        vectorE.at(i)->walkUP();
                    }
                    if(direction == Drawable::RIGHT) {
                        vectorE.at(i)->walkRIGHT();
                    }
                    if(direction == Drawable::DOWN) {
                        vectorE.at(i)->walkDOWN();
                    }
                    if(direction == Drawable::LEFT) {
                        vectorE.at(i)->walkLEFT();
                    }
                }
            }else if (this->activeMap->numMap != 5){
                this->activeMap->getVectorEnemies().at(i)->update();
            }
        }else {
            this->activeMap->getVectorEnemies().at(i)->dieAnim();

        }
    }
}

//////////////////    FUNCIONES FUERA DEL LOOP PRINCIPAL        //////////////////////

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
                    case Drawable::UP:
                        startAngle = 90-percent/2;
                        break;
                    //RIGHT
                    case Drawable::RIGHT:
                        startAngle = 180-percent/2;
                        break;
                    //DOWN
                    case Drawable::DOWN:
                        startAngle = -90-percent/2;
                        break;
                    //LEFT
                    case Drawable::LEFT:
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

void BaseGame::winGame()
{
    //SI A MATADO AL BOSS...
    if(this->activeMap->numMap == 5 && this->player.getX() >= 334 && this->player.getX() <= 392
       && this->player.getY() <= 40 && !this->activeMap->getVectorEnemies().at(0)->isIsAlive())
    {
        this->managerMusic.stopAllSounds();
        this->managerMusic.soundWin();
        this->game->pushState(new WinState(this->game));
    }
}

void BaseGame::colPlayerAndEnemyWithLimits()
{
    /**
    Enemigo boss no tendra colision con limites ya que seguirá al player, pero se deja aqui
    por si en un futuro ponemos enemigos en este ultimo mapa
    */
    /*
    for (int j = 0; j < this->activeMap->getVectorEnemies().size(); ++j) {
        if (this->activeMap->getVectorEnemies().at(j)->isIsAlive()){
            this->activeMap->getVectorEnemies().at(i)->setX(this->activeMap->getVectorEnemies().at(i)->getAX());
            this->activeMap->getVectorEnemies().at(i)->setY(this->activeMap->getVectorEnemies().at(i)->getAY());
            int direction = rand()%4;
            this->activeMap->getVectorEnemies().at(i)->setDirectionEnemy(direction);
        }
    }*/
    if(this->player.getX() <= 24) this->player.setXandAX(this->player.getAX());
    if(this->player.getX() >= 703) this->player.setXandAX(this->player.getAX());
    if(this->player.getY() <= 49) {
        if(this->player.getX() <= 334 || this->player.getX() >= 392){
            this->player.setYandAY(this->player.getAY());
            this->player.setXandAX(this->player.getAX());
        }
    }

    if(this->player.getY() >= 420){
        if(this->player.getX() <= 290 || this->player.getX() >= 434){
            this->player.setYandAY(this->player.getAY());
            this->player.setXandAX(this->player.getAX());
        }
    }
}

void BaseGame::playMusic()
{
    if(!this->managerMusic.isPlayingMap1 && !this->managerMusic.isPlayingMap2 && !this->managerMusic.isPlayingMap3
        && !this->managerMusic.isPlayingMap4 && !this->managerMusic.isPlayingMap5){

        if(this->activeMap->numMap == 1){
            this->managerMusic.soundMap1();
        }else if(this->activeMap->numMap == 2){
            this->managerMusic.soundMap2();
        }else if(this->activeMap->numMap == 3){
            this->managerMusic.soundMap3();
        }else if(this->activeMap->numMap == 4){
            this->managerMusic.soundMap4();
        }else if(this->activeMap->numMap == 5){
            this->managerMusic.soundMap5();
        }

    }


}


void BaseGame::nextMap()
{

    if(this->activeMap->numMap == 1 && this->player.getX() > 720 && this->player.getY() >= 350 && this->player.getY() <= 420)
        {
            this->managerMusic.stopSoundMap1();
            this->activeMap = this->managerMaps->getMap(1);
            this->player.setXandAX(50);
            this->player.setYandAY(350);
        }
    else if (this->activeMap->numMap == 2 && this->player.getX() > 430 && this->player.getX() <= 520 && this->player.getY() >= 535)
        {
            this->managerMusic.stopSoundMap2();
            this->activeMap = this->managerMaps->getMap(2);
            this->player.setXandAX(340);
            this->player.setYandAY(20);
        }
    else if (this->activeMap->numMap == 3 && this->player.getX() > 700 && this->player.getY() >= 340 && this->player.getY() <= 465)
        {
            this->managerMusic.stopSoundMap3();
            this->activeMap = this->managerMaps->getMap(3);
            this->player.setXandAX(50);
            this->player.setYandAY(500);
        }
    else if (this->activeMap->numMap == 4 && this->player.getX() >= 380 && this->player.getX() <= 440
              && this->player.getY() >= 180 && this->player.getY() <= 200)
        {
            this->managerMusic.stopSoundMap4();
            this->activeMap = this->managerMaps->getMap(4);
            this->player.setXandAX(360);
            this->player.setYandAY(500);
        }

}

void BaseGame::previousMap()
{

    if(this->activeMap->numMap == 2 && this->player.getX() <=  2 && this->player.getY() >= 350 && this->player.getY() <= 415)
        {
            this->managerMusic.stopSoundMap2();
            this->activeMap = this->managerMaps->getMap(0);
            this->player.setXandAX(650);
            this->player.setYandAY(380);
        }
    else if (this->activeMap->numMap == 3 && this->player.getX() >= 310 && this->player.getX() <= 405 && this->player.getY() <= 0)
        {
            this->managerMusic.stopSoundMap3();
            this->activeMap = this->managerMaps->getMap(1);
            this->player.setXandAX(470);
            this->player.setYandAY(500);
        }
    else if (this->activeMap->numMap == 4 && this->player.getX() <= 0 && this->player.getY() >= 430)
        {
            this->managerMusic.stopSoundMap4();
            this->activeMap = this->managerMaps->getMap(2);
            this->player.setXandAX(690);
            this->player.setYandAY(350);
        }
    else if (this->activeMap->numMap == 5 && this->player.getX() >= 295 && this->player.getX() <= 420 && this->player.getY() >= 520)
        {
            this->managerMusic.stopSoundMap5();
            if (!this->bossDetected){
                this->activeMap = this->managerMaps->getMap(3);
                this->player.setXandAX(410);
                this->player.setYandAY(230);
            }
        }

}


void BaseGame::collisionCheck() {
    colPlayerWithEnemies();
    colPlayerWithAmbient();
    colEnemiesWithAmbient();
    colEnemies();

    if(this->activeMap->numMap == 5){
        colPlayerAndEnemyWithLimits();
    }
}




void BaseGame::colPlayerWithEnemies() {
    for (int i = 0; i < this->activeMap->getVectorEnemies().size(); ++i) {
        if (this->player.collision(this->activeMap->getVectorEnemies().at(i)) && this->activeMap->getVectorEnemies().at(i)->isIsAlive()){
            //TODO

            this->player.setX(this->player.getAX()) ;
            this->player.setY(this->player.getAY()) ;
        }
        if (player.isBehind(this->activeMap->getVectorEnemies().at(i))){
            player.checkCollision = true;
            cout << "is behind ";
        }
    }
}

void BaseGame::colPlayerWithAmbient(){
    //TODO CAMBIAR MAS ADELANTE

    for (int i=0;i<this->activeMap->getQuantElementsOfAmbient();i++){
            switch(i){
                case 0: {break;}

                case 1: {
                        for (int j=0;j<this->activeMap->getCol1Quantity();j++) {
                            if (player.collision(&this->activeMap->getAmbientMatrix()[i][j])){
                                //TODO
                                this->player.setX(this->player.getAX());
                                this->player.setY(this->player.getAY());

                            }
                            if (player.isBehind(&this->activeMap->getAmbientMatrix()[i][j])){
                                player.checkCollision = true;
                            }
                        }
                        break;
                    }

                case 2: {

                        for (int j=0;j<this->activeMap->getCol2Quantity();j++) {
                            if (player.collision(&this->activeMap->getAmbientMatrix()[i][j])){
                                    this->player.setX(this->player.getAX());
                                    this->player.setY(this->player.getAY());
                            }
                            //
                            if (player.isBehind(&this->activeMap->getAmbientMatrix()[i][j])){
                                player.checkCollision = true;
                            }
                        }
                        break;
                    }
                case 3: {
                        for (int j=0;j<this->activeMap->getCol3Quantity();j++) {
                            if (player.collision(&this->activeMap->getAmbientMatrix()[i][j])){
                                //TODO
                                this->player.setX(this->player.getAX());
                                this->player.setY(this->player.getAY());

                            }
                            if (player.isBehind(&this->activeMap->getAmbientMatrix()[i][j])){
                                player.checkCollision = true;
                            }
                        }
                        break;
                }
                case 4: {
                    for (int j=0;j<this->activeMap->getCol4Quantity();j++) {
                        if (player.collision(&this->activeMap->getAmbientMatrix()[i][j])){
                            //TODO
                            this->player.setX(this->player.getAX());
                            this->player.setY(this->player.getAY());

                        }
                        if (player.isBehind(&this->activeMap->getAmbientMatrix()[i][j])){
                                player.checkCollision = true;
                            }
                    }
                    break;
                }
                case 5: {
                    for (int j=0;j<this->activeMap->getCol5Quantity();j++) {
                        if (player.collision(&this->activeMap->getAmbientMatrix()[i][j])){
                            //TODO
                            this->player.setX(this->player.getAX());
                            this->player.setY(this->player.getAY());

                        }
                        if (player.isBehind(&this->activeMap->getAmbientMatrix()[i][j])){
                                player.checkCollision = true;
                            }
                    }
                    break;
                }
            }
    }
}

//Col entre enemigos y player
void BaseGame::colEnemies(){
    for (int i = 0; i < this->activeMap->getVectorEnemies().size(); ++i) {
        for (int j = 0; j < this->activeMap->getVectorEnemies().size(); ++j) {
            if (i!=j){
                if (this->activeMap->getVectorEnemies().at(i)->collision(this->activeMap->getVectorEnemies().at(j)) && this->activeMap->getVectorEnemies().at(j)->isIsAlive()){
                    //TODO
                    this->activeMap->getVectorEnemies().at(i)->setX(this->activeMap->getVectorEnemies().at(i)->getAX());
                    this->activeMap->getVectorEnemies().at(i)->setY(this->activeMap->getVectorEnemies().at(i)->getAY());

                    if (this->activeMap->getVectorEnemies().at(i)->isIsAlive()){
                        int direction = rand()%4;
                        this->activeMap->getVectorEnemies().at(i)->setDirectionEnemy(direction);
                    }
                }
                if (this->activeMap->getVectorEnemies().at(i)->isBehind(this->activeMap->getVectorEnemies().at(j)) && this->activeMap->getVectorEnemies().at(j)->isIsAlive()){
                        //if(!this->activeMap->getVectorEnemies().at(i)->checkCollision){
                            //if(this->activeMap->getVectorEnemies().at(i)->getY() < this->activeMap->getVectorEnemies().at(j)->getY()){
                                this->activeMap->getVectorEnemies().at(i)->checkCollisionWithOCharacther = true;
                                this->activeMap->getVectorEnemies().at(j)->checkCollisionWithOCharacther = false;
                            //}
                        //}

                }
            }
        }
        //col enemy with player
        if (this->activeMap->getVectorEnemies().at(i)->collision(&this->player)){
            //TODO
            this->activeMap->getVectorEnemies().at(i)->setX(this->activeMap->getVectorEnemies().at(i)->getAX());
            this->activeMap->getVectorEnemies().at(i)->setY(this->activeMap->getVectorEnemies().at(i)->getAY());
        }
    }

}
void BaseGame::colEnemiesWithAmbient(){
    for (int p = 0; p < this->activeMap->getVectorEnemies().size(); ++p) {
        for (int i = 0; i < this->activeMap->getQuantElementsOfAmbient(); i++) {

            switch(i){
                case 0: {break;}

                case 1: {
                        for (int j=0;j<this->activeMap->getCol1Quantity();j++) {
                            if (this->activeMap->getVectorEnemies().at(p)->collision(&this->activeMap->getAmbientMatrix()[i][j])) {
                                //TODO CAMBIAR FUNCION VOLVER ATRAS DE CHARACTER
                                this->activeMap->getVectorEnemies().at(p)->setX(this->activeMap->getVectorEnemies().at(p)->getAX());
                                this->activeMap->getVectorEnemies().at(p)->setY(this->activeMap->getVectorEnemies().at(p)->getAY());
                                int direction = rand()%4;
                                this->activeMap->getVectorEnemies().at(p)->setDirectionEnemy(direction);

                            }
                            if (this->activeMap->getVectorEnemies().at(p)->isBehind(&this->activeMap->getAmbientMatrix()[i][j])){
                                this->activeMap->getVectorEnemies().at(p)->checkCollision = true;
                            }
                        }
                        break;
                    }

                case 2: {

                        for (int j = 0; j < this->activeMap->getCol2Quantity(); j++) {
                            if (this->activeMap->getVectorEnemies().at(p)->collision(&this->activeMap->getAmbientMatrix()[i][j])) {
                                //TODO CAMBIAR FUNCION VOLVER ATRAS DE CHARACTER
                                this->activeMap->getVectorEnemies().at(p)->setX(this->activeMap->getVectorEnemies().at(p)->getAX());
                                this->activeMap->getVectorEnemies().at(p)->setY(this->activeMap->getVectorEnemies().at(p)->getAY());
                                int direction = rand()%4;
                                this->activeMap->getVectorEnemies().at(p)->setDirectionEnemy(direction);
                            }
                            if (this->activeMap->getVectorEnemies().at(p)->isBehind(&this->activeMap->getAmbientMatrix()[i][j])){
                                this->activeMap->getVectorEnemies().at(p)->checkCollision = true;
                            }
                        }
                        break;
                }
                case 3: {

                    for (int j = 0; j < this->activeMap->getCol3Quantity(); j++) {
                        if (this->activeMap->getVectorEnemies().at(p)->collision(&this->activeMap->getAmbientMatrix()[i][j])) {
                            //TODO CAMBIAR FUNCION VOLVER ATRAS DE CHARACTER
                            this->activeMap->getVectorEnemies().at(p)->setX(this->activeMap->getVectorEnemies().at(p)->getAX());
                            this->activeMap->getVectorEnemies().at(p)->setY(this->activeMap->getVectorEnemies().at(p)->getAY());
                            int direction = rand()%4;
                            this->activeMap->getVectorEnemies().at(p)->setDirectionEnemy(direction);
                        }
                        if (this->activeMap->getVectorEnemies().at(p)->isBehind(&this->activeMap->getAmbientMatrix()[i][j])){
                                this->activeMap->getVectorEnemies().at(p)->checkCollision = true;
                            }
                    }
                    break;
                }
                case 4: {

                    for (int j = 0; j < this->activeMap->getCol4Quantity(); j++) {
                        if (this->activeMap->getVectorEnemies().at(p)->collision(&this->activeMap->getAmbientMatrix()[i][j])) {
                            //TODO CAMBIAR FUNCION VOLVER ATRAS DE CHARACTER
                            this->activeMap->getVectorEnemies().at(p)->setX(this->activeMap->getVectorEnemies().at(p)->getAX());
                            this->activeMap->getVectorEnemies().at(p)->setY(this->activeMap->getVectorEnemies().at(p)->getAY());
                            int direction = rand()%4;
                            this->activeMap->getVectorEnemies().at(p)->setDirectionEnemy(direction);
                        }
                        if (this->activeMap->getVectorEnemies().at(p)->isBehind(&this->activeMap->getAmbientMatrix()[i][j])){
                                this->activeMap->getVectorEnemies().at(p)->checkCollision = true;
                        }
                    }
                    break;
                }
                case 5: {

                    for (int j = 0; j < this->activeMap->getCol5Quantity(); j++) {
                        if (this->activeMap->getVectorEnemies().at(p)->collision(&this->activeMap->getAmbientMatrix()[i][j])) {
                            //TODO CAMBIAR FUNCION VOLVER ATRAS DE CHARACTER
                            this->activeMap->getVectorEnemies().at(p)->setX(this->activeMap->getVectorEnemies().at(p)->getAX());
                            this->activeMap->getVectorEnemies().at(p)->setY(this->activeMap->getVectorEnemies().at(p)->getAY());
                            int direction = rand()%4;
                            this->activeMap->getVectorEnemies().at(p)->setDirectionEnemy(direction);
                        }
                        if (this->activeMap->getVectorEnemies().at(p)->isBehind(&this->activeMap->getAmbientMatrix()[i][j])){
                                this->activeMap->getVectorEnemies().at(p)->checkCollision = true;
                            }
                    }
                    break;
                }

            }
        }
    }
}


void BaseGame::drawHUD() {

    //barras de vida player
    int posXbars = 10;
    int posYhp = 10;
    int posYsh = 25;

    BITMAP *BlackBar = load_bitmap("src\\Resources\\hpbarblack.bmp",NULL);
    masked_blit(BlackBar, this->game->getBuffer(), 0, 0, posXbars-2, posYhp-2, 104, 14);
    masked_blit(BlackBar, this->game->getBuffer(), 0, 0, posXbars-2, posYsh-2, 104, 14);


    BITMAP *bitmapHealth = load_bitmap("src\\Resources\\health.bmp",NULL);
    masked_blit(bitmapHealth, this->game->getBuffer(), 0, 0, posXbars, posYhp, this->player.getHealth(), 10);

    BITMAP *bitmapShield = load_bitmap("src\\Resources\\shield.bmp",NULL);
    masked_blit(bitmapShield, this->game->getBuffer(), 0, 0, posXbars, posYsh, this->player.getShield(), 10);

}

void BaseGame::drawEnemyHUD(Enemy *enemy) {
    if (enemy->isIsAlive()){
        int maxSizeBar = enemy->getWidth();
        //barras de vida enemigo
        int posXbars = 0;
        int posYhp = -15;
        int posYsh = -5;

        BITMAP *BlackBar = load_bitmap("src\\Resources\\hpbarblack.bmp",NULL);
        masked_blit(BlackBar, this->game->getBuffer(), 0, 0,  enemy->getX()+posXbars-1, enemy->getY()+posYhp-1, maxSizeBar +2, 7);
        masked_blit(BlackBar, this->game->getBuffer(), 0, 0,  enemy->getX()+posXbars-1, enemy->getY()+posYsh-1, maxSizeBar +2, 7);


        BITMAP *bitmapHealth = load_bitmap("src\\Resources\\health.bmp",NULL);
    masked_blit(bitmapHealth, this->game->getBuffer(), 0, 0, enemy->getX()+posXbars, enemy->getY()+posYhp, (enemy->getHealth()*maxSizeBar)/100, 5);

        BITMAP *bitmapShield = load_bitmap("src\\Resources\\shield.bmp",NULL);
    masked_blit(bitmapShield, this->game->getBuffer(), 0, 0, enemy->getX()+posXbars, enemy->getY()+posYsh, (enemy->getShield()*maxSizeBar)/100, 5);
    }
}
void BaseGame::cleanUp(){
    delete this->activeMap;
    delete this->managerMaps;
}
