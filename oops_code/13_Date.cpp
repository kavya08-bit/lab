#include <iostream>
using namespace std;

class Date {
private:
    int day, month, year;

public:
    void setDate() {
        cout<<"Enter Day ";
        cin>>day;
        cout<<"Enter Month ";
        cin>>month;
        cout<<"Enter Year ";
        cin>>year;
    }

    void display() {
        if (day < 10) cout << "0" << day << "/";
        else cout << day << "/";

        if (month < 10) cout << "0" << month << "/";
        else cout << month << "/";

        cout << year << endl;
    }

    void subtractDays(int n) {
        day -= n;
        while (day <= 0) {
            month--;
            if (month <= 0) {
                month = 12;
                year--;
            }
            int daysInMonth;
            if (month == 1 || month == 3 || month == 5 || month == 7 ||
                month == 8 || month == 10 || month == 12)
                daysInMonth = 31;
            else if (month == 4 || month == 6 || month == 9 || month == 11)
                daysInMonth = 30;
            else
                daysInMonth = 28;

            day += daysInMonth;
        }
    }

    int subtractDate(Date d2) {
        int total1 = year * 365 + month * 30 + day;
        int total2 = d2.year * 365 + d2.month * 30 + d2.day;
        return total1 - total2;
    }
};

int main() {
    Date d1, d2;

    d1.setDate();
    cout << "Original date: ";
    d1.display();

    d1.subtractDays(20);
    cout << "After subtracting 20 days: ";
    d1.display();

    d2.setDate();
    cout << "Second date: ";
    d2.display();

    int diff = d1.subtractDate(d2);
    cout << "Difference between dates (approx days): " << diff << endl;
    cout<<"Kavya Pal Singh"<<endl<< " 03476803124";
    return 0;
}
