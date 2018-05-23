#ifndef DAOMap_h
#define DAOMap_h

#include <vector>
#include "Map.h"

using namespace std;

class DAOMap {
    public:
        DAOMap();
        DAOMap(int difficult);
        vector<Map*> getMapList();
        Map* getMap(int id);
        int getDifficultGame();
        void setDifficultGame(int difficult);

    private:
        int difficultGame;
        int quantEnemies;
        int quantElementsAmbient;
        /**
        Numero autoincremental que se va incrementando a medida que se meten mapas en el vector
        */
        int numMap = 1;
        vector<Map*> mapList;


};


#endif //DAOMap_h
