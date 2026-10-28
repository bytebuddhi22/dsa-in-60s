// DSA in 60s #10: Binary Search Tree (search)
// Node and search() are exactly the code shown in the video.
#include <vector>
using namespace std;

struct Node {
  int val;
  Node *left, *right;
};

// smaller → go left, bigger → go right. O(h): O(log n) if balanced, O(n) if skewed
Node* search(Node* cur, int x) {
  while (cur && cur->val != x)
    cur = x < cur->val ? cur->left
                       : cur->right;
  return cur;   // found or null
}

// helpers for the demo and tests
Node* insert(Node* root, int x) {  // duplicates are ignored
  if (!root) return new Node{x, nullptr, nullptr};
  if (x < root->val) root->left = insert(root->left, x);
  else if (x > root->val) root->right = insert(root->right, x);
  return root;
}

int height(Node* root) {  // edges on the longest root-to-leaf path; empty tree = -1
  if (!root) return -1;
  int l = height(root->left), r = height(root->right);
  return 1 + (l > r ? l : r);
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
  cout << (search(root, 34) ? "found" : "null") << "\n";  // found, in 3 steps: 27 → 41 → 34
  cout << (search(root, 30) ? "found" : "null") << "\n";  // null
  cout << height(root) << "\n";                           // 2 (balanced)
  freeTree(root);
}
#endif
