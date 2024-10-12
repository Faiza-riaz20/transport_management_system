#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

class City {
public:
    string name;

    City(string name) : name(name) {}
};

class BusOperator {
public:
    string name;
    vector<pair<string, string> > routes; // vector of city pairs representing routes

    BusOperator(string name) : name(name) {}
    
    void addRoute(string from, string to) {
        routes.push_back(make_pair(from, to));
    }
};

class JourneyPlanner {
private:
    vector<City> cities;
    map<string, vector<string> > roadNetwork; // adjacency list
    vector<BusOperator> busOperators;

public:
    void addCity(string cityName) {
        cities.push_back(City(cityName));
    }

    void addRoad(string from, string to) {
        roadNetwork[from].push_back(to);
        roadNetwork[to].push_back(from); // assuming bidirectional roads
    }

    void addBusOperator(BusOperator busOperator) {
        busOperators.push_back(busOperator);
    }

    void displayRoutes(string from, string to) {
        cout << "Routes from " << from << " to " << to << ":\n";
        for (size_t i = 0; i < busOperators.size(); ++i) {
            for (size_t j = 0; j < busOperators[i].routes.size(); ++j) {
                if (busOperators[i].routes[j].first == from && busOperators[i].routes[j].second == to) {
                    cout << "Operator: " << busOperators[i].name << endl;
                }
            }
        }
    }

    void displayCities() {
        cout << "Cities:\n";
        for (size_t i = 0; i < cities.size(); ++i) {
            cout << cities[i].name << endl;
        }
    }
};

int main() {
    JourneyPlanner jp;

    // Adding cities
    jp.addCity("Islamabad");
    jp.addCity("Lahore");
    jp.addCity("Karachi");
    jp.addCity("Peshawar");
    jp.addCity("Quetta");
    // Add more cities...

    // Adding roads
    jp.addRoad("Islamabad", "Lahore");
    jp.addRoad("Lahore", "Karachi");
    jp.addRoad("Peshawar", "Quetta");
    // Add more roads...

    // Adding bus operators
    BusOperator daewoo("Daewoo");
    daewoo.addRoute("Islamabad", "Lahore");
    daewoo.addRoute("Lahore", "Karachi");

    BusOperator faisalMovers("Faisal Movers");
    faisalMovers.addRoute("Islamabad", "Lahore");
    faisalMovers.addRoute("Peshawar", "Quetta");

    // Add more bus operators...

    jp.addBusOperator(daewoo);
    jp.addBusOperator(faisalMovers);
    // Add more bus operators...

    // Display cities
    jp.displayCities();

    // Display routes from Islamabad to Lahore
    jp.displayRoutes("Islamabad", "Lahore");

    return 0;
}

