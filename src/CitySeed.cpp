#include <random>
#include "../headers/CitySeed.h"

using namespace std;

vector<City> CitySeed::SeedData(int count) {
    random_device randomDevice;
    default_random_engine engine(randomDevice());
    uniform_int_distribution<int> dist(1, 10);

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
