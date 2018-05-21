#include <iostream>
#include "../headers/HamiltonianPath.h"
#include "../headers/CitySeed.h"

using namespace std;
using namespace ts;

#define N 5

int main() {
    HamiltonianPath hamiltonianPath;
    CitySeed citySeed;

    vector<int[]> neighbors = citySeed.SeedNeighborhood(N, 3);

    vector<City> cities = citySeed.SeedData(N);
    hamiltonianPath.GetUsingBruteforce(cities, 0);

    cities = hamiltonianPath.GetBruteforceResult();

    for (auto city : cities) {
        cout << city.name << endl;
    }

    delete(&cities);
    delete(&hamiltonianPath);
    delete(&citySeed);
    return 0;
}