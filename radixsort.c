#include <stdio.h>
#include <stdlib.h>

struct Array {
    int* data;
    int size;
};

// A utility function to get the maximum value in arr[]
int getMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

// Using counting sort to sort the elements based on significant places
void countingSort(int arr[], int n, int exp) {
    const int RANGE = 10; // 0 to 9
    int output[n];
    int count[RANGE]; // Remove initialization

    // Initialize count array to zeros
    for (int i = 0; i < RANGE; i++)
        count[i] = 0;

    // Store count of occurrences in count[]
    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % RANGE]++;

    // Change count[i] so that count[i] now contains actual
    // position of this digit in output[]
    for (int i = 1; i < RANGE; i++)
        count[i] += count[i - 1];

    // Build the output array
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % RANGE] - 1] = arr[i];
        count[(arr[i] / exp) % RANGE]--;
    }

    // Copy the output array to arr[], so that arr[] contains sorted numbers according to current digit
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}


// The main function to implement Radix Sort
void radixSort(int arr[], int n) {
    // Find the maximum number to know the number of digits
    int max = getMax(arr, n);

    // Do counting sort for every digit
    for (int exp = 1; max / exp > 0; exp *= 10)
        countingSort(arr, n, exp);
}

// A utility function to print an array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Driver program to test above functions
int main() {
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Unsorted array: ");
    printArray(arr, n);

    radixSort(arr, n);

    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}
