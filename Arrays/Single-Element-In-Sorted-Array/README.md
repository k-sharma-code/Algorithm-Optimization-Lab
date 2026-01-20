# Single Element in a Sorted Array: A Binary Search Approach

##  Problem Axioms & Assumptions
To ensure the mathematical validity of the search space, the following conditions are assumed:
1. **Strictly Sorted:** The input array is sorted in non-decreasing order.
2. **Frequency Invariant:** Exactly one element appears once; all other elements appear exactly twice.
3. **Array Parity:** Due to the (n-1) paired elements and one unique element, the array size ($n$) is always odd ($n = 2k + 1$).

##  Theoretical Correctness Argument
The algorithm leverages the **Index-Pair Parity** property:
- **Before the Unique Element:** Pairs occupy indices in the pattern `(Even, Odd)`. For any pair starting at index `i`, `arr[i] == arr[i+1]` where `i` is even.
- **After the Unique Element:** The insertion of the single element shifts the entire sequence, causing pairs to occupy the pattern `(Odd, Even)`.
- **Conclusion:** Any violation of the `(Even, Odd)` parity rule guarantees that the single element resides on the left side of the current midpoint; otherwise, it lies on the right.

## ⚙️ Optimized Binary Search Implementation
We utilize a modified Binary Search to achieve $O(\log n)$ time complexity while maintaining $O(1)$ auxiliary space.

### Core Decision Logic (Excerpt)
```cpp
// Explicit boundary protection and parity-based partitioning
while (st <= end) {
    int mid = st + (end - st) / 2;

    // 1. Boundary Case: Single element at extremes
    if (mid == 0 && arr[0] != arr[1]) return arr[mid];
    if (mid == n - 1 && arr[n - 1] != arr[n - 2]) return arr[mid];

    // 2. Base Case: Unique element identified
    if (arr[mid - 1] != arr[mid] && arr[mid] != arr[mid + 1]) return arr[mid];

    // 3. Parity-Based Search Space Reduction
    if (mid % 2 == 0) { // Even Index
        if (arr[mid] == arr[mid + 1]) st = mid + 1; // Correct parity: search right
        else end = mid - 1; // Violated parity: search left
    } else { // Odd Index
        if (arr[mid] == arr[mid - 1]) st = mid + 1; // Correct parity: search right
        else end = mid - 1; // Violated parity: search left
    }
}
