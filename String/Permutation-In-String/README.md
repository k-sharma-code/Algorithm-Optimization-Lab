#  Permutation in String: Optimized Sliding Window

##  Title: Sequence Invariant Validation
**Problem Statement:** Given strings `s1` and `s2`, determine if any permutation of `s1` exists as a contiguous substring within `s2`.

---

##  Intuition 
A **Permutation** means the character counts must be identical. Instead of using a heavy `std::map` (which has overhead), we use a **Fixed-size Frequency Array** (Hashing) for $O(1)$ efficiency.

We "slide" a window across `s2`. Instead of re-calculating the entire window's frequency every time, we simply:
1. **Subtract** the character entering from the `right`.
2. **Add back** the character exiting from the `left`.
This keeps our algorithm **High-Level** and extremely fast.

---

##  Variable Dictionary (Code Alignment)
Based on your implementation, here is what each variable governs:
* `freq[26]`: Our **Integer Hash Map**. Stores the required counts of characters from `s1`.
* `needed`: The **Master Counter**. Tracks how many total characters we still need to satisfy the permutation requirement.
* `left`: The **Trailing Pointer**. Defines the start of our sliding window.
* `right`: The **Leading Pointer**. Expands our window to explore new characters in `s2`.

---

## 🏛️ Algorithm: The Step-by-Step Process
1. **Initial Audit:** If `s1` is longer than `s2`, return `false` (Imperial Constraint).
2. **Hash Mapping:** Populate `freq[26]` with characters of `s1`. Set `needed = s1.length()`.
3. **Window Expansion:** Iterate with `right` pointer. 
   - Decrement `freq[s2[right]]`.
   - If the value is still $\ge 0$, it means we found a useful character. Decrement `needed`.
4. **Window Maintenance:** If window size exceeds `s1.length()`, release `s2[left]`.
   - Increment `freq[s2[left]]`.
   - If the value becomes $> 0$, it means we just lost a character we actually needed. Increment `needed`.
   - `left++` to move the window.
5. **Success Condition:** If `needed == 0` at any point, return `true`.

---

##  Example Walkthrough (Visual Audit)
**Input:** `s1 = "ab"`, `s2 = "eidba"`  
**Initial `freq`:** `{a:1, b:1}`, `needed = 2`

| Step | Window | `left` | `right` | `freq` Snapshot (Relevant) | `needed` | Action |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 1 | `e` | 0 | 0 | `{a:1, b:1, e:-1}` | 2 | `e` is not needed. |
| 2 | `i` | 1 | 1 | `{a:1, b:1, i:-1}` | 2 | `left` moved, `e` released. |
| 3 | `d` | 2 | 2 | `{a:1, b:1, d:-1}` | 2 | `left` moved, `i` released. |
| 4 | `b` | 3 | 3 | `{a:1, b:0}` | 1 | `b` found! `needed--` |
| 5 | `ba` | 3 | 4 | `{a:0, b:0}` | 0 | **Match!** `needed == 0` |

---

##  Time & Space Complexity
* **Time Complexity:** $O(M)$, where $M$ is the length of `s2`. (Each pointer moves only once).
* **Space Complexity:** $O(1)$. We only use a 26-integer array, regardless of string size.

---

## what I  Learn
* **Array-Based Hashing:** Avoiding `std::map` saved us from logarithmic overhead, making the code **Sophisticated** and efficient.
* **Invariant Control:** Learned to maintain a running counter (`needed`) to avoid checking the whole `freq` array in every iteration.
* **Sliding Window Boundary:** Mastered the logic of `right - left >= s1.length()` to keep the window size strictly controlled.

---
