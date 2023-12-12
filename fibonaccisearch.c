#include <stdio.h>

int min(int x, int y) {
    return (x <= y) ? x : y;
}

int fibonacciSearch(int arr[], int n, int key) {
    int fibM_minus_2 = 0;
    int fibM_minus_1 = 1;
    int fibM = fibM_minus_1 + fibM_minus_2;

    while (fibM < n) {
        fibM_minus_2 = fibM_minus_1;
        fibM_minus_1 = fibM;
        fibM = fibM_minus_1 + fibM_minus_2;
    }

    int offset = 0;

    while (fibM > 1) {
        int i = min(offset + fibM_minus_2, n);

        if (arr[i] < key) {
            fibM = fibM_minus_1;
            fibM_minus_1 = fibM_minus_2;
            fibM_minus_2 = fibM - fibM_minus_1;
            offset = i;
        } else if (arr[i] > key) {
            fibM = fibM_minus_2;
            fibM_minus_1 = fibM_minus_1 - fibM_minus_2;
            fibM_minus_2 = fibM - fibM_minus_1;
        } else {
            return i;
        }
    }

    

    return -1; // Return -1 if the key is not found
}

int main() {
    int arr[] = {10,22,35,40,45,50,80,82,85,90,100};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    int key;
    printf("Enter the element to search: ");
    scanf("%d", &key);

    int result = fibonacciSearch(arr, n, key);

    if (result != -1) {
        printf("Element found at index %d\n", result);
    } else {
        printf("Element not found\n");
    }

    return 0;
}
