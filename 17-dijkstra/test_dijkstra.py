import random
import unittest

from dijkstra import INF, build_graph, dijkstra


def bellman_ford(n, adj, src):
    # Relax every edge n-1 times. O(V * E), no heap.
    dist = [INF] * n
    dist[src] = 0
    for _ in range(n - 1):
        for u in range(n):
            for v, w in adj[u]:
                if dist[u] + w < dist[v]:
                    dist[v] = dist[u] + w
    return dist


VIDEO_EDGES = [(0, 1, 4), (0, 2, 1), (1, 2, 2), (1, 3, 1), (2, 3, 5), (3, 4, 3)]


class TestDijkstra(unittest.TestCase):
    def test_video_example(self):
        adj = build_graph(5, VIDEO_EDGES)
        self.assertEqual(dijkstra(5, adj, 0), [0, 3, 1, 4, 7])
        self.assertEqual(dijkstra(5, adj, 4), [7, 4, 6, 3, 0])

    def test_edge_cases(self):
        self.assertEqual(dijkstra(3, build_graph(3, [(0, 1, 5)]), 0), [0, 5, INF])
        self.assertEqual(dijkstra(2, build_graph(2, [(0, 1, 0)]), 0), [0, 0])

    def test_random_against_bellman_ford(self):
        rng = random.Random(17)
        for _ in range(2000):
            n = rng.randint(1, 9)
            edges = [(rng.randrange(n), rng.randrange(n), rng.randint(0, 9)) for _ in range(rng.randint(0, 19))]
            adj = build_graph(n, edges)
            src = rng.randrange(n)
            self.assertEqual(dijkstra(n, adj, src), bellman_ford(n, adj, src))


if __name__ == "__main__":
    unittest.main()
