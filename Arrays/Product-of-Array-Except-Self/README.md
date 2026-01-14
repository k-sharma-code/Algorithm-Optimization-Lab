# Product of Array Except Self - Optimized Solution (C++)

##  Introduction
 "Product of Array Except Self" problem. The objective is to return an array such that each element at index `i` is the product of all the numbers in the original array except the one at `i`.

The solution is implemented with an **optimal time and space complexity**, adhering to strict constraints often required in high-stakes interviews (like MEXT or Top Tech companies), specifically avoiding the use of the division operator.

---

##  Algorithmic Approach: Two-Pass Optimization
Instead of using a naive $O(n^2)$ approach or using extra $O(n)$ space for prefix/suffix arrays, this implementation utilizes a **Two-Pass In-place** strategy:

1. **Prefix Pass:** We traverse the array from left to right, storing the running product of all elements to the left of the current index directly in the result array.
2. **Suffix Pass:** We traverse the array from right to left using a single `suffix` variable. We multiply the existing prefix values in the result array by this running suffix product.

### Complexity Analysis
- **Time Complexity:** $O(n)$ — We traverse the array exactly twice.
- **Space Complexity:** $O(1)$ — Beyond the output array (which is required), we use only a single integer variable for the suffix product.

---

##  Code Features
- **Zero Division:** Does not use the `/` operator, making it robust for arrays containing zeros.
- **Memory Efficient:** Uses the output array to store intermediate results, minimizing memory footprint.

---

## Edge Cases Handled
- **Single Zero:** If the array contains one zero (e.g., `[1, 2, 0, 4]`), the result will correctly show non-zero only at the index of the zero.
- **Multiple Zeros:** If the array contains more than one zero, the entire result array correctly becomes zero.
- **Negative Numbers:** Handles negative integers seamlessly.
  
