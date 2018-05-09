#include "Animation.h"
#include <allegro.h>
#include <vector>

using namespace std;

Animation::Animation(){

}

//TODO futuro cambiar por string y en contructor hacer load de bitmaps (base de datos = string)
Animation::Animation(vector<BITMAP*> up, vector<BITMAP*> right, vector<BITMAP*> down, vector<BITMAP*> left){
    this.up = up;
    this.right = right;
    this.down = down;
    this.left = left;
}
BITMAP* Animation::getUp(int pos){
    return this.up[pos];
}

BITMAP* Animation:: getRight(int pos){
    return this.right[pos];
}

BITMAP* Animation:: getDown(int pos){
    return this.down[pos];
}

BITMAP* Animation:: getLeft(int pos){
    return this.left[pos];
}


