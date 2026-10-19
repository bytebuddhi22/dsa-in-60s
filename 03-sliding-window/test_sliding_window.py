import random
import unittest

from sliding_window import max_window_sum


class TestSlidingWindow(unittest.TestCase):
    def test_video_example(self):
        self.assertEqual(max_window_sum([2, 1, 5, 1, 3, 2], 3), 9)

    def test_window_is_whole_array_or_single(self):
        self.assertEqual(max_window_sum([4, -1, 2], 3), 5)
        self.assertEqual(max_window_sum([4, -1, 7], 1), 7)

    def test_random_against_brute_force(self):
        rng = random.Random(3)
        for _ in range(3000):
            a = [rng.randint(-50, 50) for _ in range(rng.randint(1, 25))]
            k = rng.randint(1, len(a))
            expected = max(sum(a[i:i + k]) for i in range(len(a) - k + 1))
            self.assertEqual(max_window_sum(a, k), expected)


if __name__ == "__main__":
    unittest.main()
