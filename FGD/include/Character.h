#ifndef Character_h
#define Character_h



class Character {


 protected:

    virtual int getX();

    virtual int getY();


 protected:
    int x;
    int y;
    int damage;
    int health;
    int shield;
};

#endif // Character_h
