#include <limits>
#include <iostream>
#include "../headers/HamiltonianPath.h"

using namespace ts;

vector<City> currentMinVector = vector<City>();
double minLength = numeric_limits<double>::infinity();

void HamiltonianPath::GetUsingBruteforce(vector<City> cities, int startIndex, int i) {
    if (currentMinVector.empty()) {
        swap(cities[0], cities[startIndex]);
    }

    if (i == cities.size()) {
        double lenght = 0.0;
        for (int j = 0; j < cities.size() - 1; ++j)
            lenght += cities[j].location.GetDistanceTo(cities[j + 1].location);

        if (lenght < minLength) {
            currentMinVector = cities;
            minLength = lenght;
        }
        return;
    }

    for (int j = i; j < cities.size(); ++j) {
        swap(cities[i], cities[j]);
        GetUsingBruteforce(cities, startIndex, i + 1);
        swap(cities[i], cities[j]);
    }
}

vector<City> HamiltonianPath::GetBruteforceResult() {
    if (currentMinVector.empty())
        cout << "Vector is empty." << endl;
    return currentMinVector;
}

vector<City> HamiltonianPath::GetUsingGreedy(vector<City> cities, int startIndex) {
    vector<City> newCities = vector<City>();
    newCities.push_back(cities.at((unsigned long long int) startIndex));

    auto citiesIterator = cities.begin() + startIndex;
    auto currentCity = *citiesIterator;
    cities.erase(citiesIterator);

    while (!cities.empty()) {
        City nearestCity = *cities.begin();
        auto nearestCityIterator = cities.begin();

        for (citiesIterator = cities.begin(); citiesIterator != cities.end(); citiesIterator++) {
            auto distanceToNearest = currentCity.location.GetDistanceTo(nearestCity.location);
            auto distanceToTemp = currentCity.location.GetDistanceTo(citiesIterator->location);

            if (distanceToNearest > distanceToTemp) {
                nearestCity = *citiesIterator;
                nearestCityIterator = citiesIterator;
            }
        }
        cities.erase(nearestCityIterator);
        newCities.push_back(nearestCity);
    }

    return newCities;
}