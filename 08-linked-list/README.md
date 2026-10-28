# #08 Linked List: insert in O(1)

▶ Watch on [YouTube](https://www.youtube.com/@ByteBuddhi) · [Instagram](https://www.instagram.com/bytebuddhi/)

> Array ke shuru mein ek number daalo: baaki 10 lakh khiskenge. Linked List mein? Bas 2 pointers badlo, kuch nahi hilta.

## Idea
- Node = `value` + `next` (agle node ka arrow). Aakhri ka `next` = null
- Insert after node `p`: naya node banao jo `p->next` ko point kare, phir `p->next` = naya node
- Koi shifting nahi, koi fixed size nahi

## Example from the video
`5 → 12 → 30 → 41`, insert 19 after 12:
1. `new Node{19, p->next}`: 19 now points to 30
2. `p->next = n`: 12 now points to 19
3. `5 → 12 → 19 → 30 → 41`, 0 shifts

## Complexity
- Insert / delete (node pata ho): **O(1)**
- Index access: **O(n)**, head se chalna padta hai (array: O(1))
- Rule: insert/delete zyada → Linked List, index access zyada → Array

## Code
- [linked_list.cpp](linked_list.cpp): the video's code (`insertAfter`; the video uses value 19)
- [linked_list.py](linked_list.py): Python version
- Tests: [test_linked_list.cpp](test_linked_list.cpp), [test_linked_list.py](test_linked_list.py)

## Practice
- [LeetCode 206: Reverse Linked List](https://leetcode.com/problems/reverse-linked-list/)
- [LeetCode 21: Merge Two Sorted Lists](https://leetcode.com/problems/merge-two-sorted-lists/)
- [LeetCode 707: Design Linked List](https://leetcode.com/problems/design-linked-list/)
