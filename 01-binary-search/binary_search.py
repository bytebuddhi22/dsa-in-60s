"""DSA in 60s #01: Binary Search (Python version of the video's C++ code)."""


def binary_search(a, target):
    """Index of target in sorted list a, or -1. O(log n)"""
    lo, hi = 0, len(a) - 1
    while lo <= hi:
        mid = lo + (hi - lo) // 2
        if a[mid] == target:
            return mid
        if a[mid] < target:
            lo = mid + 1
        else:
            hi = mid - 1
    return -1  # not found


if __name__ == "__main__":
    print(binary_search([5, 12, 19, 27, 34, 41, 56], 34))  # 4
