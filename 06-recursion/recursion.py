"""DSA in 60s #06: Recursion (Python version of the video's C++ code)."""


def fact(n):
    if n <= 1:
        return 1            # base case
    return n * fact(n - 1)  # smaller


if __name__ == "__main__":
    print(fact(4))  # 24
