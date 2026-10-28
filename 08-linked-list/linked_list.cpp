// DSA in 60s #08: Linked List (insert after a node)
// insertAfter's body is the code shown in the video, which uses value = 19.
#include <vector>
using namespace std;

struct Node { int value; Node* next; };

// insert value right after node p (p != null). O(1): only 2 pointers change
void insertAfter(Node* p, int value) {
  Node* n = new Node{value, p->next};
  p->next = n;
}

// helpers for the demo and tests
Node* build(const vector<int>& v) {
  Node* head = nullptr;
  for (int i = (int)v.size() - 1; i >= 0; i--) head = new Node{v[i], head};
  return head;
}

vector<int> toVector(Node* head) {
  vector<int> out;
  for (Node* cur = head; cur != nullptr; cur = cur->next) out.push_back(cur->value);
  return out;
}

void freeList(Node* head) {
  while (head != nullptr) { Node* next = head->next; delete head; head = next; }
}

#ifndef DSA_TEST
#include <iostream>
int main() {
  Node* head = build({5, 12, 30, 41});
  insertAfter(head->next, 19);  // after 12
  for (int x : toVector(head)) cout << x << " ";
  cout << "\n";  // 5 12 19 30 41
  freeList(head);
}
#endif
