#  Bubble Sort (Ascending Order)

##  Executive Summary
This implementation demonstrates a **refined** version of the Bubble Sort algorithm in C++. Unlike the naive approach, this version integrates an **Adaptive Early-Exit Strategy** using a boolean flag to detect if the array is already sorted, thereby enhancing the best-case performance.

---

##  Algorithm Mechanics & Intuition
Bubble Sort operates on the principle of **consecutive comparisons** and **adjacent swaps**.
1. **The Bubble Effect:** In each pass, the largest unsorted element "bubbles up" to its correct position at the end of the array.
2. **Inner Loop Constraint:** The inner loop boundary `n - i - 1` ensures that we do not re-check elements that are already finalized in previous passes.
3. **Ascending Logic:** A swap occurs only if `arr[j] > arr[j + 1]`, ensuring a strictly increasing order.

---

##  Code Specifics 

### Key Variables:
- `bool isSwap`: A local sentinel flag initialized to `false` at the start of each outer pass. It tracks if any elements were moved.
- `bool alreadysorted`: The function's return type. It remains `true` if the entire array was processed without a single swap, indicating high **Technical Integrity** of the input data.
### Optimization:
If `isSwap` remains `false` after an entire inner loop pass, the algorithm executes a `break`, terminating early to save redundant CPU cycles.

---

##  Complexity Analysis

| Case | Time Complexity | Justification |
| :--- | :--- | :--- |
| **Worst Case** | $O(n^2)$ | Occurs when the input array is sorted in reverse order. |
| **Average Case**| $O(n^2)$ | Occurs with random distribution of elements. |
| **Best Case** | $O(n)$ | Achieved via the **isSwap flag** when the array is already sorted. |
| **Space Complexity** | $O(1)$ | An **In-place** algorithm requiring zero auxiliary memory. |

---

##  Technical Integrity Checklist
- [x] **Stability:** Maintained (Relative order of equal elements is preserved).
- [x] **Optimization:** Early-exit sentinel flag implemented.
- [x] **Memory:** Zero allocation on heap for sorting logic..
