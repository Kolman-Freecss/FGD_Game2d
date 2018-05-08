#include "DAOMap.h"
#include "Map.h"
#include <vector>
#include "allegro.h"
#include "Enemy.h"

using namespace std;



DAOMap::DAOMap()
{
    //mapList.push_back();
    Drawable **mapAmbient;
    vector<Enemy> firtMapEnemies;
    /**
    Fill the matrix of animations enemy
    */
    BITMAP **matrixAnimationsEnemy;
    this->chargeMatrixAnimations(matrixAnimationsEnemy, 1, 1);
    this->chargeMatrixAmbient(mapAmbient, 1, 1);

    firtMapEnemies.push_back(Enemy(matrixAnimationsEnemy, 100, 20, 1, 20, 50, 50, 33, 66));

    this->mapList.push_back(Map(firtMapEnemies, mapAmbient));
    /**
    Free allocated values and memory of matrix
    */
    for(int i = 0; i < 1; i++){
        delete[] matrixAnimationsEnemy[i];
    }
    delete[] matrixAnimationsEnemy;
    for(int i = 0; i < 1; i++){
        delete[] mapAmbient[i];
    }
    delete[] mapAmbient;


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
void DAOMap::chargeMatrixAnimations(BITMAP **matrix, int numMap, int lenght)
{
    matrix = new BITMAP*[lenght];
    for(int i = 0; i < lenght; i++){
        matrix[i] = new BITMAP[lenght];
    }

    switch(numMap){

        case 1: BITMAP *bitmap = load_bitmap("src\\Resources\\Player_Front_With_Sword.bmp",NULL);
                matrix[0][0] = *bitmap;
                break;


    }


}


/**
Charge the matrix of the ambient map
*/
void DAOMap::chargeMatrixAmbient(Drawable **matrix, int numMap, int lenght)
{

    switch(numMap){

        case 1: matrix = new Drawable*[lenght];
                for(int i = 0; i < lenght; i++){
                    matrix[i] = new Drawable[lenght];
                }
                matrix[0][0] = Drawable(load_bitmap("src\\Resources\\grass.bmp",NULL), 0, 0 , 0, 0);

                break;


    }


}


