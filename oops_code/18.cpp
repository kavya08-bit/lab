#include <iostream>
#include <string>

using namespace std;

class Student {
protected:
    int roll_number;
    string name;

public:
    void get_student_details() {
        cout << "Enter Roll Number: ";
        cin >> roll_number;
        cin.ignore(); 
        cout << "Enter Name: ";
        getline(cin, name);
    }

    void put_student_details() {
        cout << "Roll Number: " << roll_number << endl;
        cout << "Name: " << name << endl;
    }
};

class Exam {
protected:
    float marks_subject1;
    float marks_subject2;

public:
    void get_exam_marks() {
        cout << "Enter marks for Subject 1: ";
        cin >> marks_subject1;
        cout << "Enter marks for Subject 2: ";
        cin >> marks_subject2;
    }

    void put_exam_marks() {
        cout << "Marks Subject 1: " << marks_subject1 << endl;
        cout << "Marks Subject 2: " << marks_subject2 << endl;
    }
};

class Result : public Student, public Exam {
private:
    float total_marks;

public:
    void display_total() {
        total_marks = marks_subject1 + marks_subject2;

        cout << "\n--- Final Result ---" << endl;
        
        put_student_details(); 
        
        put_exam_marks();      
        
        cout << "Total Marks: " << total_marks << endl;
    }
};

int main() {
    Result student_result;

    cout << "--- Enter Student Details ---" << endl;
    student_result.get_student_details();

    cout << "\n--- Enter Exam Marks ---" << endl;
    student_result.get_exam_marks();

    student_result.display_total();
    cout<<"Kavya Pal Singh"<<endl<< " 03476803124";

    return 0;
}