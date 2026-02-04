#  Reverse Words in a String

## Title
**Reverse Words in a String (Space Normalization Approach)**

##  Intuition
The core idea is to reverse the entire sentence first. This moves the words to their correct relative positions but leaves the characters within each word reversed. By performing a second pass to reverse each individual word, we restore the correct character order. This approach is highly efficient as it operates in a single linear pass for extraction after the global reversal.

##  Algorithm
1.  **Global Reversal:** The entire string `s` is reversed using `reverse(s.begin(), s.end())`.
2.  **Word Extraction:** A `for` loop iterates through the reversed string.
3.  **Space Handling:** A nested `while` loop identifies word boundaries by skipping spaces and accumulating characters into a temporary `word` string.
4.  **Local Reversal:** Each identified `word` is reversed back to its original form using `reverse(word.begin(), word.end())`.
5.  **Result Construction:** Non-empty words are appended to `ans` with a preceding space to ensure single-space separation.
6.  **Final Polish:** The extra leading space is removed using `ans.substr(1)` before returning.

##  Complexity Analysis
* **Time Complexity:** $O(n)$, where $n$ is the length of the string. We traverse the string for global reversal and once more for word extraction.
* **Space Complexity:** $O(n)$ to store the `ans` string.

##  Example
**Input:** `"  hello   world  "`
1.  **After Global Reverse:** `"  dlrow   olleh  "`
2.  **Word 1 Extracted & Reversed:** `"world"` -> `ans` becomes `" world"`
3.  **Word 2 Extracted & Reversed:** `"hello"` -> `ans` becomes `" world hello"`
4.  **Final Output (substr):** `"world hello"`

##  Corner Cases Handled
* **Multiple Spaces:** The `while` loop and `word.length() > 0` check ensure that multiple spaces are reduced to a single space.
* **Leading/Trailing Spaces:** These are effectively ignored during the extraction phase, ensuring a clean output.
* **Single Word Strings:** The global reversal followed by a single local reversal correctly returns the word in its original order.

##  What I Learned
* learn **Two-Step Reversal** technique for sentence-level manipulation.
* Practiced string normalization techniques to handle inconsistent spacing in user inputs.
