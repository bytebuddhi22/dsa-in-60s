// DSA in 60s #04: Prefix Sum (range-sum queries in O(1))
// The two function bodies are exactly the code shown in the video.
#include <vector>
using namespace std;

// Build once: P[i] = arr[0] + ... + arr[i-1]. O(n)
vector<long long> buildPrefix(const vector<int>& arr) {
  int n = arr.size();
  vector<long long> P(n + 1, 0);
  for (int i = 0; i < n; i++)
    P[i + 1] = P[i] + arr[i];
  return P;
}

// Each query: sum of arr[L..R] (inclusive). O(1)
long long rangeSum(const vector<long long>& P, int L, int R) {
  // range sum of arr[L..R]:
  long long sum = P[R + 1] - P[L];
  return sum;
}

#ifndef DSA_TEST
#include <iostream>
int main() {
  vector<int> arr = {3, 1, 4, 1, 5, 9, 2};
  vector<long long> P = buildPrefix(arr);  // 0 3 4 8 9 14 23 25
  cout << rangeSum(P, 2, 5) << "\n";       // 19 = P[6] - P[2] = 23 - 4
}
#endif
