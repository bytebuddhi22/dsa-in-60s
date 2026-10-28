# #14 Merge Sort

▶ Watch on [YouTube](https://www.youtube.com/@ByteBuddhi) · [Instagram](https://www.instagram.com/bytebuddhi/)

> 10 lakh numbers. Bubble Sort: 4,99,99,95,00,000 comparisons. Merge Sort: ~2 crore. 25,000x kam.

## Idea
- **Divide & conquer:** beech se todo (Recursion #06), jab tak akela number na bache
- **Jodo:** dono sorted halves ke front compare karo, chhota pehle
- `log₂ n` levels × har level pe n kaam = O(n log n)

## Example from the video
- `[38, 27, 43, 3, 9, 82, 10, 5]` → 4-4 → 2-2 → 1-1
- Jodo: `27 38`, `3 43`, ... → `3 27 38 43`, `5 9 10 82` → `[3, 5, 9, 10, 27, 38, 43, 82]`

## Complexity
- Time: **O(n log n)** always
- Extra space: O(n) (merge ke liye temp array)
- **Stable:** barabar values ka order same rehta hai (5a pehle, 5b baad)

## Code
- [merge_sort.cpp](merge_sort.cpp): the video's `mergeSort()` (uses `std::inplace_merge` to join). Python writes the merge by hand
- [merge_sort.py](merge_sort.py): Python version
- Tests: [test_merge_sort.cpp](test_merge_sort.cpp), [test_merge_sort.py](test_merge_sort.py)

## Practice
- [LeetCode 912: Sort an Array](https://leetcode.com/problems/sort-an-array/)
- [LeetCode 88: Merge Sorted Array](https://leetcode.com/problems/merge-sorted-array/)
- [LeetCode 148: Sort List](https://leetcode.com/problems/sort-list/)
