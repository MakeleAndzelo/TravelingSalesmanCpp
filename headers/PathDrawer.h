#ifndef TRAVELINGSALESMANCPP_PATHDRAWER_H
#define TRAVELINGSALESMANCPP_PATHDRAWER_H

#include <iostream>
#include <GL/gl.h>
#include <unistd.h>
#include "../headers/HamiltonianPath.h"
#include "../headers/CitySeed.h"

namespace ts {
    class PathDrawer {
    public:
        void draw(vector<City>);
    };
}

#endif //TRAVELINGSALESMANCPP_PATHDRAWER_H
