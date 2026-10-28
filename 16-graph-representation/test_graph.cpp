#define DSA_TEST
#include "graph.cpp"
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <random>
#include <set>

#define CHECK(x) if (!(x)) { printf("FAIL line %d: %s\n", __LINE__, #x); exit(1); }

int main() {
  vector<pair<int, int>> edges = {{0, 1}, {0, 2}, {1, 3}, {2, 3}, {3, 4}};
  auto adj = buildAdj(5, edges);
  CHECK(adj[3] == vector<int>({1, 2, 4}));
  CHECK(adj[0] == vector<int>({1, 2}));
  CHECK(adj[4] == vector<int>({3}));
  size_t entries = 0;
  for (auto& l : adj) entries += l.size();
  CHECK(entries == 10);  // 5 edges x 2
  auto mat = buildMatrix(5, edges);
  int ones = 0;
  for (auto& row : mat) for (int c : row) ones += c;
  CHECK(ones == 10);  // 25 cells = 10 ones + 15 zeros
  CHECK(mat[1][3] == 1 && mat[3][1] == 1 && mat[0][4] == 0);

  CHECK(buildAdj(3, {}) == vector<vector<int>>(3));

  mt19937 rng(16);
  for (int it = 0; it < 2000; it++) {
    int n = 1 + rng() % 10;
    set<pair<int, int>> chosen;  // simple graph: no loops, no repeated edges
    vector<pair<int, int>> es;
    for (int k = 0; k < 15; k++) {
      int u = rng() % n, v = rng() % n;
      if (u == v || chosen.count({min(u, v), max(u, v)})) continue;
      chosen.insert({min(u, v), max(u, v)});
      es.push_back({u, v});
    }
    auto a = buildAdj(n, es);
    auto m = buildMatrix(n, es);
    size_t total = 0;
    for (int u = 0; u < n; u++) {
      vector<int> fromMatrix;
      for (int v = 0; v < n; v++) if (m[u][v]) fromMatrix.push_back(v);
      vector<int> fromList = a[u];
      sort(fromList.begin(), fromList.end());
      CHECK(fromList == fromMatrix);
      total += a[u].size();
    }
    CHECK(total == 2 * es.size());
  }
}
