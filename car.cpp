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

     // Function to display rental information
    void displayRentalInfo() {
        cout << "Customer: " << customerName << endl;
        cout << "Car Model: " << rentedCar->model << endl;
        cout << "Rental Days: " << rentalDays << endl;
        cout << "Total Cost: $" << fixed << setprecision(2) << totalCost << endl;
        cout << "-------------------------" << endl;
    }
};

// CarRentalSystem class to manage the entire rental process
class CarRentalSystem {
private:
    vector<Car> cars;
    vector<Rental> rentals;

    public:
    // Add car to the system
    void addCar(string model, string licensePlate, double dailyRentalRate) {
        Car newCar(model, licensePlate, dailyRentalRate);
        cars.push_back(newCar);
    }

    // Display available cars
    void displayAvailableCars() {
        cout << "Available Cars: " << endl;
        for (auto &car : cars) {
            if (car.isAvailable) {
                car.displayCarInfo();
            }
        }
    }

    // Rent a car
    void rentCar() {
        string customerName;
        string licensePlate;
        int rentalDays;

        
        cout << "Enter customer name: ";
        cin >> customerName;
        cout << "Enter car's license plate: ";
        cin >> licensePlate;
        cout << "Enter rental days: ";
        cin >> rentalDays;

         // Find the car by license plate
        Car* carToRent = nullptr;
        for (auto &car : cars) {
            if (car.licensePlate == licensePlate && car.isAvailable) {
                carToRent = &car;
                break;
            }
        }

         // Find the car by license plate
        Car* carToRent = nullptr;
        for (auto &car : cars) {
            if (car.licensePlate == licensePlate && car.isAvailable) {
                carToRent = &car;
                break;
            }
        }

        if (carToRent != nullptr) {
            carToRent->isAvailable = false;
            Rental newRental(customerName, carToRent, rentalDays);
            rentals.push_back(newRental);
            cout << "Car rented successfully!" << endl;
            newRental.displayRentalInfo();
        } else {
            cout << "Car not available or invalid license plate!" << endl;
        }
    }

     // Find the car by license plate
        Car* carToRent = nullptr;
        for (auto &car : cars) {
            if (car.licensePlate == licensePlate && car.isAvailable) {
                carToRent = &car;
                break;
            }
        }

        if (carToRent != nullptr) {
            carToRent->isAvailable = false;
            Rental newRental(customerName, carToRent, rentalDays);
            rentals.push_back(newRental);
            cout << "Car rented successfully!" << endl;
            newRental.displayRentalInfo();
        } else {
            cout << "Car not available or invalid license plate!" << endl;
        }
    }

    // Return a car
    void returnCar() {
        string licensePlate;

        cout << "Enter car's license plate to return: ";
        cin >> licensePlate;

         // Find the car by license plate
        for (auto &car : cars) {
            if (car.licensePlate == licensePlate && !car.isAvailable) {
                car.isAvailable = true;
                cout << "Car returned successfully!" << endl;
                return;
            }
        }

        cout << "Car not found or already returned!" << endl;
    }


 // Display rental history
    void displayRentalHistory() {
        cout << "Rental History: " << endl;
        for (auto &rental : rentals) {
            rental.displayRentalInfo();
        }
    }
};

int main() {
    CarRentalSystem system;
    
    // Adding some cars to the system
    system.addCar("Toyota Camry", "ABC123", 50.0);
    system.addCar("Honda Accord", "XYZ789", 45.0);
    system.addCar("Ford Mustang", "LMN456", 75.0);

    int choice;

