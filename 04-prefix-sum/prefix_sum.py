"""DSA in 60s #04: Prefix Sum (Python version of the video's C++ code)."""


def build_prefix(arr):
    """P[i] = arr[0] + ... + arr[i-1]. O(n)"""
    P = [0] * (len(arr) + 1)
    for i, x in enumerate(arr):
        P[i + 1] = P[i] + x
    return P


def range_sum(P, L, R):
    """Sum of arr[L..R] (inclusive). O(1)"""
    return P[R + 1] - P[L]


if __name__ == "__main__":
    P = build_prefix([3, 1, 4, 1, 5, 9, 2])
    print(P)                   # [0, 3, 4, 8, 9, 14, 23, 25]
    print(range_sum(P, 2, 5))  # 19
