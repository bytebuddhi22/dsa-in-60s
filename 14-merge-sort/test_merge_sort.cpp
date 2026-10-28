#define DSA_TEST
#include "merge_sort.cpp"
#include <cstdio>
#include <cstdlib>
#include <random>

#define CHECK(x) if (!(x)) { printf("FAIL line %d: %s\n", __LINE__, #x); exit(1); }

int main() {
  vector<int> a = {38, 27, 43, 3, 9, 82, 10, 5};
  mergeSort(a, 0, a.size() - 1);
  CHECK(a == vector<int>({3, 5, 9, 10, 27, 38, 43, 82}));

  vector<int> empty;
  mergeSort(empty, 0, -1);
  CHECK(empty.empty());
  vector<int> one = {7};
  mergeSort(one, 0, 0);
  CHECK(one == vector<int>({7}));

  vector<int> part = {9, 8, 7, 6, 5};  // only sort the middle three
  mergeSort(part, 1, 3);
  CHECK(part == vector<int>({9, 6, 7, 8, 5}));

  mt19937 rng(14);
  for (int it = 0; it < 3000; it++) {
    int n = rng() % 40;
    vector<int> v(n);
    for (int& x : v) x = (int)(rng() % 41) - 20;
    vector<int> ref = v;
    sort(ref.begin(), ref.end());
    mergeSort(v, 0, n - 1);
    CHECK(v == ref);
  }
}
