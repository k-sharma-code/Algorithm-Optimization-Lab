#  Next Permutation (Optimal Lexicographical Strategy)

###  Problem Context
The challenge is to find the **Lexicographically Next Greater** arrangement of numbers. If the array represents the largest possible configuration (already sorted descending), we reset it to the smallest possible configuration (sorted ascending).

---

###  The "Three-Step" Observation Strategy
To achieve the result in **$O(N)$ Time** and **$O(1)$ Space**, we utilize three distinct linear phases that mirror the structure of a mathematical dictionary.

####  Phase 1: Locating the Pivot (Breakpoint)
We traverse the array from the rear (`i = n - 2`) to find the first instance where `arr[i] < arr[i + 1]`.
- **The Logic:** Up until this point, the array is in a strict **Descent** from right-to-left. This pivot is the exact location where we can create a slightly larger value by swapping.
- **Code Reference:** `for (int i = n - 2; i >= 0; i--)`

####  Phase 2: Finding the Successor
If a pivot is found, we scan the right-hand suffix again from the end (`i = n - 1`) until we find the first value **strictly greater** than our pivot element `arr[pivot]`.
- **The Logic:** We swap the pivot with its **smallest possible successor** to ensure the new permutation is the "Just Next" one, not a much larger one.
- **Code Reference:** `for (int i = n - 1; i > pivot; i--)`

####  Phase 3: Suffix Reversal
After the swap, the elements following the pivot are still in descending order. To get the lexicographically **smallest** suffix, we must transform it into ascending order.
- **The Logic:** Reversing a descending sequence is a mathematically efficient way to obtain the smallest possible arrangement for that suffix.
- **Code Reference:** `while(i <= j) { swap(arr[i++], arr[j--]); }`

---

###  Manual Trace (Step-by-Step)
**Input:** `arr = [2, 1, 5, 4, 3, 0]` | **n = 6**

| Phase | Variable State | Action Taken | Array Configuration |
| :--- | :--- | :--- | :--- |
| **1. Pivot Scan** | `i = 1` | `arr[1] (1) < arr[2] (5)`. **Pivot found at index 1.** | `[2, 1, 5, 4, 3, 0]` |
| **2. Successor Scan** | `i = 4` | `arr[4] (3) > arr[1] (1)`. **Successor found.** | `[2, 1, 5, 4, 3, 0]` |
| **3. Pivot Swap** | `swap(arr[1], arr[4])` | Swap values `1` and `3`. | `[2, 3, 5, 4, 1, 0]` |
| **4. Suffix Reverse** | `i=2, j=5` | Reverse everything from index `2` to `5`. | **[2, 3, 0, 1, 4, 5]** |

---

###  Edge Case Handling (Pointer Integrity)
1. **Already Largest:** If `pivot == -1` (e.g., `[3, 2, 1]`), the code triggers `reverse(arr.begin(), arr.end())` immediately, returning the smallest sequence `[1, 2, 3]`.
2. **Duplicated Elements:** The check `arr[i] < arr[i + 1]` ensures that sequences with duplicates are handled without creating infinite loops or redundant swaps.

---

###  Complexity Analysis
| Metric | Complexity | Rationale |
| :--- | :--- | :--- |
| **Time Complexity** | $O(N)$ | We perform at most three linear passes over the array. |
| **Space Complexity** | $O(1)$ | Swaps and reversals are performed **in-place** with no auxiliary storage. |
