#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Class to represent a hotel room
class Room {
public:
    int roomNumber;
    bool isBooked;

    Room(int number) : roomNumber(number), isBooked(false) {}
};

// Class to represent a customer record
class Customer {
public:
    string name;
    int roomNumber;

    Customer(string customerName, int number) : name(customerName), roomNumber(number) {}
};

class HotelManagementSystem {
private:
    vector<Room> rooms;
    vector<Customer> customers;

public:
    HotelManagementSystem(int totalRooms) {
        for (int i = 1; i <= totalRooms; ++i) {
            rooms.push_back(Room(i));
        }
    }

    void bookRoom() {
        int roomNumber;
        string customerName;

        cout << "Enter Room Number to Book: ";
        cin >> roomNumber;
        cout << "Enter Customer Name: ";
        cin >> customerName;

        if (roomNumber <= rooms.size() && !rooms[roomNumber - 1].isBooked) {
            rooms[roomNumber - 1].isBooked = true;
            customers.push_back(Customer(customerName, roomNumber));
            cout << "Room " << roomNumber << " has been booked by " << customerName << ".\n";
        } else {
            cout << "Room " << roomNumber << " is either already booked or invalid.\n";
        }
    }

    void displayAvailableRooms() {
        cout << "Available Rooms: \n";
        for (auto &room : rooms) {
            if (!room.isBooked) {
                cout << "Room " << room.roomNumber << " is available.\n";
            }
        }
    }

    void displayCustomerRecords(){
        if (customers.empty()){
            cout << "No customer records found. \n";
        } else {
            cout << "Customer Records: \n";
            for (auto &customer : customers){
                cout << "Customer Name: " << customer.name << ", Room Number: " << customer.roomNumber <<"\n";
            }
        }
    }

    void editCustomerRecords(){
        string customerName;
        cout << "Enter the name of the customer to edit: ";
        cin >> customerName;

        bool found = false;
        for (auto &customer : customers){
            if (customer.name == customerName){
                found = true;
                cout << "Customer found: " << customer.name << ", Room Number: " << customer.roomNumber <<"\n";
                cout << "Enter new name:";
                cin >> customer.name;
                cout << "Enter new room number: ";
                cin >> customer.roomNumber;
                cout << "Customer record updated. \n";
                break;
            }
        }
    }

    void displayMenu() {
        int choice;

        do {
            cout << "\nHotel Management System For...\n";
            cout << "1. Book A Room\n";
            cout << "2. Rooms Available\n";
            cout << "3. Customer Records\n";
            cout << "4. Edit Records\n";
            cout << "5. Exit\n";
            cout << "Enter Your Choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    bookRoom();
                    break;
                case 2:
                    displayAvailableRooms();
                    break;
                case 3:
                    displayCustomerRecords();
                    break;
                case 4:
                    editCustomerRecords();
                    break;
                case 5:
                    cout << "Exiting the system...\n";
                    break;
                default:
                    cout << "Invalid choice. Please try again.\n";
                    break;
            }
        } while (choice != 5);
    }
};

int main() {
    HotelManagementSystem hotel(10); // Create a hotel with 10 rooms
    hotel.displayMenu();

    return 0;
}
