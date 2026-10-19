# #03 Sliding Window

▶ Watch on [YouTube](https://www.youtube.com/@ByteBuddhi) · [Instagram](https://www.instagram.com/bytebuddhi/)

> 3 lagataar numbers ka maximum sum. Brute force har window phir se jodta hai. Sliding Window: jo bahar gaya ghatao, jo andar aaya jodo.

## Idea
- Pehli window ka sum ek baar nikalo
- Har slide par bas 2 kaam: ek minus, ek plus → `sum += a[i] - a[i - k]`
- O(n·k) se seedha O(n)

## Example from the video
Array `[2, 1, 5, 1, 3, 2]`, k = **3**:

| Window | Sum | Best |
|---|---|---|
| 2, 1, 5 | 8 | 8 |
| 1, 5, 1 | 8 − 2 + 1 = 7 | 8 |
| 5, 1, 3 | 7 − 1 + 3 = 9 | **9** (new max) |
| 1, 3, 2 | 9 − 5 + 2 = 6 | 9 |

n = 10 lakh, k = 1000: brute force does 99,90,01,000 additions; sliding window does 19,99,000.

## Complexity
- Time: **O(n)** (vs O(n·k))
- Space: O(1)
- The code uses `int` like the video. If sums can go past ~2 × 10⁹, switch to `long long`.

## Code
- [sliding_window.cpp](sliding_window.cpp): the video's code, wrapped in a function
- [sliding_window.py](sliding_window.py): Python version
- Tests: [test_sliding_window.cpp](test_sliding_window.cpp), [test_sliding_window.py](test_sliding_window.py)

## Practice
- [LeetCode 643: Maximum Average Subarray I](https://leetcode.com/problems/maximum-average-subarray-i/)
- [LeetCode 1343: Number of Sub-arrays of Size K and Average ≥ Threshold](https://leetcode.com/problems/number-of-sub-arrays-of-size-k-and-average-greater-than-or-equal-to-threshold/)
- [LeetCode 3: Longest Substring Without Repeating Characters](https://leetcode.com/problems/longest-substring-without-repeating-characters/) (variable-size window)
