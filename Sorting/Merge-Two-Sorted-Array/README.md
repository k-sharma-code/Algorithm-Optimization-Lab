#  Merge Sorted Array (Optimal In-Place Solution)

###  Problem Context
Given two integer arrays `arr1` and `arr2`, sorted in **non-decreasing order**. The objective is to merge `arr2` into `arr1` as a single sorted sequence **in-place**.

**Key Constraints:**
- `arr1` has a total capacity of `m + n`.
- The first `m` elements are valid data; the remaining `n` elements are `0` (**buffer space**).

---

###  The "Backward Pointer" Strategy
Instead of starting from the beginning (index 0), which would necessitate $O(n)$ **auxiliary** space to avoid **overwriting** valid data, we utilize a **Three-Pointer Approach** from the **rear**.

####  Technical Justification:
- **Zero Overwriting Risk:** By filling the largest elements into the empty buffer at the end of `arr1`, we preserve the integrity of the original elements.
- **Space Optimization:** Achieves the result in **$O(1)$ Space Complexity**.



---

###  Manual Trace (Step-by-Step)
**Input:** `arr1 = [1, 2, 3, 0, 0, 0]`, `m = 3` | `arr2 = [2, 5, 6]`, `n = 3`
**Pointers:** `i = 2 (arr1[2]=3)`, `j = 2 (arr2[2]=6)`, `idx = 5`

| Step | Comparison | Action | arr1 State | Pointers |
| :--- | :--- | :--- | :--- | :--- |
| **1** | `3` vs `6` | `6 > 3`, Place `6` at `idx` | `[1, 2, 3, 0, 0, 6]` | `i:2, j:1, idx:4` |
| **2** | `3` vs `5` | `5 > 3`, Place `5` at `idx` | `[1, 2, 3, 0, 5, 6]` | `i:2, j:0, idx:3` |
| **3** | `3` vs `2` | `3 > 2`, Place `3` at `idx` | `[1, 2, 3, 3, 5, 6]` | `i:1, j:0, idx:2` |
| **4** | `2` vs `2` | `2 == 2`, Place `2` at `idx` | `[1, 2, 2, 3, 5, 6]` | `i:1, j:-1, idx:1` |
| **End** | `j < 0` | `arr2` Exhausted | **[1, 2, 2, 3, 5, 6]** | **Sorted!** |

---

###  Edge Case: Pointer Exhaustion
1. **Case `j >= 0`:** If `arr1` is exhausted first, any remaining elements in `arr2` are copied directly into the prefix of `arr1`.
2. **Case `i >= 0`:** If `arr2` is exhausted first, the remaining elements in `arr1` are already in their correct sorted positions, making any further operations **redundant**.

---

###  Complexity Analysis
| Metric | Complexity | Rationale |
| :--- | :--- | :--- |
| **Time Complexity** | $O(m + n)$ | Each element from both arrays is visited exactly once. |
| **Space Complexity** | $O(1)$ | Performed in-place; zero **auxiliary** space used. |

---
