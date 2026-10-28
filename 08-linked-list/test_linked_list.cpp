#define DSA_TEST
#include "linked_list.cpp"
#include <cstdio>
#include <cstdlib>
#include <random>

#define CHECK(x) if (!(x)) { printf("FAIL line %d: %s\n", __LINE__, #x); exit(1); }

static Node* nth(Node* head, int k) {
  while (k-- > 0) head = head->next;
  return head;
}

int main() {
  Node* head = build({5, 12, 30, 41});
  insertAfter(nth(head, 1), 19);
  CHECK(toVector(head) == vector<int>({5, 12, 19, 30, 41}));
  insertAfter(nth(head, 4), 50);  // after the last node
  CHECK(toVector(head) == vector<int>({5, 12, 19, 30, 41, 50}));
  freeList(head);

  Node* one = build({7});
  insertAfter(one, 8);
  CHECK(toVector(one) == vector<int>({7, 8}));
  freeList(one);

  mt19937 rng(8);
  for (int it = 0; it < 2000; it++) {
    int n = 1 + rng() % 12;
    vector<int> v(n);
    for (int& x : v) x = rng() % 100;
    Node* h = build(v);
    for (int ops = 0; ops < 10; ops++) {
      int k = rng() % v.size(), val = rng() % 100;
      insertAfter(nth(h, k), val);
      v.insert(v.begin() + k + 1, val);
    }
    CHECK(toVector(h) == v);
    freeList(h);
  }
}
