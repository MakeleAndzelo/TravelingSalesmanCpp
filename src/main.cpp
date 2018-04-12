#include <iostream>
#include "../headers/HamiltonianPath.h"
#include "../headers/CitySeed.h"

using namespace std;
using namespace ts;

int main() {
    HamiltonianPath hamiltonianPath;
    CitySeed citySeed;

    vector<City> cities = citySeed.SeedData(5);
    cities = hamiltonianPath.GetUsingGreedy(cities, 1);

    for (auto city : cities) {
        cout << city.name << endl;
    }

    return 0;
}