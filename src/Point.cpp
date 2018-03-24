//
// Created by Przemek on 2018-03-24.
//

#include <cmath>
#include "../headers/Point.h"

double Point::GetDistanceTo(Point *other) {
    return sqrt(pow(other->x - this->x, 2) + pow(other->y - this->y, 2));
}
