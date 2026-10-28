"""DSA in 60s #16: Graphs, adjacency list vs matrix (Python version of the video's C++ code)."""


def build_adj(n, edges):
    """Adjacency list for nodes 0..n-1 and undirected {u, v} edges. Space O(V + E)"""
    adj = [[] for _ in range(n)]
    for u, v in edges:
        adj[u].append(v)  # u -> v
        adj[v].append(u)  # v -> u
    return adj  # undirected: every edge twice


def build_matrix(n, edges):
    """n x n grid, 1 = edge, 0 = no edge. Space O(V^2)"""
    mat = [[0] * n for _ in range(n)]
    for u, v in edges:
        mat[u][v] = mat[v][u] = 1
    return mat


if __name__ == "__main__":
    edges = [(0, 1), (0, 2), (1, 3), (2, 3), (3, 4)]  # the video's graph
    print(build_adj(5, edges)[3])  # [1, 2, 4]
    mat = build_matrix(5, edges)
    print(mat[1][3], mat[0][4])    # 1 0
