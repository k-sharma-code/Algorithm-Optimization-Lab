#  Optimized Search in Rotated Sorted Array

## Overview
This file  implements a high-performance solution for locating a target element within a **Rotated Sorted Array**. The algorithm prioritizes efficiency, moving away from obsolete linear methods.

##  Performance Benchmark
| **Time Complexity** | $O(n)$ | $O(\log n)$ |
| **Scalability** | Non-Scalable | **Enterprise Ready** |

**Rationale:** Linear Search is **inherently inefficient**. While it performs $O(n)$ comparisons, this Binary Search implementation achieves the same result in **Logarithmic Time** $O(\log n)$.

##  Algorithmic Architecture
The solution relies on the mathematical certainty that in any rotated sorted array, **at least one segment is always sorted**.

1. **Midpoint Calculation:** Stabilized via `mid = st + (end - st) / 2` to prevent memory overflow.
2. **Segment Identification:**
   - **Left Segment Sorted:** If `arr[st] <= arr[mid]`.
   - **Right Segment Sorted:** If the left condition is false.
3. **Range Verification:** Uses **Boolean Logic** to determine if the target resides in the sorted segment or the disrupted half.

##  Complexity Analysis
- **Time Complexity:** $O(\log n)$ — Derived from the continuous halving of the search space ($2^k = n \implies k = \log_2 n$).
- **Space Complexity:** $O(1)$ — Achieves **Constant Space** as no **Auxiliary** data structures are used.

##  Edge Cases Handled
- ✅ **Minimal Rotation:** Handles arrays like `[3, 1]`.
- ✅ **Pivot at Extremes:** Arrays like `[2, 3, 4, 5, 1]`.
- ✅ **Element Absence:** Correctly terminates and returns `-1`.
- ✅ **Single Element:** Impeccable handling of $st = end$ scenarios.
