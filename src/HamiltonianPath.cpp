#include "../headers/HamiltonianPath.h"

using namespace ts;

vector<City> currentMinVector = vector<City>();
double minLength = numeric_limits<double>::infinity();

void HamiltonianPath::GetUsingBruteforce(vector<City> cities, int startIndex, int i) {
    if (currentMinVector.empty())
        currentMinVector.push_back(cities.at(startIndex));

    if (i == cities.size()) {
        double lenght = 0.0;
        for (int j = 0; j < cities.size() - 1; ++j)
            lenght += cities[i].location.GetDistanceTo(&cities[i + 1].location);
        if (lenght < minLength) {
            currentMinVector = cities;
            minLength = lenght;
        }
        return;
    }

    for (int j = i; i < cities.size(); ++i) {
        swap(cities[i], cities[j]);
        GetUsingBruteforce(cities, startIndex, i + 1);
        swap(cities[i], cities[j]);
    }

}

vector<City> HamiltonianPath::GetUsingGreedy(vector<City> cities, int startIndex) {
    vector<City> newCities = vector<City>();
    newCities.push_back(cities.at((unsigned long long int) startIndex));

    auto newCitiesIterator = cities.begin();

    auto currentCity = *newCitiesIterator;
    cities.erase(newCitiesIterator);

    while (!cities.empty()) {
        City nearestCity = newCitiesIterator[0];
        auto nearestCityIterator = cities.begin();

        for (newCitiesIterator = cities.begin(); newCitiesIterator != cities.end(); newCitiesIterator++) {
            auto distanceToNearest = currentCity.location.GetDistanceTo(&nearestCity.location);
            auto distanceToTemp = currentCity.location.GetDistanceTo(&newCitiesIterator->location);

            if (distanceToNearest > distanceToTemp) {
                nearestCity = *newCitiesIterator;
                nearestCityIterator = newCitiesIterator;
            }
        }
        cities.erase(nearestCityIterator);
        newCities.push_back(nearestCity);
    }

    return newCities;
}

vector<City> HamiltonianPath::GetUsingGraph(vector<City> cities, int startIndex) {
    return vector<City>();
}
