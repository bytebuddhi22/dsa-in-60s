// DSA in 60s #06: Recursion (factorial)
// The function is exactly the code shown in the video.
// Note: 20! is the largest factorial that fits in long long; fact(21) overflows.

long long fact(int n) {
  if (n <= 1) return 1;   // base case
  return n * fact(n - 1); // smaller
}

#ifndef DSA_TEST
#include <iostream>
int main() {
  std::cout << fact(4) << "\n";  // 24 = 4 x 3 x 2 x 1
}
#endif
