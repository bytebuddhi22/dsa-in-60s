// DSA in 60s #03: Sliding Window (maximum sum of k consecutive numbers)
// The function body is exactly the code shown in the video.
#include <algorithm>
#include <vector>
using namespace std;

// Max sum of any k consecutive elements (1 <= k <= n). O(n)
long long maxWindowSum(const vector<int>& a, int k) {
  int n = a.size();
  long long sum = 0;
  for (int i = 0; i < k; i++) sum += a[i];
  long long best = sum;
  for (int i = k; i < n; i++) {
    sum += a[i];  sum -= a[i - k];
    best = max(best, sum);
  }
  return best;   // 1 <= k <= n
}

#ifndef DSA_TEST
#include <iostream>
int main() {
  vector<int> a = {2, 1, 5, 1, 3, 2};
  cout << maxWindowSum(a, 3) << "\n";  // 9 (window 5, 1, 3)
}
#endif
