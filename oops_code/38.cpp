#include <iostream>
#include <string>

using namespace std;

template <typename T>
class Comparer {
private:
    T num1;
    T num2;

public:
    Comparer(T n1, T n2) {
        num1 = n1;
        num2 = n2;
        cout << "\nConstructor called: Object created with (" << num1 << ", " << num2 << ")" << endl;
    }

    ~Comparer() {
        cout << "Destructor called: Object with (" << num1 << ", " << num2 << ") destroyed." << endl;
    }

    T find_bigger() {
        return (num1 > num2) ? num1 : num2;
    }
};

int main() {
    cout << "--- Program to find the bigger of two numbers ---" << endl;

    {
        cout << "\n--- Testing with Integers ---" << endl;
        int i1, i2;
        cout << "Enter integer 1: ";
        cin >> i1;
        cout << "Enter integer 2: ";
        cin >> i2;

        Comparer<int> intComparer(i1, i2);
        
        cout << "The bigger integer is: " << intComparer.find_bigger() << endl;
    
    } 

    {
        cout << "\n--- Testing with Floats ---" << endl;
        float f1, f2;
        cout << "Enter float 1: ";
        cin >> f1;
        cout << "Enter float 2: ";
        cin >> f2;

        Comparer<float> floatComparer(f1, f2);
        
        cout << "The bigger float is: " << floatComparer.find_bigger() << endl;
    
    } 

    cout << "\n";
    cout << "Kavya Pal Singh" << endl << " 03476803124";

    return 0;
}