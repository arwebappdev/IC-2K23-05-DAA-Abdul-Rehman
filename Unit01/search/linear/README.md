# Linear Search

Linear Search is a simple searching algorithm that sequentially checks each element of an array until the target value is found or the entire array has been searched.

It does not require the array to be sorted, making it useful for small or unsorted datasets.

---

## 1. Problem Statement

Given an array of elements and a target value, find the **index position** of the target within the array.

The algorithm checks each element from left to right until:

- The target value is found, in which case its index is returned.
- The entire array is searched without finding the target, in which case `-1` is returned.

---

## 2. Algorithm / Approach

Linear Search is one of the simplest searching techniques.

### Steps

1. Start at the first element of the array (`index 0`).
2. Compare the current element with the target value.
3. If the current element matches the target, return its index.
4. If it does not match, move to the next element.
5. Continue until the target is found or the end of the array is reached.
6. If the target is not found, return `-1`.

### Key Idea

> Check every element sequentially until the target is found.

Unlike Binary Search, Linear Search **does not require the array to be sorted**.

---

## 3. Pseudocode

```text
function linearSearch(arr, size, target):
    for i from 0 to size - 1:
        if arr[i] == target:
            return i

    return -1
```

---

## 4. Time & Space Complexity

| Case                 | Time Complexity | Explanation                                                                                       |
| -------------------- | --------------: | ------------------------------------------------------------------------------------------------- |
| **Best Case**        |        **O(1)** | The target is found at the first index.                                                           |
| **Average Case**     |        **O(N)** | The target is typically found somewhere in the middle, requiring approximately `N/2` comparisons. |
| **Worst Case**       |        **O(N)** | The target is at the last index or is not present, requiring a complete traversal.                |
| **Space Complexity** |        **O(1)** | Only a constant amount of additional memory is required.                                          |

### Complexity Summary

- **Best-case time:** `O(1)`
- **Average-case time:** `O(N)`
- **Worst-case time:** `O(N)`
- **Space:** `O(1)`
- **Requires sorted data:** No
- **In-place:** Yes

---

## 5. Sample Input / Output

### Input

```text
arr = [34, 78, 12, 9, 85, 22]
target = 85
```

### Output

```text
Element 85 found at index 4
```

---

## 6. Step-by-Step Visualization

Consider the following array:

```text
Array:  [34, 78, 12, 9, 85, 22]
Target: 85
```

Linear Search starts from index `0` and moves from left to right.

```text
Step 1: Check index 0 (34) -> No match
Step 2: Check index 1 (78) -> No match
Step 3: Check index 2 (12) -> No match
Step 4: Check index 3 (9)  -> No match
Step 5: Check index 4 (85) -> MATCH!
```

The algorithm returns:

```text
4
```

Visual representation:

```text
Index:   0    1    2   3    4    5
        ┌────┬────┬───┬───┬────┬────┐
Array:  │ 34 │ 78 │12 │ 9 │ 85 │ 22 │
        └────┴────┴───┴───┴────┴────┘
                              ↑
                           Target
```

---

## 7. Implementation

A C++ implementation can be found in:

```text
linearSearch.cpp
```

Example implementation:

```cpp
#include <iostream>
#include <vector>
using namespace std;

int linearSearch(const vector<int>& arr, int target) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == target) {
            return i;
        }
    }

    return -1;
}

int main() {
    vector<int> arr = {34, 78, 12, 9, 85, 22};
    int target = 85;

    int index = linearSearch(arr, target);

    if (index != -1) {
        cout << "Element " << target
             << " found at index " << index << endl;
    } else {
        cout << "Element " << target
             << " not found" << endl;
    }

    return 0;
}
```

### Expected Output

```text
Element 85 found at index 4
```

---

## 8. Screenshots / Graphs

Add a screenshot of the terminal showing the successful compilation and execution of `linearSearch.cpp`.

For example:

```text
┌─────────────────────────────────────────────┐
│ VS Code Terminal                            │
│                                             │
│ $ g++ linearSearch.cpp -o linearSearch     │
│ $ ./linearSearch                            │
│ Element 85 found at index 4                │
└─────────────────────────────────────────────┘
```

---

## 9. Experimental Results

Linear Search performs consistently regardless of whether the input array is sorted or unsorted.

Its main advantage is that **no preprocessing or sorting is required**. This makes it useful when:

- The dataset is small.
- The data is unsorted.
- The array is searched only once or a small number of times.
- Simplicity is more important than optimal search performance.
- The data structure does not provide direct indexing or efficient lookup.

However, Linear Search becomes inefficient as the dataset grows because its average and worst-case time complexity is `O(N)`.

For repeated searches, other data structures or algorithms may be more appropriate. For example, a sorted array can use Binary Search with `O(log N)` search time, while a hash table can provide average `O(1)` lookup time for suitable workloads.

---

## 10. Linear Search vs. Binary Search

| Feature                      | Linear Search | Binary Search    |
| ---------------------------- | ------------- | ---------------- |
| **Sorted data required**     | No            | Yes              |
| **Best Case**                | `O(1)`        | `O(1)`           |
| **Average Case**             | `O(N)`        | `O(log N)`       |
| **Worst Case**               | `O(N)`        | `O(log N)`       |
| **Space**                    | `O(1)`        | `O(1)` iterative |
| **Works on unsorted arrays** | Yes           | No               |
| **Implementation**           | Very simple   | More complex     |

### Which One Should You Use?

Use **Linear Search** when the data is small, unsorted, or only needs to be searched occasionally.

Use **Binary Search** when the data is sorted and many searches need to be performed efficiently.

---

## 11. Advantages

- Very simple to understand and implement.
- Works on both sorted and unsorted arrays.
- Requires no preprocessing.
- Uses constant extra space.
- Works well for small datasets.
- Can search data structures where random access is not available.

---

## 12. Disadvantages

- `O(N)` average and worst-case time complexity.
- Slow for large datasets.
- Becomes inefficient when many searches are performed on the same data.
- Does not take advantage of sorted data.

---

## 13. Learning Outcomes

By implementing Linear Search, the following concepts can be understood:

- Basic array traversal.
- Sequential element comparison.
- Returning an index when an element is found.
- Handling unsuccessful searches using `-1`.
- Understanding best-case, average-case, and worst-case complexity.
- Recognizing when a simple algorithm is appropriate and when a more efficient approach is necessary.
- Understanding the trade-off between preprocessing and search performance.

---

## 14. Conclusion

Linear Search is one of the fundamental searching algorithms and provides an excellent introduction to sequential data processing.

Its biggest advantage is simplicity: **it can search an array without requiring the data to be sorted**. However, this simplicity comes at the cost of `O(N)` average and worst-case search time.

For small or infrequently searched datasets, Linear Search can be perfectly reasonable. For large datasets or applications involving many repeated searches, more efficient techniques such as Binary Search, hash-based lookup, or indexed data structures are generally preferable.

---
