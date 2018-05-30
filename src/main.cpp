#include <iostream>
#include "../headers/IPathSolver.h"
#include "../headers/CitySeed.h"
#include "../headers/GreedySolver.h"

using namespace std;
using namespace ts;

#define N 5

int main() {
    IPathSolver *pathSolver = new GreedySolver();
    CitySeed citySeed;

    vector<City> startCities = citySeed.SeedData(N);
    SolverResult solverResult = pathSolver->Solve(startCities, 0);

    for (auto city : solverResult.result) {
        cout << city.name << endl;
    }

    delete(&startCities);
    delete(&pathSolver);
    delete(&citySeed);
    delete(&solverResult);
    return 0;
}