# #17 Dijkstra: Shortest Path

▶ Watch on [YouTube](https://www.youtube.com/@ByteBuddhi) · [Instagram](https://www.instagram.com/bytebuddhi/)

> Kam roads ≠ chhota raasta. 3 roads = 8 km, 4 roads = 7 km. BFS roads ginta hai, km nahi.

## Idea
- Har baar: bache nodes mein **sabse kam dist** wala → pakka
- Uske padosi: `dist[u] + w < dist[v]` → update
- "Sabse kam dist" har baar chahiye → Min-Heap (#13)
- Sirf **w ≥ 0** weights pe sahi (negative edge ho toh Bellman-Ford)

## Example from the video
- A–B 4, A–C 1, B–C 2, B–D 1, C–D 5, D–E 3. Start A
- C = 1 pakka → B: 1 + 2 = 3 (4 se kam, update) → D: 3 + 1 = 4 → E: 4 + 3 = 7
- A→C→B→D→E = **7 km**. BFS waala A→B→D→E = 8 km

## Complexity
- Time: **O((V + E) log V)** with a heap
- Space: O(V + E)

## Code
- [dijkstra.cpp](dijkstra.cpp): the video's Dijkstra code (in `dijkstra()`); `buildGraph()` is a helper
- [dijkstra.py](dijkstra.py): Python version
- Tests: [test_dijkstra.cpp](test_dijkstra.cpp), [test_dijkstra.py](test_dijkstra.py)

## Practice
- [LeetCode 743: Network Delay Time](https://leetcode.com/problems/network-delay-time/)
- [LeetCode 1514: Path with Maximum Probability](https://leetcode.com/problems/path-with-maximum-probability/)
- [LeetCode 1631: Path With Minimum Effort](https://leetcode.com/problems/path-with-minimum-effort/)
