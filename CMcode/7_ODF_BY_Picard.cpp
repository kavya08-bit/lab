#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;

// required macros defined below:
double Y1(double x) {
    return (1 + (x) + pow(x, 2) / 2);
}

double Y2(double x) {
    return (1 + (x) + pow(x, 2) / 2 + pow(x, 3) / 3 + pow(x, 4) / 8);
}

double Y3(double x) {
    return (1 + (x) + pow(x, 2) / 2 + pow(x, 3) / 3 + pow(x, 4) / 8 + pow(x, 5) / 15 + pow(x, 6) / 48);
}

int main() {
    double start_value = 0, end_value = 3, allowed_error = 0.4, temp;
    double y1[30];
    double y2[30];
    double y3[30];
    int count;

    // Calculate Y1, Y2, and Y3 values
    for (temp = start_value, count = 0; temp <= end_value; temp = temp + allowed_error, count++) {
        y1[count] = Y1(temp);
        y2[count] = Y2(temp);
        y3[count] = Y3(temp);
    }

    // Print x-values (independent variable)
    cout << "\n\nX\n";
    for (temp = start_value; temp <= end_value; temp = temp + allowed_error) {
        cout << fixed << setprecision(4) << temp << " ";
    }

    // Print Y1 values
    cout << "\n\nY(1)\n";
    for (temp = start_value, count = 0; temp <= end_value; temp = temp + allowed_error, count++) {
        cout << fixed << setprecision(4) << y1[count] << " ";
    }

    // Print Y2 values
    cout << "\n\nY(2)\n";
    for (temp = start_value, count = 0; temp <= end_value; temp = temp + allowed_error, count++) {
        cout << fixed << setprecision(4) << y2[count] << " ";
    }

    // Print Y3 values
    cout << "\n\nY(3)\n";
    for (temp = start_value, count = 0; temp <= end_value; temp = temp + allowed_error, count++) {
        cout << fixed << setprecision(4) << y3[count] << " ";
    }

    return 0;
}