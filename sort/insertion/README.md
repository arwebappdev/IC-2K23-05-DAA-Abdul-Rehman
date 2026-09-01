# Insertion Sort

## 1. Problem Statement

Sort an unsorted array of integers by building a sorted portion of the array one element at a time. Each new element is inserted into its correct position within the already sorted portion of the array.

---

## 2. Algorithm / Approach

Insertion Sort works similarly to sorting playing cards in your hand.

### Steps

1. Assume the first element is already sorted.
2. Select the next element as the `key`.
3. Compare the `key` with the elements in the sorted portion.
4. Shift all elements larger than the `key` one position to the right.
5. Insert the `key` into its correct position.
6. Repeat until the entire array is sorted.

### Example

For the array:

```text
[12, 11, 13, 5, 6]
```

The algorithm gradually builds the sorted portion:

```text
[12, 11, 13, 5, 6]
 ↓
[11, 12, 13, 5, 6]
 ↓
[11, 12, 13, 5, 6]
 ↓
[5, 11, 12, 13, 6]
 ↓
[5, 6, 11, 12, 13]
```

---

## 3. Pseudocode

```text
function insertionSort(arr, size):
    for i from 1 to size - 1:
        key = arr[i]
        j = i - 1

        while j >= 0 and arr[j] > key:
            arr[j + 1] = arr[j]
            j = j - 1

        arr[j + 1] = key
```

---

## 4. Time & Space Complexity Analysis

| Case                 | Time Complexity | Explanation                                                                                                       |
| -------------------- | --------------: | ----------------------------------------------------------------------------------------------------------------- |
| **Best Case**        |        **O(N)** | Occurs when the array is already sorted. The `while` loop fails immediately for each element.                     |
| **Average Case**     |       **O(N²)** | Elements are randomly distributed, so shifting is required for some elements on each pass.                        |
| **Worst Case**       |       **O(N²)** | Occurs when the array is in reverse order. Every new element must be shifted past all previously sorted elements. |
| **Space Complexity** |        **O(1)** | In-place algorithm requiring only a few extra variables such as `key`, `i`, and `j`.                              |

### Complexity Summary

```text
Best Case:     O(N)
Average Case:  O(N²)
Worst Case:    O(N²)
Space:         O(1)
```

---

## 5. Sample Input / Output

### Input

```text
[12, 11, 13, 5, 6]
```

### Output

```text
[5, 6, 11, 12, 13]
```

---

## 6. Step-by-Step Visualization

### Initial Array

```text
[12, 11, 13, 5, 6]
```

### Pass 1 — `key = 11`

`11` is smaller than `12`, so `12` is shifted one position to the right.

```text
[11, 12, 13, 5, 6]
```

### Pass 2 — `key = 13`

`13` is greater than `12`, so no shifting is required.

```text
[11, 12, 13, 5, 6]
```

### Pass 3 — `key = 5`

`5` is smaller than `13`, `12`, and `11`.

All three elements are shifted to the right, and `5` is inserted at the beginning.

```text
[5, 11, 12, 13, 6]
```

### Pass 4 — `key = 6`

`6` is smaller than `13`, `12`, and `11`, but greater than `5`.

The elements `13`, `12`, and `11` are shifted right.

```text
[5, 6, 11, 12, 13]
```

### Final Sorted Array

```text
[5, 6, 11, 12, 13]
```

---

## 7. Experimental Results

Although Insertion Sort has an **O(N²)** average and worst-case time complexity, it can perform very well on small or nearly sorted datasets.

The algorithm terminates its inner loop as soon as the correct position for the current element is found. Therefore, when the input is already sorted or nearly sorted, very little shifting is required.

Insertion Sort is particularly useful for:

- Small datasets.
- Nearly sorted arrays.
- Situations where simplicity and low memory usage are important.
- As a building block inside more advanced sorting algorithms.

For example, practical sorting implementations may use insertion sort for small sub-arrays because its low overhead can make it faster than more complex algorithms on tiny inputs.

---

## 8. Learning Outcomes

After implementing Insertion Sort, the following concepts were understood:

- How to build a sorted portion of an array incrementally.
- How to insert an element into its correct position.
- How to shift array elements without overwriting data.
- Why a temporary `key` variable is required during insertion.
- How an algorithm can adapt to the existing order of the input data.
- Why an algorithm with **O(N²)** complexity can still be efficient for small or nearly sorted datasets.
- The importance of considering constant factors and implementation overhead, not just asymptotic complexity.

---

## 9. Key Characteristics

| Property           | Insertion Sort   |
| ------------------ | ---------------- |
| **Algorithm Type** | Comparison-based |
| **Time — Best**    | O(N)             |
| **Time — Average** | O(N²)            |
| **Time — Worst**   | O(N²)            |
| **Space**          | O(1)             |
| **In-place**       | Yes              |
| **Stable**         | Yes              |
| **Adaptive**       | Yes              |

---

## 10. Conclusion

Insertion Sort is a simple, intuitive, and efficient sorting algorithm for small or nearly sorted datasets. It sorts the array in-place by repeatedly selecting an element and inserting it into the correct position within the sorted portion.

While it is not suitable for large, randomly ordered datasets because of its **O(N²)** average and worst-case complexity, its simplicity, stability, adaptiveness, and **O(1)** auxiliary space make it an important fundamental sorting algorithm.
