"""DSA in 60s #13: Min-Heap (Python version of the video's C++ code)."""
import heapq


class MinHeap:
    """A min-heap on a list: children of i are 2i+1 and 2i+2, parent is (i-1)//2."""

    def __init__(self):
        self.a = []

    def top(self):
        return self.a[0]  # smallest, O(1)

    def push(self, x):
        """Add at the end, swap up while smaller than the parent. O(log n)"""
        a = self.a
        a.append(x)
        i = len(a) - 1
        while i > 0 and a[i] < a[(i - 1) // 2]:
            a[i], a[(i - 1) // 2] = a[(i - 1) // 2], a[i]
            i = (i - 1) // 2

    def pop(self):
        """Move the last item to the top, swap down with the smaller child. O(log n)"""
        a = self.a
        a[0] = a[-1]
        a.pop()
        i = 0
        while True:
            l, r, m = 2 * i + 1, 2 * i + 2, i
            if l < len(a) and a[l] < a[m]:
                m = l
            if r < len(a) and a[r] < a[m]:
                m = r
            if m == i:
                break
            a[i], a[m] = a[m], a[i]
            i = m


if __name__ == "__main__":
    pq = []  # heapq is a min-heap
    for x in (3, 8, 5, 12, 10):
        heapq.heappush(pq, x)
    heapq.heappush(pq, 4)          # O(log n)
    smallest = pq[0]               # 3, O(1)
    heapq.heappop(pq)              # O(log n)
    print(smallest, pq[0])         # 3 4

    h = MinHeap()
    for x in (3, 8, 5, 12, 10, 4):
        h.push(x)
    print(h.a)  # [3, 8, 4, 12, 10, 5]
