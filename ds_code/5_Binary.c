#include <stdio.h>
int binarySearch(int arr[], int n, int target) {
    int low = 0;
    int high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) {
            return mid; 
        }
        if (arr[mid] < target) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return -1;
}

int main() {
    int arr[100];
    int n, target, result;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    printf("Enter %d integers IN SORTED ORDER:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to search for: ");
    scanf("%d", &target);

    result = binarySearch(arr, n, target);


    if (result == -1) {
        printf("Element not found in the array.\n");
    } else {
        printf("Element found at position: %d\n", result);
    }

    return 0;
}