import random
import unittest

from linked_list import build, insert_after, to_list


def nth(head, k):
    for _ in range(k):
        head = head.next
    return head


class TestLinkedList(unittest.TestCase):
    def test_video_example(self):
        head = build([5, 12, 30, 41])
        insert_after(nth(head, 1), 19)
        self.assertEqual(to_list(head), [5, 12, 19, 30, 41])

    def test_edge_cases(self):
        head = build([5, 12, 30, 41])
        insert_after(nth(head, 3), 50)  # after the last node
        self.assertEqual(to_list(head), [5, 12, 30, 41, 50])
        one = build([7])
        insert_after(one, 8)
        self.assertEqual(to_list(one), [7, 8])
        self.assertEqual(to_list(build([])), [])

    def test_random_against_python_list(self):
        rng = random.Random(8)
        for _ in range(2000):
            v = [rng.randint(0, 99) for _ in range(rng.randint(1, 12))]
            head = build(v)
            for _ in range(10):
                k, val = rng.randrange(len(v)), rng.randint(0, 99)
                insert_after(nth(head, k), val)
                v.insert(k + 1, val)
            self.assertEqual(to_list(head), v)


if __name__ == "__main__":
    unittest.main()
