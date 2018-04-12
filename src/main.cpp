#include <iostream>
#include "../headers/HamiltonianPath.h"

using namespace std;
using namespace ts;

int main() {
    HamiltonianPath hamiltonianPath;

    City city1;
    city1.location = {1, 2};
    city1.name = "1";
    City city2;
    city2.location = {2, 3};
    city1.name = "2";
    City city3;
    city3.location = {4, 1};
    city1.name = "3";
    City city4;
    city4.location = {5, 6};
    city1.name = "4";

    vector<City> cities;
    cities.push_back(city1);
    cities.push_back(city2);
    cities.push_back(city3);
    cities.push_back(city4);

    cities = hamiltonianPath.GetUsingGreedy(cities, 0);

    for (auto city : cities) {
        cout << city.name << endl;
    }

    return 0;
}