#ifndef TRAVELINGSALESMANCPP_PATHDRAWER_H
#define TRAVELINGSALESMANCPP_PATHDRAWER_H

#include <iostream>
#include <GL/gl.h>
#include <unistd.h>
#include "../headers/CitySeed.h"

namespace ts {
    class Drawer {
    private:
        vector<City> cities;
    public:
        Drawer(vector<City>);
        void drawCities();
        void drawPath();
    };
}

#endif //TRAVELINGSALESMANCPP_PATHDRAWER_H
