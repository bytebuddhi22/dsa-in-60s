// DSA in 60s #13: Min-Heap
// main() opens with exactly the priority_queue code shown in the video.
// MinHeap below is the same idea built by hand on an array (children 2i+1, 2i+2, parent (i-1)/2).
#include <queue>
#include <utility>
#include <vector>
using namespace std;

struct MinHeap {
  vector<int> a;
  bool empty() const { return a.empty(); }
  int top() const { return a[0]; }  // smallest, O(1)
  // add at the end, swap up while smaller than the parent. O(log n)
  void push(int x) {
    a.push_back(x);
    int i = a.size() - 1;
    while (i > 0 && a[i] < a[(i - 1) / 2]) {
      swap(a[i], a[(i - 1) / 2]);
      i = (i - 1) / 2;
    }
  }
  // move the last item to the top, swap down with the smaller child. O(log n)
  void pop() {
    a[0] = a.back();
    a.pop_back();
    int i = 0, n = a.size();
    while (true) {
      int l = 2 * i + 1, r = 2 * i + 2, m = i;
      if (l < n && a[l] < a[m]) m = l;
      if (r < n && a[r] < a[m]) m = r;
      if (m == i) break;
      swap(a[i], a[m]);
      i = m;
    }
  }
};

#ifndef DSA_TEST
#include <iostream>
int main() {
  // default priority_queue = max-heap
  priority_queue<int, vector<int>,
      greater<int>> pq;   // min-heap
  for (int x : {3,8,5,12,10}) pq.push(x);
  pq.push(4);                 // O(log n)
  int smallest = pq.top();  // 3, O(1)
  pq.pop();                   // O(log n)
  cout << smallest << " " << pq.top() << "\n";  // 3 4

  MinHeap h;
  for (int x : {3, 8, 5, 12, 10}) h.push(x);
  h.push(4);
  for (int x : h.a) cout << x << " ";
  cout << "\n";  // 3 8 4 12 10 5: 4 swapped up once, as in the video
}
#endif
