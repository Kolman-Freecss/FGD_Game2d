#ifndef Map_h
#define Map_h
#include <allegro.h>
#include "Enemy.h"
#include <vector>

using namespace std;

class Map{

 private:
     vector<Enemy> enemies;

 protected:

 public:
    Map();
    //virtual ~Map();

};

#endif // Map_h
