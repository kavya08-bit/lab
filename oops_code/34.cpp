#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Customer {
private:
    char name[50];
    int room_number;

public:
    void get_data() {
        cin.ignore(); 
        cout << "Enter customer name: ";
        cin.getline(name, 50);
        cout << "Enter room number: ";
        cin >> room_number;
    }

    void display_data() {
        cout << "  Name: " << name << ", Room: " << room_number << endl;
    }
};

int main() {
    string filename = "hotel.dat";
    fstream file;
    Customer cust;
    char choice;

    file.open(filename, ios::binary | ios::app | ios::out); 

    if (!file.is_open()) {
        cout << "Error: Could not open file for writing." << endl;
        return 1;
    }

    do {
        cout << "\n--- Enter New Customer Details ---" << endl;
        cust.get_data();
        
        file.write((char*)&cust, sizeof(Customer));
        
        cout << "\nDo you want to enter another customer? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    file.close(); 
    cout << "Data saved." << endl;

    int customer_count = 0;

    file.open(filename, ios::binary | ios::in); 

    if (!file.is_open()) {
        cout << "Error: Could not open file for reading." << endl;
        return 1;
    }

    cout << "\n--- Reading All Customers from File ---" << endl;
    Customer temp_cust; 

    while (file.read((char*)&temp_cust, sizeof(Customer))) {
        temp_cust.display_data();
        customer_count++; 
    }

    file.close(); 

    cout << "\n-----------------------------------" << endl;
    cout << "Total number of customers: " << customer_count << endl;

    cout << "\n";
    cout << "Kavya Pal Singh" << endl << " 03476803124";

    return 0;
}