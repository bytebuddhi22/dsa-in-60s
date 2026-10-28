// DSA in 60s #18: Topological Sort (Kahn's algorithm)
// The body of topoSort() is exactly the code shown in the video.
#include <queue>
#include <utility>
#include <vector>
using namespace std;

// adj[u] = tasks that need u first; indeg[v] = how many tasks v waits for.
// Returns {order, cycle}. If cycle is true, not every task could be ordered. O(V + E)
pair<vector<int>, bool> topoSort(int n, const vector<vector<int>>& adj, vector<int> indeg) {
  // tasks 0..n-1, adj + indeg already built
  queue<int> q; vector<int> order;
  for (int v = 0; v < n; v++)
    if (indeg[v] == 0) q.push(v);
  while (!q.empty()) {
    int u = q.front(); q.pop();
    order.push_back(u);
    for (int v : adj[u])
      if (--indeg[v] == 0) q.push(v);
  }
  bool cycle = (int)order.size() < n;
  return {order, cycle};
}

// helper: adj + indeg from directed {u, v} edges ("u before v")
void build(int n, const vector<pair<int, int>>& edges, vector<vector<int>>& adj, vector<int>& indeg) {
  adj.assign(n, {});
  indeg.assign(n, 0);
  for (auto [u, v] : edges) {
    adj[u].push_back(v);
    indeg[v]++;
  }
}

#ifndef DSA_TEST
#include <iostream>
int main() {
  // the video: Basics=0, Arrays=1, Strings=2, DSA=3, Interview=4
  const char* name[] = {"Basics", "Arrays", "Strings", "DSA", "Interview"};
  vector<vector<int>> adj;
  vector<int> indeg;
  build(5, {{0, 1}, {0, 2}, {1, 3}, {2, 3}, {3, 4}}, adj, indeg);
  auto [order, cycle] = topoSort(5, adj, indeg);
  for (int v : order) cout << name[v] << " ";
  cout << "\n";  // Basics Arrays Strings DSA Interview
  build(5, {{0, 1}, {0, 2}, {1, 3}, {2, 3}, {3, 4}, {4, 0}}, adj, indeg);  // Interview → Basics
  cout << boolalpha << topoSort(5, adj, indeg).second << "\n";  // true: cycle
}
#endif
