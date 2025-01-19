#include <iostream>
#include <vector>
using namespace std;
class Seat {
protected:
    string seatNumber;
    bool isAvailable;
    double price;
public:
    Seat(string num, double cost) {
        seatNumber = num;
        price = cost;
        isAvailable = true;
    }
    virtual void displayDetails() {
        cout << "Seat: " << seatNumber << ", Price: " << price << ", " << (isAvailable ? "Available" : "Booked") << endl;
    }
    bool checkAvailability() {
        return isAvailable;
    }
    void bookSeat() {
        isAvailable = false;
    }
    string getSeatNumber() {
        return seatNumber;
    }
};
class EconomySeat : public Seat {
public:
    EconomySeat(string num, double cost) : Seat(num, cost) {}
    void displayDetails() {
        cout << "[Economy] ";
        Seat::displayDetails();
    }
};
class BusinessSeat : public Seat {
public:
    BusinessSeat(string num, double cost) : Seat(num, cost) {}
    void displayDetails() {
        cout << "[Business] ";
        Seat::displayDetails();
    }
};
class AirplaneSeatSelector {
private:
    vector<Seat*> seats;
public:
    void addSeat(Seat* seat) {
        seats.push_back(seat);
    }
    void displayAvailableSeats() {
        cout << "\nAvailable Seats:\n";
        for (int i = 0; i < seats.size(); i++) {
            if (seats[i]->checkAvailability()) {
                seats[i]->displayDetails();
            }
        }
    }
    void selectSeat(string seatNumber) {
        for (int i = 0; i < seats.size(); i++) {
            if (seats[i]->getSeatNumber() == seatNumber) {
                if (seats[i]->checkAvailability()) {
                    seats[i]->bookSeat();
                    cout << "Seat " << seatNumber << " booked successfully!\n";
                } else {
                    cout << "Seat " << seatNumber << " is already booked.\n";
                }
                return;
            }
        }
        cout << "Invalid seat number.\n";
    }
};
int main() {
    AirplaneSeatSelector selector;
    selector.addSeat(new EconomySeat("E1", 50));
    selector.addSeat(new EconomySeat("E2", 50));
    selector.addSeat(new BusinessSeat("B1", 100));
    selector.addSeat(new BusinessSeat("B2", 100));
    int choice;
    do {
        cout << "\n--- Airplane Seat Selector ---\n";
        cout << "1. View Available Seats\n";
        cout << "2. Book a Seat\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            selector.displayAvailableSeats();
        } else if (choice == 2) {
            string seatNumber;
            cout << "Enter seat number: ";
            cin >> seatNumber;
            selector.selectSeat(seatNumber);
        } else if (choice == 3) {
            cout << "Thank you for using the Airplane Seat Selector!\n";
        } else {
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 3);
    return 0;
}