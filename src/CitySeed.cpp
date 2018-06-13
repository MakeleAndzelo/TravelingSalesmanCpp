#include <random>
#include <ctime>
#include "../headers/CitySeed.h"

using namespace std;
using namespace ts;

vector<City> CitySeed::SeedData(int count) {
    random_device randomDevice;

    default_random_engine engine(randomDevice());
    engine.seed((unsigned int)time(nullptr));
    uniform_int_distribution<int> dist(0, 400);

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