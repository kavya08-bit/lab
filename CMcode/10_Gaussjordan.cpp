#include <iostream>
#include <iomanip>
#include <math.h>
#include <cstdlib> // For exit()
#define SIZE 10
using namespace std;

int main() {
    float a[SIZE][2 * SIZE], x[SIZE], ratio;
    int i, j, k, n;

    cout << setprecision(3) << fixed;
    cout << "Enter order of matrix: ";
    cin >> n;

    // Reading the matrix coefficients
    cout << "Enter coefficients of Matrix: " << endl;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            cout << "a[" << i << "][" << j << "]= ";
            cin >> a[i][j];
        }
    }

    // Displaying the Given Matrix
    cout << endl << "\nGiven Matrix is: " << endl;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            cout << a[i][j] << "\t";
        }
        cout << endl;
    }

    // Creating the Augmented Matrix [A | I]
    for (i = 1; i <= n; i++) {
        for (j = n + 1; j <= 2 * n; j++) {
            if (i == j - n) {
                a[i][j] = 1;
            } else {
                a[i][j] = 0;
            }
        }
    }

    // Applying Gauss-Jordan Elimination (Transforming [A | I] to [I | A^-1])
    for (i = 1; i <= n; i++) {
        // Check for zero pivot element
        if (a[i][i] == 0.0) {
            cout << "Mathematical Error! Cannot perform division by zero." << endl;
            exit(0);
        }

        // Perform elimination for all rows (j) other than the current row (i)
        for (j = 1; j <= n; j++) {
            if (i != j) {
                ratio = a[j][i] / a[i][i];
                for (k = 1; k <= 2 * n; k++) {
                    a[j][k] = a[j][k] - ratio * a[i][k];
                }
            }
        }
    }
    
    // Normalizing the Diagonal elements to 1 (making the left side the Identity Matrix)
    for (i = 1; i <= n; i++) {
        for (j = n + 1; j <= 2 * n; j++) {
            a[i][j] = a[i][j] / a[i][i];
        }
    }

    // Displaying the Inverse Matrix (the right half of the augmented matrix)
    cout << endl << "Inverse Matrix is:" << endl;
    for (i = 1; i <= n; i++) {
        for (j = n + 1; j <= 2 * n; j++) {
            cout << a[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}