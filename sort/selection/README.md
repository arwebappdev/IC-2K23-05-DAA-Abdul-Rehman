# Selection Sort

An **in-place comparison-based sorting algorithm** that repeatedly searches for the minimum element in the unsorted portion of an array and places it in its correct position.

## 1. Problem Statement

Sort an unsorted array of integers **in-place** by repeatedly finding the smallest element from the unsorted portion of the array and moving it to its correct position.

---

## 2. Algorithm / Approach

Selection Sort maintains two logical portions within the same array:

1. **Sorted portion** — Elements that have already been placed in their final positions.
2. **Unsorted portion** — Elements that still need to be processed.

During each iteration:

1. Assume the first element of the unsorted portion is the minimum.
2. Scan the remaining unsorted elements to find the actual minimum.
3. Swap the minimum element with the first element of the unsorted portion.
4. Expand the sorted portion by one element.
5. Repeat until the entire array is sorted.

### High-Level Flow

```text id="8y4m2k"
Unsorted Array
      │
      ▼
Find Minimum
      │
      ▼
Swap with First
Unsorted Element
      │
      ▼
Expand Sorted Portion
      │
      ▼
Repeat Until Sorted
```

---

## 3. Pseudocode

```text id="m6j3pt"
function selectionSort(arr, size):
    for i from 0 to size - 2:
        minIndex = i

        for j from i + 1 to size - 1:
            if arr[j] < arr[minIndex]:
                minIndex = j

        if minIndex != i:
            swap arr[i] with arr[minIndex]
```

---

## 4. Time & Space Complexity

| Metric                | Complexity | Explanation                                                                                                   |
| --------------------- | ---------: | ------------------------------------------------------------------------------------------------------------- |
| **Best Case Time**    |    `O(N²)` | Even when the array is already sorted, Selection Sort still scans the remaining elements to find the minimum. |
| **Average Case Time** |    `O(N²)` | Each position requires scanning the remaining unsorted portion.                                               |
| **Worst Case Time**   |    `O(N²)` | The number of comparisons is essentially independent of the input order.                                      |
| **Space Complexity**  |     `O(1)` | Selection Sort operates directly on the input array and requires only a constant amount of auxiliary memory.  |

### Number of Comparisons

Selection Sort performs approximately:

```text id="r7q1vx"
(N - 1) + (N - 2) + ... + 2 + 1
```

comparisons.

This gives:

```text id="k5n8dz"
N(N - 1) / 2
```

comparisons, which results in:

```text id="c2w9hf"
O(N²)
```

time complexity.

---

## 5. Sample Input / Output

### Input

```text id="p3x6az"
[64, 25, 12, 22, 11]
```

### Output

```text id="j8m4qy"
[11, 12, 22, 25, 64]
```

---

## 6. Step-by-Step Visualization

Starting with:

```text id="n4b7ws"
[64, 25, 12, 22, 11]
```

### Step 1

Find the minimum element in the entire array.

```text id="z2k9mp"
Minimum = 11

Swap 11 and 64

[11, 25, 12, 22, 64]
 ↑
Sorted
```

### Step 2

Find the minimum element in the remaining unsorted portion:

```text id="v6q3ht"
Minimum = 12

Swap 12 and 25

[11, 12, 25, 22, 64]
     ↑
   Sorted
```

### Step 3

Find the minimum element in the remaining portion:

```text id="x8r5kc"
Minimum = 22

Swap 22 and 25

[11, 12, 22, 25, 64]
         ↑
       Sorted
```

### Step 4

The remaining minimum is already in its correct position:

```text id="s1m7dp"
Minimum = 25

No swap required.

[11, 12, 22, 25, 64]
```

The array is now completely sorted.

### Complete Visualization

```text id="h4q9bx"
Initial:
[64, 25, 12, 22, 11]

        ↓ Find minimum (11)

[11, 25, 12, 22, 64]
 ↑
Sorted

        ↓ Find minimum (12)

[11, 12, 25, 22, 64]
     ↑
   Sorted

        ↓ Find minimum (22)

[11, 12, 22, 25, 64]
         ↑
       Sorted

        ↓ Remaining element already sorted

[11, 12, 22, 25, 64]
```

---

## 7. Screenshots / Graphs

Add a screenshot of the VS Code terminal showing the successful compilation and execution of `selectionSort.cpp`.

