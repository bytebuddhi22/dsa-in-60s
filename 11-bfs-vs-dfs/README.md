# #11 BFS vs DFS

▶ Watch on [YouTube](https://www.youtube.com/@ByteBuddhi) · [Instagram](https://www.instagram.com/bytebuddhi/)

> Maze mein raasta: har mod pe thoda-thoda dekhoge (BFS), ya ek galli end tak jaoge (DFS)?

## Idea
- **BFS** (Breadth First): level by level. Root queue mein daalo, nikaalo, bachche peeche daalo
- **DFS** (Depth First): ek raasta end tak, dead end pe wapas. Recursion = call stack = Stack
- BFS → unweighted shortest path. DFS → saare raaste, backtracking

## Example from the video
- Tree 27 / 12, 41 / 5, 19, 34, 56
- BFS: `27 12 41 5 19 34 56` (level by level)
- DFS: `27 12 5 19 41 34 56` (5 dead end → wapas → 19 → ...)

## Complexity
- Time: dono **O(n)**, har node ek baar
- Space: BFS O(width), DFS O(height)

## Code
- [traversal.cpp](traversal.cpp): the video's `dfs()` and BFS loop (wrapped in `bfs()`); `visit()` records the order
- [traversal.py](traversal.py): Python version
- Tests: [test_traversal.cpp](test_traversal.cpp), [test_traversal.py](test_traversal.py)

## Practice
- [LeetCode 102: Binary Tree Level Order Traversal](https://leetcode.com/problems/binary-tree-level-order-traversal/)
- [LeetCode 104: Maximum Depth of Binary Tree](https://leetcode.com/problems/maximum-depth-of-binary-tree/)
- [LeetCode 200: Number of Islands](https://leetcode.com/problems/number-of-islands/)
