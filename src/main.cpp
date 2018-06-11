#include <iostream>
#include "../headers/IPathSolver.h"
#include "../headers/CitySeed.h"
#include "../headers/GreedySolver.h"
#include "../headers/BruteforceSolver.h"

using namespace std;
using namespace ts;

enum SolverType {
    Greedy,
    Bruteforce
};

IPathSolver *createSolver(enum SolverType type);

SolverResult startMenu();

void endMenu(SolverResult result);

int main() {
    SolverResult result = startMenu();
    endMenu(result);
    return 0;
}

SolverResult startMenu() {
    int citiesCout, solverType;
    cout << "Podaj liczbe miast";
    cin >> citiesCout;
    cout << "Podaj algorytm wykonania" << endl
         << "0: greedy" << endl
         << "1: bruteforce";
    cin >> solverType;

    IPathSolver *solver = createSolver((enum SolverType) solverType);

    CitySeed citySeed;

    vector<City> startCities = citySeed.SeedData(citiesCout);
    SolverResult solverResult = solver->Solve(startCities, 0);

    delete(solver);

    return solverResult;
}

void endMenu(SolverResult result) {
    cout << "KONIEC" << endl;
    cout << "Liczba permutacji:" << endl;
    cout << result.permutationCount << endl;
    cout << "Czas:" << endl;
    cout << result.elapsedMiliseconds + " ms" << endl;

    cout << "Trasa: ";
    for (auto city : result.result) {
        cout << city.name + " ";
    }
}

IPathSolver *createSolver(enum SolverType type) {
    switch (type) {
        case Greedy:
            return new GreedySolver();
            break;
        case Bruteforce:
            return new BruteforceSolver();
            break;
    }
}