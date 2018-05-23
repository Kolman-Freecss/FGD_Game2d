#include <House.h>
#include "Map.h"
#include "allegro.h"
#include "Enemy.h"
#include "GameStateManager.h"

Map::Map()
{
}

Map::Map(int quantEnemies, int quantElementsOfAmbient, int numMap)
{

    this->quantEnemies = quantEnemies;
    this->quantElementsOfAmbient = quantElementsOfAmbient;

    /**
    Segons el numero de mapa que cargem assignem una quantitat d'elements per saber
    cuanta memoria hem de reservar y quants elements hem de recorrer a la hora de printar
    */
    switch(numMap){

        case 1:
                this->quantOtherElements = 1;
                this->col1Quantity = 2;
                this->col2Quantity = 2;

                break;

        case 2:
                this->quantOtherElements = 1;
                this->col1Quantity = 2;
                this->col2Quantity = 2;

                break;
    }

    /**
    Reservamos memoria para la matriz segons la quantitat d'elements a cada posici�
    */

    /**
    TO DO : Habria que cambiar el nombre de "quantTrees quantHouses"
            ya que en otro mapa puede haber en la misma posicion otro tipo de elemento porque o no hay arboles o no hay casas
    */
    this->ambientMatrix = new Drawable*[this->quantElementsOfAmbient];
    for(int i = 0; i < this->quantElementsOfAmbient; i++){
            switch(i){
                case 0: this->ambientMatrix[i] = new Drawable[this->quantOtherElements];
                        break;
                case 1: this->ambientMatrix[i] = new Drawable[this->col1Quantity];
                        break;
                case 2: this->ambientMatrix[i] = new Drawable[this->col2Quantity];
                        break;
            }
         //this->ambientMatrix[i] = new Drawable[2];
    }

    /**
    Reservamos memoria para la matriz
    */
    BITMAP*** matrixAnimationsEnemy;
    matrixAnimationsEnemy = new BITMAP**[12];
    for(int i = 0; i < 12; i++){
        matrixAnimationsEnemy[i] = new BITMAP*[4];
    }


    /**
    Cargamos las matrices de datos
    */
    this->chargeMatrixAnimationsOfEnemy(matrixAnimationsEnemy, 1);
    this->chargeMatrixAmbient(this->ambientMatrix, 1);



    /**
    Generacion dinamica de enemigos comprovando la colision con otros enemigos, player o ambiente
    */
    srand(time(NULL));
    for(int i = 0; i < this->quantEnemies; i++){
        int positionX = rand()%(800-33);
        int positionY = rand()%(600-50);
        //std::cout << positionX << " position x " << positionY << " position y";
        Enemy *enemy = new Enemy(matrixAnimationsEnemy, 100, 20, 1, 20, positionX, positionY, 64, 75);

        bool generado = false;
        while(!generado){
                //col with enemies
            generado = true;
            for(int j = 0; j < this->getVectorEnemies().size(); j++){
                while (enemy->collision(getVectorEnemies().at(j))){
                    positionX = rand()%(800-33);
                    positionY = rand()%(600-50);
                    enemy->setX(positionX);
                    enemy->setY(positionY);
                    if(!enemy->collision(getVectorEnemies().at(j))){
                        j = 0;
                        generado = false;
                    }
                }
            }
        //col with ambient
            for (int i = 0; i < 1; i++) {
                for (int j = 0; j < 2; j++) {
                    if (i != 0 || j != 0) {
                        while (enemy->collision(&this->getAmbientMatrix()[i][j])) {
                                positionX = rand()%(800-33);
                                positionY = rand()%(600-50);
                                enemy->setX(positionX);
                                enemy->setY(positionY);
                                if(!enemy->collision(getVectorEnemies().at(j))){
                                    j = 0;
                                    generado = false;
                                }
                        }
                    }
                }
            }
            /**
            Recuadro donde aparecer� el player
            */
           if(positionX <= 100 && positionY <= 100)
            {
                positionX = rand()%(800-33);
                positionY = rand()%(600-50);
                enemy->setX(positionX);
                enemy->setY(positionY);
                generado = false;
            }
        }

        this->enemies.push_back(enemy);

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

        case 1:
            //WALK
            matrix[0][0] = load_bitmap("src\\Resources\\SKELETON1\\SWU1.bmp",NULL);
            matrix[0][1] = load_bitmap("src\\Resources\\SKELETON1\\SWU2.bmp",NULL);
            matrix[0][2] = load_bitmap("src\\Resources\\SKELETON1\\SWU1.bmp",NULL);
            matrix[0][3] = load_bitmap("src\\Resources\\SKELETON1\\SWU4.bmp",NULL);

            matrix[1][0] = load_bitmap("src\\Resources\\SKELETON1\\SWR1.bmp",NULL);
            matrix[1][1] = load_bitmap("src\\Resources\\SKELETON1\\SWR2.bmp",NULL);
            matrix[1][2] = load_bitmap("src\\Resources\\SKELETON1\\SWR1.bmp",NULL);
            matrix[1][3] = load_bitmap("src\\Resources\\SKELETON1\\SWR4.bmp",NULL);

            matrix[2][0] = load_bitmap("src\\Resources\\SKELETON1\\SWD1.bmp",NULL);
            matrix[2][1] = load_bitmap("src\\Resources\\SKELETON1\\SWD2.bmp",NULL);
            matrix[2][2] = load_bitmap("src\\Resources\\SKELETON1\\SWD1.bmp",NULL);
            matrix[2][3] = load_bitmap("src\\Resources\\SKELETON1\\SWD4.bmp",NULL);

            matrix[3][0] = load_bitmap("src\\Resources\\SKELETON1\\SWL1.bmp",NULL);
            matrix[3][1] = load_bitmap("src\\Resources\\SKELETON1\\SWL2.bmp",NULL);
            matrix[3][2] = load_bitmap("src\\Resources\\SKELETON1\\SWL1.bmp",NULL);
            matrix[3][3] = load_bitmap("src\\Resources\\SKELETON1\\SWL4.bmp",NULL);

            //ATTACK
            matrix[4][0] = load_bitmap("src\\Resources\\SKELETON1\\SAU1.bmp",NULL);
            matrix[4][1] = load_bitmap("src\\Resources\\SKELETON1\\SAU2.bmp",NULL);
            matrix[4][2] = load_bitmap("src\\Resources\\SKELETON1\\SAU3.bmp",NULL);
            matrix[4][3] = load_bitmap("src\\Resources\\SKELETON1\\SAU4.bmp",NULL);

            matrix[5][0] = load_bitmap("src\\Resources\\SKELETON1\\SAR1.bmp",NULL);
            matrix[5][1] = load_bitmap("src\\Resources\\SKELETON1\\SAR2.bmp",NULL);
            matrix[5][2] = load_bitmap("src\\Resources\\SKELETON1\\SAR3.bmp",NULL);
            matrix[5][3] = load_bitmap("src\\Resources\\SKELETON1\\SAR4.bmp",NULL);

            matrix[6][0] = load_bitmap("src\\Resources\\SKELETON1\\SAD1.bmp",NULL);
            matrix[6][1] = load_bitmap("src\\Resources\\SKELETON1\\SAD2.bmp",NULL);
            matrix[6][2] = load_bitmap("src\\Resources\\SKELETON1\\SAD3.bmp",NULL);
            matrix[6][3] = load_bitmap("src\\Resources\\SKELETON1\\SAD4.bmp",NULL);

            matrix[7][0] = load_bitmap("src\\Resources\\SKELETON1\\SAL1.bmp",NULL);
            matrix[7][1] = load_bitmap("src\\Resources\\SKELETON1\\SAL2.bmp",NULL);
            matrix[7][2] = load_bitmap("src\\Resources\\SKELETON1\\SAL3.bmp",NULL);
            matrix[7][3] = load_bitmap("src\\Resources\\SKELETON1\\SAL4.bmp",NULL);

            //DIE
            matrix[8][0] = load_bitmap("src\\Resources\\SKELETON1\\SDU1.bmp",NULL);
            matrix[8][1] = load_bitmap("src\\Resources\\SKELETON1\\SDU2.bmp",NULL);
            matrix[8][2] = load_bitmap("src\\Resources\\SKELETON1\\SDU3.bmp",NULL);
            matrix[8][3] = load_bitmap("src\\Resources\\SKELETON1\\SDU4.bmp",NULL);

            matrix[9][0] = load_bitmap("src\\Resources\\SKELETON1\\SDR1.bmp",NULL);
            matrix[9][1] = load_bitmap("src\\Resources\\SKELETON1\\SDR2.bmp",NULL);
            matrix[9][2] = load_bitmap("src\\Resources\\SKELETON1\\SDR3.bmp",NULL);
            matrix[9][3] = load_bitmap("src\\Resources\\SKELETON1\\SDR4.bmp",NULL);

            matrix[10][0] = load_bitmap("src\\Resources\\SKELETON1\\SDD1.bmp",NULL);
            matrix[10][1] = load_bitmap("src\\Resources\\SKELETON1\\SDD2.bmp",NULL);
            matrix[10][2] = load_bitmap("src\\Resources\\SKELETON1\\SDD3.bmp",NULL);
            matrix[10][3] = load_bitmap("src\\Resources\\SKELETON1\\SDD4.bmp",NULL);

            matrix[11][0] = load_bitmap("src\\Resources\\SKELETON1\\SDL1.bmp",NULL);
            matrix[11][1] = load_bitmap("src\\Resources\\SKELETON1\\SDL2.bmp",NULL);
            matrix[11][2] = load_bitmap("src\\Resources\\SKELETON1\\SDL3.bmp",NULL);
            matrix[11][3] = load_bitmap("src\\Resources\\SKELETON1\\SDL4.bmp",NULL);

            break;
       }
}


