#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Клас, що описує місто
class City {
private:
    string name;
    string region;
    int population;

public:
    City(string name, string region, int population)
        : name(name), region(region), population(population) {
    }

    string getCityName() const {
        return name;
    }

    string getRegion() const {
        return region;
    }
};

// Клас, що описує літак
class Plane {
private:
    int planeNumber;
    int capacity;
    int occupiedSeats;

public:
    Plane(int planeNumber, int capacity)
        : planeNumber(planeNumber), capacity(capacity), occupiedSeats(0) {
    }

    int getPlaneNumber() const {
        return planeNumber;
    }

    int getCapacity() const {
        return capacity;
    }

    int getOccupiedSeats() const {
        return occupiedSeats;
    }

    void occupySeats(int seats) {
        if (occupiedSeats + seats <= capacity) {
            occupiedSeats += seats;
        }
        else {
            cout << "Not enough free seats available!" << endl;
        }
    }

    void unoccupySeats(int seats) {
        if (occupiedSeats >= seats) {
            occupiedSeats -= seats;
        }
        else {
            cout << "There are not enough occupied seats to unoccupy!" << endl;
        }
    }

    bool isFullyOccupied() const {
        return occupiedSeats == capacity;
    }

    double getOccupancyRate() const {
        return static_cast<double>(occupiedSeats) / capacity;
    }
};

// Клас, що описує аеропорт
class Airport {
private:
    string airportName;
    City city;
    vector<Plane> planes;

public:
    Airport(string airportName, City city)
        : airportName(airportName), city(city) {
    }

    string getCityName() const {
        return city.getCityName();
    }

    string getRegionName() const {
        return city.getRegion();
    }

    double getAverageOccupancy() const {
        if (planes.empty()) return 0.0;

        double totalOccupancy = 0;
        for (const Plane& plane : planes) {
            totalOccupancy += plane.getOccupancyRate();
        }
        return totalOccupancy / planes.size();
    }

    void addPlane(int planeNumber, int capacity) {
        planes.push_back(Plane(planeNumber, capacity));
    }

    void occupyPlane(int planeNumber, int seats) {
        for (Plane& plane : planes) {
            if (plane.getPlaneNumber() == planeNumber) {
                plane.occupySeats(seats);
                return;
            }
        }
        cout << "Plane with number " << planeNumber << " not found!" << endl;
    }

    void unoccupyPlane(int planeNumber, int seats) {
        for (Plane& plane : planes) {
            if (plane.getPlaneNumber() == planeNumber) {
                plane.unoccupySeats(seats);
                return;
            }
        }
        cout << "Plane with number " << planeNumber << " not found!" << endl;
    }

    void removePlane(int planeNumber) {
        planes.erase(remove_if(planes.begin(), planes.end(),
            [planeNumber](const Plane& plane) { return plane.getPlaneNumber() == planeNumber; }),
            planes.end());
    }

    int getTotalFreeSeats() const {
        int totalFreeSeats = 0;
        for (const Plane& plane : planes) {
            totalFreeSeats += (plane.getCapacity() - plane.getOccupiedSeats());
        }
        return totalFreeSeats;
    }

    int getFullyOccupiedPlanesPercentage() const {
        if (planes.empty()) return 0;

        int fullyOccupiedCount = 0;
        for (const Plane& plane : planes) {
            if (plane.isFullyOccupied()) {
                fullyOccupiedCount++;
            }
        }
        return (fullyOccupiedCount * 100) / planes.size();
    }

    void displayPlanes() const {
        for (const Plane& plane : planes) {
            cout << "Plane Number: " << plane.getPlaneNumber() << ", Capacity: " << plane.getCapacity()
                << ", Occupied Seats: " << plane.getOccupiedSeats() << endl;
        }
    }
};

// Тестування програми
int main() {
    City city("Kyiv", "Kyiv Oblast", 3000000);
    Airport airport("Kyiv International", city);

    // Додаємо літаки
    airport.addPlane(101, 200);
    airport.addPlane(102, 150);
    airport.addPlane(103, 180);

    // Займаємо місця
    airport.occupyPlane(101, 150);
    airport.occupyPlane(102, 150);
    airport.occupyPlane(103, 100);

    // Виводимо інформацію
    cout << "City: " << airport.getCityName() << ", Region: " << airport.getRegionName() << endl;
    cout << "Average Occupancy: " << airport.getAverageOccupancy() * 100 << "%" << endl;
    cout << "Total Free Seats: " << airport.getTotalFreeSeats() << endl;
    cout << "Fully Occupied Planes: " << airport.getFullyOccupiedPlanesPercentage() << "%" << endl;

    airport.displayPlanes();

    // Списуємо літак
    airport.removePlane(102);
    cout << "After removing plane 102:" << endl;
    airport.displayPlanes();

    return 0;
}