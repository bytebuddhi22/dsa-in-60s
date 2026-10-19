import math
import unittest

from recursion import fact


class TestRecursion(unittest.TestCase):
    def test_video_example(self):
        self.assertEqual(fact(4), 24)

    def test_base_cases(self):
        self.assertEqual(fact(0), 1)
        self.assertEqual(fact(1), 1)

    def test_against_math_factorial(self):
        for n in range(0, 60):
            self.assertEqual(fact(n), math.factorial(n))


if __name__ == "__main__":
    unittest.main()
