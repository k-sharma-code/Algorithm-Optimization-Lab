#  Book Allocation Problem — Binary Search on Answer Space  

##  Introduction  
The **Book Allocation Problem** is a classic optimization problem where the objective is to distribute `n` books (each having a certain number of pages) among `m` students such that the **maximum number of pages assigned to any student is minimized**. This problem follows a **Minimax strategy** and is efficiently solved using **Binary Search on the Answer Space** rather than directly on indices.  

---

##  Problem Statement  
You are given an array `arr[]` where `arr[i]` represents the number of pages in the `i-th` book, and an integer `m` representing the number of students. The task is to allocate books in such a way that:  

1. Every student is assigned **at least one book**.  
2. Books are allocated in a **contiguous manner** (no skipping of books).  
3. The **maximum number of pages assigned to any student is minimized**.  

---

##  Assumptions & Constraints  
- **Contiguous Allocation:** A student can only receive a continuous sequence of books.  
- **Feasibility Condition:** If `m > n`, allocation is impossible because each student must receive at least one book.  
- **Order Preservation:** The order of books cannot be changed; allocation must follow the given sequence.  

---

##  Core Idea — Binary Search on Answer Space  
Instead of applying binary search on book indices, we apply it on the **range of possible answers**.  

- The **minimum possible answer** is `max(arr)` because at least one student must read the book with the maximum pages.  
- The **maximum possible answer** is `sum(arr)` because, in the worst case, a single student reads all the books.  

So, the search space becomes **[max(arr), sum(arr)]**, and we perform binary search within this range to find the optimal minimum value.  

---

##  Feasibility Check — `isPossible()`  
To validate whether a given value `mid` (maximum pages limit) is feasible:  

- We allocate books sequentially to the current student until adding a book exceeds `mid`.  
- Once exceeded, allocation moves to the next student.  
- If the number of students required exceeds `m`, the function returns `false`; otherwise, it returns `true`.  

This greedy approach ensures we always try to fit books efficiently within the given limit.  

---

##  Binary Search Strategy  
- If `isPossible(mid)` returns **true**, then `mid` is a valid solution. We store it and try to minimize it further by searching the left half (`end = mid - 1`).  
- If `isPossible(mid)` returns **false**, the limit is too small, so we search the right half (`start = mid + 1`).  

The final stored value gives the **minimum possible maximum pages**.  

---

##  Edge Cases Handled  
- `m > n` → Return `-1` (allocation not possible).  
- Single student or single book scenarios are handled naturally.  
- Large page values are safely handled using `long long` to avoid overflow.  

---

##  Complexity Analysis  
- **Time Complexity:** `O(N × log(sum(arr)))`  
- **Space Complexity:** `O(1)`  

---

###  Conclusion  
This approach efficiently solves the Book Allocation Problem by combining **binary search** with a **greedy feasibility check**, ensuring optimal allocation while maintaining strict constraints.
