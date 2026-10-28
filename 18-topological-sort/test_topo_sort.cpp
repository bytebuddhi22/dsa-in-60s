#define DSA_TEST
#include "topo_sort.cpp"
#include <cstdio>
#include <cstdlib>
#include <functional>
#include <random>

#define CHECK(x) if (!(x)) { printf("FAIL line %d: %s\n", __LINE__, #x); exit(1); }

// DFS with colours: reaching a grey (in progress) node again means a cycle.
static bool hasCycle(int n, const vector<vector<int>>& adj) {
  vector<int> colour(n, 0);  // 0 new, 1 in progress, 2 done
  function<bool(int)> go = [&](int u) {
    colour[u] = 1;
    for (int v : adj[u])
      if (colour[v] == 1 || (colour[v] == 0 && go(v))) return true;
    colour[u] = 2;
    return false;
  };
  for (int u = 0; u < n; u++)
    if (colour[u] == 0 && go(u)) return true;
  return false;
}

int main() {
  vector<vector<int>> adj;
  vector<int> indeg;
  build(5, {{0, 1}, {0, 2}, {1, 3}, {2, 3}, {3, 4}}, adj, indeg);
  auto [order, cycle] = topoSort(5, adj, indeg);
  CHECK(order == vector<int>({0, 1, 2, 3, 4}) && !cycle);
  CHECK(indeg == vector<int>({0, 1, 1, 2, 1}));  // the video's indeg, left unchanged

  build(5, {{0, 1}, {0, 2}, {1, 3}, {2, 3}, {3, 4}, {4, 0}}, adj, indeg);
  auto [o2, c2] = topoSort(5, adj, indeg);
  CHECK(c2 && o2.empty());  // the video: 0 of 5 nodes come out

  build(3, {}, adj, indeg);
  CHECK(topoSort(3, adj, indeg).first == vector<int>({0, 1, 2}));

  mt19937 rng(18);
  for (int it = 0; it < 3000; it++) {
    int n = 1 + rng() % 9;
    vector<pair<int, int>> es;
    int m = rng() % 14;
    bool dagOnly = rng() % 2;  // half the time only forward edges → guaranteed DAG
    for (int k = 0; k < m; k++) {
      int u = rng() % n, v = rng() % n;
      if (dagOnly && u >= v) continue;
      es.push_back({u, v});
    }
    build(n, es, adj, indeg);
    auto [ord, cyc] = topoSort(n, adj, indeg);
    CHECK(cyc == hasCycle(n, adj));
    if (!cyc) {
      vector<int> pos(n, -1);
      for (int i = 0; i < (int)ord.size(); i++) pos[ord[i]] = i;
      CHECK((int)ord.size() == n);
      for (int v = 0; v < n; v++) CHECK(pos[v] >= 0);
      for (auto [u, v] : es) CHECK(pos[u] < pos[v]);  // every "u before v" respected
    }
  }
}
