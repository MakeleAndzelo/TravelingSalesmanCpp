#include <cmath>
#include "../headers/Point.h"

double ts::Point::GetDistanceTo(Point *other) {
    return sqrt(pow(other->x - this->x, 2) + pow(other->y - this->y, 2));
}

