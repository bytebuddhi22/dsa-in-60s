import random
import unittest

from quick_sort import partition, quick_sort


class TestQuickSort(unittest.TestCase):
    def test_video_example(self):
        b = [7, 2, 9, 4, 3, 8, 5]
        self.assertEqual(partition(b, 0, 6), 3)  # 5 → index 3
        self.assertEqual(b, [2, 4, 3, 5, 9, 8, 7])
        a = [7, 2, 9, 4, 3, 8, 5]
        quick_sort(a, 0, len(a) - 1)
        self.assertEqual(a, [2, 3, 4, 5, 7, 8, 9])

    def test_edge_cases(self):
        a = []
        quick_sort(a, 0, -1)
        self.assertEqual(a, [])
        a = list(range(300))  # worst case: already sorted
        quick_sort(a, 0, len(a) - 1)
        self.assertEqual(a, list(range(300)))

    def test_random_against_sorted(self):
        rng = random.Random(15)
        for _ in range(3000):
            a = [rng.randint(-20, 20) for _ in range(rng.randint(0, 39))]
            if a:
                w = a[:]
                p = partition(w, 0, len(w) - 1)
                self.assertTrue(all(x < w[p] for x in w[:p]))
                self.assertTrue(all(x >= w[p] for x in w[p + 1:]))
            ref = sorted(a)
            quick_sort(a, 0, len(a) - 1)
            self.assertEqual(a, ref)


if __name__ == "__main__":
    unittest.main()
