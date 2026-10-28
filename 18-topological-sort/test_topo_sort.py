import random
import unittest

from topo_sort import build, topo_sort

VIDEO_EDGES = [(0, 1), (0, 2), (1, 3), (2, 3), (3, 4)]


def has_cycle(n, adj):
    # DFS with colours: reaching an in-progress node again means a cycle.
    colour = [0] * n  # 0 new, 1 in progress, 2 done

    def go(u):
        colour[u] = 1
        for v in adj[u]:
            if colour[v] == 1 or (colour[v] == 0 and go(v)):
                return True
        colour[u] = 2
        return False

    return any(colour[u] == 0 and go(u) for u in range(n))


class TestTopoSort(unittest.TestCase):
    def test_video_example(self):
        adj, indeg = build(5, VIDEO_EDGES)
        self.assertEqual(indeg, [0, 1, 1, 2, 1])
        self.assertEqual(topo_sort(5, adj, indeg), ([0, 1, 2, 3, 4], False))
        self.assertEqual(indeg, [0, 1, 1, 2, 1])  # caller's list unchanged

    def test_cycle(self):
        adj, indeg = build(5, VIDEO_EDGES + [(4, 0)])  # Interview → Basics
        self.assertEqual(topo_sort(5, adj, indeg), ([], True))

    def test_random_against_dfs(self):
        rng = random.Random(18)
        for _ in range(3000):
            n = rng.randint(1, 9)
            dag_only = rng.random() < 0.5
            edges = []
            for _ in range(rng.randint(0, 13)):
                u, v = rng.randrange(n), rng.randrange(n)
                if not (dag_only and u >= v):
                    edges.append((u, v))
            adj, indeg = build(n, edges)
            order, cycle = topo_sort(n, adj, indeg)
            self.assertEqual(cycle, has_cycle(n, adj))
            if not cycle:
                pos = {v: i for i, v in enumerate(order)}
                self.assertEqual(sorted(order), list(range(n)))
                self.assertTrue(all(pos[u] < pos[v] for u, v in edges))


if __name__ == "__main__":
    unittest.main()
