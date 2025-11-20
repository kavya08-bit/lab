#include <iostream>
#include <iomanip>
using namespace std;

#define f(x, y) (x*x + y*y) / 10

int main() {
    float x0, y0, xn, h, yn, k1, k2, k3, k4, k;
    int i, n;

    cout << "Enter Initial Condition" << endl;
    cout << "x0 = ";
    cin >> x0;
    cout << "y0 = ";
    cin >> y0;
    cout << "Enter calculation point xn = ";
    cin >> xn;
    
    // (Content from the second part of the image)
    
    cout << "Enter number of steps: ";
    cin >> n;

    h = (xn - x0) / n;
    cout << setw(5);
    cout << "\n\nx0\t\t y0\t\t k\t\t yn\n";
    cout << "------------------------------------------\n";
    
    for (i = 0; i < n; i++) {
        k1 = h * (f(x0, y0));
        k2 = h * (f(x0 + h/2, y0 + k1/2));
        k3 = h * (f(x0 + h/2, y0 + k2/2));
        k4 = h * (f(x0 + h, y0 + k3));
        k = (k1 + 2 * k2 + 2 * k3 + k4) / 6;
        yn = y0 + k;

        cout << setw(5);
        cout << setprecision(6) << x0 << "\t\t" << y0 << "\t\t" << k << "\t\t" << yn << endl;
        
        x0 = x0 + h;
        y0 = yn;
    }

    cout << "\nValue of y at x = " << xn << " is " << yn;

    return 0;
}