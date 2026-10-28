import random
import unittest
from collections import deque

from circular_queue import CircularQueue


class TestCircularQueue(unittest.TestCase):
    def test_video_example(self):
        cq = CircularQueue(5)
        for x in (1, 2, 3):
            cq.push(x)
        self.assertEqual(cq.peek(), 1)
        cq.pop()
        cq.pop()
        for x in (4, 5, 6):
            cq.push(x)
        self.assertEqual(cq.rear, 0)  # 6 wrapped around to slot 0
        self.assertEqual(cq.front, 2)
        out = []
        while not cq.empty():
            out.append(cq.peek())
            cq.pop()
        self.assertEqual(out, [3, 4, 5, 6])

    def test_size_one(self):
        cq = CircularQueue(1)
        self.assertTrue(cq.empty())
        cq.push(42)
        self.assertTrue(cq.full())
        self.assertEqual(cq.peek(), 42)

    def test_random_against_deque(self):
        rng = random.Random(9)
        for _ in range(2000):
            n = rng.randint(1, 8)
            cq, ref = CircularQueue(n), deque()
            for _ in range(60):
                if rng.random() < 0.5 and not cq.full():
                    x = rng.randint(0, 99)
                    cq.push(x)
                    ref.append(x)
                elif not cq.empty():
                    self.assertEqual(cq.peek(), ref[0])
                    cq.pop()
                    ref.popleft()
                self.assertEqual(cq.size, len(ref))
                self.assertEqual(cq.full(), len(ref) == n)


if __name__ == "__main__":
    unittest.main()
