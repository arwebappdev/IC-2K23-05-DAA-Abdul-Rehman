# Quick Sort

An efficient **in-place sorting algorithm** based on the **Divide and Conquer** paradigm. Quick Sort is known for its excellent average-case performance and low auxiliary memory requirements.

## 1. Problem Statement

Sort an unsorted array of integers efficiently **in-place**, minimizing the need for auxiliary memory while maintaining high performance for large datasets.

---

## 2. Algorithm / Approach

Quick Sort is a highly efficient **Divide and Conquer** algorithm.

Unlike Merge Sort, which divides the array into halves regardless of the values, Quick Sort divides the array based on a selected **pivot**.

The algorithm works in three main steps:

1. **Pivot Selection** — Select an element as the pivot. In this implementation, the **last element** is selected.
2. **Partitioning** — Rearrange the array so that elements smaller than or equal to the pivot appear before it, while larger elements appear after it. The pivot is then placed in its final sorted position.
3. **Recursion** — Recursively apply the same process to the sub-arrays on the left and right of the pivot.

### High-Level Flow

```text id="4f8r2p"
Unsorted Array
      │
      ▼
 Select a Pivot
      │
      ▼
   Partition
   /       \
  ▼         ▼
Left       Right
Sub-array  Sub-array
  │         │
  └────┬────┘
       ▼
    Recursively
     Sort Both
       │
       ▼
 Sorted Array
```

---

## 3. Pseudocode

### Quick Sort

```text id="5w0jzq"
function quickSort(arr, low, high):
    if low < high:
        pi = partition(arr, low, high)

        quickSort(arr, low, pi - 1)
        quickSort(arr, pi + 1, high)
```

### Partition

```text id="c4m2xz"
function partition(arr, low, high):
    pivot = arr[high]
    i = low - 1

    for j = low to high - 1:
        if arr[j] <= pivot:
            i = i + 1
            swap arr[i] and arr[j]

    swap arr[i + 1] and arr[high]

    return i + 1
```

---

## 4. Time & Space Complexity

| Metric                          |   Complexity | Explanation                                                                                                                                               |
| ------------------------------- | -----------: | --------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **Best Case Time**              | `O(N log N)` | The pivot consistently divides the array into two nearly equal partitions.                                                                                |
| **Average Case Time**           | `O(N log N)` | With reasonably balanced partitions, Quick Sort performs efficiently on average.                                                                          |
| **Worst Case Time**             |      `O(N²)` | Occurs when the pivot repeatedly produces highly unbalanced partitions, such as when sorting an already sorted array using the last element as the pivot. |
| **Average Space Complexity**    |   `O(log N)` | The recursive call stack requires logarithmic space when partitions are reasonably balanced.                                                              |
| **Worst Case Space Complexity** |       `O(N)` | Highly unbalanced partitions can produce recursion depth of `N`.                                                                                          |

> **Note:** Quick Sort is considered an **in-place sorting algorithm** because the partitioning is performed directly within the original array and does not require an auxiliary array proportional to `N`.

---

## 5. Pivot Selection

This implementation always chooses the **last element** as the pivot:

```cpp id="m9p6nk"
pivot = arr[high];
```

This approach is simple to implement, but it has an important drawback.

For an already sorted array:

```text id="n6c2ra"
[10, 20, 30, 40, 50, 60, 70]
```

the last element is always the largest element. This produces extremely unbalanced partitions:

```text id="z5d8qp"
[10, 20, 30, 40, 50, 60] [70]
[10, 20, 30, 40, 50]     [60]
[10, 20, 30, 40]         [50]
[10, 20, 30]             [40]
...
```

As a result, the time complexity degrades to:

```text id="8v3h1q"
O(N²)
```

Randomized pivot selection, median-of-three selection, or other partition strategies can reduce the likelihood of encountering this worst-case behavior.

---

## 6. Sample Input / Output

### Input

```text id="w7r4cy"
[10, 80, 30, 90, 40, 50, 70]
```

### Output

```text id="b1m9sd"
[10, 30, 40, 50, 70, 80, 90]
```

---

## 7. Partitioning Visualization

For the input:

```text id="9n2j7x"
[10, 80, 30, 90, 40, 50, 70]
```

the pivot is the last element:

```text
Pivot = 70
```

The partitioning process can be visualized as follows:

