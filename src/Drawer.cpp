#include <zconf.h>
#include "../headers/Drawer.h"

using namespace ts;

Drawer::Drawer(vector<City> cities)
{
    this->cities = cities;
}

void Drawer::drawCities()
{
    glColor3d(0.50, 0.60, 0.92);
    for (auto city : cities) {
        glRectd(city.location.x, city.location.y, city.location.x + 2, city.location.y + 2);
    }
}

void Drawer::drawPath()
{
    glBegin(GL_LINE_STRIP);
    glColor3ub(100, 200, 150);
    for (auto city : cities) {
        glVertex2f(city.location.x, city.location.y);
    }
    glEnd();
}
