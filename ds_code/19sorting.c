#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void resetArray(int arr[], int original[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = original[i];
    }
}

void selectionSort(int arr[], int n) {
    int i, j, min_idx;

    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        swap(&arr[min_idx], &arr[i]);
    }
}

void bubbleSort(int arr[], int n) {
    int i, j;
    int swapped;
    for (i = 0; i < n - 1; i++) {
        swapped = 0;
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                swapped = 1;
            }
        }
        if (swapped == 0)
            break;
    }
}

void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int main() {
    int original_list[] = {56, 77, 23, 99, 68, 11, 9, 29, 33, 45, 10, 87};
    int n = sizeof(original_list) / sizeof(original_list[0]);
    
    int arr[n];
    
    printf("Original List: ");
    printArray(original_list, n);
    printf("\n");

    // --- 1. Selection Sort ---
    resetArray(arr, original_list, n);
    printf("--- Selection Sort ---\n");
    printf("Sorted List:   ");
    selectionSort(arr, n);
    printArray(arr, n);
    printf("\n");

    // --- 2. Bubble Sort ---
    resetArray(arr, original_list, n);
    printf("--- Bubble Sort ---\n");
    printf("Sorted List:   ");
    bubbleSort(arr, n);
    printArray(arr, n);
    printf("\n");

    // --- 3. Insertion Sort ---
    resetArray(arr, original_list, n);
    printf("--- Insertion Sort ---\n");
    printf("Sorted List:   ");
    insertionSort(arr, n);
    printArray(arr, n);
    printf("\n");

    // --- 4. Quick Sort ---
    resetArray(arr, original_list, n);
    printf("--- Quick Sort ---\n");
    printf("Sorted List:   ");
    quickSort(arr, 0, n - 1);
    printArray(arr, n);
    printf("\n");

    // --- 5. Merge Sort ---
    resetArray(arr, original_list, n);
    printf("--- Merge Sort ---\n");
    printf("Sorted List:   ");
    mergeSort(arr, 0, n - 1);
    printArray(arr, n);
    printf("\n");

    return 0;
}
