# 🌊 Container With Most Water

## 📌 Problem Description
Given `n` non-negative integers representing an elevation map, find two lines that form a container such that it contains the most water.

## 💡 Intuition & Strategy
We utilize the **Two-Pointer Technique** to achieve an optimal solution. 
- **Initial State:** Two pointers at the extreme ends ($i=0, j=n-1$).
- **Complexity:** $O(n)$ Time | $O(1)$ Space.

## 🧠 Why Move the Shorter Line? (Logical Proof)
The area of the container is **constrained** by the shorter line: 
$$Area = \min(h_i, h_j) \times (j - i)$$

1. **Moving the Longer Line:** If we move the pointer of the longer line, the width $(j-i)$ decreases. Since the height is still limited by the original shorter line, the area can **only decrease**.
2. **Moving the Shorter Line:** If we move the shorter line's pointer, the width still decreases, but there is a **possibility** of finding a significantly taller line that could **compensate** for the lost width and increase the total area.



## 📊 Complexity Analysis
- **Time Complexity:** $O(n)$ - Each element is visited at most once.
- **Space Complexity:** $O(1)$ - No auxiliary data structures used.

## 🚀 Implementation
The solution is implemented in C++ and can be found in `Solution.cpp`.