For example:

```text id="f7p2mv"
$ g++ selectionSort.cpp -o selectionSort
$ ./selectionSort

Original Array:
64 25 12 22 11

Sorted Array:
11 12 22 25 64
```

---

## 8. Experimental Results

Selection Sort has an `O(N²)` time complexity regardless of whether the input is sorted, reverse-sorted, or randomly ordered.

At first, this may make Selection Sort seem inferior to more advanced algorithms such as Merge Sort and Quick Sort. However, Selection Sort has an important practical characteristic: **it performs very few swaps**.

For an array of `N` elements, Selection Sort performs at most `N - 1` swaps.

This is significantly fewer memory writes than many other comparison-based sorting algorithms.

### Comparisons vs. Writes

| Operation           | Selection Sort |
| ------------------- | -------------: |
| **Comparisons**     |        `O(N²)` |
| **Swaps**           |         `O(N)` |
| **Auxiliary Space** |         `O(1)` |

This makes Selection Sort useful in situations where **writing to memory is significantly more expensive than reading or comparing values**.

For example, systems involving certain types of non-volatile memory may benefit from minimizing the number of writes.

For general-purpose sorting of large datasets, however, the `O(N²)` running time makes Selection Sort much less suitable than algorithms such as Merge Sort or Quick Sort.

---

## 9. Advantages

- Simple and easy to understand.
- Requires only `O(1)` auxiliary space.
- Performs sorting directly within the original array.
- Performs at most `N - 1` swaps.
- Useful when memory writes are significantly more expensive than comparisons.
- Has predictable `O(N²)` performance regardless of input ordering.

---

## 10. Disadvantages

- `O(N²)` time complexity in the best, average, and worst cases.
- Inefficient for large datasets.
- Performs many comparisons even when the array is already sorted.
- Generally slower than `O(N log N)` sorting algorithms for large inputs.
- The standard implementation is **not stable**.

---

## 11. Stability

The standard Selection Sort implementation is **not stable**.

A sorting algorithm is stable if equal-valued elements maintain their original relative order after sorting.

Selection Sort can move an element across other equal-valued elements when performing a swap, which can change their relative ordering.

A stable variant can be implemented by shifting elements instead of swapping, but this increases the number of element writes.

---

## 12. Selection Sort vs. Other Sorting Algorithms

| Feature                    | Selection Sort | Insertion Sort   | Quick Sort         | Merge Sort   |
| -------------------------- | -------------- | ---------------- | ------------------ | ------------ |
| **Best Case**              | `O(N²)`        | `O(N)`           | `O(N log N)`       | `O(N log N)` |
| **Average Case**           | `O(N²)`        | `O(N²)`          | `O(N log N)`       | `O(N log N)` |
| **Worst Case**             | `O(N²)`        | `O(N²)`          | `O(N²)`            | `O(N log N)` |
| **Auxiliary Space**        | `O(1)`         | `O(1)`           | `O(log N)` average | `O(N)`       |
| **In-Place**               | Yes            | Yes              | Yes                | Typically no |
| **Stable**                 | No             | Yes              | No                 | Yes          |
| **Number of Swaps/Writes** | Very Low       | Potentially High | Moderate           | Higher       |

---

## 13. Learning Outcomes

By implementing Selection Sort, the following concepts are demonstrated:

- Understanding how to maintain **sorted and unsorted boundaries** within an array.
- Finding the minimum element within a restricted portion of an array.
- Implementing an **in-place sorting algorithm**.
- Understanding the difference between **comparisons** and **memory writes**.
- Analyzing an algorithm whose running time is independent of the initial ordering of the data.
- Understanding the trade-off between algorithm simplicity, runtime, and memory usage.
- Recognizing situations where minimizing swaps can be more important than minimizing comparisons.

---

## 14. Conclusion

Selection Sort is one of the simplest comparison-based sorting algorithms. It repeatedly finds the minimum element from the unsorted portion of the array and places it at the beginning of that portion.

Although its `O(N²)` time complexity makes it unsuitable for large datasets, it has a useful characteristic: **a very small number of swaps**.

Therefore:

> **Selection Sort:** Simple, in-place, and minimizes swaps, but performs `O(N²)` comparisons.

It provides an excellent introduction to sorting algorithms and helps demonstrate why algorithm performance should be evaluated using more than just overall time complexity.
