"""DSA in 60s #18: Topological Sort, Kahn's algorithm (Python version of the video's C++ code)."""
from collections import deque


def topo_sort(n, adj, indeg):
    """adj[u] = tasks that need u first; indeg[v] = how many tasks v waits for.
    Returns (order, cycle). If cycle is True, not every task could be ordered. O(V + E)"""
    indeg = indeg[:]  # don't change the caller's list
    q = deque(v for v in range(n) if indeg[v] == 0)
    order = []
    while q:
        u = q.popleft()
        order.append(u)
        for v in adj[u]:
            indeg[v] -= 1
            if indeg[v] == 0:
                q.append(v)
    cycle = len(order) < n
    return order, cycle


def build(n, edges):
    """adj + indeg from directed (u, v) edges ("u before v")."""
    adj, indeg = [[] for _ in range(n)], [0] * n
    for u, v in edges:
        adj[u].append(v)
        indeg[v] += 1
    return adj, indeg


if __name__ == "__main__":
    name = ["Basics", "Arrays", "Strings", "DSA", "Interview"]  # the video's topics
    edges = [(0, 1), (0, 2), (1, 3), (2, 3), (3, 4)]
    order, cycle = topo_sort(5, *build(5, edges))
    print([name[v] for v in order], cycle)  # ['Basics', 'Arrays', 'Strings', 'DSA', 'Interview'] False
    print(topo_sort(5, *build(5, edges + [(4, 0)]))[1])  # True: Interview → Basics is a cycle
