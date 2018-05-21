#include <random>
#include <ctime>
#include "../headers/CitySeed.h"

using namespace std;
using namespace ts;

vector<City> CitySeed::SeedData(int count) {
    random_device randomDevice;

    default_random_engine engine(randomDevice());
    engine.seed((unsigned int)time(nullptr));
    uniform_int_distribution<int> dist(0, 1000);

    vector<City> cities = vector<City>((unsigned long long int) count);
    for (int i = 0; i < count; ++i) {
        City newCity = City();
        newCity.name = std::to_string(i);
        newCity.location.x = dist(engine);
        newCity.location.y = dist(engine);
        cities[i] = newCity;
    }
    return cities;
}

vector<int[]> CitySeed::SeedNeighborhood(int count, int maxNeighbors) {
    random_device randomDevice;

    default_random_engine engine(randomDevice());
    engine.seed((unsigned int)time(nullptr));
    uniform_int_distribution<int> maxDist(0, maxNeighbors);
    uniform_int_distribution<int> neighborsDist(0, count);

    vector<int[]> neighbors = vector<int[]>((unsigned long long int) count);
    for (int i = 0; i < count; ++i) {
        for (int j = 0; j < maxDist(engine); ++j) {
            int neighborhood[maxNeighbors];
            neighborhood[j] = neighborsDist(engine);
        }
    }
    return neighbors;
}
