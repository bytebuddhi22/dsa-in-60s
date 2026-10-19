#define DSA_TEST
#include "binary_search.cpp"
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <random>

#define CHECK(x) if (!(x)) { printf("FAIL line %d: %s\n", __LINE__, #x); exit(1); }

int main() {
  CHECK(binarySearch({5, 12, 19, 27, 34, 41, 56}, 34) == 4);
  CHECK(binarySearch({5, 12, 19}, 7) == -1);
  CHECK(binarySearch({}, 1) == -1);

  // 10 lakh numbers: never more than 20 guesses
  vector<int> big(1000000);
  for (int i = 0; i < 1000000; i++) big[i] = 2 * i;
  CHECK(binarySearch(big, 2 * 777777) == 777777);
  CHECK(binarySearch(big, 3) == -1);

  mt19937 rng(1);
  for (int it = 0; it < 5000; it++) {
    vector<int> a;
    int n = rng() % 30;
    for (int i = 0; i < n; i++) a.push_back(int(rng() % 200) - 100);
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    int t = int(rng() % 220) - 110;
    auto p = find(a.begin(), a.end(), t);
    int expected = p == a.end() ? -1 : int(p - a.begin());
    CHECK(binarySearch(a, t) == expected);
  }
}
