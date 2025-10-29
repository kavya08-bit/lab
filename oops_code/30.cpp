#include <iostream>
#include <fstream> 
#include <string>

using namespace std;

void create_sample_file() {
    ofstream outFile("sample_data.txt");
    if (!outFile) {
        cout << "Error creating sample file." << endl;
        return;
    }
    
    outFile << "This is a sample file." << endl;
    outFile << "It has multiple words\t and lines." << endl;
    outFile << "Reading word by word should handle all whitespace." << endl;
    outFile.close();
    cout << "Sample file 'sample_data.txt' created for reading." << endl;
}

class WordReader {
private:
    string filename;

public:
    WordReader(string fname) {
        filename = fname;
    }

    void display_word_by_word() {
        ifstream inFile(filename);

        if (!inFile.is_open()) {
            cout << "Error: Could not open " << filename << " for reading." << endl;
            return;
        }

        string word;
        cout << "\n--- Displaying data word by word ---" << endl;

        while (inFile >> word) {
            cout << word << endl;
        }

        inFile.close();
    }
};

int main() {
    create_sample_file();

    WordReader reader("sample_data.txt");
    
    reader.display_word_by_word();

    cout << "\n";
    cout << "Kavya Pal Singh" << endl << " 03476803124";

    return 0;
}