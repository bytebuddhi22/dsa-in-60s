// DSA in 60s #12: Dynamic Programming (Fibonacci)
// memo and fib() are exactly the code shown in the video (trick 1: memoization).
#include <vector>
using namespace std;

long long memo[51] = {0, 1};  // n <= 50
// each fib(n) is computed once, then read from memo. O(n) instead of O(2^n)
long long fib(int n) {
  if (n <= 1) return n;
  if (memo[n]) return memo[n]; // hit
  return memo[n] = fib(n-1) + fib(n-2);
}

// trick 2: tabulation, the same table filled with a loop instead of recursion. O(n)
long long fibTable(int n) {
  vector<long long> dp(n + 2);
  dp[1] = 1;
  for (int i = 2; i <= n; i++) dp[i] = dp[i - 1] + dp[i - 2];
  return dp[n];
}

#ifndef DSA_TEST
#include <iostream>
int main() {
  cout << fib(50) << "\n";       // 12586269025, with only 99 calls
  cout << fibTable(50) << "\n";  // 12586269025
  cout << fib(10) << "\n";       // 55 (straight from memo)
}
#endif
