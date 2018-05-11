#include "DAOMap.h"
#include "Map.h"
#include <vector>
#include "allegro.h"
#include "Enemy.h"

using namespace std;


/**
Rellena todas las matrices de un mapa en concreto que contendra lo siguiente:
Vector de enemigos, matriz de Ambiente, la longitud de la matriz
*/
DAOMap::DAOMap()
{
    //mapList.push_back();
    Drawable **mapAmbient;
    vector<Enemy*> firtMapEnemies; //= new vector<Enemy>(1);
    /**
    Fill the matrix of animations enemy
    */
    BITMAP ***matrixAnimationsEnemy;


    int lenght = 1;
    mapAmbient = new Drawable*[lenght];
    for(int i = 0; i < lenght; i++){
         mapAmbient[i] = new Drawable[lenght];
    }

    matrixAnimationsEnemy = new BITMAP**[lenght];
    for(int i = 0; i < lenght; i++){
        matrixAnimationsEnemy[i] = new BITMAP*[lenght];
    }


    this->chargeMatrixAnimations(&matrixAnimationsEnemy, 1, 1);
    this->chargeMatrixAmbient(&mapAmbient, 1, 1);

    firtMapEnemies.push_back(new Enemy(matrixAnimationsEnemy, 100, 20, 1, 20, 100, 100, 50, 33));
    firtMapEnemies.push_back(new Enemy(matrixAnimationsEnemy, 100, 20, 2, 20, 200, 200, 50, 33));
    firtMapEnemies.push_back(new Enemy(matrixAnimationsEnemy, 100, 20, 3, 20, 300, 300, 50, 33));
    firtMapEnemies.push_back(new Enemy(matrixAnimationsEnemy, 100, 20, 4, 20, 400, 400, 50, 33));
    firtMapEnemies.push_back(new Enemy(matrixAnimationsEnemy, 100, 20, 5, 20, 500, 500, 50, 33));


    this->mapList.push_back(Map(firtMapEnemies, mapAmbient, 1));
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

vector<Map> DAOMap::getMapList()
{
    return mapList;
}

Map DAOMap::getMap(int id)
{
    return mapList.at(id);
}

/**
Charge the matrix of the animations enemy
*/
void DAOMap::chargeMatrixAnimations(BITMAP ****matrix, int numMap, int lenght)
{
    /*matrix = new BITMAP*[lenght];
    for(int i = 0; i < lenght; i++){
        matrix[i] = new BITMAP[lenght];
    }*/

    switch(numMap){

        case 1: BITMAP *bitmap = load_bitmap("src\\Resources\\Player_Front_With_Sword.bmp",NULL);
                //BITMAP *pointerOfBitmap = &bitmap;
                *matrix[0][0] = bitmap; //////////
                break;


    }


}


/**
Charge the matrix of the ambient map
*/
void DAOMap::chargeMatrixAmbient(Drawable ***matrix, int numMap, int lenght)
{
    switch(numMap){

        case 1:
                //matrix = new Drawable*[lenght];
                //for(int i = 0; i < lenght; i++){
                  //  matrix[i] = new Drawable[lenght];
                //}
                BITMAP *bitmapTest = load_bitmap("src\\Resources\\grass.bmp",NULL);
                Drawable *drawable = new Drawable(bitmapTest, 0, 0 , 0, 0);
                //Drawable *pointerOf = &drawable;
                matrix[0][0] = drawable;

                break;


    }


}


