#  Painter's Partition Mastery: Optimal Resource Allocation

##  Introduction
The **Painter's Partition Problem** is a critical optimization challenge solved using **Binary Search on the Answer Space**. The goal is to minimize the maximum time any single painter spends, ensuring that boards are allocated in a contiguous manner.

##  Strategic Technical Logic

### 1. Determining the Search Boundaries
Instead of searching indices, we search the possible time range $[st, end]$:
* **Lower Bound (`st`):** `maxVal` (Initialized to `INT_MIN` then updated via loop).
    * *Justification:* A painter must be able to paint at least the longest board. If the limit is below `maxVal`, the longest board cannot be assigned.
* **Upper Bound (`end`):** `sum` (Cumulative total of all board lengths).
    * *Justification:* The total time required if only one painter is available to paint all boards.

### 2. Feasibility Logic (`isPossible` function)
We use a **Greedy Check** to determine if a specific `maxAllowedTime` is valid:
* **Variable `time`:** Tracks the current accumulated board length for a painter.
* **Variable `painters`:** Tracks the number of painters utilized.
* **Transition:** If `time + arr[i] > maxAllowedTime`, we assign a new painter and reset `time = arr[i]`.
* **Validity:** If `painters <= m`, the configuration is feasible.

##  Edge Case Handling & Constraints
* **Painter Surplus (`m > n`):** * *Logic:* `if (m > n) return -1;`.
    * *Assumption:* This implementation strictly follows the rule that each painter must be assigned **at least one board** .
* **Data Limits:**
    * The implementation utilizes `int` for all variables.
    * **Precondition:** It is assumed that the total sum of boards fits within the signed 32-bit integer range ($2^{31}-1$).

##  Complexity Analysis
* **Time Complexity:** $O(N \cdot \log(\text{sum of lengths}))$.
* **Space Complexity:** $O(1)$ — Constant space usage.

##  Structural Isomorphism
This problem is **Isomorphic** to the **Book Allocation Problem**. The algorithm implemented here for painters and boards follows the exact same logical flow as students and books.

