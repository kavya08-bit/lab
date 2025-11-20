#include <stdio.h>

#define MAX_ROWS 50
#define MAX_COLS 50

struct SparseTerm {
    int row;
    int col;
    int value;
};

int main() {
    int matrix[MAX_ROWS][MAX_COLS];
    int rows, cols;
    
    struct SparseTerm sparseMatrix[MAX_ROWS * MAX_COLS];
    
    int nonZeroCount = 0; 

    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    printf("Enter the elements of the %dx%d matrix:\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("\nOriginal Matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] != 0) {
                sparseMatrix[nonZeroCount].row = i;
                sparseMatrix[nonZeroCount].col = j;
                sparseMatrix[nonZeroCount].value = matrix[i][j];
                
                nonZeroCount++;
            }
        }
    }

    printf("\nSparse Matrix Representation (Row, Col, Value):\n");
    printf("--------------------------------------------------\n");
    printf("Row\tCol\tValue\n");
    printf("--------------------------------------------------\n");
    
    printf("%d\t%d\t%d\n", rows, cols, nonZeroCount);
    
    for (int i = 0; i < nonZeroCount; i++) {
        printf("%d\t%d\t%d\n", sparseMatrix[i].row, sparseMatrix[i].col, sparseMatrix[i].value);
    }

    return 0;
}
