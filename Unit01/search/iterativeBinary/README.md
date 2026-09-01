# Iterative Binary Search

Binary Search is an efficient searching algorithm that finds a target value in a **sorted array** by repeatedly dividing the search interval in half.

This implementation uses an **iterative approach**, meaning it uses a loop instead of recursive function calls.

---

## 1. Problem Statement

Given a **sorted array** and a target value, efficiently find the index of the target using Binary Search.

If the target exists in the array, return its index. If it does not exist, return `-1`.

---

## 2. Algorithm / Approach

Binary Search follows the **Divide and Conquer** principle.

Instead of checking every element sequentially like Linear Search, Binary Search eliminates half of the remaining search space after every comparison.

### Steps

1. Initialize `left` to the first index of the array.
2. Initialize `right` to the last index of the array.
3. Calculate the middle index:

   ```text
   mid = left + (right - left) / 2
   ```

4. Compare `arr[mid]` with the target.
5. If `arr[mid] == target`, return `mid`.
6. If `arr[mid] < target`, the target must be in the right half, so update:

   ```text
   left = mid + 1
   ```

7. If `arr[mid] > target`, the target must be in the left half, so update:

   ```text
   right = mid - 1
   ```

8. Repeat while `left <= right`.
9. If `left` becomes greater than `right`, the target is not present, so return `-1`.

### Key Idea

> Because the array is sorted, each comparison allows us to eliminate half of the remaining search space.

### Important Requirement

Binary Search **requires the input data to be sorted**.

For example:

```text
Sorted:   [2, 5, 8, 12, 16, 23, 38, 56, 72, 91]
```

Binary Search can efficiently search this array.

An unsorted array such as:

```text
[23, 5, 91, 12, 2, 56, 8]
```

cannot be searched correctly using standard Binary Search.

---

## 3. Pseudocode

```text
function iterativeBinarySearch(arr, size, target):
    left = 0
    right = size - 1

    while left <= right:
        mid = left + (right - left) / 2

        if arr[mid] == target:
            return mid

        else if arr[mid] < target:
            left = mid + 1

        else:
            right = mid - 1

    return -1
```

### Why Use `left + (right - left) / 2`?

The following calculation is commonly used:

```text
mid = (left + right) / 2
```

However, if `left` and `right` are very large integers, `left + right` can potentially overflow the integer range.

Using:

```text
mid = left + (right - left) / 2
```

avoids that particular overflow scenario while producing the same midpoint.

---

## 4. Time & Space Complexity

| Case                 | Time Complexity | Explanation                                                                                               |
| -------------------- | --------------: | --------------------------------------------------------------------------------------------------------- |
| **Best Case**        |        **O(1)** | The target is found at the middle position during the first comparison.                                   |
| **Average Case**     |    **O(log N)** | The search space is approximately halved after every iteration.                                           |
| **Worst Case**       |    **O(log N)** | The maximum number of iterations is logarithmic because half of the search space is eliminated each time. |
| **Space Complexity** |        **O(1)** | The iterative implementation uses only `left`, `right`, and `mid`.                                        |

### Complexity Summary

- **Best-case time:** `O(1)`
- **Average-case time:** `O(log N)`
- **Worst-case time:** `O(log N)`
- **Space:** `O(1)`
- **Requires sorted data:** Yes
- **In-place:** Yes
- **Approach:** Iterative

---

## 5. Sample Input / Output

### Input

```text
arr = [2, 5, 8, 12, 16, 23, 38, 56, 72, 91]
target = 23
```

### Output

```text
Element 23 found at index 5
```

---

## 6. Step-by-Step Visualization

Consider the following sorted array:

```text
Array:  [2, 5, 8, 12, 16, 23, 38, 56, 72, 91]
Target: 23
```

### Iteration 1

```text
left = 0
right = 9
mid = 4
```

The middle element is:

```text
arr[4] = 16
```

Since:

```text
16 < 23
```

the target must be in the **right half**.

Update the boundaries:

```text
left = 5
right = 9
```

---

### Iteration 2

```text
left = 5
right = 9
mid = 7
```

The middle element is:

```text
arr[7] = 56
```

Since:

```text
56 > 23
```

the target must be in the **left half**.

Update the boundaries:

```text
left = 5
right = 6
```

---

### Iteration 3

```text
left = 5
right = 6
mid = 5
```

The middle element is:

```text
arr[5] = 23
```

The target has been found.

```text
Element 23 found at index 5
```

Visual representation:

```text
Index:   0   1   2    3    4    5    6    7    8    9
        ┌───┬───┬────┬────┬────┬────┬────┬────┬────┬────┐
Array:  │ 2 │ 5 │ 8  │ 12 │ 16 │ 23 │ 38 │ 56 │ 72 │ 91 │
        └───┴───┴────┴────┴────┴────┴────┴────┴────┴────┘
                                  ↑
                               Target
```

