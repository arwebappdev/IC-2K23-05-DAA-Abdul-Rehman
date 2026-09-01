#include <iostream>

using namespace std;

// Function to perform Iterative Binary Search
int iterativeBinarySearch(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        // Calculate mid this way to prevent integer overflow for large arrays
        int mid = left + (right - left) / 2;

        // Check if target is present at mid
        if (arr[mid] == target) {
            return mid;
        }

        // If target is greater, ignore the left half
        if (arr[mid] < target) {
            left = mid + 1;
        } 
        // If target is smaller, ignore the right half
        else {
            right = mid - 1;
        }
    }

    // Target was not found
    return -1;
}

int main() {
    // Array MUST be sorted for Binary Search to work
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 23;

    cout << "Sorted array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    int result = iterativeBinarySearch(arr, size, target);

    if (result != -1) {
        cout << "Element " << target << " found at index " << result << endl;
    } else {
        cout << "Element " << target << " not found in the array." << endl;
    }

    return 0;
}