import itertools
import random
import unittest

from two_pointers import pair_with_sum


class TestTwoPointers(unittest.TestCase):
    def test_video_example(self):
        self.assertEqual(pair_with_sum([4, 12, 17, 23, 30, 36, 52], 48), (12, 36))

    def test_no_pair(self):
        self.assertEqual(pair_with_sum([1, 2, 3], 100), (-1, -1))
        self.assertEqual(pair_with_sum([5], 10), (-1, -1))
        self.assertEqual(pair_with_sum([], 0), (-1, -1))

    def test_random_against_brute_force(self):
        rng = random.Random(2)
        for _ in range(3000):
            a = sorted(rng.randint(-50, 50) for _ in range(rng.randint(0, 20)))
            t = rng.randint(-100, 100)
            exists = any(x + y == t for x, y in itertools.combinations(a, 2))
            x, y = pair_with_sum(a, t)
            if exists:
                self.assertEqual(x + y, t)
            else:
                self.assertEqual((x, y), (-1, -1))


if __name__ == "__main__":
    unittest.main()
