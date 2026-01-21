#  Power Function ($x^n$) — Binary Exponentiation (Optimized)

##  Introduction  
Calculating $x^n$ naively takes $O(n)$ time. This implementation utilizes **Binary Exponentiation (Exponentiation by Squaring)**. By leveraging mathematical properties of exponents, we reduce the computational complexity to **logarithmic time**, making it indispensable for competitive programming.

---

##  Problem Statement  
Implement a function to calculate $a^b$ where:
1. **Base `a`** is a `double` (to handle precision and large values).
2. **Exponent `b`** is an `int` (can be positive, negative, or zero).

---

## ⚙️ Assumptions & Constraints  
- **Precision:** Result is stored in a `double` to maintain accuracy for floating-point bases.
- **Negative Exponents:** Handled using the identity $x^{-n} = (1/x)^n$.
- **Overflow Prevention:** The exponent is transferred to a `long` variable (`binform`) to safely negate `INT_MIN` ($-2^{31}$), which would otherwise overflow a standard 32-bit `int`.

---

##  Core Logic & Optimization
The algorithm follows the **Divide and Conquer** principle:
- **Square the Base:** $x \rightarrow x^2 \rightarrow x^4 \rightarrow x^8 \dots$
- **Halve the Exponent:** $n \rightarrow n/2 \rightarrow n/4 \dots$

###  Strategic Early Returns (Code Specific)
To optimize performance, the implementation handles common cases immediately:
- **Exponent 0:** Returns `1.0`.
- **Base 0:** Returns `0.0`.
- **Base 1:** Returns `1.0`.
- **Base -1:** Uses **Parity Check** (`pow % 2`) to return `1.0` (even) or `-1.0` (odd).

---

##  Implementation Workflow
1. **Normalization:** If `pow < 0`, we invert the base (`base = 1/base`) and convert the exponent to positive.
2. **Iterative Calculation:**
   - While `binform > 0`:
     - If `binform` is odd (`% 2 == 1`), multiply the result by the current base.
     - Square the base (`base *= base`).
     - Halve the exponent (`binform /= 2`).



---

##  Edge Cases Covered
- **Negative Exponents:** Successfully handled via base inversion.
- **Large Exponents:** Efficiency remains $O(\log n)$.
- **Base -1 with Large Power:** Handled by early return logic for $O(1)$ efficiency in this specific case.

---

##  Complexity Analysis  
- **Time Complexity (TC):** $O(\log n)$  
  - The exponent decreases exponentially (divided by 2), resulting in logarithmic iterations.
- **Space Complexity (SC):** $O(1)$  
  - No additional data structures; calculation is performed in-place using primitive variables.

---

###  Conclusion  
This implementation is **'Sovereign'** in its efficiency, combining early-exit optimizations with the robust Binary Exponentiation algorithm to handle all boundary conditions of the Power Function.
