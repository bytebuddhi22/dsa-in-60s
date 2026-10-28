"""DSA in 60s #14: Merge Sort (Python version of the video's C++ code).

Python has no inplace_merge, so merge() does the "join": compare both fronts, smaller first.
"""


def merge(a, lo, mid, hi):
    """Join sorted a[lo..mid] and a[mid+1..hi]. <= keeps equal items in order (stable)."""
    left, right = a[lo:mid + 1], a[mid + 1:hi + 1]
    i = j = 0
    for k in range(lo, hi + 1):
        if j == len(right) or (i < len(left) and left[i] <= right[j]):
            a[k] = left[i]
            i += 1
        else:
            a[k] = right[j]
            j += 1


def merge_sort(a, lo, hi):
    """Sort a[lo..hi] (both ends included) in place. O(n log n), stable, O(n) extra space"""
    if hi - lo < 1:
        return  # 0/1 item
    mid = lo + (hi - lo) // 2
    merge_sort(a, lo, mid)       # left
    merge_sort(a, mid + 1, hi)   # right
    merge(a, lo, mid, hi)        # join


if __name__ == "__main__":
    a = [38, 27, 43, 3, 9, 82, 10, 5]  # the video's array
    merge_sort(a, 0, len(a) - 1)
    print(a)  # [3, 5, 9, 10, 27, 38, 43, 82]
