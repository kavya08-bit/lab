#include <iostream>
#include <math.h>
#define f(x) 1 / (1 + pow(x, 2))
using namespace std;

int main() {
    float lower, upper, integration = 0.0, stepSize, k;
    int i, subInterval;

    cout << "Enter lower limit of integration: ";
    cin >> lower;
    cout << "Enter upper limit of integration: ";
    cin >> upper;
    cout << "Enter number of sub intervals: ";
    cin >> subInterval;

    stepSize = (upper - lower) / subInterval;
    integration = f(lower) + f(upper); // Initialize with first and last terms

    for (i = 1; i <= subInterval - 1; i++) {
        k = lower + i * stepSize;
        if (i % 2 == 0) { // Check if 'i' is even09
            integration = integration + 2 * f(k);
        } else { // 'i' is odd
            integration = integration + 4 * f(k);
        }
    }

    integration = integration * stepSize / 3;
    cout << endl << "Required value of integration is: " << integration;

    return 0;
}