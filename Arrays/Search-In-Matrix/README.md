#  Search in a 2D Matrix (Multi-Approach Optimization)

##  Problem Statement
Find the (row, column) coordinates of a target integer `target` in an $M \times N$ matrix `mat`.
**Constraints:**
1. Each row is sorted in ascending order.
2. The first element of a row is greater than the last element of the previous row (`mat[i][0] > mat[i-1][n-1]`).

---

##  Approach 1: Nested Binary Search
**File:** `searchInMatrix.cpp`

**Algorithm:**
1. **Row Selection:** Binary search on row boundaries to find `midRow` such that `mat[midRow][0] <= target <= mat[midRow][n-1]`.
2. **Column Search:** Once the row is isolated, execute a standard binary search within that row using pointer convergence.

**Complexity:** $O(\log m + \log n)$ time | $O(1)$ space.

---

##  Approach 2: Virtual Flattening (1D Mapping)
**File:** `searchMAtrixFlatten.cpp`

**Algorithm:**
1. **Safety Check:** Validate if the matrix is empty (`mat.empty()`) to prevent runtime crashes.
2. **Search Space:** Define `st = 0` and `end = (1LL * m * n) - 1`. 
   - *Note:* `1LL` ensures the product calculation is promoted to `long long`, preventing integer overflow.
3. **Coordinate Mapping:** Map 1D index `mid` to 2D indices:
   - `row = mid / n`
   - `col = mid % n`
4. **Binary Search:** Perform standard search using `mat[row][col]`.

**Complexity:** $O(\log(m \times n))$ time | $O(1)$ space.
*Note: Asymptotically equivalent to Approach 1 as $\log(m \times n) = \log m + \log n$.*

---

##  Comparative Analysis
| Feature | Nested Binary Search (`solution1.cpp`) | Virtual Flattening (`solution2.cpp`) |
| :--- | :--- | :--- |
| **Search Logic** | Two-pass (Row then Column) | Single-pass (Direct mapping) |
| **Mathematical Base** | $\log m + \log n$ | $\log(m \times n)$ |
| **Input Validation** | Standard | Includes explicit empty matrix checks |
| **Complexity** | $O(\log m + \log n)$ | $O(\log(m \times n))$ |



##  What I Learned
* **Asymptotic Equivalence:** Confirmed that different implementation styles for sorted matrices yield identical time complexity.
* **Coordinate Transformation:** Using `/` and `%` to treat 2D storage as a virtual 1D search space.
* **Edge Case Handling:** Implementing safety checks for empty matrices (`mat.empty()`) and invalid sizes to ensure production-grade robustness.
* **Overflow Prevention:** Using `1LL` to promote calculations to `long long`, avoiding "Garbage Values" in large-scale matrix computations.


