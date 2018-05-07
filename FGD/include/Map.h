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
    BITMAP **staticMatriz;

 protected:

 public:
    Map();
    Map(vector<Enemy> enemies, Drawable **mapMatriz);
    void setStaticMatriz();
    //virtual ~Map();



};

#endif // Map_h
