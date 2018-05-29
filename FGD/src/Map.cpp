#include <House.h>
#include "Map.h"
#include "allegro.h"
#include "Enemy.h"
#include "GameStateManager.h"
#include <iostream>
using namespace std;


Map::Map()
{
}

Map::Map(int quantEnemies, int quantElementsOfAmbient, int numMap)
{

    this->numMap = numMap;
    this->quantEnemies = quantEnemies;
    this->quantElementsOfAmbient = quantElementsOfAmbient;

    /**
    Segons el numero de mapa que cargem assignem una quantitat d'elements per saber
    cuanta memoria hem de reservar y quants elements hem de recorrer a la hora de printar
    */
    switch(numMap){

        case 1:
                this->quantOtherElements = 10;
                //Trees
                this->col1Quantity = 0;
                //Houses y caja huerto
                this->col2Quantity = 5;
                this->col3Quantity = 17;
                this->col4Quantity = 0;
                this->col5Quantity = 0;
                this->col6Quantity = 0;

                break;

        case 2:
                this->quantOtherElements = 1;
                //Tumbas
                this->col1Quantity = 18;
                this->col2Quantity = 3;
                this->col3Quantity = 4;
                //Casas y fuente
                this->col4Quantity = 2;
                this->col5Quantity = 0;
                this->col6Quantity = 0;

                break;

        case 3:
                this->quantOtherElements = 1;
                this->col1Quantity = 4;
                this->col2Quantity = 6;
                //Caballos
                this->col3Quantity = 5;
                //vallas
                this->col4Quantity = 6;
                //farolas y cajas lampara
                this->col5Quantity = 18;
                this->col6Quantity = 0;

                break;

        case 4:
                this->quantOtherElements = 2;
                this->col1Quantity = 1;
                this->col2Quantity = 12;
                //Agua
                this->col3Quantity = 3;
                //tiburon
                this->col4Quantity = 6;
                this->col5Quantity = 0;
                this->col6Quantity = 0;

                break;

        case 5:
                this->quantOtherElements = 1;
                this->col1Quantity = 0;
                this->col2Quantity = 0;
                this->col3Quantity = 0;
                this->col4Quantity = 0;
                this->col5Quantity = 0;
                this->col6Quantity = 0;

                break;
    }

    /**
    Reservamos memoria para la matriz segons la quantitat d'elements a cada posici�
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
                case 3: this->ambientMatrix[i] = new Drawable[this->col3Quantity];
                        break;
                case 4: this->ambientMatrix[i] = new Drawable[this->col4Quantity];
                        break;
                case 5: this->ambientMatrix[i] = new Drawable[this->col5Quantity];
                        break;
                case 6: this->ambientMatrix[i] = new Drawable[this->col6Quantity];
                        break;
            }
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
    this->chargeMatrixAmbient(this->ambientMatrix, numMap);


    if(numMap != 4 && numMap != 5){
        /**
        Generacion dinamica de enemigos comprovando la colision con otros enemigos, player o ambiente
        */
        srand(time(NULL));
        for(int i = 0; i < this->quantEnemies; i++){
            int positionX = rand()%(800-75);
            int positionY = rand()%(600-64);
            Enemy *enemy = new Enemy(matrixAnimationsEnemy, 100, 20, 1, 20, positionX, positionY, 64, 75);

            bool generado = false;
            while(!generado){
                    //col with enemies
                generado = true;
                for(int j = 0; j < this->getVectorEnemies().size(); j++){
                    while (enemy->collision(getVectorEnemies().at(j))){
                        positionX = rand()%(800-75);
                        positionY = rand()%(600-64);
                        enemy->setXandAX(positionX);
                        enemy->setYandAY(positionY);
                        if(!enemy->collision(getVectorEnemies().at(j))){
                            j = 0;
                            generado = false;
                        }
                    }
                }
            //col with ambient
                for (int i = 0; i < this->getQuantElementsOfAmbient(); i++) {
                        switch(i){
                            case 1 : {for (int j = 0; j < this->getCol1Quantity(); j++) {
                                            while (enemy->collision(&this->getAmbientMatrix()[i][j])) {
                                                    positionX = rand()%(800-75);
                                                    positionY = rand()%(600-64);
                                                    enemy->setXandAX(positionX);
                                                    enemy->setYandAY(positionY);
                                                    if(!enemy->collision(&this->getAmbientMatrix()[i][j])){
                                                        j = 0;
                                                        generado = false;
                                                    }
                                                }
                                        }
                                        break;
                            }

                            case 2:{for (int j = 0; j < this->getCol2Quantity(); j++) {
                                            while (enemy->collision(&this->getAmbientMatrix()[i][j])) {
                                                    positionX = rand()%(800-75);
                                                    positionY = rand()%(600-64);
                                                    enemy->setXandAX(positionX);
                                                    enemy->setYandAY(positionY);
                                                    if(!enemy->collision(&this->getAmbientMatrix()[i][j])){
                                                        j = 0;
                                                        generado = false;
                                                    }
                                                }
                                        }
                                    break;
                            }

                        }

                }
                /**
                Recuadro donde aparece el player
                */
               if(positionX <= 300 && positionY >= 220)
                {
                    positionX = rand()%(800-75);
                    positionY = rand()%(600-64);
                    enemy->setXandAX(positionX);
                    enemy->setYandAY(positionY);
                    generado = false;
                }
            }

            this->enemies.push_back(enemy);

        }
    }
    //Generacion enemigos terminada


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
                BITMAP *bitmapTest = load_bitmap("src\\Resources\\Map_1\\grass.bmp",NULL);
                matrix[0][0] = Drawable(bitmapTest, 0, 0 , 0, 0);
                bitmapTest = load_bitmap("src\\Resources\\Map_1\\huerto.bmp",NULL);
                matrix[0][1] = Drawable(bitmapTest, 0, 473 , 127, 64);
                matrix[0][2] = Drawable(bitmapTest, 64, 473 , 127, 64);
                matrix[0][3] = Drawable(bitmapTest, 128, 473 , 127, 64);
                matrix[0][4] = Drawable(bitmapTest, 0, 409 , 64, 64);
                matrix[0][5] = Drawable(bitmapTest, 64, 409 , 64, 64);
                matrix[0][6] = Drawable(bitmapTest, 128, 409 , 64, 64);
                bitmapTest = load_bitmap("src\\Resources\\Map_1\\espantapajaros.bmp",NULL);
                matrix[0][7] = Drawable(bitmapTest, 64, 473 , 51, 30);
                bitmapTest = load_bitmap("src\\Resources\\Map_1\\camino_piedra.bmp",NULL);
                matrix[0][8] = Drawable(bitmapTest, 706, 380 , 94, 94);
                matrix[0][9] = Drawable(bitmapTest, 612, 380 , 94, 94);




                /**
                1 = Arboles
                */
                bitmapTest = load_bitmap("src\\Resources\\Map_1\\arbol_2.bmp",NULL);
                //matrix[1][0] = Drawable(bitmapTest, 50, 130 , 64, 62);
                //matrix[1][1] = Drawable(bitmapTest, 220, 55 , 64, 62);



                /**
                2 = Casas y la cajas del huerto
                */
                bitmapTest = load_bitmap("src\\Resources\\Map_1\\casa.bmp",NULL);
                matrix[2][0] = House(bitmapTest, 730, 0, 96,70);
                matrix[2][1] = House(bitmapTest, 650, 0, 96,70);
                bitmapTest = load_bitmap("src\\Resources\\Map_1\\casa_granja.bmp",NULL);
                matrix[2][2] = House(bitmapTest, 0, GameStateManager::SIZE_WINDOW_X/2-150, 94,64);
                matrix[2][3] = House(bitmapTest, 71, GameStateManager::SIZE_WINDOW_X/2-150, 94,64);
                bitmapTest = load_bitmap("src\\Resources\\Map_1\\cajas_huerto.bmp",NULL);
                matrix[2][4] = House(bitmapTest, 0, 0, 128,128);

                /**
                2 = Columnas y el pozo
                */
                bitmapTest = load_bitmap("src\\Resources\\Map_1\\columna.bmp",NULL);
                //TODO constructor cambiar columna

                //Drawable(itmapAmbient, x, int y, int width, int height, int colPosX, int colPosY, int colRadius, int coltype) {

                matrix[3][0] = Drawable(bitmapTest, 300, 50, 70,24, 0, 45, 0, 3);
                matrix[3][1] = Drawable(bitmapTest, 300, 180, 70,24, 0, 45, 0, 3);
                matrix[3][2] = Drawable(bitmapTest, 300, 300, 70,24, 0, 45, 0, 3);
                matrix[3][3] = Drawable(bitmapTest, 300, 450, 70,24, 0, 45, 0, 3);
                matrix[3][4] = Drawable(bitmapTest, 580, 50, 70,24, 0, 45, 0, 3);
                matrix[3][5] = Drawable(bitmapTest, 580, 180, 70,24, 0, 45, 0, 3);
                matrix[3][6] = Drawable(bitmapTest, 580, 300, 70,24, 0, 45, 0, 3);
                matrix[3][7] = Drawable(bitmapTest, 580, 450, 70,24, 0, 45, 0, 3);
                bitmapTest = load_bitmap("src\\Resources\\Map_1\\pozo.bmp",NULL);
                matrix[3][8] = Drawable(bitmapTest, 650, 150, 87,72, 0, 45, 0, 3);
                bitmapTest = load_bitmap("src\\Resources\\Map_1\\bordillo_piedra.bmp",NULL);
                matrix[3][9] = Drawable(bitmapTest, 736, 350, 30,64, 0, 0, 0, 2);
                matrix[3][10] = Drawable(bitmapTest, 672, 350, 30,64, 0, 0, 0, 2);
                matrix[3][11] = Drawable(bitmapTest, 608, 350, 30,64, 0, 0, 0, 2);
                matrix[3][12] = Drawable(bitmapTest, 736, 474, 30,64, 0, 0, 0, 2);
                matrix[3][13] = Drawable(bitmapTest, 672, 474, 30,64, 0, 0, 0, 2);
                matrix[3][14] = Drawable(bitmapTest, 608, 474, 30,64, 0, 0, 0, 2);
                bitmapTest = load_bitmap("src\\Resources\\Map_1\\paja_huerto.bmp",NULL);
                matrix[3][15] = Drawable(bitmapTest, 180, 473 , 58, 64, 0, 0, 0, 2);
                matrix[3][16] = Drawable(bitmapTest, 180, 540 , 58, 64, 0, 0, 0, 2);

                break;
        }

        case 2:{
                BITMAP *map2_bitmapTest = load_bitmap("src\\Resources\\Map_2\\background_map2.bmp",NULL);
                matrix[0][0] = Drawable(map2_bitmapTest, 0, 0 , 0, 0);

                map2_bitmapTest = load_bitmap("src\\Resources\\Map_2\\cruz_tumba.bmp",NULL);
                matrix[1][0] = Drawable(map2_bitmapTest, 20, 30 , 64, 47, 0, 0, 0, 2);
                matrix[1][1] = Drawable(map2_bitmapTest, 80, 30 , 64, 47, 0, 0, 0, 2);
                matrix[1][2] = Drawable(map2_bitmapTest, 140, 30 , 64, 47, 0, 0, 0, 2);
                matrix[1][3] = Drawable(map2_bitmapTest, 200, 30 , 64, 47, 0, 0, 0, 2);
                matrix[1][4] = Drawable(map2_bitmapTest, 20, 110 , 64, 47, 0, 0, 0, 2);
                matrix[1][5] = Drawable(map2_bitmapTest, 80, 110 , 64, 47, 0, 0, 0, 2);
                matrix[1][6] = Drawable(map2_bitmapTest, 140, 110 , 64, 47, 0, 0, 0, 2);
                matrix[1][7] = Drawable(map2_bitmapTest, 200, 110 , 64, 47, 0, 0, 0, 2);
                matrix[1][8] = Drawable(map2_bitmapTest, 20, 190 , 64, 47, 0, 0, 0, 2);
                matrix[1][9] = Drawable(map2_bitmapTest, 80, 190 , 64, 47, 0, 0, 0, 2);
                matrix[1][10] = Drawable(map2_bitmapTest, 140, 190 , 64, 47, 0, 0, 0, 2);
                matrix[1][11] = Drawable(map2_bitmapTest, 200, 190 , 64, 47, 0, 0, 0, 2);
                map2_bitmapTest = load_bitmap("src\\Resources\\Map_2\\valla_tumbas.bmp",NULL);
                matrix[1][12] = Drawable(map2_bitmapTest, 0, 254 , 32, 73, 0, 0, 0, 2);
                matrix[1][13] = Drawable(map2_bitmapTest, 73, 254 , 32, 73, 0, 0, 0, 2);
                matrix[1][14] = Drawable(map2_bitmapTest, 146, 254 , 32, 73, 0, 0, 0, 2);
                map2_bitmapTest = load_bitmap("src\\Resources\\Map_2\\valla_tumbas_rotada.bmp",NULL);
                matrix[1][15] = Drawable(map2_bitmapTest, 247, 0, 74, 33, 0, 0, 0, 2);
                matrix[1][16] = Drawable(map2_bitmapTest, 247, 74, 74, 33, 0, 0, 0, 2);
                matrix[1][17] = Drawable(map2_bitmapTest, 247, 148, 74, 33, 0, 0, 0, 2);

                map2_bitmapTest = load_bitmap("src\\Resources\\Map_2\\agujero_ojos.bmp",NULL);
                matrix[2][0] = Drawable(map2_bitmapTest,GameStateManager::SIZE_WINDOW_X/2 - 40, GameStateManager::SIZE_WINDOW_Y /2 - 40,  79, 81, 0, 0, 0, 2);
                matrix[2][1] = Drawable(map2_bitmapTest,GameStateManager::SIZE_WINDOW_X/2 - 150, 470,  79, 81, 40, 40, 40, 1);
                matrix[2][2] = Drawable(map2_bitmapTest,GameStateManager::SIZE_WINDOW_X/2 + 250, 470,  79, 81, 40, 40, 40, 1);

                map2_bitmapTest = load_bitmap("src\\Resources\\Map_2\\arbol_map2.bmp",NULL);
                matrix[3][0] = Drawable(map2_bitmapTest,470, 100,  99, 1000, 52, 92, 22, 1);
                matrix[3][1] = Drawable(map2_bitmapTest,670, 180,  99, 100, 52, 92, 22, 1);
                matrix[3][2] = Drawable(map2_bitmapTest,350, 501,  99, 100, 52, 92, 22, 1);
                matrix[3][3] = Drawable(map2_bitmapTest,540, 501,  99, 100, 52, 92, 22, 1);

                map2_bitmapTest = load_bitmap("src\\Resources\\Map_2\\casa_tumba.bmp",NULL);
                matrix[4][0] = House(map2_bitmapTest, 600, 80,  120, 74);
                map2_bitmapTest = load_bitmap("src\\Resources\\Map_2\\fuente.bmp",NULL);
                matrix[4][1] = House(map2_bitmapTest, 660, 300,  99, 140);



                break;
        }

       case 3:{
                BITMAP *bitmapTest = load_bitmap("src\\Resources\\Map_3\\rocks.bmp",NULL);
                matrix[0][0] = Drawable(bitmapTest, 0, 0 , 0, 0);

                bitmapTest = load_bitmap("src\\Resources\\Map_3\\establo.bmp",NULL);
                matrix[1][0] = Drawable(bitmapTest, 0, 0 , 70, 62, 0, 0, 0, 2);
                matrix[1][1] = Drawable(bitmapTest, 62, 0 , 70, 62, 0, 0, 0, 2);
                matrix[1][2] = Drawable(bitmapTest, 124, 0 , 70, 62, 0, 0, 0, 2);
                matrix[1][3] = Drawable(bitmapTest, 186, 0 , 70, 62, 0, 0, 0, 2);

                bitmapTest = load_bitmap("src\\Resources\\Map_3\\tienda_campaña.bmp",NULL);
                matrix[2][0] = House(bitmapTest, 479, 0 , 88, 107);
                matrix[2][1] = House(bitmapTest, 586, 0 , 88, 107);
                matrix[2][2] = House(bitmapTest, 693, 0 , 88, 107);
                bitmapTest = load_bitmap("src\\Resources\\Map_3\\lagito.bmp",NULL);
                matrix[2][3] = House(bitmapTest, 120, 190 , 125, 109);
                bitmapTest = load_bitmap("src\\Resources\\Map_3\\cajas.bmp",NULL);
                matrix[2][4] = House(bitmapTest, 260, 0 , 56, 50);
                matrix[2][5] = House(bitmapTest, 260, 56 , 56, 50);

                bitmapTest = load_bitmap("src\\Resources\\Map_3\\caballo.bmp",NULL);
                matrix[3][0] = Drawable(bitmapTest, 20, 480 , 67, 27, 0, 0, 0, 2);
                matrix[3][1] = Drawable(bitmapTest, 100, 460, 67, 27, 0, 0, 0, 2);
                bitmapTest = load_bitmap("src\\Resources\\Map_3\\caballo_derecha.bmp",NULL);
                matrix[3][2] = Drawable(bitmapTest, 140, 500 , 48, 68, 0, 0, 0, 2);
                matrix[3][3] = Drawable(bitmapTest, 50, 380 , 48, 68, 0, 0, 0, 2);
                matrix[3][4] = Drawable(bitmapTest, 150, 390 , 48, 68, 0, 0, 0, 2);

                bitmapTest = load_bitmap("src\\Resources\\Map_3\\valla_tumbas.bmp",NULL);
                matrix[4][0] = Drawable(bitmapTest, 0, 346 , 32, 73, 0, 0, 0, 2);
                matrix[4][1] = Drawable(bitmapTest, 73, 346 , 32, 73, 0, 0, 0, 2);
                matrix[4][2] = Drawable(bitmapTest, 146, 346 , 32, 73, 0, 0, 0, 2);
                bitmapTest = load_bitmap("src\\Resources\\Map_3\\valla_tumbas_rotada.bmp",NULL);
                matrix[4][3] = Drawable(bitmapTest, 219, 378, 74, 33, 0, 0, 0, 2);
                matrix[4][4] = Drawable(bitmapTest, 219, 452, 74, 33, 0, 0, 0, 2);
                matrix[4][5] = Drawable(bitmapTest, 219, 526, 74, 33, 0, 0, 0, 2);

                bitmapTest = load_bitmap("src\\Resources\\Map_3\\farola.bmp",NULL);
                matrix[5][0] = Drawable(bitmapTest, 320, 20, 44, 8, 4, 40, 4, 1);
                matrix[5][1] = Drawable(bitmapTest, 450, 20, 44, 8, 4, 40, 4, 1);
                matrix[5][2] = Drawable(bitmapTest, 320, 100, 44, 8, 4, 40, 4, 1);
                matrix[5][3] = Drawable(bitmapTest, 450, 100, 44, 8, 4, 40, 4, 1);
                matrix[5][4] = Drawable(bitmapTest, 340, 180, 44, 8, 4, 40, 4, 1);
                matrix[5][5] = Drawable(bitmapTest, 480, 180, 44, 8, 4, 40, 4, 1);
                matrix[5][6] = Drawable(bitmapTest, 370, 260, 44, 8, 4, 40, 4, 1);
                matrix[5][7] = Drawable(bitmapTest, 510, 260, 44, 8, 4, 40, 4, 1);
                matrix[5][8] = Drawable(bitmapTest, 410, 340, 44, 8, 4, 40, 4, 1);
                matrix[5][9] = Drawable(bitmapTest, 570, 340, 44, 8, 4, 40, 4, 1);
                matrix[5][10] = Drawable(bitmapTest, 440, 420, 44, 8, 4, 40, 4, 1);
                matrix[5][11] = Drawable(bitmapTest, 680, 340, 44, 8, 4, 40, 4, 1);
                matrix[5][12] = Drawable(bitmapTest, 680, 340, 44, 8, 4, 40, 4, 1);
                matrix[5][13] = Drawable(bitmapTest, 560, 470, 44, 8, 4, 40, 4, 1);
                matrix[5][14] = Drawable(bitmapTest, 680, 470, 44, 8, 4, 40, 4, 1);
                bitmapTest = load_bitmap("src\\Resources\\Map_3\\cajas_lampara.bmp",NULL);
                matrix[5][15] = Drawable(bitmapTest, 650, 150, 60, 47, 0, 21, 0, 3);
                matrix[5][16] = Drawable(bitmapTest, 720, 150, 60, 47, 0, 21, 0, 3);
                bitmapTest = load_bitmap("src\\Resources\\Map_3\\deposito_agua.bmp",NULL);
                matrix[5][17] = Drawable(bitmapTest, 300, 450, 128, 82, 41, 112, 28, 1);

                break;
       }


        case 4:  {
                BITMAP *bitmapTest = load_bitmap("src\\Resources\\Map_4\\rocks.bmp",NULL);
                matrix[0][0] = Drawable(bitmapTest, 0, 0 , 0, 0);
                bitmapTest = load_bitmap("src\\Resources\\Map_4\\puente.bmp",NULL);
                matrix[0][1] = Drawable(bitmapTest, 378, 350 , 91, 233);

                bitmapTest = load_bitmap("src\\Resources\\Map_4\\castle.bmp",NULL);
                matrix[1][0] = Drawable(bitmapTest, 300, 0 , 236, 280);

                bitmapTest = load_bitmap("src\\Resources\\Map_4\\tumba_castillo.bmp",NULL);
                matrix[2][0] = Drawable(bitmapTest, 700, 20 , 31, 30);
                matrix[2][1] = Drawable(bitmapTest, 730, 20 , 31, 30);
                matrix[2][2] = Drawable(bitmapTest, 760, 20 , 31, 30);
                matrix[2][3] = Drawable(bitmapTest, 700, 70 , 31, 30);
                matrix[2][4] = Drawable(bitmapTest, 730, 70 , 31, 30);
                matrix[2][5] = Drawable(bitmapTest, 760, 70 , 31, 30);
                matrix[2][6] = Drawable(bitmapTest, 50, 20 , 31, 30);
                matrix[2][7] = Drawable(bitmapTest, 80, 20 , 31, 30);
                matrix[2][8] = Drawable(bitmapTest, 110, 20 , 31, 30);
                matrix[2][9] = Drawable(bitmapTest, 50, 70 , 31, 30);
                matrix[2][10] = Drawable(bitmapTest, 80, 70 , 31, 30);
                matrix[2][11] = Drawable(bitmapTest, 110, 70 , 31, 30);

                bitmapTest = load_bitmap("src\\Resources\\Map_4\\agua.bmp",NULL);
                matrix[3][0] = Drawable(bitmapTest, 0, 350 , 91, 189);
                matrix[3][1] = House(bitmapTest, 189, 350 , 91, 189);
                matrix[3][2] = House(bitmapTest, 611, 350 , 91, 189);

                bitmapTest = load_bitmap("src\\Resources\\Map_4\\aleta_tiburon.bmp",NULL);
                matrix[4][0] = Drawable(bitmapTest, 50, 370 , 27, 42);
                matrix[4][1] = Drawable(bitmapTest, 120, 390 , 27, 42);
                matrix[4][2] = Drawable(bitmapTest, 200, 380 , 27, 42);
                matrix[4][3] = Drawable(bitmapTest, 650, 390 , 27, 42);
                matrix[4][4] = Drawable(bitmapTest, 690, 370 , 27, 42);
                matrix[4][5] = Drawable(bitmapTest, 300, 390 , 27, 42);


                break;
        }

        case 5:  {
                BITMAP *bitmapTest = load_bitmap("src\\Resources\\Map_5\\castle_dentro.bmp",NULL);
                matrix[0][0] = Drawable(bitmapTest, 0, 0 , 0, 0);

                break;
        }

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

int Map::getCol3Quantity()
{
    return this->col3Quantity;
}
int Map::getCol4Quantity()
{
    return this->col4Quantity;
}
int Map::getCol5Quantity()
{
    return this->col5Quantity;
}
int Map::getCol6Quantity()
{
    return this->col6Quantity;
}

