#ifndef DAOManager_h
#define DAOManager_h


#include "DAOMap.h"


class DAOManager{
    public:
        static DAOMap daoMap;


        static DAOMap getDaoMap(int mode);
        //DAOManager();
        //virtual ~DAOManager();


};

#endif // DAOManager_h
