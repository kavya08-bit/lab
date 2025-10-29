#include <iostream>

using namespace std;

class Complex {
private:
    float real;
    float imag;

public:
    Complex(float r = 0.0, float i = 0.0) {
        real = r;
        imag = i;
    }

    Complex operator+(const Complex& other) {
        Complex temp;
        temp.real = this->real + other.real;
        temp.imag = this->imag + other.imag;
        return temp;
    }

    void display() {
        cout << real;
        if (imag >= 0) {
            cout << " + " << imag << "i";
        } else {
            cout << " - " << -imag << "i";
        }
    }
};

int main() {
    Complex c1(5.5, 3.1);
    Complex c2(2.3, 4.8);

    cout << "--- Overloading the '+' Operator ---" << endl;
    cout << "Number 1: ";
    c1.display();
    cout << endl;

    cout << "Number 2: ";
    c2.display();
    cout << endl;

    Complex sum = c1 + c2;

    cout << "Sum:      ";
    sum.display();
    cout << endl;
    
    cout << "\n";
    cout << "Kavya Pal Singh" << endl << " 03476803124";

    return 0;
}