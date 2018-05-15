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



    /**
    Reservamos memoria para la matriz
    */
    this->ambientMatrix = new Drawable*[1];
    for(int i = 0; i < 1; i++){
         this->ambientMatrix[i] = new Drawable[2];
    }

    /**
    Reservamos memoria para la matriz
    */
    BITMAP ***matrixAnimationsEnemy = new BITMAP**[1];
    for(int i = 0; i < 1; i++){
        matrixAnimationsEnemy[i] = new BITMAP*[2];
    }

    this->chargeMatrixAnimationsOfEnemy(matrixAnimationsEnemy, 1);
    this->chargeMatrixAmbient(this->ambientMatrix, 1);

    srand(time(NULL));
    for(int i = 0; i < this->quantEnemies; i++){
        int positionX = rand()%(800-33);
        int positionY = rand()%(600-50);
        //std::cout << positionX << " position x " << positionY << " position y";
        this->enemies.push_back(new Enemy(matrixAnimationsEnemy, 100, 20, 1, 20, positionX, positionY, 50, 33));
    }

    /*
    /**
    Free allocated values and memory of matrix

    for(int i = 0; i < 1; i++){
            for(int j = 0; j < 2; j++){
                delete[] matrixAnimationsEnemy[i][j];
            }
    }
    delete[] matrixAnimationsEnemy;
    //delete[] matrixAnimationsEnemy;
    for(int i = 0; i < 1; i++){
                delete[] this->ambientMatrix[i];
    }
    delete[] this->ambientMatrix;*/


}


/**
Charge the matrix of the animations enemy
Esto no deberia recibir la cantidad de enemigos sino que enemigos hay y en base a ello cargar las animaciones
*/
void Map::chargeMatrixAnimationsOfEnemy(BITMAP ***matrix, int numMap)
{

    switch(numMap){

        case 1: BITMAP *bitmap = load_bitmap("src\\Resources\\Player_Front_With_Sword.bmp",NULL);
                for(int b = 0 ; b < 1; b++){
                    for (int j = 0; j < 1; j++){
                        matrix[b][j] = bitmap;
                    }
                }
                BITMAP *bitmap2 = load_bitmap("src\\Resources\\Player_W_Trans.bmp",NULL);
                matrix[0][1] = bitmap2;

                break;


    }


}


/**
Charge the matrix of the ambient map
*/
void Map::chargeMatrixAmbient(Drawable **matrix, int numMap)
{

    switch(numMap){

        case 1:
                BITMAP *bitmapTest = load_bitmap("src\\Resources\\grass.bmp",NULL);
                matrix[0][0] = Drawable(bitmapTest, 0, 0 , 0, 0);

                BITMAP *bitmapTest2 = load_bitmap("src\\Resources\\house.bmp",NULL);
                matrix[0][1] = Drawable(bitmapTest2, 150, 150, 300, 300);

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
