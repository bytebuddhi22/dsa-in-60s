// DSA in 60s #15: Quick Sort
// partition() and quickSort() are exactly the code shown in the video. Sort a[low..high].
#include <utility>
#include <vector>
using namespace std;

// pivot = last item; everything smaller goes left of it. Returns the pivot's final index
int partition(vector<int>& a, int low, int high) {
  int pivot = a[high], i = low - 1;  // last item
  for (int j = low; j < high; j++)
    if (a[j] < pivot) swap(a[++i], a[j]);
  swap(a[i + 1], a[high]);  // pivot -> final spot
  return i + 1;
}

// in place, average O(n log n), worst O(n^2) (sorted input), not stable
void quickSort(vector<int>& a, int low, int high) {
  if (low >= high) return;
  int p = partition(a, low, high);
  quickSort(a, low, p - 1);
  quickSort(a, p + 1, high);
}

#ifndef DSA_TEST
#include <iostream>
int main() {
  vector<int> a = {7, 2, 9, 4, 3, 8, 5};  // the video's array, pivot 5
  vector<int> b = a;
  cout << partition(b, 0, b.size() - 1) << "\n";  // 3: 5 lands at index 3
  for (int x : b) cout << x << " ";
  cout << "\n";  // 2 4 3 5 9 8 7
  quickSort(a, 0, a.size() - 1);
  for (int x : a) cout << x << " ";
  cout << "\n";  // 2 3 4 5 7 8 9
}
#endif
