#ifndef TRAVELINGSALESMANCPP_GREEDYSOLVER_H
#define TRAVELINGSALESMANCPP_GREEDYSOLVER_H

#include "IPathSolver.h"

namespace ts {
    class GreedySolver : public IPathSolver {
    public:
        SolverResult Solve(vector<City> cities, int startIndex) override;
    };
}

#endif //TRAVELINGSALESMANCPP_GREEDYSOLVER_H
