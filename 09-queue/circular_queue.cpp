// DSA in 60s #09: Queue (FIFO) + the Circular Queue trick
// main() opens with the STL queue code shown in the video; CircularQueue is the ring from the video.
#include <queue>
#include <vector>
using namespace std;

// Fixed-size queue on an array. front and rear wrap around with % N, so nothing ever shifts.
struct CircularQueue {
  vector<int> buf;
  int front = 0, rear, size = 0;
  explicit CircularQueue(int N) : buf(N), rear(N - 1) {}
  bool empty() const { return size == 0; }
  bool full() const { return size == (int)buf.size(); }
  // enqueue at rear, O(1). Caller checks !full()
  void push(int x) {
    int N = buf.size();
    rear = (rear + 1) % N;  // ring: rear = (rear + 1) % N
    buf[rear] = x;
    size++;
  }
  int peek() const { return buf[front]; }
  // dequeue from front, O(1). Caller checks !empty()
  void pop() {
    int N = buf.size();
    front = (front + 1) % N;
    size--;
  }
};

#ifndef DSA_TEST
#include <iostream>
int main() {
  queue<int> q;
  q.push(7);     // enqueue at rear
  q.push(9);
  cout << q.front() << "\n";  // 7
  q.pop();       // dequeue from front
  cout << q.front() << "\n";  // 9

  CircularQueue cq(5);  // the ring from the video: A B C in, A B out, D E F in
  for (int x : {1, 2, 3}) cq.push(x);
  cq.pop(); cq.pop();
  for (int x : {4, 5, 6}) cq.push(x);  // 6 wraps around to slot 0
  while (!cq.empty()) { cout << cq.peek() << " "; cq.pop(); }
  cout << "\n";  // 3 4 5 6
}
#endif
