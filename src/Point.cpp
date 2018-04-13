#include <cmath>
#include "../headers/Point.h"

using namespace ts;

double Point::GetDistanceTo(Point other) {
    return sqrt(pow(other.x - x, 2) + pow(other.y - y, 2));
}

