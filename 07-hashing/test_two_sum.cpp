#define DSA_TEST
#include "two_sum.cpp"
#include <cstdio>
#include <cstdlib>
#include <random>

#define CHECK(x) if (!(x)) { printf("FAIL line %d: %s\n", __LINE__, #x); exit(1); }

// Smallest i that has some j < i with a[j] + a[i] == target, or -1. O(n^2)
static int firstPairEnd(const vector<int>& a, int target) {
  for (int i = 0; i < (int)a.size(); i++)
    for (int j = 0; j < i; j++)
      if (a[j] + a[i] == target) return i;
  return -1;
}

int main() {
  CHECK(twoSum({8, 3, 16, 6, 12}, 20) == make_pair(0, 4));
  CHECK(twoSum({1, 2, 3}, 100) == make_pair(-1, -1));
  CHECK(twoSum({}, 5) == make_pair(-1, -1));
  CHECK(twoSum({5}, 10) == make_pair(-1, -1));  // can't use 5 twice
  CHECK(twoSum({5, 5}, 10) == make_pair(0, 1));
  CHECK(twoSum({-3, 4, 3, 90}, 0) == make_pair(0, 2));

  mt19937 rng(7);
  for (int it = 0; it < 5000; it++) {
    int n = rng() % 15;
    vector<int> a(n);
    for (int& x : a) x = (int)(rng() % 21) - 10;
    int target = (int)(rng() % 41) - 20;
    auto [j, i] = twoSum(a, target);
    int end = firstPairEnd(a, target);
    CHECK(i == end);
    if (end == -1) {
      CHECK(j == -1);
    } else {
      CHECK(0 <= j && j < i && a[j] + a[i] == target);
    }
  }
}
