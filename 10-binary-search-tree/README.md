# #10 Binary Search Tree

▶ Watch on [YouTube](https://www.youtube.com/@ByteBuddhi) · [Instagram](https://www.instagram.com/bytebuddhi/)

> 10 lakh items, sirf 20 steps mein dhoondho. Rule simple hai: chhote left, bade right.

## Idea
- Tree: root, har node ke max 2 bachche, bina bachche wala = leaf
- BST rule: left subtree mein sab **chhote**, right mein sab **bade**
- Search: x chhota → left, bada → right. Har step pe ek poora subtree gaayab (Binary Search #01 jaisa)
- Balanced → height log n. Sorted order mein insert kiya → skewed chain, height n

## Example from the video
- Tree 27 / 12, 41 / 5, 19, 34, 56. Dhoondho 34:
- 34 > 27 → right → 41; 34 < 41 → left → 34 **found**, 3 steps

## Complexity
- Search / insert: **O(h)**: O(log n) balanced, O(n) skewed
- Isliye balance zaroori (AVL, Red-Black trees)

## Code
- [bst_search.cpp](bst_search.cpp): the video's `Node` + `search()`; `insert()`, `height()`, `freeTree()` are helpers
- [bst_search.py](bst_search.py): Python version
- Tests: [test_bst_search.cpp](test_bst_search.cpp), [test_bst_search.py](test_bst_search.py)

## Practice
- [LeetCode 700: Search in a Binary Search Tree](https://leetcode.com/problems/search-in-a-binary-search-tree/)
- [LeetCode 701: Insert into a Binary Search Tree](https://leetcode.com/problems/insert-into-a-binary-search-tree/)
- [LeetCode 98: Validate Binary Search Tree](https://leetcode.com/problems/validate-binary-search-tree/)
