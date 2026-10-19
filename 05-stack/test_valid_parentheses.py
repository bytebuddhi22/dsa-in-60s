import random
import unittest

from valid_parentheses import is_valid


def brute_force(s):
    # Repeatedly delete adjacent matching pairs; valid iff nothing is left.
    prev = None
    while prev != s:
        prev = s
        s = s.replace("()", "").replace("[]", "").replace("{}", "")
    return s == ""


class TestValidParentheses(unittest.TestCase):
    def test_video_examples(self):
        self.assertTrue(is_valid("{[()]}"))
        self.assertFalse(is_valid("(]"))
        self.assertFalse(is_valid("(()"))

    def test_edge_cases(self):
        self.assertTrue(is_valid(""))
        self.assertTrue(is_valid("()[]{}"))
        self.assertFalse(is_valid(")"))
        self.assertFalse(is_valid("([)]"))

    def test_random_against_brute_force(self):
        rng = random.Random(5)
        for _ in range(5000):
            s = "".join(rng.choice("()[]{}") for _ in range(rng.randint(0, 12)))
            self.assertEqual(is_valid(s), brute_force(s), s)


if __name__ == "__main__":
    unittest.main()
