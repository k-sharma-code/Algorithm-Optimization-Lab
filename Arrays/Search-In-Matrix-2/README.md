#  Search in a Row-Column Sorted Matrix

##  Problem Statement
Given a 2D matrix where each row and column is sorted in ascending order, find the coordinates $(row, col)$ of a target element. 
**Note:** The first element of a row is NOT necessarily greater than the last element of the previous row.

---

##  Intuition
Since both rows and columns are sorted, we can treat the matrix as a "Staircase." By starting at the top-right corner, we can eliminate either a row or a column in each step.
- **Goal:** Achieve $O(m + n)$ time complexity without flattening the matrix.

---

##  Algorithm

### Staircase Search Strategy
1.  **Safety Check:** If matrix is empty or has no columns, return `{-1, -1}`.
2.  **Initialization:** Start at `row = 0` and `col = mat[0].size() - 1` (Top-Right).
3.  **Traverse:**
    - If `mat[row][col] == target`: Return current coordinates.
    - If `mat[row][col] > target`: Move **Left** (`col--`) because all elements below are even larger.
    - If `mat[row][col] < target`: Move **Down** (`row++`) because all elements to the left are even smaller.
4.  **Failure:** If boundaries are crossed, the target does not exist.

---

##  Complexity Analysis

- **Time Complexity:** $O(m + n)$ – In the worst case, we traverse from the top-right to the bottom-left corner.
- **Space Complexity:** $O(1)$ – Constant space efficiency as no extra data structures are used. [cite: 2026-01-22]

---

##  Example
**Input:** ```text
mat = [[1, 4, 7], 
       [2, 5, 8], 
       [3, 6, 9]], target = 5
**Output**
rows = 1 and cols = 1.```
