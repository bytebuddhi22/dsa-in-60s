// DSA in 60s #11: BFS vs DFS on a binary tree
// dfs() and the body of bfs() are exactly the code shown in the video.
#include <queue>
#include <vector>
using namespace std;

struct Node {  // same Node as #10
  int val;
  Node *left, *right;
};

vector<int> visited;  // visit order
void visit(Node* n) { visited.push_back(n->val); }

// DFS: go deep first, back up at a dead end. The call stack is the stack. O(n)
void dfs(Node* n) {  // recursion
  if (!n) return;
  visit(n); dfs(n->left); dfs(n->right);
}

// BFS: level by level, using a queue. O(n)
void bfs(Node* root) {
  queue<Node*> q; if (root) q.push(root);
  while (!q.empty()) {   // bfs
    Node* n = q.front(); q.pop(); visit(n);
    if (n->left) q.push(n->left);
    if (n->right) q.push(n->right);
  }
}

// helpers for the demo and tests
Node* insert(Node* root, int x) {  // BST insert, duplicates ignored
  if (!root) return new Node{x, nullptr, nullptr};
  if (x < root->val) root->left = insert(root->left, x);
  else if (x > root->val) root->right = insert(root->right, x);
  return root;
}

void freeTree(Node* root) {
  if (!root) return;
  freeTree(root->left);
  freeTree(root->right);
  delete root;
}

#ifndef DSA_TEST
#include <iostream>
int main() {
  Node* root = nullptr;
  for (int x : {27, 12, 41, 5, 19, 34, 56}) root = insert(root, x);  // the video's tree
  dfs(root);
  for (int v : visited) cout << v << " ";
  cout << "\n";  // 27 12 5 19 41 34 56
  visited.clear();
  bfs(root);
  for (int v : visited) cout << v << " ";
  cout << "\n";  // 27 12 41 5 19 34 56
  freeTree(root);
}
#endif
