#include <iostream>

using namespace std;

class Date {
private:
    int day;
    int month;
    int year;

    bool isLeap(int y) {
        if (y % 400 == 0) return true;
        if (y % 100 == 0) return false;
        if (y % 4 == 0) return true;
        return false;
    }

    int daysInMonth(int m, int y) {
        if (m == 2) {
            return isLeap(y) ? 29 : 28;
        } else if (m == 4 || m == 6 || m == 9 || m == 11) {
            return 30;
        } else {
            return 31;
        }
    }

public:
    Date(int d, int m, int y) {
        day = d;
        month = m;
        year = y;
    }

    void display() {
        cout << "Date: " << day << "/" << month << "/" << year << endl;
    }

    void operator++() {
        int maxDays = daysInMonth(month, year);
        
        day++;

        if (day > maxDays) {
            day = 1;
            month++;

            if (month > 12) {
                month = 1;
                year++;
            }
        }
    }
};

int main() {
    cout << "--- Test 1: Normal Day Increment ---" << endl;
    Date d1(15, 6, 2024);
    cout << "Original ";
    d1.display();
    
    ++d1; 
    
    cout << "Incremented ";
    d1.display();

    cout << "\n--- Test 2: Leap Day (Feb 2024) ---" << endl;
    Date d2(28, 2, 2024);
    cout << "Original ";
    d2.display();
    ++d2; 
    cout << "Incremented ";
    d2.display();

    cout << "\n--- Test 3: Year Rollover ---" << endl;
    Date d3(31, 12, 2024);
    cout << "Original ";
    d3.display();
    
    ++d3; 
    
    cout << "Incremented ";
    d3.display();

    cout << "\n";
    cout << "Kavya Pal Singh" << endl << " 03476803124";

    return 0;
}