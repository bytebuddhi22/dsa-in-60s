# #04 Prefix Sum

▶ Watch on [YouTube](https://www.youtube.com/@ByteBuddhi) · [Instagram](https://www.instagram.com/bytebuddhi/)

> 1 lakh elements, 1 lakh range-sum queries. Har query pe loop = 1000 crore operations. Prefix Sum: build ek baar, har query O(1).

## Idea
- `P[i + 1] = P[i] + arr[i]`: P[i] = pehle i elements ka sum
- `sum(L..R) = P[R + 1] − P[L]`
- Build O(n) ek baar, phir har query O(1)

## Example from the video
Array `[3, 1, 4, 1, 5, 9, 2]` → `P = [0, 3, 4, 8, 9, 14, 23, 25]`

sum(2..5) = 4 + 1 + 5 + 9 = **19** = P[6] − P[2] = 23 − 4, in one step.

n = q = 1 lakh: looping per query is 10,00,00,00,000 operations; prefix sum is about 2,00,000.

## Complexity
- Build: **O(n)**, each query: **O(1)**
- Space: O(n) for P
- P uses `long long` so big sums don't overflow.

## Code
- [prefix_sum.cpp](prefix_sum.cpp): the video's code as `buildPrefix()` + `rangeSum()`
- [prefix_sum.py](prefix_sum.py): Python version
- Tests: [test_prefix_sum.cpp](test_prefix_sum.cpp), [test_prefix_sum.py](test_prefix_sum.py)

## Practice
- [LeetCode 303: Range Sum Query – Immutable](https://leetcode.com/problems/range-sum-query-immutable/)
- [LeetCode 560: Subarray Sum Equals K](https://leetcode.com/problems/subarray-sum-equals-k/)
- [LeetCode 1480: Running Sum of 1d Array](https://leetcode.com/problems/running-sum-of-1d-array/)
