#define DSA_TEST
#include "circular_queue.cpp"
#include <cstdio>
#include <cstdlib>
#include <random>

#define CHECK(x) if (!(x)) { printf("FAIL line %d: %s\n", __LINE__, #x); exit(1); }

int main() {
  CircularQueue cq(5);
  for (int x : {1, 2, 3}) cq.push(x);
  CHECK(cq.peek() == 1);
  cq.pop(); cq.pop();
  for (int x : {4, 5, 6}) cq.push(x);
  CHECK(cq.rear == 0);  // 6 wrapped around to slot 0, as in the video
  CHECK(cq.front == 2);
  vector<int> out;
  while (!cq.empty()) { out.push_back(cq.peek()); cq.pop(); }
  CHECK(out == vector<int>({3, 4, 5, 6}));

  CircularQueue one(1);
  CHECK(one.empty() && !one.full());
  one.push(42);
  CHECK(one.full() && one.peek() == 42);

  mt19937 rng(9);
  for (int it = 0; it < 2000; it++) {
    int N = 1 + rng() % 8;
    CircularQueue c(N);
    queue<int> ref;
    for (int op = 0; op < 60; op++) {
      if (rng() % 2 && !c.full()) {
        int x = rng() % 100;
        c.push(x); ref.push(x);
      } else if (!c.empty()) {
        CHECK(c.peek() == ref.front());
        c.pop(); ref.pop();
      }
      CHECK(c.size == (int)ref.size());
      CHECK(c.empty() == ref.empty());
      CHECK(c.full() == ((int)ref.size() == N));
    }
  }
}
