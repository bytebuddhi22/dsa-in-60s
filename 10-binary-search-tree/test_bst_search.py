import random
import unittest

from bst_search import height, insert, search


def build(values):
    root = None
    for x in values:
        root = insert(root, x)
    return root


class TestBstSearch(unittest.TestCase):
    def test_video_example(self):
        root = build([27, 12, 41, 5, 19, 34, 56])
        self.assertEqual(search(root, 34).val, 34)
        self.assertIsNone(search(root, 30))
        self.assertEqual(height(root), 2)

    def test_edge_cases(self):
        self.assertIsNone(search(None, 5))
        skewed = build([5, 12, 19, 27, 34, 41, 56])  # sorted inserts → chain
        self.assertEqual(height(skewed), 6)
        self.assertEqual(search(skewed, 56).val, 56)

    def test_random_against_set(self):
        rng = random.Random(10)
        for _ in range(2000):
            values = [rng.randint(0, 49) for _ in range(rng.randint(0, 29))]
            root, ref = build(values), set(values)
            for x in range(-1, 51):
                found = search(root, x)
                self.assertEqual(found is not None, x in ref)
                if found is not None:
                    self.assertEqual(found.val, x)


if __name__ == "__main__":
    unittest.main()
