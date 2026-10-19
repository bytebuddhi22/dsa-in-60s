"""DSA in 60s #03: Sliding Window (Python version of the video's C++ code)."""


def max_window_sum(a, k):
    """Max sum of any k consecutive elements (1 <= k <= len(a)). O(n)"""
    s = sum(a[:k])
    best = s
    for i in range(k, len(a)):
        s += a[i] - a[i - k]  # one in, one out
        best = max(best, s)
    return best


if __name__ == "__main__":
    print(max_window_sum([2, 1, 5, 1, 3, 2], 3))  # 9
