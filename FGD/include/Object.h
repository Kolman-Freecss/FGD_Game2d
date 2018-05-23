#ifndef Object_h
#define Object_h

#include <allegro.h>

class Object{

 public:
     Object();
     Object(BITMAP *imageOfObject, int width, int height);
     BITMAP *getImageOfObject();
     int getWidth();
     int getHeight();

 protected:
    int level;

 private:
    BITMAP *imageOfObject;
    int width;
    int height;

};

#endif // Object_h
