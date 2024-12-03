#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

// Клас Airport (Аеропорт)
class Airport {
public:
    std::string name;
    int terminals;

    Airport() : name(""), terminals(0) {}
    Airport(const std::string& n, int t) : name(n), terminals(t) {}

    // Перевантаження операцій виведення
    friend std::ostream& operator<<(std::ostream& out, const Airport& a) {
        out << "Airport: " << a.name << ", Terminals: " << a.terminals;
        return out;
    }

    // Перевантаження операцій введення
    friend std::istream& operator>>(std::istream& in, Airport& a) {
        std::cout << "Enter airport name: ";
        in >> a.name;
        std::cout << "Enter number of terminals: ";
        in >> a.terminals;
        return in;
    }

    // Перевантаження операцій порівняння
    bool operator==(const Airport& other) const {
        return (name == other.name && terminals == other.terminals);
    }

    bool operator!=(const Airport& other) const {
        return !(*this == other);
    }
};

// Клас Aircraft (Літак)
class Aircraft {
public:
    std::string plane_number;
    int capacity;
    int occupied_seats;

    Aircraft() : plane_number(""), capacity(0), occupied_seats(0) {}
    Aircraft(const std::string& num, int cap, int occupied) : plane_number(num), capacity(cap), occupied_seats(occupied) {}

    // Перевантаження операцій виведення
    friend std::ostream& operator<<(std::ostream& out, const Aircraft& a) {
        out << "Plane Number: " << a.plane_number << ", Capacity: " << a.capacity << ", Occupied seats: " << a.occupied_seats;
        return out;
    }

    // Перевантаження операцій введення
    friend std::istream& operator>>(std::istream& in, Aircraft& a) {
        std::cout << "Enter plane number: ";
        in >> a.plane_number;
        std::cout << "Enter plane capacity: ";
        in >> a.capacity;
        std::cout << "Enter number of occupied seats: ";
        in >> a.occupied_seats;
        return in;
    }

    // Перевантаження арифметичної операції + (для зміни кількості зайнятих місць)
    Aircraft operator+(int seats) const {
        Aircraft new_aircraft = *this;
        new_aircraft.occupied_seats += seats;
        if (new_aircraft.occupied_seats > new_aircraft.capacity) {
            throw std::out_of_range("Occupied seats exceed plane capacity!");
        }
        return new_aircraft;
    }

    // Перевантаження арифметичної операції - (для звільнення місць)
    Aircraft operator-(int seats) const {
        Aircraft new_aircraft = *this;
        new_aircraft.occupied_seats -= seats;
        if (new_aircraft.occupied_seats < 0) {
            throw std::out_of_range("Occupied seats cannot be negative!");
        }
        return new_aircraft;
    }
};

// Клас City (Місто)
class City {
public:
    std::string city_name;
    int population;

    City() : city_name(""), population(0) {}
    City(const std::string& name, int pop) : city_name(name), population(pop) {}

    // Перевантаження операцій виведення
    friend std::ostream& operator<<(std::ostream& out, const City& c) {
        out << "City: " << c.city_name << ", Population: " << c.population;
        return out;
    }

    // Перевантаження операцій введення
    friend std::istream& operator>>(std::istream& in, City& c) {
        std::cout << "Enter city name: ";
        in >> c.city_name;
        std::cout << "Enter population: ";
        in >> c.population;
        return in;
    }

    // Перевантаження порівняння < (для порівняння кількості населення)
    bool operator<(const City& other) const {
        return population < other.population;
    }

    bool operator>(const City& other) const {
        return population > other.population;
    }

    bool operator==(const City& other) const {
        return population == other.population;
    }
};

// Демонстрація використання класів
int main() {
    try {
        Airport airport1, airport2;
        Aircraft aircraft1, aircraft2;
        City city1, city2;

        std::cout << "Enter details for Airport 1:\n";
        std::cin >> airport1;

        std::cout << "Enter details for Airport 2:\n";
        std::cin >> airport2;

        std::cout << "\nEnter details for Aircraft 1:\n";
        std::cin >> aircraft1;

        std::cout << "\nEnter details for Aircraft 2:\n";
        std::cin >> aircraft2;

        std::cout << "\nEnter details for City 1:\n";
        std::cin >> city1;

        std::cout << "\nEnter details for City 2:\n";
        std::cin >> city2;

        std::cout << "\nDetails for Airport 1:\n" << airport1 << std::endl;
        std::cout << "Details for Airport 2:\n" << airport2 << std::endl;

        std::cout << "\nDetails for Aircraft 1:\n" << aircraft1 << std::endl;
        std::cout << "Details for Aircraft 2:\n" << aircraft2 << std::endl;

        std::cout << "\nDetails for City 1:\n" << city1 << std::endl;
        std::cout << "Details for City 2:\n" << city2 << std::endl;

        // Перевірка арифметичних операцій
        aircraft1 = aircraft1 + 30;  // Додаємо 30 зайнятих місць
        std::cout << "\nAircraft 1 after adding 30 seats:\n" << aircraft1 << std::endl;

        aircraft1 = aircraft1 - 10;  // Зменшуємо зайняті місця на 10
        std::cout << "\nAircraft 1 after removing 10 seats:\n" << aircraft1 << std::endl;

        // Перевірка порівняння міст за населенням
        if (city1 < city2) {
            std::cout << city1.city_name << " has a smaller population than " << city2.city_name << ".\n";
        }
        else if (city1 > city2) {
            std::cout << city1.city_name << " has a larger population than " << city2.city_name << ".\n";
        }
        else {
            std::cout << city1.city_name << " and " << city2.city_name << " have the same population.\n";
        }

        // Перевірка порівняння аеропортів
        if (airport1 == airport2) {
            std::cout << "Both airports are identical.\n";
        }
        else {
            std::cout << "Airports are different.\n";
        }

    }
    catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}
