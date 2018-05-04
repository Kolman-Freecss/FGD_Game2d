#ifndef Map_h
#define Map_h
#include <allegro.h>

class Map{

 private:
    BITMAP images[5];

 protected:
    int speed;
    int damage;
    int health;
    int shield;

 public:
    Character();
    //virtual ~Character();
    int getSpeed();
    BITMAP[] getImages();

};

#endif // Character_h
