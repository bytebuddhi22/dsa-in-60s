// DSA in 60s #17: Dijkstra (shortest path, weights >= 0)
// The body of dijkstra() is exactly the code shown in the video.
#include <queue>
#include <utility>
#include <vector>
using namespace std;

// adj[u] = {v, w} pairs. Returns the shortest distance from src to every node (INF = unreachable).
// O((V + E) log V) with the min-heap from #13
vector<long long> dijkstra(int n, const vector<vector<pair<int, int>>>& adj, int src) {
  const long long INF = 1e18;   // w >= 0
  vector<long long> dist(n, INF);
  dist[src] = 0;
  using P = pair<long long, int>; // {dist, node}
  priority_queue<P, vector<P>, greater<P>> pq;
  pq.push({0, src});
  while (!pq.empty()) {
    auto [d, u] = pq.top(); pq.pop();
    if (d > dist[u]) continue;  // purani entry
    for (auto [v, w] : adj[u])  // adj[u]: {v, w}
      if (d + w < dist[v]) {
        dist[v] = d + w; pq.push({dist[v], v});
      }
  }
  return dist;
}

// helper: undirected weighted graph from {u, v, w} triples
vector<vector<pair<int, int>>> buildGraph(int n, const vector<vector<int>>& edges) {
  vector<vector<pair<int, int>>> adj(n);
  for (auto& e : edges) {
    adj[e[0]].push_back({e[1], e[2]});
    adj[e[1]].push_back({e[0], e[2]});
  }
  return adj;
}

#ifndef DSA_TEST
#include <iostream>
int main() {
  // the video's map: A=0 B=1 C=2 D=3 E=4
  auto adj = buildGraph(5, {{0, 1, 4}, {0, 2, 1}, {1, 2, 2}, {1, 3, 1}, {2, 3, 5}, {3, 4, 3}});
  for (long long d : dijkstra(5, adj, 0)) cout << d << " ";
  cout << "\n";  // 0 3 1 4 7: A→C→B→D→E = 1+2+1+3 = 7 km (BFS's 3-road route is 8 km)
}
#endif
