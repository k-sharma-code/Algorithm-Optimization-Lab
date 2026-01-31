#  Valid Palindrome (Optimized Approach)

##  Title
**Memory-Efficient Two-Pointer Palindrome Validation with Alphanumeric Filtering**

## Intuition
Standard palindrome checks often fail when dealing with real-world strings that contain spaces, punctuation, or mixed casing. To solve this, we avoid the $O(N)$ space overhead of reversing the string. Instead, we use an **In-place Two-Pointer Strategy** to validate the string while dynamically skipping non-alphanumeric characters. This ensures the algorithm is robust against "noisy" data and highly performant.

## Algorithm
The logic follows a symmetric comparison model:
1. **Pointers:** Initialize `st` (start) at 0 and `end` at the last index of the string `str`.
2. **Filtering Logic:** - While `st < end`, if `str[st]` is not alphanumeric (using `isalnum`), increment `st` and skip.
   - While `st < end`, if `str[end]` is not alphanumeric, decrement `end` and skip.
3. **Case Transformation:** Convert both characters to lowercase using `tolower()` to ensure uniform comparison.
4. **Validation:** Compare `str[st]` and `str[end]`. If they mismatch, return `false`.
5. **Conclusion:** If the pointers meet or cross without a mismatch, return `true`.

##  Complexity Analysis
- **Time Complexity:** $O(N)$ — Each character in the string `str` is visited at most once.
- **Space Complexity:** $O(1)$ — No **auxiliary** data structures are used, maintaining constant memory usage.

##  Example Trace (Reviewer View)
**Input:** `str = "A man, a plan, a canal: Panama"`

| Step | `str[st]` | `str[end]` | Action Taken | Result |
| :--- | :--- | :--- | :--- | :--- |
| 1 | `'A'` | `'a'` | Compare `tolower` | Match, `st++`, `end--` |
| 2 | `' '` | `'m'` | `!isalnum(str[st])` | Skip space at `st` |
| 3 | `'m'` | `'m'` | Compare `tolower` | Match, `st++`, `end--` |
| 4 | `','` | `'a'` | `!isalnum(str[st])` | Skip comma at `st` |
| 5 | `'a'` | `'a'` | Compare `tolower` | Match, `st++`, `end--` |

##  What I Learned
During the implementation of this logic, I gained significant technical **insights**:
- **Character Filtering:** Mastered the use of `isalnum()` from `<cctype>` to handle edge cases like symbols and punctuation gracefully.
- **Space Optimization:** Understood why the Two-Pointer approach is superior to creating a temporary reversed string, reducing **Auxiliary Space** consumption.
- **Pointer Management:** Learned to implement nested `while` conditions to prevent pointers from going "Out of Bounds" during character skipping.
- **Robustness:** Built a solution that handles empty strings, spaces-only strings, and mixed-case alphanumeric inputs with high precision.
