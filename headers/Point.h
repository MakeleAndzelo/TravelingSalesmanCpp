//
// Created by Przemek on 2018-03-24.
//

#ifndef TRAVELINGSALESMANCPP_POINT_H
#define TRAVELINGSALESMANCPP_POINT_H


class Point {
public:
    double x, y;

    double GetDistanceTo(Point *other);
};


#endif //TRAVELINGSALESMANCPP_POINT_H
