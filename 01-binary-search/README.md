# #01 Binary Search

▶ Watch on [YouTube](https://www.youtube.com/@ByteBuddhi) · [Instagram](https://www.instagram.com/bytebuddhi/)

> 10 lakh numbers mein se ek dhoondhna hai aur chances sirf 20. Possible? Haan: Binary Search.

## Idea
- Ek rule: array **sorted** hona chahiye
- Mid dekho → aadha array bahar
- Har step pe range aadhi, isliye 10 lakh elements mein bhi sirf ~20 steps

## Example from the video
Array `[5, 12, 19, 27, 34, 41, 56]`, target **34**:

| Step | lo | mid | hi | a[mid] | Decision |
|---|---|---|---|---|---|
| 1 | 0 | 3 | 6 | 27 | 27 < 34 → go right |
| 2 | 4 | 5 | 6 | 41 | 41 > 34 → go left |
| 3 | 4 | 4 | 4 | 34 | found at index 4 ✅ |

10,00,000 numbers: linear search up to 10,00,000 steps, binary search at most **20**.

## Complexity
- Time: **O(log n)**
- Space: O(1)
- Why `mid = lo + (hi - lo) / 2`? Same as `(lo + hi) / 2`, but `lo + hi` can overflow `int` for huge arrays.

## Code
- [binary_search.cpp](binary_search.cpp): the video's code, wrapped in a function
- [binary_search.py](binary_search.py): Python version
- Tests: [test_binary_search.cpp](test_binary_search.cpp), [test_binary_search.py](test_binary_search.py)

## Practice
- [LeetCode 704: Binary Search](https://leetcode.com/problems/binary-search/)
- [LeetCode 35: Search Insert Position](https://leetcode.com/problems/search-insert-position/)
- [LeetCode 278: First Bad Version](https://leetcode.com/problems/first-bad-version/)
