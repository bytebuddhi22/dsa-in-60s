# #12 Dynamic Programming: Fibonacci

▶ Watch on [YouTube](https://www.youtube.com/@ByteBuddhi) · [Instagram](https://www.instagram.com/bytebuddhi/)

> fib(50) = 40,73,00,22,147 recursion calls. Ek chhoti si trick ke baad? Sirf 99.

## Idea
- `fib(n) = fib(n-1) + fib(n-2)` (Recursion #06). Par fib(3), fib(2)... baar baar compute hote hain
- **Trick 1, memoization:** answer table (`memo[]`) mein likh lo, agli baar seedha return
- **Trick 2, tabulation:** recursion chhodo, loop se table bharo
- Rule: same problem baar baar? Answer yaad rakho = **DP**

## Example from the video
- Naive fib(50): 2·fib(51) − 1 = **40,73,00,22,147** calls (~4 hazaar crore)
- Memo: **99 calls** (49 compute + 50 seedha return) → `fib(50) = 12,58,62,69,025`

## Complexity
- Time: O(2ⁿ) → **O(n)**
- Space: O(n) for the memo table

## Code
- [fib_dp.cpp](fib_dp.cpp): the video's `memo[51]` + `fib()` (memoization); `fibTable()` is trick 2 (tabulation)
- [fib_dp.py](fib_dp.py): Python version
- Tests: [test_fib_dp.cpp](test_fib_dp.cpp), [test_fib_dp.py](test_fib_dp.py)

## Practice
- [LeetCode 509: Fibonacci Number](https://leetcode.com/problems/fibonacci-number/)
- [LeetCode 70: Climbing Stairs](https://leetcode.com/problems/climbing-stairs/)
- [LeetCode 198: House Robber](https://leetcode.com/problems/house-robber/)
