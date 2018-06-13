#ifndef TRAVELINGSALESMANCPP_BRUTEFORCESOLVER_H
#define TRAVELINGSALESMANCPP_BRUTEFORCESOLVER_H

#include "IPathSolver.h"

namespace ts {
    class BruteforceSolver : public IPathSolver {
    public:
        SolverResult Solve(vector<City> cities, int startIndex) override;

    private:
        void FindUsingBruteforce(vector<City> cities, int startIndex, int i);
    };
}

#endif //TRAVELINGSALESMANCPP_BRUTEFORCESOLVER_H
