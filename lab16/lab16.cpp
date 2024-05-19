#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;

class Taxi {
private:
    string driverName;
    string taxiNumber;
    string carBrand;
    int yearOfUse;
    int mileage;

public:
    Taxi() : driverName(""), taxiNumber(""), carBrand(""), yearOfUse(0), mileage(0) {}

    Taxi(string driverName, string taxiNumber, string carBrand, int yearOfUse, int mileage)
        : driverName(driverName), taxiNumber(taxiNumber), carBrand(carBrand), yearOfUse(yearOfUse), mileage(mileage) {}

    void setDriverName(string name) { driverName = name; }
    void setTaxiNumber(string number) { taxiNumber = number; }
    void setCarBrand(string brand) { carBrand = brand; }
    void setYearOfUse(int year) { yearOfUse = year; }
    void setMileage(int miles) { mileage = miles; }

    string getDriverName() { return driverName; }
    string getTaxiNumber() { return taxiNumber; }
    string getCarBrand() { return carBrand; }
    int getYearOfUse() { return yearOfUse; }
    int getMileage() { return mileage; }

    void show() {
        cout << "Водій: " << driverName << ", Номер таксі: " << taxiNumber<< ", Марка машини: " << carBrand << ", Рік початку експлуатації: " << yearOfUse<< ", Пробіг: " << mileage << " км" << endl;
    }

    bool isAudi() { return carBrand == "Audi"; }

    bool isOlderThan3Years(int currentYear) { return (currentYear - yearOfUse) > 3; }

    bool isMileageMoreThan20000() { return mileage > 20000; }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int currentYear = 2024;

    const int SIZE = 5;
    Taxi taxis[SIZE] = {
        Taxi("Іван Сирота", "AH1815CK", "Audi", 2020, 25000),
        Taxi("Софія Любченко", "AX1658OK", "BMW", 2021, 15000),
        Taxi("Олексій Ковальов", "AI1114CC", "Audi", 2018, 30000),
        Taxi("Андрій Бебін", "AA2400BO", "Mercedes", 2017, 40000),
        Taxi("Сергій Притула", "AH1109OX", "Volkswagen", 2013, 100000)
    };

    cout << "Машини марки Audi:" << endl;
    for (int i = 0; i < SIZE; ++i) {
        if (taxis[i].isAudi()) {
            taxis[i].show();
        }
    }

    cout << "\nТаксі, які експлуатуються більше 3 років:" << endl;
    for (int i = 0; i < SIZE; ++i) {
        if (taxis[i].isOlderThan3Years(currentYear)) {
            taxis[i].show();
        }
    }

    cout << "\nТаксі з пробігом більше 20 000 км:" << endl;
    for (int i = 0; i < SIZE; ++i) {
        if (taxis[i].isMileageMoreThan20000()) {
            taxis[i].show();
        }
    }

    return 0;
}
