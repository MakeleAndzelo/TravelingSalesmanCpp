#include "../headers/HamiltonianPath.h"

using namespace ts;

vector<City> HamiltonianPath::GetUsingBruteforce(vector<City> cities, int startIndex) {

}

vector<City> HamiltonianPath::GetUsingNearestNeighbour(vector<City> cities, int startIndex) {
    vector<City> newCities;
    auto iterator = cities.begin();
    newCities.insert(iterator, cities.at((unsigned long long int) startIndex));

    auto currentCity = *iterator;
    cities.erase(iterator);

    while (!cities.empty()) {
        City nearestCity = iterator[0];
        auto nearestCityIterator = cities.begin();

        for (iterator = cities.begin(); iterator != cities.end(); iterator++) {
            auto distanceToNearest = currentCity.location.GetDistanceTo(&nearestCity.location);
            auto distanceToTemp = currentCity.location.GetDistanceTo(&iterator->location);

            if (distanceToNearest > distanceToTemp) {
                nearestCity = *iterator;
                nearestCityIterator = iterator;
            }
        }
        cities.erase(nearestCityIterator);
        newCities.push_back(nearestCity);
    }
    return
            newCities;
}