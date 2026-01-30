# Best Time to Buy and Sell Stock (LeetCode #121)

## Title
**Linear Time Greedy Solution for Stock Profit Calculation**

##  Intuition
To find the maximum profit, we need to identify the largest difference between a buy price and a sell price, ensuring the buy day comes before the sell day. Instead of checking every possible pair ($O(N^2)$), we use a **One-Pass Greedy Approach**. By keeping track of the minimum price encountered so far, we can calculate the potential profit at each step and update our global maximum.

##  Algorithm (Step-by-Step Breakdown)

1. **Empty Input Handling:**
   - The function starts with `if (n == 0) return 0;`.
   - **Reasoning:** This prevents out-of-bounds access when initializing the `bestBuy` variable with `prices[0]`.

2. **Initialization:**
   - `maxProfit`: Initialized to `0`.
   - `bestBuy`: Initialized to `prices[0]` (the first available price).

3. **Single Pass Iteration:**
   - The loop runs from index `1` to `n-1`.
   - **Profit Calculation:** If the current price is higher than `bestBuy`, we calculate the difference and update `maxProfit` using `max(maxProfit, prices[i] - bestBuy)`.
   - **Minimum Price Update:** We then update `bestBuy` using `min(bestBuy, prices[i])`. This ensures that for all future days, we are comparing the price against the lowest possible historical buy point.

## Complexity Analysis
- **Time Complexity:** $O(N)$ - We traverse the prices array exactly once.
- **Space Complexity:** $O(1)$ - We only use a fixed number of integer variables (`maxProfit`, `bestBuy`, `n`, `i`) regardless of the input size. 
  *(Note: Pass-by-reference `vector<int>& prices` is used to avoid unnecessary memory copying.)*

## 🧪 Trace & Validation
| Input Prices | `bestBuy` | `currentPrice` | Potential Profit | `maxProfit` |
| :--- | :--- | :--- | :--- | :--- |
| **[7, 1, 5, 3, 6, 4]** | 7 $\rightarrow$ 1 | 1 | 0 | 0 |
| | 1 | 5 | 4 | 4 |
| | 1 | 6 | 5 | **5** |

##  Performance
- **Runtime:** very fast in practice (plateform dependent)
- **Memory Usage:** Minimal due to constant auxiliary space logic.
