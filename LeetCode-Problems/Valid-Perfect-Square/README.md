# Valid Perfect Square (LeetCode #367)

##  Title
**High-Performance Binary Search Solution for Perfect Square Verification**

##  Intuition
The problem of determining if a number is a perfect square is essentially a search operation within a **Monotonic Search Space** $[0, n]$. To bypass the inefficiency of a Linear Search $O(N)$, we implement a **Binary Search** $O(\log N)$. By strategically limiting the search boundary to $n/2$, we significantly **Prune** the search space, ensuring peak computational efficiency.

##  Algorithm (Technical Deep-Dive)

1. **Edge Case Mitigation (Guard Clauses):**
   - The algorithm initiates with `if (num == 0 || num == 1) return true;`. 
   - **Reasoning:** This is a critical architectural decision. Without this guard clause, the optimized range $[0, n/2]$ would become mathematically invalid for $n=1$ (since $1/2 = 0$ in integer division). This ensures the **Technical Integrity** of the optimization for all subsequent calculations.

2. **Search Space Optimization:**
   - For all $n > 1$, the search range is constrained to $[0, n/2]$. This effectively reduces the search volume by 50%, providing a streamlined path for the binary search pointers.

3. **Overflow Handling & Mitigation:**
   - We utilize `long long` for both `mid` and `square` variables. This is a mandatory safety measure to prevent **Integer Overflow** when dealing with large inputs approaching `INT_MAX` (e.g., $n = 2147395600$).

4. **Binary Search Execution:**
   - **Early Exit Strategy:** The moment `square == num` is satisfied, the function terminates with `true`, saving unnecessary CPU cycles.
   - **Pointer Convergence:** Utilizing standard binary search mechanics (`st = mid + 1` and `end = mid - 1`) to converge on the result with logarithmic time complexity.

## 📊 Complexity Analysis
- **Time Complexity:** $O(\log N)$ - Achieved through consistent halving of the search space.
- **Space Complexity:** $O(1)$ - Constant space usage with zero auxiliary data structure overhead.

## 🧪 Comprehensive Validation Trace
| Input ($n$) | Execution Path | Mathematical Root | Final Result |
| :--- | :--- | :--- | :--- |
| **0** | Guard Clause | 0 | `true` |
| **1** | Guard Clause | 1 | `true` |
| **16** | Range $[0, 8]$, Converged at mid=4 | 4 | `true` |
| **14** | Range $[0, 7]$, Exhausted | None | `false` |
| **2147395600**| Overflow-safe Search, mid=46340 | 46340 | `true` |

## 🚀 LeetCode Performance Metrics
- **Runtime:** 0 ms (Achieved excellent runtime performance on LeetCode)
- **Memory Usage:** 7.70 MB (Optimized stack allocation)
