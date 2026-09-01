#include <iostream>

using namespace std;

// Function to perform Recursive Binary Search
int recursiveBinarySearch(int arr[], int left, int right, int target) {
    // Base case: If the search space is valid
    if (left <= right) {
        // Calculate mid to prevent integer overflow
        int mid = left + (right - left) / 2;

        // Check if the target is present at the middle
        if (arr[mid] == target) {
            return mid;
        }

        // If the target is smaller than mid, it must be in the left subarray
        if (arr[mid] > target) {
            return recursiveBinarySearch(arr, left, mid - 1, target);
        }

        // Otherwise, the target must be in the right subarray
        return recursiveBinarySearch(arr, mid + 1, right, target);
    }

    // Target is not present in the array
    return -1;
}

int main() {
    // Array MUST be sorted
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 72;

    cout << "Sorted array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Perform the recursive search
    int result = recursiveBinarySearch(arr, 0, size - 1, target);

    if (result != -1) {
        cout << "Element " << target << " found at index " << result << endl;
    } else {
        cout << "Element " << target << " not found in the array." << endl;
    }

    return 0;
}