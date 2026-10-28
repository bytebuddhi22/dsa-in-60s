#define DSA_TEST
#include "traversal.cpp"
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <random>
#include <stack>
#include <utility>

#define CHECK(x) if (!(x)) { printf("FAIL line %d: %s\n", __LINE__, #x); exit(1); }

// Preorder with an explicit stack (no recursion), plus each node's depth.
static vector<pair<int, int>> preorderWithDepth(Node* root) {
  vector<pair<int, int>> out;  // {depth, val}
  stack<pair<Node*, int>> st;
  if (root) st.push({root, 0});
  while (!st.empty()) {
    auto [n, d] = st.top(); st.pop();
    out.push_back({d, n->val});
    if (n->right) st.push({n->right, d + 1});
    if (n->left) st.push({n->left, d + 1});
  }
  return out;
}

static vector<int> run(void (*f)(Node*), Node* root) {
  visited.clear();
  f(root);
  return visited;
}

int main() {
  Node* root = nullptr;
  for (int x : {27, 12, 41, 5, 19, 34, 56}) root = insert(root, x);
  CHECK(run(dfs, root) == vector<int>({27, 12, 5, 19, 41, 34, 56}));
  CHECK(run(bfs, root) == vector<int>({27, 12, 41, 5, 19, 34, 56}));
  freeTree(root);
  CHECK(run(dfs, nullptr).empty());
  CHECK(run(bfs, nullptr).empty());

  mt19937 rng(11);
  for (int it = 0; it < 2000; it++) {
    Node* r = nullptr;
    int n = rng() % 25;
    for (int i = 0; i < n; i++) r = insert(r, rng() % 60);
    auto pre = preorderWithDepth(r);
    vector<int> dfsRef, bfsRef;
    for (auto [d, v] : pre) dfsRef.push_back(v);
    // BFS order = preorder, stably sorted by depth (left-to-right within each level)
    stable_sort(pre.begin(), pre.end(), [](auto& a, auto& b) { return a.first < b.first; });
    for (auto [d, v] : pre) bfsRef.push_back(v);
    CHECK(run(dfs, r) == dfsRef);
    CHECK(run(bfs, r) == bfsRef);
    freeTree(r);
  }
}
