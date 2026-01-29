#  Sqrt(x) - Floor Value Calculation (LeetCode #69 problem)

##  Title
**Precise Binary Search Implementation for Integer Square Root (Floor)**

##  Intuition
The objective is to find the integer square root of a non-negative integer $n$. If $n$ is not a perfect square, we must return the **Floor Value** (the largest integer whose square does not exceed $n$). Since the potential square roots lie in a sorted range $[0, n]$, **Binary Search** ($O(\log N)$) is utilized to achieve optimal performance.

##  Algorithm (Technical Deep-Dive)

1. **Rigid Edge Case Handling:**
   - The algorithm initiates with explicit guard clauses:
     - `if (n == 0) return 0;`
     - `if (n == 1) return 1;`
     - `if (n < 0) return -1;` (Invalid Input Protection)
   - **Reasoning:** These pre-emptive checks ensure mathematical correctness and allow for search space optimization without range-based errors.

2. **Search Space Pruning & Initialization:**
   - **Search Range:** We define the initial boundary as `st = 0` and `end = n/2`.
   - **Result Variable:** The variable `ans` is initialized to `-1` to track the most recent valid floor value found during iterations.
   - **Logic:** For any $n \geq 4$, the square root cannot exceed $n/2$. This **Prunes** the search space by half for larger integers.

3. **Execution & Overflow Mitigation:**
   - **Data Types:** `long long mid` and `long long square` are used to prevent **Integer Overflow** during the calculation of `mid * mid`.
   - **Workflow:**
     - Calculate `mid = st + (end - st) / 2` to avoid overflow in the index itself.
     - If `square == n`: Exact root found; return `mid` immediately.
     - If `square < n`: Current `mid` is a potential floor. Store `ans = mid` and move right (`st = mid + 1`).
     - If `square > n`: Current `mid` is too large; move left (`end = mid - 1`).

4. **Final Approximation:**
   - Once the search loop terminates, `ans` holds the maximum integer whose square is $\leq n$.

##  Complexity Analysis
- **Time Complexity:** $O(\log N)$ - Achieved through logarithmic partitioning of the search space. [cite: 2026-01-28]
- **Space Complexity:** $O(1)$ - Constant space utilization with no auxiliary structures. [cite: 2026-01-28]

##  Comprehensive Validation Trace
| Input ($n$) | Logic Path | Last `ans` Stored | Final Result |
| :--- | :--- | :--- | :--- |
| **8** | Binary Search in $[0, 4]$ | 2 | 2 |
| **14** | Binary Search in $[0, 7]$ | 3 | 3 |
| **1** | Guard Clause | N/A | 1 |
| **2147395600**| Overflow-safe Search | 46340 | 46340 |

##  LeetCode Performance
- **Runtime:** Very fast (often ~0 ms depending on platform)
- **Memory Usage:** 7.50 MB (Optimized stack usage)
-
