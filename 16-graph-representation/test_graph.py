import random
import unittest

from graph import build_adj, build_matrix


class TestGraph(unittest.TestCase):
    def test_video_example(self):
        edges = [(0, 1), (0, 2), (1, 3), (2, 3), (3, 4)]
        adj = build_adj(5, edges)
        self.assertEqual(adj[3], [1, 2, 4])
        self.assertEqual(sum(len(l) for l in adj), 10)  # 5 edges x 2
        mat = build_matrix(5, edges)
        self.assertEqual(sum(map(sum, mat)), 10)       # 25 cells = 10 ones + 15 zeros

    def test_no_edges(self):
        self.assertEqual(build_adj(3, []), [[], [], []])

    def test_random_list_matches_matrix(self):
        rng = random.Random(16)
        for _ in range(2000):
            n = rng.randint(1, 10)
            chosen, edges = set(), []
            for _ in range(15):
                u, v = rng.randrange(n), rng.randrange(n)
                if u != v and (min(u, v), max(u, v)) not in chosen:
                    chosen.add((min(u, v), max(u, v)))
                    edges.append((u, v))
            adj, mat = build_adj(n, edges), build_matrix(n, edges)
            for u in range(n):
                self.assertEqual(sorted(adj[u]), [v for v in range(n) if mat[u][v]])
            self.assertEqual(sum(len(l) for l in adj), 2 * len(edges))


if __name__ == "__main__":
    unittest.main()
