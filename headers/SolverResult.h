#ifndef TRAVELINGSALESMANCPP_SOLVERRESULT_H
#define TRAVELINGSALESMANCPP_SOLVERRESULT_H

#include <vector>
#include "City.h"

namespace ts {
    struct SolverResult {
    public:
        vector<City> result;
        time_t elapsedMiliseconds;
        int permutationCount;
    };
}

#endif //TRAVELINGSALESMANCPP_SOLVERRESULT_H
