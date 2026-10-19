#define DSA_TEST
#include "two_pointers.cpp"
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <random>

#define CHECK(x) if (!(x)) { printf("FAIL line %d: %s\n", __LINE__, #x); exit(1); }

int main() {
  CHECK(pairWithSum({4, 12, 17, 23, 30, 36, 52}, 48) == make_pair(12, 36));
  CHECK(pairWithSum({1, 2, 3}, 100) == make_pair(-1, -1));
  CHECK(pairWithSum({}, 0) == make_pair(-1, -1));

  mt19937 rng(2);
  for (int it = 0; it < 3000; it++) {
    vector<int> a;
    int n = rng() % 20;
    for (int i = 0; i < n; i++) a.push_back(int(rng() % 101) - 50);
    sort(a.begin(), a.end());
    int t = int(rng() % 201) - 100;
    bool exists = false;
    for (int i = 0; i < n; i++)
      for (int j = i + 1; j < n; j++) exists |= a[i] + a[j] == t;
    auto [x, y] = pairWithSum(a, t);
    if (exists) { CHECK(x + y == t); }
    else { CHECK(x == -1 && y == -1); }
  }
}
