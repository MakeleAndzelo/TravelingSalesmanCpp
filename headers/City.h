//
// Created by przem on 02.04.2018.
//

#ifndef TRAVELINGSALESMANCPP_CITY_H
#define TRAVELINGSALESMANCPP_CITY_H


#include <string>
#include "Point.h"

using namespace std;

namespace ts {
    class City {
    public:
        Point location;
        string name;
    };
}


#endif //TRAVELINGSALESMANCPP_CITY_H
