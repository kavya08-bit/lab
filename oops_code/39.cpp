#include <iostream>
#include <stdexcept> 

using namespace std;

class SafeArray {
private:
    int* arr;
    int size;

public:
    SafeArray(int s) {
        size = s;
        arr = new int[size];
        for (int i = 0; i < size; ++i) {
            arr[i] = (i + 1) * 10; 
        }
        cout << "SafeArray of size " << size << " created." << endl;
    }

    ~SafeArray() {
        delete[] arr;
        cout << "\nSafeArray destroyed." << endl;
    }

    int get_element(int index) {
        if (index < 0 || index >= size) {
            throw "Error: Array index is out of bounds!";
        }
        return arr[index];
    }
    
    void display() {
        cout << "Array contents: [ ";
        for (int i = 0; i < size; ++i) {
            cout << arr[i] << " ";
        }
        cout << "]" << endl;
    }
};

int main() {
    cout << "--- Array Index Exception Test (OOP) ---" << endl;
    
    SafeArray arr(5); 
    arr.display();

    int index;
    cout << "Enter an index to access (0 to 4): ";
    cin >> index;

    try {
        cout << "Accessing element at index " << index << "..." << endl;
        
        int value = arr.get_element(index);
        
        cout << "Value: " << value << endl;
    
    } catch (const char* msg) {
        cerr << "\n--- EXCEPTION CAUGHT ---" << endl;
        cerr << msg << endl;
        cerr << "You tried to access invalid index " << index << "." << endl;
    }

    cout << "\nProgram continues after the try-catch block." << endl;
    
    cout << "\n";
    cout << "Kavya Pal Singh" << endl << " 03476803124";

    return 0;
}