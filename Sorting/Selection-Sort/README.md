# Selection Sort Optimization 

##  Problem Statement
The objective is to sort an array of $n$ elements in **ascending order** using the Selection Sort algorithm. Selection Sort is an in-place comparison-based sorting algorithm that divides the input list into two parts: a sorted sublist and an unsorted sublist.

##  Intuition
Imagine you have a deck of unsuffled cards. You look through the entire deck to find the **absolute minimum** card and swap it with the card in the first position. Then, you look for the next minimum card in the remaining deck and swap it with the second card. You repeat this until the entire deck is organized.

In my implementation, I start from the $i^{th}$ index and assume it is the smallest. I then scan the **unsorted territory** (from $i+1$ to $n$) to find a value even smaller. If found, I update the index and perform a **strategic swap** at the end of the scan.

##  Algorithm 
1. Initialize `smallestIndex` to the current position `i`.
2. Traverse the unsorted part of the array from `j = i + 1` to `n-1`.
3. **Comparison:** If `arr[j] < arr[smallestIndex]`, update `smallestIndex = j`.
4. **Optimization Check:** Once the inner loop finishes, check if `smallestIndex != i`. 
5. **Swap:** If the condition is true, swap `arr[i]` and `arr[smallestIndex]`.
6. Repeat until the array is sorted.



##  Time & Space Complexity
| Case | Time Complexity | Justification |
| :--- | :--- | :--- |
| **Best Case** | $O(n^2)$ | The algorithm must scan the unsorted part even if the array is already sorted. |
| **Average Case** | $O(n^2)$ | Two nested loops result in quadratic time. |
| **Worst Case** | $O(n^2)$ | Occurs when the array is sorted in reverse order. |
| **Space Complexity** | $O(1)$ | **In-place algorithm**: No extra memory is used apart from a few variables. |

##  Why this Approach is useful?
* **Memory Efficient:** Unlike Merge Sort, it does not require auxiliary space ($O(1)$).
* **Minimized Swaps:** While Bubble Sort performs multiple swaps per pass, Selection Sort performs at most **one swap** per pass ($O(n)$ total swaps). 
* **Reliability:** In embedded systems or research environments where memory writes are "expensive," reducing the number of swaps is a significant **computational** advantage.

> **Note on Stability:** Selection Sort is **Unstable**. During the swap of the minimum element, the relative order of equal elements can be disrupted. This is a critical factor for high-integrity data processing.
