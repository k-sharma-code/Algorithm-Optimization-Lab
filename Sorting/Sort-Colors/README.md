#  Sort Colors: Dual-Approach Optimization

###  Project Overview
This module demonstrates the implementation of the **Sort Colors** problem  using two distinct algorithmic paradigms. The objective is to sort an array containing 0s, 1s, and 2s (Red, White, Blue) **in-place** with optimal time efficiency.

---

###  Approach 1: The Frequency Counting Method
**Source Code:** `countApproach.cpp`

**Mechanism:**
This approach utilizes a two-pass strategy. 
1. **Pass 1:** Iterate through the array to calculate the frequency of each element (0, 1, and 2).
2. **Pass 2:** Overwrite the original array using the collected counts to place 0s, 1s, and 2s in sequence.

**Technical Metrics:**
- **Time Complexity:** $O(2N) \approx O(N)$ (Requires two linear traversals).
- **Space Complexity:** $O(1)$ (**In-place**; requires only three auxiliary integer variables).

---

###  Approach 2: Dutch National Flag (DNF) Algorithm
**Source Code:** `dnfAlgorithm.cpp` 

**Mechanism:**
Developed by Edsger W. Dijkstra, this is an **optimal single-pass** algorithm that uses three pointers (`low`, `mid`, `high`) to partition the array into four functional zones.


**The 4-Region Partitioning:**
1. **[0 ... low-1]:** Guaranteed region of **0s**.
2. **[low ... mid-1]:** Guaranteed region of **1s**.
3. **[mid ... high]:** **Unsorted/Unknown** region (The "Gap").
4. **[high+1 ... n-1]:** Guaranteed region of **2s**.

**Logic Refinement:**
As the `mid` pointer advances and the `high` pointer recedes, the **Unsorted Gap** shrinks until `mid > high`, at which point the entire array is partitioned and sorted.

**Critical Implementation Note (The High-Swap Rule):**
In `dnf_algorithm.cpp`, when `arr[mid] == 2`, we swap with `arr[high]` and decrement `high`. However, we **do not** increment `mid`. This is because the element arriving from `high` is **unprocessed**; it could be a 0, 1, or 2, and must be re-evaluated in the next iteration to maintain technical integrity.

**Technical Metrics:**
- **Time Complexity:** $O(N)$ (Single-pass; superior for streaming data).
- **Space Complexity:** $O(1)$ (**In-place** manipulation).

---

### 🔬 Comparative Analysis
| Feature | Counting Method | DNF Algorithm |
| :--- | :--- | :--- |
| **Passes** | 2 Passes | 1 Pass (Optimal) |
| **Swaps** | 0 (Overwrites) | Frequent (In-place Swaps) |
| **Best Use Case** | Small, fixed range | Streaming data / Minimal memory access |

---
