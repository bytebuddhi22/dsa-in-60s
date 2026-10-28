# #13 Heap: Min-Heap

▶ Watch on [YouTube](https://www.youtube.com/@ByteBuddhi) · [Instagram](https://www.instagram.com/bytebuddhi/)

> 10 lakh numbers mein sabse chhota, baar baar. Har baar sort = 1,99,31,569 steps. Heap se ~20.

## Idea
- Min-heap: har parent apne bachchon se **chhota** → min hamesha top pe
- Complete tree: left → right bharta hai, isliye array mein fit: bachche `2i+1`, `2i+2`, parent `(i−1)/2`
- Insert: end mein daalo, parent se chhota → swap up
- Extract min: top nikaalo, last waala top pe, chhote bachche se swap down

## Example from the video
- Heap `[3, 8, 5, 12, 10]`, insert 4: 4 < 5 swap, 4 > 3 stop → `[3, 8, 4, 12, 10, 5]`
- Pop: 3 bahar, 5 top pe, bachche 8, 4 → swap with 4 → `[4, 8, 5, 12, 10]`

## Complexity
- Top dekhna: **O(1)**
- Insert / extract: **O(log n)**: 10 lakh → ~20 levels → ~20 steps

## Where it's used
- Dijkstra (#17) uses this heap

## Code
- [min_heap.cpp](min_heap.cpp): the video's `priority_queue` code is in `main()`; `MinHeap` builds the same thing by hand on an array
- [min_heap.py](min_heap.py): Python version
- Tests: [test_min_heap.cpp](test_min_heap.cpp), [test_min_heap.py](test_min_heap.py)

## Practice
- [LeetCode 215: Kth Largest Element in an Array](https://leetcode.com/problems/kth-largest-element-in-an-array/)
- [LeetCode 703: Kth Largest Element in a Stream](https://leetcode.com/problems/kth-largest-element-in-a-stream/)
- [LeetCode 23: Merge k Sorted Lists](https://leetcode.com/problems/merge-k-sorted-lists/)
