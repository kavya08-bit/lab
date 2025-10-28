#include <iostream>
using namespace std;

class Matrix {
private:
    int mat[10][10];  
    int rows, cols;

public:

    void input(int r, int c) {
        rows = r;
        cols = c;
        cout << "Enter elements of " << rows << "x" << cols << " matrix:\n";
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cin >> mat[i][j];
            }
        }
    }

    // Function to display matrix
    void display() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
    }

    // Function to multiply two matrices
    Matrix multiply(Matrix m2) {
        Matrix result;
        if (cols != m2.rows) {
            cout << "Matrix multiplication not possible!\n";
            result.rows = result.cols = 0;
            return result;
        }

        result.rows = rows;
        result.cols = m2.cols;

        // Initialize result matrix with 0
        for (int i = 0; i < result.rows; i++) {
            for (int j = 0; j < result.cols; j++) {
                result.mat[i][j] = 0;
            }
        }

        // Matrix multiplication logic
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < m2.cols; j++) {
                for (int k = 0; k < cols; k++) {
                    result.mat[i][j] += mat[i][k] * m2.mat[k][j];
                }
            }
        }

        return result;
    }
};

int main() {
    Matrix m1, m2, m3;
    int r1, c1, r2, c2;

    cout << "Enter rows and columns of first matrix: ";
    cin >> r1 >> c1;
    m1.input(r1, c1);

    cout << "Enter rows and columns of second matrix: ";
    cin >> r2 >> c2;
    m2.input(r2, c2);

    cout << "\nMatrix 1:\n";
    m1.display();

    cout << "\nMatrix 2:\n";
    m2.display();

    m3 = m1.multiply(m2);

    cout << "\nResultant Matrix (Multiplication):\n";
    m3.display();
    cout<<"Kavya pal singh   03476803124";
    return 0;
}
