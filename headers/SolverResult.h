#ifndef TRAVELINGSALESMANCPP_SOLVERRESULT_H
#define TRAVELINGSALESMANCPP_SOLVERRESULT_H

#include <vector>
#include "City.h"

using namespace std;

namespace ts {
    struct SolverResult {
    public:
        vector<City> result;
        time_t time;
        int permutationCount;
    };
}

#endif //TRAVELINGSALESMANCPP_SOLVERRESULT_H
