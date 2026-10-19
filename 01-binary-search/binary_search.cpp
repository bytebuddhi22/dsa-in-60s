// DSA in 60s #01: Binary Search
// The function body is exactly the code shown in the video.
#include <vector>
using namespace std;

// Index of target in sorted array a, or -1. O(log n)
int binarySearch(const vector<int>& a, int target) {
  int n = a.size();
  int lo = 0, hi = n - 1;
  while (lo <= hi) {
    int mid = lo + (hi - lo) / 2;
    if (a[mid] == target) return mid;
    if (a[mid] < target) lo = mid + 1;
    else hi = mid - 1;
  }
  return -1;  // not found
}

#ifndef DSA_TEST
#include <iostream>
int main() {
  vector<int> a = {5, 12, 19, 27, 34, 41, 56};
  cout << binarySearch(a, 34) << "\n";  // 4 (found in 3 steps)
}
#endif
