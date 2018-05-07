#include "DAOMap.h"
#include "Map.h"
#include <vector>
#include "allegro.h"
#include "Enemy.h"

using namespace std;

vector<Map> mapList;

DAOMap::DAOMap()
{
    //mapList.push_back();
    Drawable **firstMapAmbient;
    vector<Enemy> firtMapEnemies;

    firtMapEnemies.push_back(Enemy());

    mapList.push_back(Map(firtMapEnemies, firstMapAmbient));



}

vector<Map> DAOMap::getMapList()
{
    return mapList;
}

Map DAOMap::getMap(int id)
{
    return mapList.at(id);
}



