# Recursive Binary Search

Recursive Binary Search is a searching algorithm that efficiently locates a target value within a **sorted array** by repeatedly dividing the search interval in half.

Unlike the iterative implementation, this version uses **recursive function calls** to represent each reduction of the search space.

---

## 1. Problem Statement

Given a **sorted array** and a target value, find the index of the target using Recursive Binary Search.

If the target exists, return its index. If it does not exist, return `-1`.

The algorithm repeatedly reduces the search interval by half until the target is found or no elements remain to be searched.

---

## 2. Algorithm / Approach

Recursive Binary Search applies the **Divide and Conquer** principle through recursive function calls.

### Steps

1. Define the current search boundaries using `left` and `right`.
2. Check whether the search interval is empty:

   ```text
   if left > right
   ```

   If it is empty, return `-1`.

3. Calculate the middle index:

   ```text
   mid = left + (right - left) / 2
   ```

4. Compare `arr[mid]` with the target.
5. If they are equal, return `mid`.
6. If the target is smaller than `arr[mid]`, recursively search the left half:

   ```text
   right = mid - 1
   ```

7. If the target is larger than `arr[mid]`, recursively search the right half:

   ```text
   left = mid + 1
   ```

8. Continue until the target is found or the search interval becomes empty.

### Key Idea

> Each recursive call eliminates approximately half of the remaining search space.

### Important Requirement

The input array **must be sorted** for standard Binary Search to work correctly.

---

## 3. Pseudocode

```text id="v9zq2k"
function recursiveBinarySearch(arr, left, right, target):
    if left > right:
        return -1

    mid = left + (right - left) / 2

    if arr[mid] == target:
        return mid

    else if arr[mid] > target:
        return recursiveBinarySearch(
            arr,
            left,
            mid - 1,
            target
        )

    else:
        return recursiveBinarySearch(
            arr,
            mid + 1,
            right,
            target
        )
```

---

## 4. Time & Space Complexity

| Case                 | Time Complexity | Explanation                                                                                          |
| -------------------- | --------------: | ---------------------------------------------------------------------------------------------------- |
| **Best Case**        |        **O(1)** | The target is found at the middle index during the first call.                                       |
| **Average Case**     |    **O(log N)** | The search space is approximately halved after every recursive call.                                 |
| **Worst Case**       |    **O(log N)** | The maximum recursion depth is logarithmic because half of the search space is eliminated each time. |
| **Space Complexity** |    **O(log N)** | Each recursive call creates a stack frame, resulting in logarithmic auxiliary space.                 |

### Complexity Summary

- **Best-case time:** `O(1)`
- **Average-case time:** `O(log N)`
- **Worst-case time:** `O(log N)`
- **Space:** `O(log N)`
- **Requires sorted data:** Yes
- **In-place:** Yes, with respect to the array itself
- **Approach:** Recursive

### Iterative vs. Recursive

The two implementations have the same time complexity but different auxiliary-space requirements:

| Implementation              |       Time | Auxiliary Space |
| --------------------------- | ---------: | --------------: |
| **Iterative Binary Search** | `O(log N)` |          `O(1)` |
| **Recursive Binary Search** | `O(log N)` |      `O(log N)` |

The additional space comes from the **call stack**, not from creating another copy of the array.

---

## 5. Sample Input / Output

### Input

```text id="q9f4jo"
arr = [2, 5, 8, 12, 16, 23, 38, 56, 72, 91]
target = 72
```

### Output

```text id="m6c0ax"
Element 72 found at index 8
```

---

## 6. Step-by-Step Visualization

Consider the following sorted array:

```text id="j2tw3p"
Array:  [2, 5, 8, 12, 16, 23, 38, 56, 72, 91]
Target: 72
```

### Call 1

```text id="h3zv2p"
left = 0
right = 9
mid = 4

arr[4] = 16
```

Since:

```text id="p5qj9t"
16 < 72
```

the target must be in the right half.

Recursive call:

```text id="z7j2yw"
search(left = 5, right = 9)
```

---

### Call 2

```text id="n4s7xw"
left = 5
right = 9
mid = 7

arr[7] = 56
```

Since:

```text id="g3v6kz"
56 < 72
```

the target must be further to the right.

Recursive call:

```text id="x5m9ac"
search(left = 8, right = 9)
```

---

### Call 3

```text id="e5x3qp"
left = 8
right = 9
mid = 8

arr[8] = 72
```

The target has been found:

```text id="s2b4nf"
Element 72 found at index 8
```

### Call Stack

```text id="g4v1rd"
Call 1:
search(left=0, right=9)
    mid=4
    arr[4]=16
    16 < 72
        |
        +--> Call 2:
             search(left=5, right=9)
                 mid=7
                 arr[7]=56
                 56 < 72
                     |
                     +--> Call 3:
                          search(left=8, right=9)
                              mid=8
                              arr[8]=72
                              MATCH!
                                  |
                                  <- return 8
                          <- return 8
                 <- return 8
        <- return 8
```

The return value propagates back through each recursive call until the original function call receives the final index.

---

## 7. Implementation

A C++ implementation can be found in:

```text id="2g3j5q"
recursiveBinarySearch.cpp
```

Example implementation:

