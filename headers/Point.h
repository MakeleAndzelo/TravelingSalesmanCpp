#ifndef TRAVELINGSALESMANCPP_POINT_H
#define TRAVELINGSALESMANCPP_POINT_H

namespace ts {
    class Point {
    public:
        double x, y;

        double GetDistanceTo(Point *other);
    };
}


#endif //TRAVELINGSALESMANCPP_POINT_H
