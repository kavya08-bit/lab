#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class FileMerger {
private:
    string file1;
    string file2;
    string mergedFile;

public:
    FileMerger(string f1, string f2, string m) {
        file1 = f1;
        file2 = f2;
        mergedFile = m;
    }

    void create_source_files() {
        cout << "Creating source files..." << endl;
        
        ofstream outFile1(file1);
        outFile1 << "Record A from File 1" << endl;
        outFile1 << "Record B from File 1" << endl;
        outFile1.close();

        ofstream outFile2(file2);
        outFile2 << "Record C from File 2" << endl;
        outFile2 << "Record D from File 2" << endl;
        outFile2.close();
        
        cout << "Source files (" << file1 << ", " << file2 << ") created." << endl;
    }

    void display_file(string filename) {
        ifstream inFile(filename);
        if (!inFile.is_open()) {
            cout << "Error opening " << filename << " for display." << endl;
            return;
        }

        cout << "\n--- Content of " << filename << " ---" << endl;
        string line;
        while (getline(inFile, line)) {
            cout << line << endl;
        }
        cout << "-----------------------------------" << endl;
        inFile.close();
    }

    void merge_files() {
        ifstream inFile1(file1);
        ifstream inFile2(file2);
        ofstream outFile(mergedFile);

        if (!inFile1.is_open() || !inFile2.is_open() || !outFile.is_open()) {
            cout << "Error: Could not open one or more files." << endl;
            return;
        }

        cout << "\nMerging files..." << endl;
        
        string line;

        while (getline(inFile1, line)) {
            outFile << line << endl;
        }
        
        while (getline(inFile2, line)) {
            outFile << line << endl;
        }

        inFile1.close();
        inFile2.close();
        outFile.close();

        cout << "Files merged successfully into " << mergedFile << endl;
    }

    string get_merged_filename() {
        return mergedFile;
    }
};

int main() {
    FileMerger merger("file1_oop.txt", "file2_oop.txt", "merged_file_oop.txt");

    merger.create_source_files();

    merger.merge_files();

    merger.display_file(merger.get_merged_filename());

    cout << "\n";
    cout << "Kavya Pal Singh" << endl << " 03476803124";

    return 0;
}