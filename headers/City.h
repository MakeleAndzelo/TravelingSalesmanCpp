#ifndef TRAVELINGSALESMANCPP_CITY_H
#define TRAVELINGSALESMANCPP_CITY_H

#include <string>
#include "Point.h"

using namespace std;

namespace ts {
    /**
     * Klasa opisujaca miasto
     *
     * @class City
     */
    class City {
    public:
        /**
         * @field location obiekt przechowujacy wspolrzedne miasta
         */
        Point location;
        /**
         * @field name pole przechowujace nazwe miasta
         */
        string name;
    };
}


#endif //TRAVELINGSALESMANCPP_CITY_H
