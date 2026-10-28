"""DSA in 60s #12: Dynamic Programming, Fibonacci (Python version of the video's C++ code)."""

memo = [0] * 51  # n <= 50
memo[1] = 1


def fib(n):
    """Trick 1, memoization: each fib(n) is computed once, then read from memo. O(n)"""
    if n <= 1:
        return n
    if memo[n]:
        return memo[n]  # hit
    memo[n] = fib(n - 1) + fib(n - 2)
    return memo[n]


def fib_table(n):
    """Trick 2, tabulation: the same table filled with a loop instead of recursion. O(n)"""
    dp = [0] * (n + 2)
    dp[1] = 1
    for i in range(2, n + 1):
        dp[i] = dp[i - 1] + dp[i - 2]
    return dp[n]


if __name__ == "__main__":
    print(fib(50))        # 12586269025, with only 99 calls
    print(fib_table(50))  # 12586269025
