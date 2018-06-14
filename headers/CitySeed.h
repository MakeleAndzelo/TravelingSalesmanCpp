#include <vector>
#include "../headers/City.h"

#ifndef TRAVELINGSALESMANCPP_CITYSEED_H
#define TRAVELINGSALESMANCPP_CITYSEED_H

namespace ts {
    /**
     * Klasa odpowiedzialna za stworzenie obiektów typu City
     *
     * @class CitySeed
     */
    class CitySeed {
    public:
        /**
         * Metoda tworząca obiekty typu City
         *
         * @param count ilość miast
         * @return vector<City>
         */
        vector<City> SeedData(int count);
    };
}

#endif //TRAVELINGSALESMANCPP_CITYSEED_H
