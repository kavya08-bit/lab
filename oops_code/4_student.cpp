#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string name;
    int roll;
    int marks[5];

public:
    void input() {
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter roll number: ";
        cin >> roll;
        cout << "Enter marks of 5 subjects (out of 100):\n";
        for (int i = 0; i < 5; i++) {
            cin >> marks[i];
        }
    }

    float average() {
        int sum = 0;
        for (int i = 0; i < 5; i++) {
            sum += marks[i];
        }
        return sum / 5.0;
    }

    void assignStream() {
        float avg = average();

        cout << "\nStudent Name: " << name;
        cout << "\nRoll Number: " << roll;
        cout << "\nAverage Marks: " << avg << "%";

        cout << "\nAssigned Stream: ";
        if (avg >= 96)
            cout << "Computer Science";
        else if (avg >= 91)
            cout << "Electronics";
        else if (avg >= 86)
            cout << "Mechanical";
        else if (avg >= 81)
            cout << "Electrical";
        else if (avg >= 76)
            cout << "Chemical";
        else if (avg >= 71)
            cout << "Civil";
        else
            cout << "Not eligible for given streams";
    }
};

int main() {
    Student s;
    s.input();
    s.assignStream();
    return 0;
}
