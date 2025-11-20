#include <iostream>
#include <cmath>

using namespace std;

// Define the function for which we want to find the root.
double f(double x) {
    return (x * log10(x) - 1.2);
}

// Define the derivative of the function.
double f_prime(double x) {
    return log10(x) + 1;
}
// Newton-Raphson method to find the root of a function.
double newtonRaphson(double x0, double tol, int maxlter) {
    for (int i = 0; i < maxlter; i++) {
        double fx = f(x0);
        double fpx = f_prime(x0);

        if (fabs(fpx) < 1e-6) {
            cout << "Derivative is close to zero. Newton-Raphson cannot converge." << endl;
            return 0.0;
        }

        double x1 = x0 - fx / fpx;

        cout << "Iteration " << i + 1 << ": x0=" << x0 << ", x1=" << x1 << ", f(x1)=" << f(x1) << endl;

        if (fabs(x1 - x0) < tol) {
            cout << "Root found: x = " << x1 << " (within tolerance)" << endl;
            return x1;
        }

        x0 = x1;
    }

    cout << "Maximum number of iterations reached." << endl;
    return 0.0;
}

int main() {
    double x0, tol;
    int maxlter;

    cout << "Enter initial guess (x0): ";
    cin >> x0;
    cout << "Enter the tolerance (e.g., 0.001): ";
    cin >> tol;
    cout << "Enter the maximum number of iterations: ";
    cin >> maxlter;

    double root = newtonRaphson(x0, tol, maxlter);

    if (root != 0.0) {
        cout << "Approximate root: " << root << endl;
    }

    return 0;
}