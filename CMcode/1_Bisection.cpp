#include <iostream>
#include <cmath>

using namespace std;

// Define the function for which we want to find the root.
double f(double x) {
    return (x * x * x - 4 * x - 9); // Function: x^3 - 4x - 9
}

// Bisection method to find the root of a function within a given interval.
double bisection(double a, double b, double tol, int maxlter) {
    double fa = f(a);
    double fb = f(b);

    if (fa * fb >= 0) {
        cout << "Bisection method cannot be applied. The function values at endpoints have the same sign." << endl;
        return 0.0;
    }

    for (int i = 0; i < maxlter; i++) {
        double c = (a + b) / 2;double fc = f(c);

    cout << "Iteration " << i + 1 << ": a=" << a << ", b=" << b << ", c=" << c << ", f(c)=" << fc << endl;

    if (fabs(fc) < tol) {
        cout << "Root found: x = " << c << " (within tolerance)" << endl;
        return c;
    }

    if (fa * fc < 0) {
        b = c;
        fb = fc;
    } else {
        a = c;
        fa = fc;
    }
}

cout << "Maximum number of iterations reached." << endl;
return 0.0;
}

int main() {
    double a, b, tol;
    int maxIter;

    cout << "Enter the interval [a, b]: ";
    cin >> a >> b;
    cout << "Enter the tolerance (e.g., 0.001): ";
    cin >> tol;
    cout << "Enter the maximum number of iterations: ";
    cin >> maxIter;

    double root = bisection(a, b, tol, maxIter);

    if (root != 0.0) {
        cout << "Approximate root: " << root << endl;
    }

    return 0;
}