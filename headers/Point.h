#ifndef TRAVELINGSALESMANCPP_POINT_H
#define TRAVELINGSALESMANCPP_POINT_H

namespace ts {
    /**
     * Klasa opisujaca punkt na ekranie
     *
     * @class Point
     */
    class Point {
    public:
        /**
         * @field x wspolrzedna x
         */
        double x;

        /**
         * @field y wspolrzedna y
         */
        double y;

        /**
         * Klasa liczaca odleglosc do innego punktu na ekranie
         *
         * @param other punkt, do ktorego ma byc zmierzona odleglosc
         * @return odleglosc do punktu
         */
        double GetDistanceTo(Point other);
    };
}


#endif //TRAVELINGSALESMANCPP_POINT_H
