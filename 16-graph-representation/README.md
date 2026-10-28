# #16 Graphs: Matrix vs Adjacency List

▶ Watch on [YouTube](https://www.youtube.com/@ByteBuddhi) · [Instagram](https://www.instagram.com/bytebuddhi/)

> 10 lakh users, 100 friends each. Matrix mein 1 lakh crore cells. List mein bas 10 crore.

## Idea
- Graph = **nodes** (users) + **edges** (friendships). Tree (#10, #11) bhi graph hai, bas cycle nahi
- Edges directed ho sakte hain, ya weighted (Dijkstra #17)
- **Tareeka 1, Adjacency Matrix:** V × V grid, edge → 1, warna 0. `mat[1][3]` O(1)
- **Tareeka 2, Adjacency List:** har node ke saath sirf uske padosi

## Example from the video
- 5 nodes, 5 edges: 0-1, 0-2, 1-3, 2-3, 3-4
- Matrix: 5 × 5 = 25 cells = 10 ones + 15 zeros
- List: 5 edges × 2 = 10 entries, `adj[3] = {1, 2, 4}`

## Complexity
- Space: Matrix **O(V²)**, List **O(V + E)**
- Sparse graph (E ≪ V²), jaise 10 lakh users: List hi best

## Code
- [graph.cpp](graph.cpp): the video's adjacency list code (in `buildAdj()`); `buildMatrix()` for comparison
- [graph.py](graph.py): Python version
- Tests: [test_graph.cpp](test_graph.cpp), [test_graph.py](test_graph.py)

## Practice
- [LeetCode 1971: Find if Path Exists in Graph](https://leetcode.com/problems/find-if-path-exists-in-graph/)
- [LeetCode 547: Number of Provinces](https://leetcode.com/problems/number-of-provinces/)
- [LeetCode 133: Clone Graph](https://leetcode.com/problems/clone-graph/)
