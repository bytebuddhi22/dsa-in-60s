"""DSA in 60s #17: Dijkstra, shortest path with weights >= 0 (Python version of the video's C++ code)."""
import heapq

INF = float("inf")


def dijkstra(n, adj, src):
    """adj[u] = list of (v, w). Shortest distance from src to every node (INF = unreachable).
    O((V + E) log V)"""
    dist = [INF] * n
    dist[src] = 0
    pq = [(0, src)]  # (dist, node), min-heap
    while pq:
        d, u = heapq.heappop(pq)
        if d > dist[u]:
            continue  # purani entry
        for v, w in adj[u]:
            if d + w < dist[v]:
                dist[v] = d + w
                heapq.heappush(pq, (dist[v], v))
    return dist


def build_graph(n, edges):
    """Undirected weighted graph from (u, v, w) triples."""
    adj = [[] for _ in range(n)]
    for u, v, w in edges:
        adj[u].append((v, w))
        adj[v].append((u, w))
    return adj


if __name__ == "__main__":
    # the video's map: A=0 B=1 C=2 D=3 E=4
    adj = build_graph(5, [(0, 1, 4), (0, 2, 1), (1, 2, 2), (1, 3, 1), (2, 3, 5), (3, 4, 3)])
    print(dijkstra(5, adj, 0))  # [0, 3, 1, 4, 7]
