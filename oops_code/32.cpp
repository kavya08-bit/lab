#include <iostream>
#include <fstream>
#include <string>
#include <cctype> 

using namespace std;

class WhitespaceRemover {
private:
    string inputFilename;
    string outputFilename;

public:
    WhitespaceRemover(string input, string output) {
        inputFilename = input;
        outputFilename = output;
    }

    void create_sample_file() {
        ofstream outFile(inputFilename);
        if (!outFile) {
            cout << "Error creating sample file." << endl;
            return;
        }
        
        outFile << "Hello \t World" << endl; 
        outFile << "This \n is \v a test." << endl; 
        outFile << "End of \r\n file."; 
        
        outFile.close();
        cout << "Sample file '" << inputFilename << "' created." << endl;
    }

    void display_file_content(string filename) {
        ifstream inFile(filename);
        if (!inFile.is_open()) {
            cout << "Error opening " << filename << " for display." << endl;
            return;
        }

        cout << "--- Content of " << filename << " ---" << endl;
        char ch;
        while (inFile.get(ch)) {
            cout.put(ch);
        }
        cout << "\n-----------------------------------" << endl;
        inFile.close();
    }

    void process_file() {
        ifstream inFile(inputFilename);
        ofstream outFile(outputFilename);

        if (!inFile.is_open()) {
            cout << "Error: Could not open input file: " << inputFilename << endl;
            return;
        }
        if (!outFile.is_open()) {
            cout << "Error: Could not open output file: " << outputFilename << endl;
            inFile.close();
            return;
        }

        char ch;
        while (inFile.get(ch)) {
            if (!isspace(ch)) {
                outFile.put(ch);
            }
        }

        inFile.close();
        outFile.close();

        cout << "\nWhitespace removal complete. Result stored in '" << outputFilename << "'." << endl;
    }
};

int main() {
    WhitespaceRemover remover("input.txt", "output_no_space.txt");
    
    remover.create_sample_file();
    
    remover.display_file_content("input.txt");
    
    remover.process_file();
    
    remover.display_file_content("output_no_space.txt");

    cout << "\n";
    cout << "Kavya Pal Singh" << endl << " 03476803124";

    return 0;
}