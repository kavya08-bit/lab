#include <iostream>

using namespace std;

class Complex {
private:
    float real;
    float imag;

public:
    Complex() {
        real = 0;
        imag = 0;
    }

    Complex(float val) {
        real = val;
        imag = val;
    }

    Complex(float r, float i) {
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
        cout << endl;
    }
};

int main() {
    Complex c1;
    cout << "c1 (no-arg constructor):   ";
    c1.display();

    Complex c2(5);
    cout << "c2 (one-arg constructor):  ";
    c2.display();

    Complex c3(3, 4);
    cout << "c3 (two-arg constructor): ";
    c3.display();

    cout << "\n--- Adding c2 and c3 ---" << endl;

    Complex sum = c2 + c3;

    cout << "Result of (";
    c2.display();
    cout << ") + (";
    c3.display();
    cout << ") = ";
    sum.display();
    cout<<"Kavya Pal Singh"<<endl<< " 03476803124";

    return 0;
}