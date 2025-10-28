#include <iostream>
#include <string>
using namespace std;

class Date {
private:
    int day, month, year;

public:
    void setDate(int d, int m, int y) {
        day = d;
        month = m;
        year = y;
    }

    void display() {
        if (day < 10) cout << "0" << day << "/";
        else cout << day << "/";

        if (month < 10) cout << "0" << month << "/";
        else cout << month << "/";

        cout << year;
    }
};

class Patient {
private:
    string name;
    string disease;
    Date admissionDate;
    Date dischargeDate;

public:
    void enterData() {
        cout << "\nEnter patient name: ";
        getline(cin, name);

        cout << "Enter disease: ";
        getline(cin, disease);

        int d, m, y;
        cout << "Enter admission date (dd mm yyyy): ";
        cin >> d >> m >> y;
        admissionDate.setDate(d, m, y);

        cout << "Enter discharge date (dd mm yyyy): ";
        cin >> d >> m >> y;
        dischargeDate.setDate(d, m, y);

        cin.ignore();
    }

    void displayData() {
        cout << "\nPatient Name: " << name;
        cout << "\nDisease: " << disease;
        cout << "\nDate of Admission: ";
        admissionDate.display();
        cout << "\nDate of Discharge: ";
        dischargeDate.display();
        cout << "\n-----------------------------"<<endl;
    }
};

int main() {
    int n;
    cout << "Enter number of patients: ";
    cin >> n;
    cin.ignore(); 
    Patient patients[50];

    for (int i = 0; i < n; i++) {
        cout << "\nEnter details of patient " << i + 1 << ":\n";
        patients[i].enterData();
    }

    cout << "\n\n--- Patient Database ---\n";
    for (int i = 0; i < n; i++) {
        patients[i].displayData();
    }
    cout<<"Kavya Pal Singh"<<endl<< " 03476803124";
    return 0;
}
