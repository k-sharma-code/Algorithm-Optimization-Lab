# Two Sum (LeetCode #1)

###  Title
Solving Two Sum using Two-Pointer and Hashmap.

### Problem Statement
Find two numbers in an array that sum up to a specific target. 
- The first approach returns the actual values.
- The second approach returns the original indices.

---

###  Intuition
The goal is to find a "partner" for every number. If the current number is `x`, we need to find `y` where `y = target - x`.
- **Two-Pointer:** If the array is sorted, we can use two pointers from the ends to find the pair.
- **Hashmap:** We store every number we see in a map. If we find the "partner" already stored in the map, we have our answer.

---

###  Approach 1: Two-Pointer
I used this method to find the values without using any extra memory.



**Algorithm:**
1. First, the array is sorted using `sort(nums.begin(), nums.end())`.
2. Place a `st` pointer at the start and a `end` pointer at the end.
3. While `st < end`:
   - If `nums[st] + nums[end] == target`, we found the pair.
   - If the sum is smaller than the target, move `st++`.
   - If the sum is larger than the target, move `end--`.

**Complexity:**
- **Time:** O(n log n) because of sorting.
- **Space:** O(1) as no extra data structure is used.
- **Note:** This returns the values because sorting changes the original positions.

---

###  Approach 2: Hashmap
This is faster and allows us to get the original indices easily.



**Algorithm:**
1. Created an `unordered_map<int, int>` to store the number and its index.
2. For every number `first` in the array:
   - Calculate `second = target - first`.
   - Check if `second` is already in the map using `m.find()`.
   - If it exists (`!= m.end()`), return the indices: `{m[second], i}`.
   - Otherwise, store the current number and its index in the map: `m[first] = i`.

**Complexity:**
- **Time:** O(n) average case (single pass).
- **Space:** O(n) because we store elements in the map.

---

### 🏛️ Comparison Table

| Feature | Two-Pointer | Hashmap |
| :--- | :--- | :--- |
| **Speed** | O(n log n) | O(n) |
| **Memory** | O(1) | O(n) |
| **Result** | Returns Values | Returns Indices |

---

### 🏛️ Example Walkthrough
**Input:** `nums = [3, 2, 4]`, `target = 6`

**Two-Pointer (Values):**
- Sorted: `[2, 3, 4]`
- `st = 2, end = 4` -> Sum is 6. 
- Returns `{2, 4}`.

**Hashmap (Indices):**
- `i = 0 (3)`: Partner 3 not in map. Store `{3: 0}`.
- `i = 1 (2)`: Partner 4 not in map. Store `{3: 0, 2: 1}`.
- `i = 2 (4)`: Partner 2 **found** at index 1.
- Returns indices `{1, 2}`.

---

###  What I Learned
- Why `unordered_map` is faster for search compared to a simple loop.
- Using `m.find()` and `m.end()` to check if a number exists in the map.
- How sorting makes original index tracking difficult.
- Returning multiple results using a `vector<int>`.
- The trade-off between speed (Time) and memory (Space).
-
