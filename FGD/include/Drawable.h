#ifndef Drawable_h
#define Drawable_h



class Drawable{

 protected:

    int x;
    int y;
    int height;
    int width;


 public:
    Drawable();
    //virtual ~Drawable();
    int getX();
    int getY();
    int getHeight();
    int getWidth();





};

#endif // Drawable_h
