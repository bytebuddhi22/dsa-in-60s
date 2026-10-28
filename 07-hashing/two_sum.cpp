// DSA in 60s #07: Hashing (Two Sum, LeetCode 1)
// The function body is exactly the code shown in the video.
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;

// indices {j, i} with j < i and a[j] + a[i] == target, or {-1, -1}. O(n) average
pair<int, int> twoSum(const vector<int>& a, int target) {
  int n = a.size();
  unordered_map<int,int> seen;
  for (int i = 0; i < n; i++) {
    int need = target - a[i];
    if (seen.count(need))
      return {seen[need], i};
    seen[a[i]] = i;   // store
  }
  return {-1, -1};   // no pair
}

#ifndef DSA_TEST
#include <iostream>
int main() {
  auto [j, i] = twoSum({8, 3, 16, 6, 12}, 20);
  cout << j << " " << i << "\n";  // 0 4: 8 + 12 = 20
  auto [x, y] = twoSum({1, 2, 3}, 100);
  cout << x << " " << y << "\n";  // -1 -1: no pair
}
#endif
