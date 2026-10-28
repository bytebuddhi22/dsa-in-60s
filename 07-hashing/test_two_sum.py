import random
import unittest

from two_sum import two_sum


def first_pair_end(a, target):
    # Smallest i that has some j < i with a[j] + a[i] == target, or -1. O(n^2)
    for i in range(len(a)):
        if any(a[j] + a[i] == target for j in range(i)):
            return i
    return -1


class TestTwoSum(unittest.TestCase):
    def test_video_example(self):
        self.assertEqual(two_sum([8, 3, 16, 6, 12], 20), (0, 4))

    def test_edge_cases(self):
        self.assertEqual(two_sum([1, 2, 3], 100), (-1, -1))
        self.assertEqual(two_sum([], 5), (-1, -1))
        self.assertEqual(two_sum([5], 10), (-1, -1))  # can't use 5 twice
        self.assertEqual(two_sum([5, 5], 10), (0, 1))
        self.assertEqual(two_sum([-3, 4, 3, 90], 0), (0, 2))

    def test_random_against_brute_force(self):
        rng = random.Random(7)
        for _ in range(5000):
            a = [rng.randint(-10, 10) for _ in range(rng.randint(0, 14))]
            target = rng.randint(-20, 20)
            j, i = two_sum(a, target)
            end = first_pair_end(a, target)
            self.assertEqual(i, end, (a, target))
            if end == -1:
                self.assertEqual(j, -1)
            else:
                self.assertTrue(0 <= j < i and a[j] + a[i] == target, (a, target))


if __name__ == "__main__":
    unittest.main()
