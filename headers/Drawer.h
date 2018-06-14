#ifndef TRAVELINGSALESMANCPP_PATHDRAWER_H
#define TRAVELINGSALESMANCPP_PATHDRAWER_H

#include <iostream>
#include <GL/gl.h>
#include <unistd.h>
#include "../headers/CitySeed.h"

namespace ts {
    /**
     * Klasa odpowiedzialna za wyświetlanie na ekranie
     *
     * @class Drawer
     */
    class Drawer {
    private:
        /**
         * @field cities vector przechowujący miasta
         */
        vector<City> cities;
    public:
        /**
         * Konstruktor klasy
         *
         * @param cities vector miast
         */
        Drawer(vector<City> cities);

        /**
         * Metoda odpowiedzialna za wyświetlanie miast
         */
        void drawCities();

        /**
         * Metoda odpowiedzialna za rysowanie drog
         */
        void drawPath();
    };
}

#endif //TRAVELINGSALESMANCPP_PATHDRAWER_H
