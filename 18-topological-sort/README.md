# #18 Topological Sort (Kahn's algorithm)

▶ Watch on [YouTube](https://www.youtube.com/@ByteBuddhi) · [Instagram](https://www.instagram.com/bytebuddhi/)

> Pehle kya padhein? Basics → Arrays, Strings → DSA → Interview. Dependencies ka sahi order kaise nikaalein?

## Idea
- Dependencies = directed edges. Cycle nahi → **DAG** (Directed Acyclic Graph)
- Har node ka **indegree** = kitne arrows andar aate hain
- Indegree 0 waale queue mein. Nikaalo, order mein daalo, padosiyon ka indegree −1, 0 hua → queue
- Sab nahi nikle → **cycle** hai, koi valid order nahi

## Example from the video
- Basics → Arrays, Strings → DSA → Interview: `indeg = [0, 1, 1, 2, 1]`
- Order: Basics, Arrays, Strings, DSA, Interview ✅
- Interview → Basics jodo: koi indeg 0 nahi → 0 / 5 nikle → cycle

## Complexity
- Time: **O(V + E)**, har node aur edge ek baar
- Space: O(V)

## Code
- [topo_sort.cpp](topo_sort.cpp): the video's Kahn's algorithm (in `topoSort()`, returns `{order, cycle}`); `build()` makes adj + indeg
- [topo_sort.py](topo_sort.py): Python version
- Tests: [test_topo_sort.cpp](test_topo_sort.cpp), [test_topo_sort.py](test_topo_sort.py)

## Practice
- [LeetCode 207: Course Schedule](https://leetcode.com/problems/course-schedule/)
- [LeetCode 210: Course Schedule II](https://leetcode.com/problems/course-schedule-ii/)
- [LeetCode 802: Find Eventual Safe States](https://leetcode.com/problems/find-eventual-safe-states/)
