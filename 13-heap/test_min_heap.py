import heapq
import random
import unittest

from min_heap import MinHeap


def is_heap(a):
    return all(a[(i - 1) // 2] <= a[i] for i in range(1, len(a)))


class TestMinHeap(unittest.TestCase):
    def test_video_example(self):
        h = MinHeap()
        for x in (3, 8, 5, 12, 10):
            h.push(x)
        h.push(4)  # 4 < 5 swap, 4 > 3 stop
        self.assertEqual(h.a, [3, 8, 4, 12, 10, 5])
        self.assertEqual(h.top(), 3)
        h.pop()    # 5 goes to the top, swaps with 4
        self.assertEqual(h.a, [4, 8, 5, 12, 10])

    def test_single(self):
        h = MinHeap()
        h.push(7)
        h.pop()
        self.assertEqual(h.a, [])

    def test_random_against_heapq(self):
        rng = random.Random(13)
        for _ in range(2000):
            h, ref = MinHeap(), []
            for _ in range(60):
                if rng.random() < 2 / 3:
                    x = rng.randint(0, 49)
                    h.push(x)
                    heapq.heappush(ref, x)
                elif ref:
                    self.assertEqual(h.top(), heapq.heappop(ref))
                    h.pop()
                self.assertTrue(is_heap(h.a))
                self.assertEqual(sorted(h.a), sorted(ref))


if __name__ == "__main__":
    unittest.main()