The search required only **3 comparisons** instead of potentially checking all 10 elements with Linear Search.

---

## 7. Implementation

A C++ implementation can be found in:

```text
iterativeBinarySearch.cpp
```

Example implementation:

```cpp
#include <iostream>
#include <vector>
using namespace std;

int iterativeBinarySearch(const vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid;
        }

        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}

int main() {
    vector<int> arr = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int target = 23;

    int index = iterativeBinarySearch(arr, target);

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
Element 23 found at index 5
```

---

## 8. Screenshots / Graphs

Add a screenshot of the terminal showing the successful compilation and execution of `iterativeBinarySearch.cpp`.

For example:

```text
┌─────────────────────────────────────────────────┐
│ VS Code Terminal                                │
│                                                 │
│ $ g++ iterativeBinarySearch.cpp -o binarySearch│
│ $ ./binarySearch                                │
│ Element 23 found at index 5                    │
└─────────────────────────────────────────────────┘
```

> **Note:** Replace the example above with an actual screenshot of your program's output.

---

## 9. Experimental Results

Binary Search demonstrates a significant improvement over Linear Search when working with large **sorted** datasets.

For example, consider an array containing `1,000,000` elements.

A Linear Search may require up to:

```text
1,000,000 comparisons
```

in the worst case.

Binary Search requires approximately:

```text
log₂(1,000,000) ≈ 20 comparisons
```

in the worst case.

This difference becomes increasingly significant as the dataset grows.

### Iterative vs. Recursive Binary Search

Both approaches have the same asymptotic time complexity:

| Approach      |       Time | Extra Space |
| ------------- | ---------: | ----------: |
| **Iterative** | `O(log N)` |      `O(1)` |
| **Recursive** | `O(log N)` |  `O(log N)` |

The iterative implementation avoids recursive function-call overhead and uses constant auxiliary space. Recursive Binary Search is still perfectly practical because its recursion depth is only `O(log N)`, but the iterative version is more memory-efficient.

---

## 10. Binary Search vs. Linear Search

| Feature                   | Linear Search | Binary Search      |
| ------------------------- | ------------- | ------------------ |
| **Sorted data required**  | No            | Yes                |
| **Best Case**             | `O(1)`        | `O(1)`             |
| **Average Case**          | `O(N)`        | `O(log N)`         |
| **Worst Case**            | `O(N)`        | `O(log N)`         |
| **Space**                 | `O(1)`        | `O(1)` iterative   |
| **Approach**              | Sequential    | Divide and Conquer |
| **Large sorted datasets** | Inefficient   | Highly efficient   |

### Important Trade-off

Binary Search is faster **only when its prerequisite is satisfied**.

If the data is unsorted, you cannot simply apply Binary Search. You may need to sort the data first, which introduces an additional cost.

Therefore:

> **Linear Search is often preferable for small or unsorted datasets, while Binary Search is preferable for large sorted datasets or repeated searches over sorted data.**

---

## 11. Advantages

- Very efficient for large sorted datasets.
- `O(log N)` average and worst-case time complexity.
- Requires only `O(1)` auxiliary space in its iterative form.
- Significantly reduces the number of comparisons compared with Linear Search.
- Simple and efficient once the divide-and-conquer principle is understood.

---

## 12. Disadvantages

- Requires the data to be sorted.
- Maintaining sorted data can introduce additional costs.
- Not directly suitable for arbitrary unsorted arrays.
- Less straightforward to implement correctly than Linear Search.
- Provides less benefit when the dataset is very small.

---

## 13. Learning Outcomes

By implementing Iterative Binary Search, the following concepts can be understood:

- The **Divide and Conquer** approach.
- How a sorted dataset can dramatically reduce search time.
- How to maintain and update search boundaries using `left` and `right`.
- How to calculate the midpoint safely.
- The difference between iterative and recursive implementations.
- Why Binary Search achieves `O(log N)` time complexity.
- The importance of prerequisites when selecting an algorithm.

---

## 14. Conclusion

Iterative Binary Search is one of the most important fundamental searching algorithms.

By taking advantage of sorted data, it eliminates approximately half of the remaining search space after every comparison. This results in `O(log N)` average and worst-case time complexity, making it dramatically faster than Linear Search for large sorted datasets.

The iterative implementation is particularly useful because it achieves this performance using only `O(1)` additional space.

However, Binary Search is not universally better than Linear Search. Its effectiveness depends on having **sorted data** and, ideally, a dataset that is large enough or searched frequently enough to justify that requirement.

---
