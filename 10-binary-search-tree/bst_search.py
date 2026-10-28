"""DSA in 60s #10: Binary Search Tree search (Python version of the video's C++ code)."""


class Node:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None


def search(cur, x):
    """Smaller → go left, bigger → go right. Returns the node or None. O(h)"""
    while cur is not None and cur.val != x:
        cur = cur.left if x < cur.val else cur.right
    return cur  # found or None


def insert(root, x):
    """Insert x (duplicates are ignored) and return the root."""
    if root is None:
        return Node(x)
    if x < root.val:
        root.left = insert(root.left, x)
    elif x > root.val:
        root.right = insert(root.right, x)
    return root


def height(root):
    """Edges on the longest root-to-leaf path; empty tree = -1."""
    if root is None:
        return -1
    return 1 + max(height(root.left), height(root.right))


if __name__ == "__main__":
    root = None
    for x in (27, 12, 41, 5, 19, 34, 56):  # the video's tree
        root = insert(root, x)
    print(search(root, 34) is not None)  # True: 27 → 41 → 34
    print(search(root, 30) is not None)  # False
    print(height(root))                  # 2 (balanced)
