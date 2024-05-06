#include <iostream>
#include <string>
#include <ctime>

class Vehicle {
private:
    std::string vehicleID;
    std::string brand;
    std::string model;
    int year;
    std::string color;

public:
    // Constructor
    Vehicle(std::string id, std::string brand, std::string model, int year, std::string color) {
        vehicleID = id;
        this->brand = brand;
        this->model = model;
        this->year = year;
        this->color = color;
    }

    // Getter and setter methods for all attributes
    std::string getVehicleID() const { return vehicleID; }
    void setVehicleID(std::string id) { vehicleID = id; }

    std::string getBrand() const { return brand; }
    void setBrand(std::string brand) { this->brand = brand; }

    std::string getModel() const { return model; }
    void setModel(std::string model) { this->model = model; }

    int getYear() const { return year; }
    void setYear(int year) { this->year = year; }

    std::string getColor() const { return color; }
    void setColor(std::string color) { this->color = color; }

    // Method to display full vehicle information
    void displayInfo() const {
        std::cout << "Vehicle ID: " << vehicleID << std::endl;
        std::cout << "Brand: " << brand << std::endl;
        std::cout << "Model: " << model << std::endl;
        std::cout << "Year: " << year << std::endl;
        std::cout << "Color: " << color << std::endl;
    }

    // Method to check if vehicle is vintage
    bool isVintage() const {
        time_t currentTime;
        time(&currentTime);
        struct tm* currentLocalTime = localtime(&currentTime);
        int currentYear = currentLocalTime->tm_year + 1900; // Convert from years since 1900 to actual year
        return (currentYear - year >= 25);
    }
};

int main() {
    std::string id, brand, model, color;
    int year;

    // Input from user
    std::cout << "Enter Vehicle ID: ";
    std::cin >> id;
    std::cout << "Enter Brand: ";
    std::cin >> brand;
    std::cout << "Enter Model: ";
    std::cin >> model;
    std::cout << "Enter Year: ";
    std::cin >> year;
    std::cout << "Enter Color: ";
    std::cin >> color;

    // Create Vehicle object
    Vehicle myCar(id, brand, model, year, color);

    // Display vehicle information
    std::cout << "\nVehicle Information:\n";
    myCar.displayInfo();

    // Check if vehicle is vintage
    if (myCar.isVintage()) {
        std::cout << "This vehicle is vintage." << std::endl;
    } else {
        std::cout << "This vehicle is not vintage." << std::endl;
    }

    return 0;
}

