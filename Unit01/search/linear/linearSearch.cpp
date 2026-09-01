#include <iostream>

using namespace std;

// Function to perform Linear Search
int linearSearch(int arr[], int size, int target) {
    // Traverse the array from start to finish
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i; // Target found, return its index
        }
    }
    return -1; // Target not found after checking all elements
}

int main() {
    // Standard fixed-size array
    int arr[] = {34, 78, 12, 9, 85, 22};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 85;

    cout << "Array elements: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Perform the search
    int result = linearSearch(arr, size, target);

    if (result != -1) {
        cout << "Element " << target << " found at index " << result << endl;
    } else {
        cout << "Element " << target << " not found in the array." << endl;
    }

    return 0;
}