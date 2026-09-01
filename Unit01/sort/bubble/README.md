# Bubble Sort

Bubble Sort is a simple comparison-based sorting algorithm that repeatedly compares adjacent elements and swaps them when they are in the wrong order. After each pass, the largest unsorted element "bubbles" to its correct position at the end of the array.

---

## 1. Problem Statement

Given an unsorted array of integers, sort the elements in **ascending order** using the Bubble Sort algorithm.

The algorithm repeatedly compares adjacent elements and swaps them if the left element is greater than the right element. This process continues until the entire array is sorted.

---

## 2. Algorithm / Approach

Bubble Sort works by repeatedly processing the unsorted portion of the array.

### Steps

1. Start from the first element of the array.
2. Compare the current element with the next element.
3. If the current element is greater than the next element, swap them.
4. Continue comparing adjacent elements until the end of the unsorted portion is reached.
5. After the first pass, the largest element will be placed at the end of the array.
6. Repeat the process for the remaining unsorted elements.
7. Use a `swapped` flag to detect whether any swaps occurred during a pass.
8. If a complete pass is made without any swaps, the array is already sorted, so the algorithm terminates early.

### Key Idea

> After every pass, the largest remaining unsorted element is moved to its correct position.

---

## 3. Pseudocode

```text
function bubbleSort(arr, size):
    for i from 0 to size - 2:
        swapped = false

        for j from 0 to size - i - 2:
            if arr[j] > arr[j + 1]:
                swap arr[j] and arr[j + 1]
                swapped = true

        if not swapped:
            break
```

---

## 4. Time & Space Complexity

| Case                 | Time Complexity | Explanation                                                                                               |
| -------------------- | --------------: | --------------------------------------------------------------------------------------------------------- |
| **Best Case**        |        **O(N)** | The array is already sorted. The optimized version completes one pass without swaps and terminates early. |
| **Average Case**     |       **O(N²)** | Elements are in a random order, requiring multiple passes and comparisons.                                |
| **Worst Case**       |       **O(N²)** | The array is reverse sorted, requiring the maximum number of comparisons and swaps.                       |
| **Space Complexity** |        **O(1)** | Bubble Sort is an in-place algorithm and requires only constant extra space.                              |

### Complexity Summary

- **Time:** `O(N²)` average and worst case
- **Best-case time:** `O(N)` with the early-termination optimization
- **Space:** `O(1)`
- **In-place:** Yes
- **Stable:** Yes

---

## 5. Sample Input / Output

### Input

```text
[64, 34, 25, 12, 22, 11, 90]
```

### Output

```text
[11, 12, 22, 25, 34, 64, 90]
```

---

## 6. Step-by-Step Visualization

Consider the following array:

```text
[64, 34, 25, 12, 22, 11, 90]
```

### First Pass

The algorithm compares adjacent elements from left to right.

```text
Initial Array:
[64, 34, 25, 12, 22, 11, 90]
```

Compare `64` and `34`:

```text
[34, 64, 25, 12, 22, 11, 90]
```

Compare `64` and `25`:

```text
[34, 25, 64, 12, 22, 11, 90]
```

Compare `64` and `12`:

```text
[34, 25, 12, 64, 22, 11, 90]
```

Compare `64` and `22`:

```text
[34, 25, 12, 22, 64, 11, 90]
```

Compare `64` and `11`:

```text
[34, 25, 12, 22, 11, 64, 90]
```

Compare `64` and `90`:

```text
No swap
```

At the end of the first pass:

```text
[34, 25, 12, 22, 11, 64, 90]
                         ↑
                 Correct position
```

The largest element, `90`, is already at the end, and `64` is moved to the second-last position.

The remaining passes continue in the same way until the array becomes:

```text
[11, 12, 22, 25, 34, 64, 90]
```

---

## 7. Implementation

A C++ implementation can be found in:

```text
bubbleSort.cpp
```

Example implementation:

```cpp
#include <iostream>
#include <vector>
using namespace std;

void bubbleSort(vector<int>& arr) {
    int n = arr.size();

    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;

        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        // Array is already sorted
        if (!swapped) {
            break;
        }
    }
}

int main() {
    vector<int> arr = {64, 34, 25, 12, 22, 11, 90};

    bubbleSort(arr);

    cout << "Sorted Array: ";

    for (int value : arr) {
        cout << value << " ";
    }

    cout << endl;

    return 0;
}
```

### Expected Output

```text
Sorted Array: 11 12 22 25 34 64 90
```

---

## 8. Screenshots / Graphs

Add a screenshot of the VS Code terminal showing the successful compilation and execution of `bubbleSort.cpp`.

For example:

```text
┌─────────────────────────────────────────────┐
│ VS Code Terminal                            │
│                                             │
│ $ g++ bubbleSort.cpp -o bubbleSort         │
│ $ ./bubbleSort                              │
│ Sorted Array: 11 12 22 25 34 64 90        │
└─────────────────────────────────────────────┘
```

---

## 9. Experimental Results

Bubble Sort is primarily useful for understanding the fundamentals of sorting algorithms rather than for production use.

Although its average and worst-case time complexity is `O(N²)`, its practical performance can be worse than other simple sorting algorithms because it performs frequent swaps.

For example:

- **Bubble Sort** repeatedly swaps adjacent elements.
- **Insertion Sort** can shift elements instead of performing repeated swaps.
- **Selection Sort** performs fewer swaps, although it still requires `O(N²)` comparisons.

Therefore, two algorithms with the same asymptotic time complexity can still have noticeably different practical performance because of differences in the number of writes, swaps, and other operations they perform.

---

## 10. Advantages

- Simple and easy to understand.
- Easy to implement.
- Requires `O(1)` extra space.
- Works in-place.
- Stable sorting algorithm.
- The optimized version can detect an already-sorted array in `O(N)` time.

---

## 11. Disadvantages

- `O(N²)` average-case time complexity.
- `O(N²)` worst-case time complexity.
- Performs many swaps compared with more efficient algorithms.
- Not suitable for large datasets.
- Generally slower than algorithms such as Merge Sort, Quick Sort, or Heap Sort.

---

## 12. Learning Outcomes

By implementing Bubble Sort, the following concepts can be understood:

- How comparison-based sorting algorithms work.
- How adjacent elements can be compared and swapped.
- How nested loops can be used to process an array.
- How an optimization such as a `swapped` flag can improve the best-case performance.
- The difference between theoretical complexity and practical performance.
- The importance of choosing an appropriate sorting algorithm based on the size and characteristics of the input.

---

## 13. Conclusion

Bubble Sort is one of the simplest sorting algorithms and is an excellent starting point for learning how sorting works internally.

Its main idea is straightforward: **repeatedly compare adjacent elements and swap them when they are out of order**. With each pass, the largest remaining unsorted element moves toward the end of the array.

Despite its simplicity, Bubble Sort is generally inefficient for large datasets because of its `O(N²)` average and worst-case time complexity. Its primary value is educational, helping build a foundation for understanding more advanced sorting algorithms.

---
