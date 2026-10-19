# #02 Two Pointers

▶ Watch on [YouTube](https://www.youtube.com/@ByteBuddhi) · [Instagram](https://www.instagram.com/bytebuddhi/)

> Sorted array mein do numbers jinka sum 48 ho. Brute force: 5 crore pairs. Two Pointers: 10,000 se bhi kam steps.

## Idea
- `left` sabse chhote pe, `right` sabse bade pe
- Sum bada → `right--`, sum chhota → `left++`
- Har step ek number hamesha ke liye bahar, isliye O(n)

## Example from the video
Array `[4, 12, 17, 23, 30, 36, 52]`, target **48**:

| Step | a[left] | a[right] | Sum | Decision |
|---|---|---|---|---|
| 1 | 4 | 52 | 56 | too big → right-- |
| 2 | 4 | 36 | 40 | too small → left++ |
| 3 | 12 | 36 | 48 | found (12, 36) ✅ |

n = 10,000: brute force checks 4,99,95,000 pairs; two pointers needs at most 9,999 steps.

## Complexity
- Time: **O(n)** (vs O(n²) brute force)
- Space: O(1)
- Works only because the array is **sorted**.

## Code
- [two_pointers.cpp](two_pointers.cpp): the video's code, wrapped in a function returning `pair<int, int>`
- [two_pointers.py](two_pointers.py): Python version
- Tests: [test_two_pointers.cpp](test_two_pointers.cpp), [test_two_pointers.py](test_two_pointers.py)

## Practice
- [LeetCode 167: Two Sum II](https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/)
- [LeetCode 125: Valid Palindrome](https://leetcode.com/problems/valid-palindrome/)
- [LeetCode 11: Container With Most Water](https://leetcode.com/problems/container-with-most-water/)
