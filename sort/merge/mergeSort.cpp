#include <iostream>

using namespace std;

// Merges two subarrays of arr[].
void merge(int arr[], int left, int mid, int right) {
    int leftSize = mid - left + 1;
    int rightSize = right - mid;

    // Standard dynamic memory allocation (avoids Variable Length Arrays)
    int* leftArray = new int[leftSize];
    int* rightArray = new int[rightSize];

    // Copy data to temporary arrays
    for (int i = 0; i < leftSize; i++) {
        leftArray[i] = arr[left + i];
    }
    for (int j = 0; j < rightSize; j++) {
        rightArray[j] = arr[mid + 1 + j];
    }

    // Merge the temp arrays back into the original array
    int leftIndex = 0;
    int rightIndex = 0;
    int mergedIndex = left;

    while (leftIndex < leftSize && rightIndex < rightSize) {
        if (leftArray[leftIndex] <= rightArray[rightIndex]) {
            arr[mergedIndex] = leftArray[leftIndex];
            leftIndex++;
        } else {
            arr[mergedIndex] = rightArray[rightIndex];
            rightIndex++;
        }
        mergedIndex++;
    }

    // Copy any remaining elements of leftArray
    while (leftIndex < leftSize) {
        arr[mergedIndex] = leftArray[leftIndex];
        leftIndex++;
        mergedIndex++;
    }

    // Copy any remaining elements of rightArray
    while (rightIndex < rightSize) {
        arr[mergedIndex] = rightArray[rightIndex];
        rightIndex++;
        mergedIndex++;
    }

    // Free memory to prevent memory leaks
    delete[] leftArray;
    delete[] rightArray;
}

// Recursive function to divide the array
void mergeSort(int arr[], int left, int right) {
    if (left >= right) {
        return; // Base case: array has 1 or 0 elements
    }

    // Calculate mid to avoid overflow for large arrays
    int mid = left + (right - left) / 2;

    // Divide the left and right halves
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);

    // Merge the sorted halves
    merge(arr, left, mid, right);
}

// Helper function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    // Standard fixed array
    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    printArray(arr, size);

    mergeSort(arr, 0, size - 1);

    cout << "Sorted array: ";
    printArray(arr, size);

    return 0;
}