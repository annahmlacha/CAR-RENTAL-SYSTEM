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

     // Function to display car details
    void displayCarInfo() {
        cout << "Model: " << model << endl;
        cout << "License Plate: " << licensePlate << endl;
        cout << "Available: " << (isAvailable ? "Yes" : "No") << endl;
        cout << "Daily Rental Rate: $" << dailyRentalRate << endl;
        cout << "-------------------------" << endl;
    }
};

// Rental class to handle the rental process
class Rental {
public:
    string customerName;
    Car* rentedCar;
    int rentalDays;
    double totalCost;

     // Constructor
    Rental(string name, Car* car, int days) {
        customerName = name;
        rentedCar = car;
        rentalDays = days;
        totalCost = days * car->dailyRentalRate;
    }