```cpp id="q8c7mz"
#include <iostream>
#include <vector>
using namespace std;

int recursiveBinarySearch(
    const vector<int>& arr,
    int left,
    int right,
    int target
) {
    if (left > right) {
        return -1;
    }

    int mid = left + (right - left) / 2;

    if (arr[mid] == target) {
        return mid;
    }

    if (arr[mid] > target) {
        return recursiveBinarySearch(
            arr,
            left,
            mid - 1,
            target
        );
    }

    return recursiveBinarySearch(
        arr,
        mid + 1,
        right,
        target
    );
}

int main() {
    vector<int> arr = {
        2, 5, 8, 12, 16,
        23, 38, 56, 72, 91
    };

    int target = 72;

    int index = recursiveBinarySearch(
        arr,
        0,
        arr.size() - 1,
        target
    );

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

```text id="u5a0h9"
Element 72 found at index 8
```

---

## 8. Screenshots / Graphs

Add a screenshot of the VS Code terminal showing the successful compilation and execution of `recursiveBinarySearch.cpp`.

For example:

```text id="v4y8ck"
┌──────────────────────────────────────────────────┐
│ VS Code Terminal                                 │
│                                                  │
│ $ g++ recursiveBinarySearch.cpp -o binarySearch │
│ $ ./binarySearch                                 │
│ Element 72 found at index 8                     │
└──────────────────────────────────────────────────┘
```

> **Note:** Replace the example above with an actual screenshot of your program's output.

---

## 9. Experimental Results

Recursive and iterative Binary Search have the same asymptotic time complexity:

```text
O(log N)
```

However, their practical characteristics differ.

The recursive implementation introduces function-call overhead and requires additional stack memory for each recursive call. The iterative implementation avoids these costs and therefore is generally preferable when minimizing runtime overhead and auxiliary memory is important.

For Binary Search specifically, the recursion depth is only `O(log N)`, so stack usage is relatively small compared with algorithms that may recurse once per input element.

The recursive version can nevertheless be attractive when **clarity and structural simplicity** are more important than minimizing these small overheads.

---

## 10. When Would You Choose Recursive Binary Search?

Despite having the same `O(log N)` time complexity as the iterative version, there are situations where the recursive implementation can be a reasonable production choice.

### 1. Readability Is a Priority

Recursive Binary Search maps naturally to its mathematical definition:

```text
Search the current range
        ↓
Check the middle
        ↓
Choose one half
        ↓
Search that half again
```

For teams that find this representation easier to understand and maintain, recursion can make the implementation more expressive.

### 2. The Codebase Already Uses Recursion

If a production codebase consistently uses recursive implementations for divide-and-conquer algorithms, using the recursive version can provide consistency across the project.

This can be especially useful in algorithm-heavy libraries where recursive decomposition is already the dominant design pattern.

### 3. The Recursive Function Is a Building Block

A recursive Binary Search function can be convenient when another recursive algorithm already operates in terms of subranges.

For example:

```text
search(arr, left, right, target)
```

naturally represents a search over a specific interval without requiring additional state.

### 4. Stack Depth Is Known to Be Safe

Binary Search has a recursion depth of only `O(log N)`.

For example:

```text
N = 1,000,000
log₂(N) ≈ 20
```

Only around 20 recursive levels are required.

Therefore, in a normal environment with a sufficiently sized call stack, recursion is unlikely to be problematic for ordinary Binary Search workloads.

### 5. Performance Requirements Allow the Small Overhead

If profiling shows that the tiny additional cost of recursive calls is irrelevant to the application's performance requirements, the readability benefits may outweigh the extra stack usage.

---

## 11. When Should You Prefer the Iterative Version?

The iterative implementation is generally the safer default when:

- Memory usage must be minimized.
- The code runs in a constrained or embedded environment.
- Extremely strict latency requirements exist.
- Function-call overhead matters.
- The project follows an iterative coding style.
- There is no meaningful readability benefit from recursion.

In these situations, the iterative version provides:

```text
O(log N) time
O(1) auxiliary space
```

without requiring recursive stack frames.

---

## 12. Advantages

- Elegant representation of the Divide and Conquer strategy.
- Closely matches the mathematical definition of Binary Search.
- Simple recursive structure.
- `O(log N)` average and worst-case time complexity.
- Natural fit for recursive algorithmic codebases.
- Recursion depth is only `O(log N)`.

---

## 13. Disadvantages

- Uses `O(log N)` auxiliary stack space.
- Introduces function-call overhead.
- Can be slightly less efficient than the iterative implementation.
- Requires careful handling of the base case.
- Recursion may be discouraged in memory-constrained or performance-critical systems.

---

## 14. Learning Outcomes

By implementing Recursive Binary Search, the following concepts can be understood:

- How Divide and Conquer can be expressed through recursion.
- How recursive calls progressively reduce the search space.
- How base cases prevent infinite recursion.
- How `left` and `right` boundaries define a recursive subproblem.
- How recursion uses the call stack.
- The difference between algorithmic complexity and implementation-level overhead.
- The trade-off between code readability and auxiliary memory usage.

---

## 15. Conclusion

Recursive Binary Search demonstrates how a Divide and Conquer algorithm can be expressed naturally using recursive function calls.

Each call reduces the search space by approximately half, resulting in `O(log N)` average and worst-case time complexity.

However, unlike the iterative implementation, the recursive version requires `O(log N)` auxiliary space because of the call stack.

In production systems, the recursive version is most appropriate when its **clarity, consistency, or integration with other recursive code** provides a meaningful benefit and the additional stack usage is acceptable.

For highly memory-constrained or performance-critical applications, the iterative implementation is generally the better choice.

---
