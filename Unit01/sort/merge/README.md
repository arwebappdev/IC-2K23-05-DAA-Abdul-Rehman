# Merge Sort

A **Merge Sort** implementation in C++ demonstrating the **Divide and Conquer** algorithmic paradigm.

## 1. Problem Statement

Sort an unsorted array of integers into **ascending order** using a stable, comparison-based sorting algorithm with predictable **worst-case performance**.

---

## 2. Algorithm / Approach

Merge Sort follows the **Divide and Conquer** strategy:

1. **Divide** — Recursively divide the array into two halves until each sub-array contains a single element.
2. **Conquer** — A single-element array is already sorted.
3. **Combine** — Merge the sorted sub-arrays to produce larger sorted sub-arrays until the entire array is sorted.

### High-Level Flow

```text
Unsorted Array
      │
      ▼
 Divide into halves
      │
      ▼
Divide recursively
      │
      ▼
Single-element arrays
      │
      ▼
  Merge sorted arrays
      │
      ▼
  Fully sorted array
```

---

## 3. Pseudocode

### Merge Sort

```text
function mergeSort(arr, left, right):
    if left < right:
        mid = left + (right - left) / 2

        mergeSort(arr, left, mid)
        mergeSort(arr, mid + 1, right)

        merge(arr, left, mid, right)
```

### Merge

```text
function merge(arr, left, mid, right):
    create temporary arrays leftArr and rightArr

    copy elements into leftArr and rightArr

    i = 0
    j = 0
    k = left

    while i < size(leftArr) and j < size(rightArr):
        if leftArr[i] <= rightArr[j]:
            arr[k] = leftArr[i]
            i++
        else:
            arr[k] = rightArr[j]
            j++

        k++

    while i < size(leftArr):
        arr[k] = leftArr[i]
        i++
        k++

    while j < size(rightArr):
        arr[k] = rightArr[j]
        j++
        k++
```

---

## 4. Time & Space Complexity

| Metric                |   Complexity | Explanation                                                                                      |
| --------------------- | -----------: | ------------------------------------------------------------------------------------------------ |
| **Best Case Time**    | `O(N log N)` | The array is always divided into halves, and merging takes `O(N)` at each level.                 |
| **Average Case Time** | `O(N log N)` | The divide-and-merge process remains the same regardless of the input distribution.              |
| **Worst Case Time**   | `O(N log N)` | Even for a reverse-sorted array, the algorithm performs the same recursive divisions and merges. |
| **Space Complexity**  |       `O(N)` | Auxiliary arrays are required during the merge operation.                                        |

### Why `O(N log N)`?

The array is divided into approximately `log₂(N)` levels, and each level performs `O(N)` work during merging.

Therefore:

```text
Time Complexity = O(N) × O(log N)
                = O(N log N)
```

---

## 5. Stability

Merge Sort is a **stable sorting algorithm** when implemented appropriately.

In the merge step, using:

```cpp
if (leftArr[i] <= rightArr[j])
```

ensures that when two elements have equal values, the element from the left sub-array is selected first.

This preserves the relative ordering of equal elements.

---

## 6. Sample Input / Output

### Input

```text
[38, 27, 43, 3, 9, 82, 10]
```

### Output

```text
[3, 9, 10, 27, 38, 43, 82]
```

---

## 7. Merge Sort Visualization

The following illustrates how the sample array is recursively divided and then merged:

```text
                   [38, 27, 43, 3, 9, 82, 10]
                  /                          \
         [38, 27, 43, 3]                  [9, 82, 10]
          /          \                     /        \
     [38, 27]      [43, 3]             [9, 82]     [10]
     /      \       /    \             /     \
   [38]    [27]   [43]   [3]         [9]    [82]

     \      /       \    /             \     /
     [27, 38]       [3, 43]            [9, 82]
          \           /                    \   /
         [3, 27, 38, 43]                [9, 10, 82]
                  \                          /
                   \                        /
                    [3, 9, 10, 27, 38, 43, 82]
```

---

## 8. Screenshots / Graphs

Add a screenshot of the VS Code terminal showing the successful compilation and execution of `mergeSort.cpp`.

For example:

```text
$ g++ mergeSort.cpp -o mergeSort
$ ./mergeSort

Original Array:
38 27 43 3 9 82 10

Sorted Array:
3 9 10 27 38 43 82
```

> **TODO:** Add a screenshot of the actual terminal output here.

---

## 9. Experimental Results

Merge Sort consistently performs well on large datasets and avoids the quadratic worst-case behavior of algorithms such as Bubble Sort and Selection Sort.

Its time complexity remains **`O(N log N)` in the best, average, and worst cases**.

However, the algorithm requires additional memory for the temporary arrays used during merging. If the implementation dynamically allocates and deallocates arrays during every merge operation, such as with `new[]` and `delete[]`, these allocations can introduce additional runtime overhead.

In practice, this may make a well-implemented Quick Sort faster on average, despite both algorithms having `O(N log N)` average-case performance.

---

## 10. Advantages

- Guaranteed `O(N log N)` time complexity.
- Stable sorting algorithm.
- Performs well on large datasets.
- Predictable worst-case performance.
- Well suited for sorting linked lists and external datasets.
- Naturally parallelizable because independent sub-arrays can be processed separately.

---

## 11. Disadvantages

- Requires `O(N)` auxiliary space for a typical array implementation.
- Additional memory allocation can introduce overhead.
- Often slower than optimized Quick Sort for in-memory array sorting due to extra copying and memory usage.
- More implementation complexity than simple algorithms such as Bubble Sort or Selection Sort.

---

## 12. Learning Outcomes

By implementing Merge Sort, the following concepts are demonstrated:

- Understanding the **Divide and Conquer** algorithmic strategy.
- Implementing recursive algorithms in C++.
- Understanding how the merge operation combines sorted arrays.
- Working with dynamic memory allocation in standard C++.
- Understanding the trade-off between **time complexity** and **space complexity**.
- Recognizing why Merge Sort provides predictable `O(N log N)` performance.
- Understanding algorithm stability and why it matters.

---

## 13. Conclusion

Merge Sort is an efficient and predictable comparison-based sorting algorithm with a guaranteed **`O(N log N)` time complexity**.

Its primary drawback is the additional **`O(N)` auxiliary space** required by the standard array-based implementation.

Overall, Merge Sort is an excellent example of the **Divide and Conquer** paradigm and provides a useful contrast to algorithms such as Quick Sort, which typically uses less auxiliary memory but does not guarantee `O(N log N)` worst-case performance.
