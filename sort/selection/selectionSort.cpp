#include <iostream>

using namespace std;

// Function to perform Selection Sort
void selectionSort(int arr[], int size) {
    // Move the boundary of the unsorted subarray one by one
    for (int i = 0; i < size - 1; i++) {
        
        // Find the minimum element in the unsorted array
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        // Swap the found minimum element with the first element of the unsorted part
        // (Only swap if a smaller element was actually found)
        if (minIndex != i) {
            int temp = arr[minIndex];
            arr[minIndex] = arr[i];
            arr[i] = temp;
        }
    }
}

// Helper function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    printArray(arr, size);

    selectionSort(arr, size);

    cout << "Sorted array: ";
    printArray(arr, size);

    return 0;
}