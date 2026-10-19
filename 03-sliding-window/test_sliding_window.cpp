#define DSA_TEST
#include "sliding_window.cpp"
#include <climits>
#include <cstdio>
#include <cstdlib>
#include <random>

#define CHECK(x) if (!(x)) { printf("FAIL line %d: %s\n", __LINE__, #x); exit(1); }

int main() {
  CHECK(maxWindowSum({2, 1, 5, 1, 3, 2}, 3) == 9);
  CHECK(maxWindowSum({4, -1, 2}, 3) == 5);
  CHECK(maxWindowSum({4, -1, 7}, 1) == 7);

  mt19937 rng(3);
  for (int it = 0; it < 3000; it++) {
    int n = 1 + rng() % 25;
    vector<int> a(n);
    for (int& x : a) x = int(rng() % 101) - 50;
    int k = 1 + rng() % n;
    int expected = INT_MIN;
    for (int i = 0; i + k <= n; i++) {
      int s = 0;
      for (int j = i; j < i + k; j++) s += a[j];
      expected = max(expected, s);
    }
    CHECK(maxWindowSum(a, k) == expected);
  }
}
