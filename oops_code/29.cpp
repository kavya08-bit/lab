#include <iostream>
#include <fstream> 
#include <string>

using namespace std;

class FileHandler {
private:
    string filename;

public:
    FileHandler(string fname) {
        filename = fname;
    }

    void write_data() {
        fstream myFile;
        myFile.open(filename, ios::out); 

        if (!myFile.is_open()) {
            cout << "Error: Could not open " << filename << " for writing." << endl;
            return; 
        }

        cout << "Writing to " << filename << "..." << endl;
        myFile << "Data written from the FileHandler class." << endl;
        myFile << "Line 1 using OOP." << endl;
        myFile << "Line 2 using OOP." << endl;
        
        myFile.close();
        cout << "Finished writing." << endl;
    }

    void read_data() {
        fstream myFile;
        myFile.open(filename, ios::in); 

        if (!myFile.is_open()) {
            cout << "Error: Could not open " << filename << " for reading." << endl;
            return; 
        }

        cout << "\n--- Reading from " << filename << " ---" << endl;
        string line;
        while (getline(myFile, line)) {
            cout << line << endl;
        }

        myFile.close();
    }
};

int main() {
    FileHandler myFileObject("data_oop.txt");

    myFileObject.write_data();
    myFileObject.read_data();

    cout << "\n";
    cout << "Kavya Pal Singh" << endl << " 03476803124";

    return 0;
}