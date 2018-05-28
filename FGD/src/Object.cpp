#include "Object.h"
#include <allegro.h>

Object::Object()
{}

Object::Object(BITMAP *imageOfObject, int width, int height)
{
    this->imageOfObject = imageOfObject;
    this->width = width;
    this->height = height;
}

BITMAP* Object::getImageOfObject()
{
    this->imageOfObject;
}

int Object::getWidth()
{
    this->width;
}

int Object::getHeight()
{
    this->height;
}

int Object::getLevel()
{
    this->level;
}
