#include <cmath>
#include "../headers/Point.h"

double ts::Point::GetDistanceTo(Point other) {
    return sqrt(pow(other.x - x, 2) + pow(other.y - y, 2));
}

