#define DSA_TEST
#include "quick_sort.cpp"
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <random>

#define CHECK(x) if (!(x)) { printf("FAIL line %d: %s\n", __LINE__, #x); exit(1); }

int main() {
  vector<int> b = {7, 2, 9, 4, 3, 8, 5};
  CHECK(partition(b, 0, 6) == 3);  // the video: 5 → index 3, FINAL
  CHECK(b == vector<int>({2, 4, 3, 5, 9, 8, 7}));

  vector<int> a = {7, 2, 9, 4, 3, 8, 5};
  quickSort(a, 0, a.size() - 1);
  CHECK(a == vector<int>({2, 3, 4, 5, 7, 8, 9}));

  vector<int> empty;
  quickSort(empty, 0, -1);
  CHECK(empty.empty());
  vector<int> sorted500(500);  // worst case: already sorted input
  for (int i = 0; i < 500; i++) sorted500[i] = i;
  vector<int> s = sorted500;
  quickSort(s, 0, s.size() - 1);
  CHECK(s == sorted500);

  mt19937 rng(15);
  for (int it = 0; it < 3000; it++) {
    int n = rng() % 40;
    vector<int> v(n);
    for (int& x : v) x = (int)(rng() % 41) - 20;
    vector<int> ref = v;
    sort(ref.begin(), ref.end());
    if (n > 0) {  // partition puts the pivot in its sorted spot
      vector<int> w = v;
      int p = partition(w, 0, n - 1);
      for (int i = 0; i < p; i++) CHECK(w[i] < w[p]);
      for (int i = p + 1; i < n; i++) CHECK(w[i] >= w[p]);
    }
    quickSort(v, 0, n - 1);
    CHECK(v == ref);
  }
}
