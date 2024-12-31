#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

// Car class to hold car details
class Car {
public:
    string model;
    string licensePlate;
    bool isAvailable;
    double dailyRentalRate;

        // Constructor
    Car(string m, string lp, double rate) {
        model = m;
        licensePlate = lp;
        isAvailable = true;
        dailyRentalRate = rate;
    }