#ifndef Map_h
#define Map_h
#include <allegro.h>
#include "Enemy.h"
#include "Drawable.h"
#include <vector>

using namespace std;

class Map{

 private:

    vector<Enemy> enemies;
    Drawable **ambientMatrix;

 protected:

 public:
    Map();
    Map(vector<Enemy> enemies, Drawable **mapMatrix);
    void setAmbientMatrix(Drawable **ambientMatrix);
    vector<Enemy> getVectorEnemies();
    Drawable **getAmbientMatrix();
    //virtual ~Map();



};

#endif // Map_h
