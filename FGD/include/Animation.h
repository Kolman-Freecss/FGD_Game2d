#ifndef Animation_h
#define Animation_h
#include <allegro.h>
#include<vector>

using namespace std;

class Animation{

 private:
    vector<BITMAP*> UP;
    vector<BITMAP*> RIGHT;
    vector<BITMAP*> DOWN;
    vector<BITMAP*> LEFT;

 public:
    Animation();
    Animation(vector<BITMAP*> UP, vector<BITMAP*> RIGHT, vector<BITMAP*> DOWN, vector<BITMAP*> LEFT);
    //virtual ~Drawable();
    BITMAP* getUp();
    BITMAP* getRight();
    BITMAP* getDown();
    BITMAP* getLeft();
    s



};

#endif // Animation_h
