#include <stdio.h>

#define MAX_TERMS 100

struct Term {
    int coefficient;
    int exponent;
};

int readPolynomial(struct Term poly[]) {
    int n;
    printf("Enter the number of terms: ");
    scanf("%d", &n);

    printf("Enter the terms (coefficient and exponent) in DESCENDING order of exponent:\n");
    for (int i = 0; i < n; i++) {
        printf("Term %d (coeff exp): ", i + 1);
        scanf("%d %d", &poly[i].coefficient, &poly[i].exponent);
    }
    return n;
}

int addPolynomials(struct Term poly1[], int n1, struct Term poly2[], int n2, struct Term resultPoly[]) {
    int i = 0; 
    int j = 0; 
    int k = 0; 

    while (i < n1 && j < n2) {
        if (poly1[i].exponent > poly2[j].exponent) {
            resultPoly[k] = poly1[i];
            i++;
            k++;
        } else if (poly1[i].exponent < poly2[j].exponent) {
            resultPoly[k] = poly2[j];
            j++;
            k++;
        } else {
            int sum_coeff = poly1[i].coefficient + poly2[j].coefficient;
            
            if (sum_coeff != 0) {
                resultPoly[k].coefficient = sum_coeff;
                resultPoly[k].exponent = poly1[i].exponent;
                k++;
            }
            i++;
            j++;
        }
    }

    while (i < n1) {
        resultPoly[k] = poly1[i];
        i++;
        k++;
    }

    while (j < n2) {
        resultPoly[k] = poly2[j];
        j++;
        k++;
    }

    return k;
}

void displayPolynomial(struct Term poly[], int n) {
    if (n == 0) {
        printf("0\n");
        return;
    }

    for (int i = 0; i < n; i++) {
        if (i > 0) {
            if (poly[i].coefficient > 0) {
                printf(" + ");
            } else {
                printf(" - "); 
            }
        } else if (poly[i].coefficient < 0) {
             printf("-"); 
        }
        
        int coeff = (poly[i].coefficient < 0) ? -poly[i].coefficient : poly[i].coefficient;

        if (coeff != 1 || poly[i].exponent == 0) {
            printf("%d", coeff);
        }

        if (poly[i].exponent > 0) {
            printf("x");
            if (poly[i].exponent > 1) {
                printf("^%d", poly[i].exponent);
            }
        }
    }
    printf("\n");
}

int main() {
    struct Term poly1[MAX_TERMS], poly2[MAX_TERMS], resultPoly[MAX_TERMS];
    int n1, n2, n3;

    printf("--- Enter Polynomial 1 ---\n");
    n1 = readPolynomial(poly1);

    printf("\n--- Enter Polynomial 2 ---\n");
    n2 = readPolynomial(poly2);

    n3 = addPolynomials(poly1, n1, poly2, n2, resultPoly);

    printf("\nPolynomial 1:       ");
    displayPolynomial(poly1, n1);

    printf("Polynomial 2:       ");
    displayPolynomial(poly2, n2);

    printf("Result (Poly1 + Poly2): ");
    displayPolynomial(resultPoly, n3);

    return 0;
}