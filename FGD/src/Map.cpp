#include "Map.h"
#include "allegro.h"
#include "Enemy.h"

Map::Map()
{
}

Map::Map(vector<Enemy> enemies, Drawable **ambientMatrix)
{
    this->enemies = enemies;
    this->ambientMatrix = ambientMatrix;


}

void Map::setAmbientMatrix(Drawable **ambientMatrix)
{
    this->ambientMatrix = ambientMatrix;
}

vector<Enemy> Map::getVectorEnemies()
{
    return this->enemies;
}

Drawable** Map::getAmbientMatrix()
{
    return this->ambientMatrix;
}
