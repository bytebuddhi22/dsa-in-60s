#define DSA_TEST
#include "dijkstra.cpp"
#include <cstdio>
#include <cstdlib>
#include <random>

#define CHECK(x) if (!(x)) { printf("FAIL line %d: %s\n", __LINE__, #x); exit(1); }

const long long INF = 1e18;

// Bellman-Ford: relax every edge n-1 times. O(V * E), no heap.
static vector<long long> bellmanFord(int n, const vector<vector<pair<int, int>>>& adj, int src) {
  vector<long long> dist(n, INF);
  dist[src] = 0;
  for (int round = 0; round < n - 1; round++)
    for (int u = 0; u < n; u++)
      if (dist[u] < INF)
        for (auto [v, w] : adj[u])
          if (dist[u] + w < dist[v]) dist[v] = dist[u] + w;
  return dist;
}

int main() {
  auto adj = buildGraph(5, {{0, 1, 4}, {0, 2, 1}, {1, 2, 2}, {1, 3, 1}, {2, 3, 5}, {3, 4, 3}});
  CHECK(dijkstra(5, adj, 0) == vector<long long>({0, 3, 1, 4, 7}));
  CHECK(dijkstra(5, adj, 4) == vector<long long>({7, 4, 6, 3, 0}));

  auto apart = buildGraph(3, {{0, 1, 5}});  // node 2 can't be reached
  CHECK(dijkstra(3, apart, 0) == vector<long long>({0, 5, INF}));
  auto zero = buildGraph(2, {{0, 1, 0}});
  CHECK(dijkstra(2, zero, 0) == vector<long long>({0, 0}));

  mt19937 rng(17);
  for (int it = 0; it < 2000; it++) {
    int n = 1 + rng() % 9;
    vector<vector<int>> es;
    int m = rng() % 20;
    for (int k = 0; k < m; k++) es.push_back({(int)(rng() % n), (int)(rng() % n), (int)(rng() % 10)});
    auto g = buildGraph(n, es);
    int src = rng() % n;
    CHECK(dijkstra(n, g, src) == bellmanFord(n, g, src));
  }
}
