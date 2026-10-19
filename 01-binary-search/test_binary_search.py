import random
import unittest

from binary_search import binary_search


class TestBinarySearch(unittest.TestCase):
    def test_video_example(self):
        self.assertEqual(binary_search([5, 12, 19, 27, 34, 41, 56], 34), 4)

    def test_not_found_and_empty(self):
        self.assertEqual(binary_search([5, 12, 19], 7), -1)
        self.assertEqual(binary_search([], 1), -1)

    def test_random_against_linear_search(self):
        rng = random.Random(1)
        for _ in range(5000):
            a = sorted(rng.sample(range(-100, 100), rng.randint(0, 30)))
            t = rng.randint(-110, 110)
            expected = a.index(t) if t in a else -1
            self.assertEqual(binary_search(a, t), expected)


if __name__ == "__main__":
    unittest.main()
