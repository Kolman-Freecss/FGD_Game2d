#include "Map.h"
#include "allegro.h"
#include "Enemy.h"

Map::Map()
{
}

Map::Map(int quantEnemies, int quantElementsOfAmbient, int numMap)
{

    this->quantEnemies = quantEnemies;
    this->quantElementsOfAmbient = quantElementsOfAmbient;

    //Drawable **mapAmbient;
    //vector<Enemy*> firtMapEnemies;
    /**
    Fill the matrix of animations enemy
    */
    BITMAP ***matrixAnimationsEnemy;

    this->chargeMatrixAnimationsOfEnemy(&matrixAnimationsEnemy, 1);
    this->chargeMatrixAmbient(&this->ambientMatrix, 1);

    srand(time(NULL));
    for(int i = 0; i < this->quantEnemies; i++){
        int positionX = rand()%(800-33);
        int positionY = rand()%(600-50);
        //std::cout << positionX << " position x " << positionY << " position y";
        this->enemies.push_back(new Enemy(matrixAnimationsEnemy, 100, 20, 1, 20, positionX, positionY, 50, 33));
    }

    /**
    Free allocated values and memory of matrix
    */
    /*for(int i = 0; i < 1; i++){
    delete[] matrixAnimationsEnemy[i];
    }*/
    //delete[] matrixAnimationsEnemy;
    /*for(int i = 0; i < 1; i++){
    delete[] mapAmbient[i]; //PETA AQUIIIIIIIIIIIIIIIIIIIIIIIIIIIIII
    }*/
    //delete[] mapAmbient;


}


/**
Charge the matrix of the animations enemy
Esto no deberia recibir la cantidad de enemigos sino que enemigos hay y en base a ello cargar las animaciones
*/
void Map::chargeMatrixAnimationsOfEnemy(BITMAP ****matrix, int numMap)
{
    /**
    Reservamos memoria para la matriz
    */
    *matrix = new BITMAP**[1];/////////////////////////////
    for(int i = 0; i < 1; i++){
        *matrix[i] = new BITMAP*[1];
    }

    switch(numMap){

        case 1: BITMAP *bitmap = load_bitmap("src\\Resources\\Player_Front_With_Sword.bmp",NULL);
                for(int b = 0 ; b < 1; b++){
                    for (int j = 0; j < 1; j++){
                        *matrix[b][j] = bitmap;
                    }
                }

                break;


    }


}


/**
Charge the matrix of the ambient map
*/
void Map::chargeMatrixAmbient(Drawable ***matrix, int numMap)
{
    /**
    Reservamos memoria para la matriz
    */
    *matrix = new Drawable*[1];
    for(int i = 0; i < 1; i++){
         *matrix[i] = new Drawable[1];
    }

    switch(numMap){

        case 1:
                BITMAP *bitmapTest = load_bitmap("src\\Resources\\grass.bmp",NULL);
                Drawable *drawable = new Drawable(bitmapTest, 0, 0 , 0, 0);
                matrix[0][0] = drawable;

                break;


    }


}


///////////////////          GETTERS & SETTERS            ////////////////////////////

void Map::setAmbientMatrix(Drawable **ambientMatrix)
{
    this->ambientMatrix = ambientMatrix;
}

vector<Enemy*> Map::getVectorEnemies()
{
    return this->enemies;
}

Drawable** Map::getAmbientMatrix()
{
    return this->ambientMatrix;
}

int Map::getQuantElementsOfAmbient()
{
    return this->quantElementsOfAmbient;
}
