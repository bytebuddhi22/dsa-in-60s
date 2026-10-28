<p align="center"><img src="assets/banner.png" alt="ByteBuddhi: tested code for every DSA in 60s episode" width="100%"></p>

<p align="center">
  <a href="https://github.com/bytebuddhi22/dsa-in-60s/actions/workflows/tests.yml"><img src="https://github.com/bytebuddhi22/dsa-in-60s/actions/workflows/tests.yml/badge.svg" alt="tests"></a>
  <a href="https://www.youtube.com/@ByteBuddhi"><img src="https://img.shields.io/badge/YouTube-@ByteBuddhi-FF0000?logo=youtube&logoColor=white" alt="YouTube"></a>
  <a href="https://www.instagram.com/bytebuddhi/"><img src="https://img.shields.io/badge/Instagram-bytebuddhi-E4405F?logo=instagram&logoColor=white" alt="Instagram"></a>
  <a href="https://discord.gg/55pd9C2zAE"><img src="https://img.shields.io/badge/Discord-join-5865F2?logo=discord&logoColor=white" alt="Discord"></a>
</p>

# DSA in 60s

**Byte-sized DSA, Hinglish mein.** One data-structures & algorithms concept per 60-second video, and here is the
code for every one of them: the exact C++ from the video, a Python version, and tests that prove both work.

## Episodes

| # | Topic | The idea in one line | Time | Code |
|---|---|---|---|---|
| 01 | [Binary Search](01-binary-search) | Look at the middle, throw away half | O(log n) | [C++](01-binary-search/binary_search.cpp) · [Python](01-binary-search/binary_search.py) |
| 02 | [Two Pointers](02-two-pointers) | Sum too big → right--, too small → left++ | O(n) | [C++](02-two-pointers/two_pointers.cpp) · [Python](02-two-pointers/two_pointers.py) |
| 03 | [Sliding Window](03-sliding-window) | One out, one in: don't re-add the whole window | O(n) | [C++](03-sliding-window/sliding_window.cpp) · [Python](03-sliding-window/sliding_window.py) |
| 04 | [Prefix Sum](04-prefix-sum) | Build once, answer any range sum in one step | O(n) + O(1)/query | [C++](04-prefix-sum/prefix_sum.cpp) · [Python](04-prefix-sum/prefix_sum.py) |
| 05 | [Stack](05-stack) | Opening → push, closing → must match the top | O(n) | [C++](05-stack/valid_parentheses.cpp) · [Python](05-stack/valid_parentheses.py) |
| 06 | [Recursion](06-recursion) | Big problem = same problem, a bit smaller + a base case | O(n) | [C++](06-recursion/recursion.cpp) · [Python](06-recursion/recursion.py) |
| 07 | [Hashing](07-hashing) | Ask "what do I need?" and look it up in O(1) | O(n) | [C++](07-hashing/two_sum.cpp) · [Python](07-hashing/two_sum.py) |
| 08 | [Linked List](08-linked-list) | Insert = change 2 pointers, nothing shifts | O(1) insert | [C++](08-linked-list/linked_list.cpp) · [Python](08-linked-list/linked_list.py) |
| 09 | [Queue](09-queue) | First in, first out; a ring so nothing shifts | O(1) | [C++](09-queue/circular_queue.cpp) · [Python](09-queue/circular_queue.py) |
| 10 | [Binary Search Tree](10-binary-search-tree) | Smaller → left, bigger → right | O(log n) balanced | [C++](10-binary-search-tree/bst_search.cpp) · [Python](10-binary-search-tree/bst_search.py) |
| 11 | [BFS vs DFS](11-bfs-vs-dfs) | Level by level (queue) vs deep first (stack) | O(n) | [C++](11-bfs-vs-dfs/traversal.cpp) · [Python](11-bfs-vs-dfs/traversal.py) |
| 12 | [Dynamic Programming](12-dynamic-programming) | Same subproblem again? Remember the answer | O(n) | [C++](12-dynamic-programming/fib_dp.cpp) · [Python](12-dynamic-programming/fib_dp.py) |
| 13 | [Heap](13-heap) | Smallest always on top; fix one path per change | O(log n) | [C++](13-heap/min_heap.cpp) · [Python](13-heap/min_heap.py) |
| 14 | [Merge Sort](14-merge-sort) | Split in half, sort both, merge the fronts | O(n log n) | [C++](14-merge-sort/merge_sort.cpp) · [Python](14-merge-sort/merge_sort.py) |
| 15 | [Quick Sort](15-quick-sort) | Pivot to its final spot, smaller left, bigger right | O(n log n) avg | [C++](15-quick-sort/quick_sort.cpp) · [Python](15-quick-sort/quick_sort.py) |
| 16 | [Graphs](16-graph-representation) | Store only the neighbours: adjacency list | O(V + E) space | [C++](16-graph-representation/graph.cpp) · [Python](16-graph-representation/graph.py) |
| 17 | [Dijkstra](17-dijkstra) | Closest unfinished node is final; relax its edges | O((V+E) log V) | [C++](17-dijkstra/dijkstra.cpp) · [Python](17-dijkstra/dijkstra.py) |
| 18 | [Topological Sort](18-topological-sort) | Indegree 0 first; leftovers mean a cycle | O(V + E) | [C++](18-topological-sort/topo_sort.cpp) · [Python](18-topological-sort/topo_sort.py) |

Next up: **Union-Find**. Subscribe so you don't miss it.

## Run it yourself

```bash
git clone https://github.com/bytebuddhi22/dsa-in-60s.git
cd dsa-in-60s
./run_tests.sh                      # every episode, C++ and Python

g++ -std=c++17 01-binary-search/binary_search.cpp -o bs && ./bs   # one C++ demo
python3 01-binary-search/binary_search.py                         # one Python demo
```

Needs `g++` (C++17) and Python 3. Every C++ file compiles with `-Wall -Wextra -Werror`, and each episode is tested
against a brute-force answer on thousands of random inputs.

## Found a bug or have a doubt?

Open an [issue](https://github.com/bytebuddhi22/dsa-in-60s/issues), or ask in **#doubts** on
[Discord](https://discord.gg/55pd9C2zAE).

MIT licensed, so use it however you like. ⭐ the repo if it helped you.
