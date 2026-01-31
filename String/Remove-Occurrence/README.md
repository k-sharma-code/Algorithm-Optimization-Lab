#  Remove All Occurrences of a Substring

##  Title
**Robust Substring Elimination using Iterative `find()` and `erase()` Strategy**

##  Intuition
In string manipulation, removing a pattern is not always a single-step process. Deleting one occurrence can inadvertently create a new one (e.g., in `baabcc`, removing the middle `abc` creates a new `bac`). This solution adopts a **Sentinel-based Iterative Approach** to ensure the string is completely purged of the target pattern, no matter how many times it reappears.

##  Algorithm
The implementation follows a minimalist and efficient iterative flow:
1. **Initial Localization:** The `str.find(part)` function is called to identify the first occurrence. The result is stored in a `size_t pos` variable.
2. **Sentinel Check:** A `while` loop is controlled by the condition `pos != string::npos`. This ensures the loop only executes if a **strict match** is found.
3. **In-place Modification:** `str.erase(pos, part.length())` is utilized to remove the substring directly, ensuring $O(1)$ auxiliary space.
4. **Iterative Update:** The `pos` variable is updated at the end of each iteration. This is **mandatory** to prevent infinite loops and to detect newly formed patterns.
5. **Termination:** The process gracefully terminates when `find()` returns `npos`, signaling that no further occurrences (even partial or insufficient ones) exist.

##  Complexity Analysis
- **Time Complexity:** $O(N^2)$ — In the worst-case scenario (e.g., `str = "aaaaaaaa"`, `part = "aa"`), each `find` and `erase` operation takes $O(N)$ time.
- **Space Complexity:** $O(1)$ — The algorithm is performed **in-place** on the original string, requiring no additional buffers.

##  Example Trace (The "aa" Logic)
**Input:** `str = "aaaaa"`, `part = "aa"`

| Step | Current `str` | `pos` (Index) | Action | Result |
| :--- | :--- | :--- | :--- | :--- |
| 1 | `"aaaaa"` | `0` | `erase(0, 2)` | `"aaa"` remains |
| 2 | `"aaa"` | `0` | `erase(0, 2)` | `"a"` remains |
| 3 | `"a"` | `npos` | **Terminate** | No strict match for `"aa"` |

##  What I Learned
- **Strict Matching:** Learned that `str.find()` requires a complete and exact match; insufficient characters (like one 'a' for a two-'a' part) result in `npos`.
- **Type Safety:** Mastered using `size_t` for indexing to avoid signed/unsigned comparison issues with `string::npos`.
- **Loop Integrity:** Realized the **mandatory** nature of updating the `pos` variable within the loop to avoid **perpetual** execution.
- **Redundancy Elimination:** Understood that implicit logic (like `npos` handling) is superior to adding redundant `length > 0` checks.
-
