#ifndef Map_h
#define Map_h
#include <allegro.h>
#include "Enemy.h"
#include "Drawable.h"
#include <vector>

using namespace std;

class Map{

 public:
    Map();
    Map(int quantEnemies, int quantElementsOfAmbient, int numMap);
    void setAmbientMatrix(Drawable **ambientMatrix);
    vector<Enemy*> getVectorEnemies();
    Drawable **getAmbientMatrix();
    int getQuantElementsOfAmbient();
    //virtual ~Map();

    int getQuantOtherElements();
    int getCol1Quantity();
    int getCol2Quantity();
    int getCol3Quantity();
    int getCol4Quantity();
    int getCol5Quantity();
    int getCol6Quantity();

    int numMap;

 private:

    int quantOtherElements;
     int col1Quantity;
     int col2Quantity;
     int col3Quantity;
     int col4Quantity;
     int col5Quantity;
     int col6Quantity;


    vector<Enemy*> enemies;

    Drawable **ambientMatrix;
    int sizeOfMatrix;

    /**
    Cantidad de enemigos que habra que estara asociado al nivel del juego que sea actualmente
    */
    int quantEnemies;
    int quantElementsOfAmbient;

    void chargeMatrixAnimationsOfEnemy(BITMAP ***matrix, int numMap);
    void chargeMatrixAmbient(Drawable **matrix, int numMap);

 protected:




};

#endif // Map_h
