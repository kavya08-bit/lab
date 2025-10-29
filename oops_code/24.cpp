#include <iostream>
#include <cmath> 

using namespace std;

class ShapeCalculator {
public:
    float AREA(float r) {
        return M_PI * r * r;
    }

    float AREA(int s) {
        return s * s;
    }

    float AREA(float l, float w) {
        return l * w;
    }

    float AREA(float a, float b, float c) {
        float s = (a + b + c) / 2.0;
        return sqrt(s * (s - a) * (s - b) * (s - c));
    }
};

int main() {
    ShapeCalculator calculator; 

    cout << "--- Method Overloading Example ---" << endl;

    cout << "Area of circle with radius 7.0: " << calculator.AREA(7.0f) << endl;

    cout << "Area of square with side 5: " << calculator.AREA(5) << endl;

    cout << "Area of rectangle 8.0 x 4.0: " << calculator.AREA(8.0f, 4.0f) << endl;

    cout << "Area of triangle with sides 3, 4, 5: " << calculator.AREA(3.0f, 4.0f, 5.0f) << endl;

    cout << "\n";
    cout << "Kavya Pal Singh" << endl << " 03476803124";

    return 0;
}