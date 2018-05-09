#ifndef Animation_h
#define Animation_h
#include <allegro.h>
#include<vector>

using namespace std;

class Animation{

 private:
    vector<BITMAP*> up;
    vector<BITMAP*> right;
    vector<BITMAP*> down;
    vector<BITMAP*> left;

 public:
    Animation();
    Animation(vector<BITMAP*> up, vector<BITMAP*> right, vector<BITMAP*> down, vector<BITMAP*> left);
    //virtual ~Drawable();
    BITMAP* getUp(int pos);
    BITMAP* getRight(int pos);
    BITMAP* getDown(int pos);
    BITMAP* getLeft(int pos);
};

#endif // Animation_h
