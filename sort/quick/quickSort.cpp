#include <iostream>

using namespace std;

// Helper function to swap two elements using references
void swapElements(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// Partitions the array around a pivot element
int partition(int arr[], int low, int high) {
    // Choosing the last element as the pivot
    int pivot = arr[high]; 
    
    // Index of the smaller element
    int i = low - 1; 

    for (int j = low; j < high; j++) {
        // If current element is smaller than or equal to pivot
        if (arr[j] <= pivot) {
            i++; 
            swapElements(arr[i], arr[j]);
        }
    }
    
    // Place the pivot exactly between the smaller and larger elements
    swapElements(arr[i + 1], arr[high]);
    
    return i + 1; // Return the partitioning index
}

// Recursive function to perform Quick Sort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // pi is the partitioning index, arr[pi] is now in its correct sorted position
        int pi = partition(arr, low, high);

        // Recursively sort the elements before and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
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
    int arr[] = {10, 80, 30, 90, 40, 50, 70};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    printArray(arr, size);

    quickSort(arr, 0, size - 1);

    cout << "Sorted array: ";
    printArray(arr, size);

    return 0;
}