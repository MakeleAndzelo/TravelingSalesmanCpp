#ifndef TRAVELINGSALESMANCPP_IPATHSOLVER_H
#define TRAVELINGSALESMANCPP_IPATHSOLVER_H

#include "City.h"
#include "SolverResult.h"
#include <vector>

namespace ts {
    class IPathSolver {
    public:
        virtual SolverResult Solve(vector<City> cities, int startIndex) = 0;
    };
}
#endif //TRAVELINGSALESMANCPP_IPATHSOLVER_H
