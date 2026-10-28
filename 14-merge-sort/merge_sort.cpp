// DSA in 60s #14: Merge Sort
// mergeSort() is exactly the code shown in the video. Sort a[lo..hi], both ends included.
#include <algorithm>
#include <vector>
using namespace std;

// split in half, sort each half, join the 2 sorted halves. O(n log n), stable, O(n) extra space
// inplace_merge joins 2 sorted halves
void mergeSort(vector<int>& a,
               int lo, int hi) {
  if (hi - lo < 1) return; // 0/1 item
  int mid = lo + (hi - lo) / 2;
  mergeSort(a, lo, mid);       // left
  mergeSort(a, mid + 1, hi);  // right
  inplace_merge(a.begin() + lo,
    a.begin() + mid + 1,
    a.begin() + hi + 1);  // join
}

#ifndef DSA_TEST
#include <iostream>
int main() {
  vector<int> a = {38, 27, 43, 3, 9, 82, 10, 5};  // the video's array
  mergeSort(a, 0, a.size() - 1);
  for (int x : a) cout << x << " ";
  cout << "\n";  // 3 5 9 10 27 38 43 82
}
#endif