```text id="q2k5mf"
Initial:
[10, 80, 30, 90, 40, 50, 70]
                                   ↑
                                 Pivot

10 <= 70
[10, 80, 30, 90, 40, 50, 70]

30 <= 70
[10, 30, 80, 90, 40, 50, 70]

40 <= 70
[10, 30, 40, 90, 80, 50, 70]

50 <= 70
[10, 30, 40, 50, 80, 90, 70]

Place pivot 70 in its final position:
[10, 30, 40, 50, 70, 90, 80]
                     ↑
                   Pivot
```

The pivot `70` is now in its correct sorted position. Quick Sort then recursively processes:

```text
Left partition:
[10, 30, 40, 50]

Right partition:
[90, 80]
```

---

## 8. Screenshots / Graphs

Add a screenshot of the VS Code terminal showing the successful compilation and execution of `quickSort.cpp`.

For example:

```text id="d4x7pv"
$ g++ quickSort.cpp -o quickSort
$ ./quickSort

Original Array:
10 80 30 90 40 50 70

Sorted Array:
10 30 40 50 70 80 90
```

---

## 9. Experimental Results

Quick Sort is often very efficient in practice because its partitioning operates directly on the input array and typically has good **CPU cache locality**.

However, performance depends heavily on **pivot selection**.

With the last-element pivot strategy used in this implementation, already sorted or reverse-sorted arrays can result in highly unbalanced partitions and cause the algorithm to degrade to `O(N²)` time.

For randomized or reasonably distributed data, Quick Sort typically achieves `O(N log N)` average-case performance and can outperform Merge Sort in many in-memory array-sorting scenarios due to lower auxiliary memory usage and favorable cache behavior.

Therefore, Quick Sort is not universally "faster" than Merge Sort; its practical performance depends on implementation details, input characteristics, pivot strategy, and hardware.

---

## 10. Advantages

- Average-case time complexity of `O(N log N)`.
- Requires very little auxiliary memory.
- Performs partitioning directly within the original array.
- Excellent cache locality in typical implementations.
- Often performs very well for in-memory array sorting.
- Can be optimized with randomized or median-based pivot selection.

---

## 11. Disadvantages

- Worst-case time complexity is `O(N²)`.
- Worst-case recursion depth can reach `O(N)`.
- The basic implementation is **not stable**.
- Performance can depend heavily on pivot selection.
- Choosing a poor pivot repeatedly can result in highly unbalanced partitions.

---

## 12. Quick Sort vs. Merge Sort

| Feature                    | Quick Sort     | Merge Sort      |
| -------------------------- | -------------- | --------------- |
| **Best Case**              | `O(N log N)`   | `O(N log N)`    |
| **Average Case**           | `O(N log N)`   | `O(N log N)`    |
| **Worst Case**             | `O(N²)`        | `O(N log N)`    |
| **Average Space**          | `O(log N)`     | `O(N)`          |
| **In-Place**               | Yes            | Typically no    |
| **Stable**                 | No             | Yes             |
| **Cache Locality**         | Generally good | Generally lower |
| **Pivot Required**         | Yes            | No              |
| **Predictable Worst Case** | No             | Yes             |

### Key Trade-off

**Quick Sort** generally uses less auxiliary memory and can be faster in practice for in-memory arrays.

**Merge Sort** provides more predictable performance and guarantees `O(N log N)` even in the worst case, but requires additional memory for the standard array implementation.

---

## 13. Learning Outcomes

By implementing Quick Sort, the following concepts are demonstrated:

- Understanding the **Divide and Conquer** algorithmic strategy.
- Implementing an **in-place sorting algorithm**.
- Understanding pivot selection and partitioning.
- Using recursion to sort sub-arrays.
- Analyzing best-case, average-case, and worst-case performance.
- Understanding how input characteristics can affect algorithm performance.
- Recognizing the trade-off between **execution speed and memory usage**.
- Understanding why pivot selection is important for practical Quick Sort performance.

---

## 14. Conclusion

Quick Sort is a powerful and memory-efficient comparison-based sorting algorithm.

Its average-case time complexity of **`O(N log N)`** and low auxiliary memory requirements make it particularly effective for in-memory array sorting.

However, the choice of pivot is critical. With the **last-element pivot** implementation used here, already sorted or reverse-sorted data can cause the algorithm to degrade to **`O(N²)`**.

Overall, Quick Sort provides an excellent contrast to Merge Sort:

> **Quick Sort:** Less auxiliary memory and excellent average performance, but no guaranteed `O(N log N)` worst case.

> **Merge Sort:** Predictable `O(N log N)` performance and stability, but requires `O(N)` auxiliary space for typical array implementations.
