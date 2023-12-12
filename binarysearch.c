#include <stdio.h>

int BinarySearch(int arr[], int n, int data) {
    int left = 0;
    int right = n - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (arr[mid] == data) {
            return mid; // Return the index if the data is found
        }

        if (arr[mid] < data) {
            left = mid + 1; // Search the right half
        } else {
            right = mid - 1; // Search the left half
        }
    }

    return -1; // Return -1 if the data is not found
}

int main() {
    int arr[] = {5, 8, 15, 25, 42, 55};
    int n = sizeof(arr) / sizeof(arr[0]);

    int data;
    printf("Enter the element to search: ");
    scanf("%d", &data);

    int result = BinarySearch(arr, n, data);

    if (result != -1) {
        printf("Element found at index %d\n", result);
    } else {
        printf("Element not found\n");
    }

    return 0;
}
