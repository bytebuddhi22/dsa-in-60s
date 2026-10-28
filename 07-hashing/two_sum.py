"""DSA in 60s #07: Hashing, Two Sum (Python version of the video's C++ code)."""


def two_sum(a, target):
    """Indices (j, i) with j < i and a[j] + a[i] == target, or (-1, -1). O(n) average"""
    seen = {}  # number -> index
    for i, x in enumerate(a):
        need = target - x
        if need in seen:
            return seen[need], i
        seen[x] = i  # store
    return -1, -1  # no pair


if __name__ == "__main__":
    print(two_sum([8, 3, 16, 6, 12], 20))  # (0, 4): 8 + 12 = 20
    print(two_sum([1, 2, 3], 100))         # (-1, -1)
