#include <iostream>
#include "../headers/HamiltonianPath.h"
#include "../headers/CitySeed.h"

using namespace std;
using namespace ts;

int main() {
    HamiltonianPath hamiltonianPath;
    CitySeed citySeed;

    vector<City> cities = citySeed.SeedData(5);
    hamiltonianPath.GetUsingBruteforce(cities, 1);

    cities = hamiltonianPath.GetBruteforceResult();

    for (auto city : cities) {
        cout << city.name << endl;
    }

    return 0;
}