#ifndef TRAVELINGSALESMANCPP_SOLVERRESULT_H
#define TRAVELINGSALESMANCPP_SOLVERRESULT_H

#include <vector>
#include "City.h"
#include <chrono>

using namespace std;
using namespace chrono;

namespace ts {
    struct SolverResult {
    public:
        vector<City> result;
        duration<double> duration;
        int permutationCount;
    };
}

#endif //TRAVELINGSALESMANCPP_SOLVERRESULT_H
