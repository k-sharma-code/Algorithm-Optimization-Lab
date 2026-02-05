#  String Compression

##  Title
**In-Place String Compression using Two-Pointer Technique**

##  Intuition
The objective is to compress consecutive duplicate characters to save space. To achieve the $O(1)$ extra space constraint, I implemented a "Read-and-Overwrite" strategy. I used one pointer to explore the character groups and another to write the compressed results directly back into the input array. This ensures that we never overwrite data that hasn't been processed yet.

##  Algorithm
1.  **Pointers Initialization:** Start `i` (explorer) and `idx` (writer) at the first index.
2.  **Character Grouping:** * Identify the current character `ch = chars[i]`.
    * Use a nested loop to find the end of the sequence for `ch` and calculate the `count`.
3.  **Writing Phase:**
    * Place the character `ch` at `chars[idx++]`.
    * If `count > 1`, convert the count to a string.
    * Iterate through each digit of the count string and write it into `chars[idx++]`.
4.  **Vector Resizing:** Once all groups are processed, resize the vector to the final `idx` position to remove obsolete trailing characters.

##  Complexity Analysis
* **Time Complexity:** $O(n)$ — We perform a single linear scan of the array.
* **Space Complexity:** $O(1)$ extra space — Modification is done in-place without auxiliary data structures.

##  Example
**Input:** `['a', 'a', 'b', 'b', 'c', 'c', 'c']`
1.  Process `'a'`: Count = 2. Update `chars` to `['a', '2', ...]`
2.  Process `'b'`: Count = 2. Update `chars` to `['a', '2', 'b', '2', ...]`
3.  Process `'c'`: Count = 3. Update `chars` to `['a', '2', 'b', '2', 'c', '3']`
**Final Output:** `['a', '2', 'b', '2', 'c', '3']`

##  Corner Cases Handled
* **Single Frequency:** If a character appears once (e.g., `['a']`), only the character is stored, no digit is added.
* **Multi-Digit Frequencies:** If a character repeats more than 9 times, each digit is treated as a separate character (e.g., 12 becomes `'1'`, `'2'`).
* **Empty/Small Input:** Logic naturally handles minimal inputs due to the while-loop boundaries.

##  What I Learned
* **Memory Efficiency:** Learned the importance of `vector::resize()` to maintain clean data after in-place operations.
* **Two-Pointer Coordination:** Improved my ability to manage multiple pointers with different traversal speeds.
* **Input Sanitization:** Handled the conversion of integers to characters for multi-digit counts.
