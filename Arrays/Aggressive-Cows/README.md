#  Aggressive Cows: Optimization via Binary Search on Answer

##  Problem Statement
Given an array of stall coordinates `arr[n]`, the objective is to assign $C$ aggressive cows to these stalls such that the **minimum separation distance** between any two cows is **maximized**. This is a classic "Maximize the Minimum" optimization problem.

---

##  Technical Architecture & Search Space

To avoid the exponential complexity of a combinatorial approach, we utilize **Binary Search on the Answer Space**. 

### 1. Monotonic Search Space
- **Lower Bound (`st`)**: $1$ (Minimum possible discrete unit).
- **Upper Bound (`end`)**: `arr[n-1] - arr[0]` (The total span of sorted coordinates).
- **Inference**: The feasibility of cow placement is monotonic; if we can place cows at distance $d$, we can certainly place them at any distance $< d$. This allows for an efficient $O(n \log(\text{Range}))$ search.



---

## 🛠️ Implementation Strategy

### A. The Greedy Predicate: `isPossible(arr, n, C, minAllowedDist)`
This $O(n)$ function validates the feasibility of a candidate distance:
1. **Deterministic Start**: Place the first cow at the first sorted stall `arr[0]` to conserve space.
2. **Greedy Placement**: Iterate through subsequent stalls and place a cow only if the gap from the `lastStallpos` is $\ge$ `minAllowedDist`.
3. **Early Exit**: Returns `true` immediately if the count of placed cows reaches $C$.

### B. Execution Flow
- **Pre-processing**: The input `vector<int> arr` is sorted using `std::sort`.
- **Optimization Strategy**: 
  - If `isPossible` returns **True**: Store `ans = mid` and search the **Right** half (`st = mid + 1`) to attempt a larger gap.
  - If `isPossible` returns **False**: Search the **Left** half (`end = mid - 1`) to find a feasible smaller gap.

---

##  Robustness & Performance Analysis

### 1. Edge Case Management
- **Infeasible Configuration**: An explicit guard `if (C > n) return -1;` ensures the program handles cases where cows outnumber stalls gracefully.
- **Academic Precision**: The use of `int` data type is sufficient under the given problem constraints to handle coordinate ranges without overflow.

### 2. Computational Complexity
- **Time Complexity**: 
  - $O(n \log n + n \log(\text{range}))$
  - $\approx O(n \log n)$ 
  - *(Note: Sorting is the primary bottleneck in most practical scenarios).*
- **Space Complexity**: $O(1)$ auxiliary space usage.

---

##  Variable Reference Table (Code-Matched)

| Variable | Definition | Data Type |
| :--- | :--- | :--- |
| `arr` | Coordinate vector of stalls | `vector<int>` |
| `n` | Count of available stalls | `int` |
| `C` | Required count of cows | `int` |
| `mid` | Candidate minimum distance (`minAllowedDist`) | `int` |
| `ans` | Resultant maximized minimum distance | `int` |
