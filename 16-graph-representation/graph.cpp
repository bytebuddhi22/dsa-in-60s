// DSA in 60s #16: Graphs (adjacency matrix vs adjacency list)
// The body of buildAdj() is exactly the code shown in the video.
#include <utility>
#include <vector>
using namespace std;

// adjacency list: each node keeps only its neighbours. Space O(V + E)
vector<vector<int>> buildAdj(int n, const vector<pair<int, int>>& edges) {
  // nodes 0..n-1, edges: {u, v} pairs
  vector<vector<int>> adj(n);
  for (auto [u, v] : edges) {
    adj[u].push_back(v);  // u -> v
    adj[v].push_back(u);  // v -> u
  }  // undirected: every edge twice
  // adj[3] = {1, 2, 4}
  return adj;
}

// adjacency matrix: an n x n grid, 1 = edge, 0 = no edge. Space O(V^2), mat[u][v] lookup O(1)
vector<vector<int>> buildMatrix(int n, const vector<pair<int, int>>& edges) {
  vector<vector<int>> mat(n, vector<int>(n, 0));
  for (auto [u, v] : edges) mat[u][v] = mat[v][u] = 1;
  return mat;
}

#ifndef DSA_TEST
#include <iostream>
int main() {
  vector<pair<int, int>> edges = {{0, 1}, {0, 2}, {1, 3}, {2, 3}, {3, 4}};  // the video's graph
  auto adj = buildAdj(5, edges);
  for (int v : adj[3]) cout << v << " ";
  cout << "\n";  // 1 2 4
  auto mat = buildMatrix(5, edges);
  cout << mat[1][3] << " " << mat[0][4] << "\n";  // 1 0
}
#endif
