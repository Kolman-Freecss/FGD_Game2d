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
DAOMap::DAOMap(int difficult)
{
    /*Drawable **mapAmbient;
    vector<Enemy*> firtMapEnemies;
    /**
    Fill the matrix of animations enemy
    */
    //BITMAP ***matrixAnimationsEnemy;

    switch(difficult){

        /**
        Case 1 = Dificultad Facil
        */
        case 1: this->quantEnemies = 6;
                this->quantElementsAmbient = 1;
                for(int i = 0; i < 1; i++){
                    this->mapList.push_back(Map(this->quantEnemies, this->quantElementsAmbient, this->numMap));
                    this->numMap++;
                }
                break;


        default: ;
    }
}

vector<Map> DAOMap::getMapList()
{
    return mapList;
}

Map DAOMap::getMap(int id)
{
    return mapList.at(id);
}


///////////////////          GETTERS & SETTERS            ////////////////////////////

int DAOMap::getDifficultGame()
{
    return this->difficultGame;
}

void DAOMap::setDifficultGame(int difficult)
{
    this->difficultGame = difficult;
}

