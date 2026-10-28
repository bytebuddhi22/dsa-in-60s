import random
import unittest

from traversal import bfs, dfs, insert


def build(values):
    root = None
    for x in values:
        root = insert(root, x)
    return root


def preorder_with_depth(root):
    # Preorder with an explicit stack (no recursion), plus each node's depth.
    out, st = [], [(root, 0)] if root else []
    while st:
        n, d = st.pop()
        out.append((d, n.val))
        if n.right:
            st.append((n.right, d + 1))
        if n.left:
            st.append((n.left, d + 1))
    return out


def run_dfs(root):
    out = []
    dfs(root, out)
    return out


class TestTraversal(unittest.TestCase):
    def test_video_example(self):
        root = build([27, 12, 41, 5, 19, 34, 56])
        self.assertEqual(run_dfs(root), [27, 12, 5, 19, 41, 34, 56])
        self.assertEqual(bfs(root), [27, 12, 41, 5, 19, 34, 56])

    def test_empty(self):
        self.assertEqual(run_dfs(None), [])
        self.assertEqual(bfs(None), [])

    def test_random_against_reference(self):
        rng = random.Random(11)
        for _ in range(2000):
            root = build([rng.randint(0, 59) for _ in range(rng.randint(0, 24))])
            pre = preorder_with_depth(root)
            self.assertEqual(run_dfs(root), [v for _, v in pre])
            # BFS order = preorder, stably sorted by depth
            self.assertEqual(bfs(root), [v for _, v in sorted(pre, key=lambda p: p[0])])


if __name__ == "__main__":
    unittest.main()
