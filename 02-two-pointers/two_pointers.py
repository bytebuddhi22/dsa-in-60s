"""DSA in 60s #02: Two Pointers (Python version of the video's C++ code)."""


def pair_with_sum(a, target):
    """Two values in sorted list a that add up to target, or (-1, -1). O(n)"""
    left, right = 0, len(a) - 1
    while left < right:
        s = a[left] + a[right]
        if s == target:
            return (a[left], a[right])
        if s > target:
            right -= 1
        else:
            left += 1
    return (-1, -1)  # no pair


if __name__ == "__main__":
    print(pair_with_sum([4, 12, 17, 23, 30, 36, 52], 48))  # (12, 36)
