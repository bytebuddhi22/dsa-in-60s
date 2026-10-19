// DSA in 60s #02: Two Pointers (pair with a given sum in a sorted array)
// The function body is exactly the code shown in the video.
#include <utility>
#include <vector>
using namespace std;

// Two values in sorted array a that add up to target, or {-1, -1}. O(n)
pair<int, int> pairWithSum(const vector<int>& a, int target) {
  int n = a.size();
  int left = 0, right = n - 1;
  while (left < right) {
    int sum = a[left] + a[right];
    if (sum == target) return {a[left], a[right]};
    if (sum > target) right--;
    else left++;
  }
  return {-1, -1};  // no pair
}

#ifndef DSA_TEST
#include <iostream>
int main() {
  vector<int> a = {4, 12, 17, 23, 30, 36, 52};
  auto [x, y] = pairWithSum(a, 48);
  cout << x << " + " << y << "\n";  // 12 + 36 (found in 3 steps)
}
#endif
