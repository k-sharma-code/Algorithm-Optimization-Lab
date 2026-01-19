#  Peak Index in Mountain Array: Algorithmic Optimization

##  Description
This repository demonstrates a **Highly Optimized** solution to identify the **Apex** (Peak Index) in a unimodal or "Mountain" array structure. Leveraging the **Binary Search Paradigm**, the implementation ensures maximum efficiency for large-scale data processing.

---

##  Performance Metrics
| **Time Complexity** | $O(n)$ | **$O(\log n)$** |
| **Space Complexity** | $O(1)$ | **$O(1)$** |
---

##  Implementation Strategy

### 1. **Boundary Constraint Protocol**
To maintain **Architectural Integrity**, the search space is strictly restricted:
* **Initialization:** `st = 1` and `end = n - 2`.
* **Logic:** A valid mountain array requires at least 3 elements; therefore, the peak can never reside at the **Extremities** (indices $0$ or $n-1$). This also prevents **Index-Out-of-Bounds** errors when evaluating neighbors.

### 2. **Slope Convergence Logic**
The algorithm identifies the peak by evaluating the local slope at each $mid$ point:

* **Peak Condition:** If $arr[mid-1] < arr[mid] > arr[mid+1]$, then $mid$ is the **Apex**.

* **Search Space Reduction:**
  - **Incline Segment:** If $arr[mid] > arr[mid-1]$, the peak lies to the right; shift $st = mid + 1$.
  - **Decline Segment:** Otherwise, the peak lies to the left; shift $end = mid - 1$.

---

##  Edge Cases Handled
*  **Minimal Unimodal Arrays:** Fully functional for arrays with exactly 3 elements.
*  **Memory Safety:** Implements overflow-safe midpoint calculation:  
  $mid = st + \frac{end - st}{2}$
*  **Robust Initialization:** Handles vector size $n$ with **Technical Rigor**.
