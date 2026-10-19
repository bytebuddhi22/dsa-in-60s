import random
import unittest

from prefix_sum import build_prefix, range_sum


class TestPrefixSum(unittest.TestCase):
    def test_video_example(self):
        P = build_prefix([3, 1, 4, 1, 5, 9, 2])
        self.assertEqual(P, [0, 3, 4, 8, 9, 14, 23, 25])
        self.assertEqual(range_sum(P, 2, 5), 19)

    def test_single_element_and_whole_array(self):
        arr = [3, 1, 4]
        P = build_prefix(arr)
        self.assertEqual(range_sum(P, 1, 1), 1)
        self.assertEqual(range_sum(P, 0, 2), 8)

    def test_random_against_brute_force(self):
        rng = random.Random(4)
        for _ in range(500):
            arr = [rng.randint(-100, 100) for _ in range(rng.randint(1, 40))]
            P = build_prefix(arr)
            for _ in range(20):
                L = rng.randrange(len(arr))
                R = rng.randrange(L, len(arr))
                self.assertEqual(range_sum(P, L, R), sum(arr[L:R + 1]))


if __name__ == "__main__":
    unittest.main()
