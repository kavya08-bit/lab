#include <iostream>

using namespace std;

template <typename T>
class Calculator {
private:
    T num;

public:
    Calculator(T n) {
        num = n;
    }

    // Member function to calculate the square
    T square() {
        return num * num;
    }

    // Helper to display the original number
    void display_num() {
        cout << num;
    }
};

int main() {
    cout << "--- Testing Class Template ---" << endl;

    // Test with an integer
    Calculator<int> int_calc(5);
    cout << "Square of ";
    int_calc.display_num();
    cout << " (int): " << int_calc.square() << endl;

    // Test with a float
    Calculator<float> float_calc(4.5f);
    cout << "Square of ";
    float_calc.display_num();
    cout << " (float): " << float_calc.square() << endl;

    // Test with a double
    Calculator<double> double_calc(10.1);
    cout << "Square of ";
    double_calc.display_num();
    cout << " (double): " << double_calc.square() << endl;

    cout << "\n";
    cout << "Kavya Pal Singh" << endl << " 03476803124";

    return 0;
}