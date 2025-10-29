#include <iostream>
#include <string>

using namespace std;

class Patient {
protected:
    string name;

public:
    void get_details() {
        cin.ignore(); 
        cout << "Enter Patient Name: ";
        getline(cin, name);
    }

    void put_details() {
        cout << "Name: " << name << endl;
    }
};

class AgedPatient : public Patient {
private:
    int age;

public:
    void get_all_details() {
        Patient::get_details(); 
        cout << "Enter Age: ";
        cin >> age;
    }

    bool display_if_pediatric() {
        if (age < 12) {
            cout << "\n* Pediatric Patient Found *" << endl;
            Patient::put_details(); 
            cout << "Age: " << age << " years" << endl;
            return true;
        }
        return false;
    }
};

int main() {
    // Define a maximum number of patients
    const int MAX_PATIENTS = 100;
    
    // Create a static array of that size
    AgedPatient patients[MAX_PATIENTS];
    
    int n;
    cout << "How many patients do you want to enter (max 100)? ";
    cin >> n;

    // Validate input
    if (n <= 0 || n > MAX_PATIENTS) {
        cout << "Invalid number of patients." << endl;
        return 1; // Exit
    }

    // --- 1. Get data for all patients ---
    cout << "\n--- Enter All Patient Details ---" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "\nEnter details for Patient " << i + 1 << ":" << endl;
        patients[i].get_all_details();
    }

    // --- 2. Display the list of pediatric patients ---
    cout << "\n\n--- Displaying List of Pediatric Patients (Less than 12) ---" << endl;
    bool found = false;

    for (int i = 0; i < n; ++i) {
        if (patients[i].display_if_pediatric()) {
            found = true;
        }
    }

    if (!found) {
        cout << "No pediatric patients (less than 12 years old) were found." << endl;
    }
    cout<<"Kavya Pal Singh"<<endl<< " 03476803124";

    return 0;
}