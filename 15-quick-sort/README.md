# #15 Quick Sort

▶ Watch on [YouTube](https://www.youtube.com/@ByteBuddhi) · [Instagram](https://www.instagram.com/bytebuddhi/)

> Merge Sort ko 10 lakh extra slots chahiye. Quick Sort? Usi array mein.

## Idea
- Ek **pivot** chuno (yahan: last item)
- **Partition:** pivot se chhote sab left zone mein swap, phir pivot zone ke baad → apni FINAL jagah
- Dono taraf yahi repeat (recursion)

## Example from the video
- `[7, 2, 9, 4, 3, 8, 5]`, pivot 5: 2 chhota swap, 4 chhota swap, 3 chhota swap
- → `[2, 4, 3, 5, 9, 8, 7]`: 5 index 3 pe FINAL. Ab `[2, 4, 3]` aur `[9, 8, 7]`

## Complexity
- Average: **O(n log n)**
- Worst: **O(n²)** (sorted input, pivot har baar sabse bada). Random pivot → worst unlikely
- **In place** (sirf recursion stack, O(log n) avg), par **stable nahi**

## Code
- [quick_sort.cpp](quick_sort.cpp): the video's `partition()` + `quickSort()`
- [quick_sort.py](quick_sort.py): Python version
- Tests: [test_quick_sort.cpp](test_quick_sort.cpp), [test_quick_sort.py](test_quick_sort.py)

## Practice
- [LeetCode 912: Sort an Array](https://leetcode.com/problems/sort-an-array/)
- [LeetCode 75: Sort Colors](https://leetcode.com/problems/sort-colors/)
- [LeetCode 215: Kth Largest Element in an Array](https://leetcode.com/problems/kth-largest-element-in-an-array/) (quickselect)
