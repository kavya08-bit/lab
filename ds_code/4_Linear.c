#include <stdio.h>
int linearSearch(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1; 
}
int main() {
    int arr[100];
    int n, target, result;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to search for: ");
    scanf("%d", &target);

    result = linearSearch(arr, n, target);

    if (result == -1) {
        printf("Element not found in the array.\n");
    } else {
        printf("Element found at position: %d\n", result);
    }

    return 0;
}