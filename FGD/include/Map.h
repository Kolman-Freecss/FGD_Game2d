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
    int getCol0Quantity();

    void setCol0Quantity(int col0Quantity);

    int getCol1Quantity();

    void setCol1Quantity(int col1Quantity);

    int getCol2Quantity();

    void setCol2Quantity(int col2Quantity);

    int getCol3Quantity();

    void setCol3Quantity(int col3Quantity);


private:

    int col0Quantity; //ELEMENTOS SIN COLISION + BACKGROUND
    int col1Quantity;
    int col2Quantity;
    int col3Quantity;

    vector<Enemy*> enemies;

    Drawable **ambientMatrix;

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
