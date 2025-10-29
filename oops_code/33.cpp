#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class student {
private:
    char name[50];
    int age;
    char sex[10];
    float height;
    float weight;

public:
    void get_data() {
        cin.ignore(); 
        
        cout << "Enter Name: ";
        cin.getline(name, 50); 
        
        cout << "Enter Age: ";
        cin >> age;
        
        cout << "Enter Sex (Male/Female/Other): ";
        cin >> sex;
        
        cout << "Enter Height (in cm): ";
        cin >> height;
        
        cout << "Enter Weight (in kg): ";
        cin >> weight;
    }

    void display_data() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Sex: " << sex << endl;
        cout << "Height: " << height << " cm" << endl;
        cout << "Weight: " << weight << " kg" << endl;
    }
};

int main() {
    string filename = "student.dat";
    fstream file;
    
    student s_write;
    
    cout << "--- Enter Student Details ---" << endl;
    s_write.get_data();

    file.open(filename, ios::binary | ios::out);
    if (!file.is_open()) {
        cout << "Error: Could not open " << filename << " for writing." << endl;
        return 1;
    }

    file.write((char*)&s_write, sizeof(student));
    
    file.close();
    cout << "\nStudent data saved to " << filename << endl;

    student s_read;

    file.open(filename, ios::binary | ios::in);
    if (!file.is_open()) {
        cout << "Error: Could not open " << filename << " for reading." << endl;
        return 1;
    }
    
    cout << "\n--- Reading Data From File ---" << endl;
    
    file.read((char*)&s_read, sizeof(student));
    
    s_read.display_data();
    
    file.close();

    cout << "\n";
    cout << "Kavya Pal Singh" << endl << " 03476803124";

    return 0;
}