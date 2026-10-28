import random
import unittest

from merge_sort import merge_sort


class Item:
    """Compares by key only, so we can check equal keys keep their order."""

    def __init__(self, key, tag):
        self.key, self.tag = key, tag

    def __lt__(self, other):
        return self.key < other.key

    def __le__(self, other):
        return self.key <= other.key


class TestMergeSort(unittest.TestCase):
    def test_video_example(self):
        a = [38, 27, 43, 3, 9, 82, 10, 5]
        merge_sort(a, 0, len(a) - 1)
        self.assertEqual(a, [3, 5, 9, 10, 27, 38, 43, 82])

    def test_edge_cases(self):
        a = []
        merge_sort(a, 0, -1)
        self.assertEqual(a, [])
        a = [9, 8, 7, 6, 5]  # only the middle three
        merge_sort(a, 1, 3)
        self.assertEqual(a, [9, 6, 7, 8, 5])

    def test_stable(self):
        # the video: 5a stays before 5b
        a = [Item(5, "a"), Item(2, "x"), Item(5, "b")]
        merge_sort(a, 0, 2)
        self.assertEqual([(i.key, i.tag) for i in a], [(2, "x"), (5, "a"), (5, "b")])

    def test_random_against_sorted(self):
        rng = random.Random(14)
        for _ in range(3000):
            a = [rng.randint(-20, 20) for _ in range(rng.randint(0, 39))]
            ref = sorted(a)
            merge_sort(a, 0, len(a) - 1)
            self.assertEqual(a, ref)


if __name__ == "__main__":
    unittest.main()
