"""DSA in 60s #11: BFS vs DFS on a binary tree (Python version of the video's C++ code)."""
from collections import deque


class Node:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None


def dfs(n, out):
    """Go deep first, back up at a dead end (recursion = the stack). Appends to out. O(n)"""
    if n is None:
        return
    out.append(n.val)
    dfs(n.left, out)
    dfs(n.right, out)


def bfs(root):
    """Level by level, using a queue. Returns the visit order. O(n)"""
    out = []
    q = deque([root] if root else [])
    while q:
        n = q.popleft()
        out.append(n.val)
        if n.left:
            q.append(n.left)
        if n.right:
            q.append(n.right)
    return out


def insert(root, x):
    """BST insert (duplicates ignored), used to build test trees."""
    if root is None:
        return Node(x)
    if x < root.val:
        root.left = insert(root.left, x)
    elif x > root.val:
        root.right = insert(root.right, x)
    return root


if __name__ == "__main__":
    root = None
    for x in (27, 12, 41, 5, 19, 34, 56):  # the video's tree
        root = insert(root, x)
    order = []
    dfs(root, order)
    print(order)      # [27, 12, 5, 19, 41, 34, 56]
    print(bfs(root))  # [27, 12, 41, 5, 19, 34, 56]
