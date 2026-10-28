#define DSA_TEST
#include "bst_search.cpp"
#include <cstdio>
#include <cstdlib>
#include <random>
#include <set>

#define CHECK(x) if (!(x)) { printf("FAIL line %d: %s\n", __LINE__, #x); exit(1); }

int main() {
  Node* root = nullptr;
  for (int x : {27, 12, 41, 5, 19, 34, 56}) root = insert(root, x);
  Node* hit = search(root, 34);
  CHECK(hit && hit->val == 34);
  CHECK(search(root, 30) == nullptr);
  CHECK(height(root) == 2);
  freeTree(root);

  CHECK(search(nullptr, 5) == nullptr);

  Node* skewed = nullptr;  // sorted inserts → a 7-node chain, height 6
  for (int x : {5, 12, 19, 27, 34, 41, 56}) skewed = insert(skewed, x);
  CHECK(height(skewed) == 6);
  CHECK(search(skewed, 56) && search(skewed, 56)->val == 56);
  freeTree(skewed);

  mt19937 rng(10);
  for (int it = 0; it < 2000; it++) {
    Node* r = nullptr;
    set<int> ref;
    int n = rng() % 30;
    for (int i = 0; i < n; i++) {
      int x = rng() % 50;
      r = insert(r, x);
      ref.insert(x);
    }
    for (int x = -1; x <= 50; x++) {
      Node* f = search(r, x);
      CHECK((f != nullptr) == (ref.count(x) == 1));
      if (f) CHECK(f->val == x);
    }
    freeTree(r);
  }
}
