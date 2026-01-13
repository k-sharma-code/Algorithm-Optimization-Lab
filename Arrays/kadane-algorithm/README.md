## Kadane's Algorithm (Maximum Subarray Sum)
### Introduction
This module contains the implementation of Kadane's Algorithm, a fundamental approach to solve the Maximum Subarray Sum problem. The objective is to identify the contiguous subarray with the largest sum within a given one-dimensional array.
### Logical Intuition
My implementation follows a Greedy strategy integrated with Dynamic Programming principles.
Local Optimization: At each element, the algorithm decides whether to extend the current subarray sum (cs) or start a new subarray from the current element.
Global Tracking: We maintain a global maximum (mx) to ensure the superior sum found during the traversal is preserved.
Key logic in my code:
cs += arr[i]; // cs= current sum
mx = max(cs, mx);
if(cs < 0) cs = 0; // Resetting if sum becomes negative
### Complexity Analysis
Time Complexity: O(n) — The solution is superior as it requires only a single traversal of the array, making it highly feasible for large datasets.
Space Complexity: O(1) — The algorithm maintains high integrity in memory-constrained environments by using no extra data structures.
