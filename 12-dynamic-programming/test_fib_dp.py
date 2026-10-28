import unittest

import fib_dp
from fib_dp import fib, fib_table


class TestFibDp(unittest.TestCase):
    def setUp(self):
        fib_dp.memo[2:] = [0] * 49  # fresh memo for every test

    def test_video_example(self):
        self.assertEqual(fib(50), 12586269025)
        self.assertEqual(fib_table(50), 12586269025)

    def test_against_iterative(self):
        a, b = 0, 1
        for n in range(51):
            self.assertEqual(fib(n), a)
            self.assertEqual(fib_table(n), a)
            a, b = b, a + b

    def test_only_99_calls(self):
        # Count calls by wrapping the module's fib (the recursion looks it up by name).
        calls = 0
        real = fib_dp.fib

        def counting(n):
            nonlocal calls
            calls += 1
            return real(n)

        fib_dp.fib = counting
        try:
            fib_dp.fib(50)
        finally:
            fib_dp.fib = real
        self.assertEqual(calls, 99)  # 49 computed + 50 straight returns


if __name__ == "__main__":
    unittest.main()
