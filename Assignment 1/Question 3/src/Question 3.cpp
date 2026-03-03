/* Q3. Imagine you are tasked with creating a program to simulate a toll booth. The toll booth
keeps track of the number of vehicles that have passed through it and the total amount of
money collected. You need to implement a class TollBooth with appropriate data members
and member functions to accomplish this.
Here are the details for the TollBooth class:
1. DataMembers:
- totalVehicles: An integer to keep track of the total number of vehicles that have
passed through the toll booth.
- totalRevenue: A double to store the total revenue collected from tolls.
2. Member Functions:
1. voidreset():Resets both the totalVehicles and totalRevenue to zero.
2. void vehiclePayingToll(int vehicleType, double tollAmount): A
Accepts
ccepts an integer
vehicleType and a double tollAmount. The vehicleType represents the type of car (1
for standard car, 2 for truck, 3 for bus). The function should increment totalVehicles
by 1 and add tollAmount to totalRevenue based on the car type.
3. int getTotalVehicles()
etTotalVehicles() : A getter method that returns the total number of vehicles
passed through the booth.
4. Double getTotalRevenue(): A getter method that returns the total revenue collected.
3. Menu-DrivenProgram:
Write a menu-driven program in main() that allows the user to interact with the TollBooth
class:
- Display a menu with the following options:
1. Add a standard car and collect toll
2. Add a truck and collect toll
3. Add a bus and collect toll
4. Display total cars passed
5. Display total revenue collected
6. Reset booth statistics
7. Exit
- Implement the logic for each menu option using appropriate member functions of the
TollBooth class.
- Continue displaying the menu until the user chooses to exit.
- Define a fixed toll amount
nt for each type of car (e.g., RS.180
RS
for standard cars, Rs
Rs.300 for
trucks, Rs. 350 for buses) */

#include <iostream>

using namespace std;

class TollBooth {
private:
    int totalVehicles;
    double totalRevenue;

public:
    TollBooth() {
        totalVehicles = 0;
        totalRevenue = 0.0;
    }

    void reset() {
        totalVehicles = 0;
        totalRevenue = 0.0;
        cout << "Booth statistics have been reset." << endl;
    }

    void vehiclePayingToll(int vehicleType, double tollAmount) {
        totalVehicles++;
        totalRevenue += tollAmount;

        string typeStr;
        if (vehicleType == 1) typeStr = "Standard Car";
        else if (vehicleType == 2) typeStr = "Truck";
        else if (vehicleType == 3) typeStr = "Bus";

        cout << typeStr << " added. Toll of Rs. " << tollAmount << " collected." << endl;
    }

    int getTotalVehicles() {
        return totalVehicles;
    }

    double getTotalRevenue() {
        return totalRevenue;
    }
};

int main() {
    TollBooth booth;
    int choice;

    const double CAR_TOLL = 180.0;
    const double TRUCK_TOLL = 300.0;
    const double BUS_TOLL = 350.0;

    do {
        cout << "\n--- Toll Booth Management System ---" << endl;
        cout << "1. Add a standard car (Rs. 180)" << endl;
        cout << "2. Add a truck (Rs. 300)" << endl;
        cout << "3. Add a bus (Rs. 350)" << endl;
        cout << "4. Display total vehicles passed" << endl;
        cout << "5. Display total revenue collected" << endl;
        cout << "6. Reset booth statistics" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";

        while (!(cin >> choice)) {
            cout << "Invalid input. ";
            cin.clear();
            while (cin.get() != '\n');
        }

        switch (choice) {
            case 1:
                booth.vehiclePayingToll(1, CAR_TOLL);
                break;
            case 2:
                booth.vehiclePayingToll(2, TRUCK_TOLL);
                break;
            case 3:
                booth.vehiclePayingToll(3, BUS_TOLL);
                break;
            case 4:
                cout << "Total vehicles passed: " << booth.getTotalVehicles() << endl;
                break;
            case 5:
                cout << "Total revenue collected: Rs. " << booth.getTotalRevenue() << endl;
                break;
            case 6:
                booth.reset();
                break;
            case 7:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != 7);

    return 0;
}
