#include <iostream>
#include <fstream>
#include <string>
#include <cctype> 

using namespace std;

class FileCounter {
private:
    string filename;
    int word_count;
    int space_count;

public:
    FileCounter(string fname) {
        filename = fname;
        word_count = 0;
        space_count = 0;
    }

    void create_sample_file() {
        ofstream outFile(filename);
        if (!outFile) {
            cout << "Error creating sample file." << endl;
            return;
        }
        
        outFile << "This is a sample file." << endl;
        outFile << "It has multiple words and    spaces." << endl;
        outFile << "And multiple lines." << endl;
        outFile.close();
        cout << "Sample file '" << filename << "' created for counting." << endl;
    }

    void count_stats() {
        ifstream inFile(filename);

        if (!inFile.is_open()) {
            cout << "Error: Could not open " << filename << " for reading." << endl;
            return;
        }

        char ch;
        bool in_word = false; 

        // Reset counts in case count_stats is called multiple times
        word_count = 0;
        space_count = 0;

        while (inFile.get(ch)) {
            
            if (ch == ' ') {
                space_count++;
                in_word = false;
            } 
            else if (isspace(ch)) {
                in_word = false;
            } 
            else {
                if (!in_word) {
                    word_count++;
                    in_word = true;
                }
            }
        }
        inFile.close();
    }

    void display_stats() {
        cout << "\n--- Counting results ---" << endl;
        cout << "Total Words: " << word_count << endl;
        cout << "Total Spaces: " << space_count << endl;
    }
};

int main() {
    FileCounter counter("count_data_oop.txt");
    
    counter.create_sample_file();
    
    counter.count_stats();
    
    counter.display_stats();

    cout << "\n";
    cout << "Kavya Pal Singh" << endl << " 03476803124";

    return 0;
}