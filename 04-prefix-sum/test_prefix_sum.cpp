#define DSA_TEST
#include "prefix_sum.cpp"
#include <cstdio>
#include <cstdlib>
#include <random>

#define CHECK(x) if (!(x)) { printf("FAIL line %d: %s\n", __LINE__, #x); exit(1); }

int main() {
  vector<long long> P = buildPrefix({3, 1, 4, 1, 5, 9, 2});
  CHECK(P == vector<long long>({0, 3, 4, 8, 9, 14, 23, 25}));
  CHECK(rangeSum(P, 2, 5) == 19);

  // long long: 1 lakh values of 10^9 doesn't overflow
  vector<int> big(100000, 1000000000);
  CHECK(rangeSum(buildPrefix(big), 0, 99999) == 100000LL * 1000000000LL);

  mt19937 rng(4);
  for (int it = 0; it < 500; it++) {
    int n = 1 + rng() % 40;
    vector<int> arr(n);
    for (int& x : arr) x = int(rng() % 201) - 100;
    vector<long long> Q = buildPrefix(arr);
    for (int q = 0; q < 20; q++) {
      int L = rng() % n, R = L + rng() % (n - L);
      long long expected = 0;
      for (int i = L; i <= R; i++) expected += arr[i];
      CHECK(rangeSum(Q, L, R) == expected);
    }
  }
}
