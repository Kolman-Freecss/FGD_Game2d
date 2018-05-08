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
    private:
        vector<Map> mapList;
        void chargeMatrixAnimations(BITMAP **matrix, int numMap, int lenght);
        void chargeMatrixAmbient(Drawable **matrix, int numMap, int lenght);

};


#endif //DAOMap_h
