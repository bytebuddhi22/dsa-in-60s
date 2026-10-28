"""DSA in 60s #09: Queue (FIFO) + Circular Queue (Python version of the video's C++ code)."""
from collections import deque


class CircularQueue:
    """Fixed-size queue on a list. front and rear wrap around with % N, so nothing ever shifts."""

    def __init__(self, n):
        self.buf = [None] * n
        self.front = 0
        self.rear = n - 1
        self.size = 0

    def empty(self):
        return self.size == 0

    def full(self):
        return self.size == len(self.buf)

    def push(self, x):
        """Enqueue at rear, O(1). Caller checks not full()."""
        self.rear = (self.rear + 1) % len(self.buf)  # ring: rear = (rear + 1) % N
        self.buf[self.rear] = x
        self.size += 1

    def peek(self):
        return self.buf[self.front]

    def pop(self):
        """Dequeue from front, O(1). Caller checks not empty()."""
        self.front = (self.front + 1) % len(self.buf)
        self.size -= 1


if __name__ == "__main__":
    q = deque()
    q.append(7)        # enqueue at rear
    q.append(9)
    print(q[0])        # 7
    q.popleft()        # dequeue from front
    print(q[0])        # 9

    cq = CircularQueue(5)
    for x in (1, 2, 3):
        cq.push(x)
    cq.pop()
    cq.pop()
    for x in (4, 5, 6):  # 6 wraps around to slot 0
        cq.push(x)
    out = []
    while not cq.empty():
        out.append(cq.peek())
        cq.pop()
    print(out)  # [3, 4, 5, 6]
