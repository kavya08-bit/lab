#include<iostream>
using namespace std;
class Fibonacci {
private:
    int n;             // number of terms
    int series[100];   // store fibonacci series (max 100 terms)

public:
    // Function to take input
    void input() {
        cout << "Enter number of terms: ";
        cin >> n;
    }

    // Function to calculate Fibonacci series
    void calculate() {
        if (n >= 1) series[0] = 0;
        if (n >= 2) series[1] = 1;

        for (int i = 2; i < n; i++) {
            series[i] = series[i - 1] + series[i - 2];
        }
    }

    // Function to display Fibonacci series
    void output() {
        cout << "Fibonacci Series: ";
        for (int i = 0; i < n; i++) {
            cout << series[i] << " ";
        }
        cout << endl;
    }
};

// Main function
int main() {
    Fibonacci fib;   // create object
    fib.input();
    fib.calculate();
    fib.output();
    cout<<"kavya pal singh"<<endl;
    cout<<"03476803124";
    return 0;
}