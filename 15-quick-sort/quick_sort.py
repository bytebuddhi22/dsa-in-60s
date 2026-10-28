"""DSA in 60s #15: Quick Sort (Python version of the video's C++ code)."""


def partition(a, low, high):
    """Pivot = last item; everything smaller goes left of it. Returns the pivot's final index."""
    pivot, i = a[high], low - 1  # last item
    for j in range(low, high):
        if a[j] < pivot:
            i += 1
            a[i], a[j] = a[j], a[i]
    a[i + 1], a[high] = a[high], a[i + 1]  # pivot -> final spot
    return i + 1


def quick_sort(a, low, high):
    """Sort a[low..high] in place. Average O(n log n), worst O(n^2), not stable."""
    if low >= high:
        return
    p = partition(a, low, high)
    quick_sort(a, low, p - 1)
    quick_sort(a, p + 1, high)


if __name__ == "__main__":
    a = [7, 2, 9, 4, 3, 8, 5]  # the video's array, pivot 5
    b = a[:]
    print(partition(b, 0, len(b) - 1), b)  # 3 [2, 4, 3, 5, 9, 8, 7]
    quick_sort(a, 0, len(a) - 1)
    print(a)  # [2, 3, 4, 5, 7, 8, 9]
