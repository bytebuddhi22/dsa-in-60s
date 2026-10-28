"""DSA in 60s #08: Linked List, insert after a node (Python version of the video's C++ code)."""


class Node:
    def __init__(self, value, next=None):
        self.value = value
        self.next = next


def insert_after(p, value):
    """Insert value right after node p (p is not None). O(1): only 2 pointers change"""
    n = Node(value, p.next)
    p.next = n


def build(values):
    head = None
    for v in reversed(values):
        head = Node(v, head)
    return head


def to_list(head):
    out = []
    while head is not None:
        out.append(head.value)
        head = head.next
    return out


if __name__ == "__main__":
    head = build([5, 12, 30, 41])
    insert_after(head.next, 19)  # after 12
    print(to_list(head))  # [5, 12, 19, 30, 41]