/**
Charge the matrix of the ambient map
*/
void Map::chargeMatrixAmbient(Drawable **matrix, int numMap)
{


    switch(numMap){

        case 1:{
                BITMAP *bitmapTest = load_bitmap("src\\Resources\\First_Map\\grass.bmp",NULL);
                matrix[0][0] = Drawable(bitmapTest, 0, 0 , 0, 0);



                /**
                1 = Arboles
                */
                bitmapTest = load_bitmap("src\\Resources\\First_Map\\arbol.bmp",NULL);
                matrix[1][0] = Drawable(bitmapTest, 50, 50 , 51, 50);

                bitmapTest = load_bitmap("src\\Resources\\First_Map\\arbol.bmp",NULL);
                matrix[1][1] = Drawable(bitmapTest, 500, 500 , 51, 50);



                /**
                2 = Casas
                */
                BITMAP *bitmapTest2 = load_bitmap("src\\Resources\\house1.bmp",NULL);
                matrix[2][0] = House(bitmapTest2, 150, 150, 228,138);

                BITMAP *bitmapTest3 = load_bitmap("src\\Resources\\house1.bmp",NULL);
                matrix[2][1] = House(bitmapTest3, 500, 150, 228,138);


                break;
        }

        case 2:{
                BITMAP *map2_bitmapTest = load_bitmap("src\\Resources\\rocks.bmp",NULL);
                matrix[0][0] = Drawable(map2_bitmapTest, 0, 0 , 0, 0);

                BITMAP *map2_bitmapTest2 = load_bitmap("src\\Resources\\house1.bmp",NULL);
                matrix[1][0] = House(map2_bitmapTest2, 150, 150, 228,138);

                map2_bitmapTest2 = load_bitmap("src\\Resources\\First_Map\\arbol.bmp",NULL);
                matrix[1][1] = Drawable(map2_bitmapTest2, 500, 500 , 51, 50);

                BITMAP *map2_bitmapTest3 = load_bitmap("src\\Resources\\house1.bmp",NULL);
                matrix[2][0] = House(map2_bitmapTest3, 150, 150, 228,138);

                BITMAP *bitmapTest3 = load_bitmap("src\\Resources\\house1.bmp",NULL);
                matrix[2][1] = House(bitmapTest3, 500, 150, 228,138);

                break;
        }
/*
        case 3:
                BITMAP *bitmapTest = load_bitmap("src\\Resources\\rocks.bmp",NULL);
                matrix[0][0] = Drawable(bitmapTest, 0, 0 , 0, 0);

                BITMAP *bitmapTest2 = load_bitmap("src\\Resources\\house1.bmp",NULL);
                matrix[0][1] = House(bitmapTest2, 150, 150, 228,138);

                break;

        case 4:
                BITMAP *bitmapTest = load_bitmap("src\\Resources\\rocks.bmp",NULL);
                matrix[0][0] = Drawable(bitmapTest, 0, 0 , 0, 0);

                BITMAP *bitmapTest2 = load_bitmap("src\\Resources\\house1.bmp",NULL);
                matrix[0][1] = House(bitmapTest2, 150, 150, 228,138);

                break;*/

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

int Map::getQuantOtherElements()
{
    return this->quantOtherElements;
}

int Map::getCol1Quantity()
{
    return this->col1Quantity;
}

int Map::getCol2Quantity()
{
    return this->col2Quantity;
}
