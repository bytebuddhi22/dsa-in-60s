#define DSA_TEST
#include "min_heap.cpp"
#include <cstdio>
#include <cstdlib>
#include <random>

#define CHECK(x) if (!(x)) { printf("FAIL line %d: %s\n", __LINE__, #x); exit(1); }

static bool isHeap(const vector<int>& a) {
  for (size_t i = 1; i < a.size(); i++)
    if (a[(i - 1) / 2] > a[i]) return false;
  return true;
}

int main() {
  MinHeap h;
  for (int x : {3, 8, 5, 12, 10}) h.push(x);
  CHECK(h.a == vector<int>({3, 8, 5, 12, 10}));
  h.push(4);  // the video: 4 < 5 swap, 4 > 3 stop
  CHECK(h.a == vector<int>({3, 8, 4, 12, 10, 5}));
  CHECK(h.top() == 3);
  h.pop();    // the video: 5 goes to the top, swaps with 4
  CHECK(h.a == vector<int>({4, 8, 5, 12, 10}));
  CHECK(h.top() == 4);

  MinHeap one;
  one.push(7);
  one.pop();
  CHECK(one.empty());

  mt19937 rng(13);
  for (int it = 0; it < 2000; it++) {
    MinHeap mh;
    priority_queue<int, vector<int>, greater<int>> ref;
    for (int op = 0; op < 60; op++) {
      if (rng() % 3) {
        int x = rng() % 50;
        mh.push(x); ref.push(x);
      } else if (!ref.empty()) {
        CHECK(mh.top() == ref.top());
        mh.pop(); ref.pop();
      }
      CHECK(isHeap(mh.a));
      CHECK(mh.a.size() == ref.size());
      if (!ref.empty()) CHECK(mh.top() == ref.top());
    }
  }
}
