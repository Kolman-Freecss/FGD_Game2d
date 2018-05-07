#ifndef DAOMap_h
#define DAOMap_h

#include <vector>
#include "Map.h"

using namespace std;

class DAOMap {
    public:
        DAOMap();
        vector<Map> getMapList();
        Map getMap(int id);

};


#endif //DAOMap_h
