#define DSA_TEST
#include "fib_dp.cpp"
#include <cstdio>
#include <cstdlib>

#define CHECK(x) if (!(x)) { printf("FAIL line %d: %s\n", __LINE__, #x); exit(1); }

static long long calls = 0;
static long long naive(int n) {  // plain recursion, no memo. O(2^n)
  calls++;
  return n <= 1 ? n : naive(n - 1) + naive(n - 2);
}

int main() {
  CHECK(fib(50) == 12586269025LL);
  CHECK(fibTable(50) == 12586269025LL);
  CHECK(fib(0) == 0 && fib(1) == 1 && fib(2) == 1 && fib(10) == 55);
  CHECK(fibTable(0) == 0 && fibTable(1) == 1);

  long long a = 0, b = 1;  // iterative reference
  for (int n = 0; n <= 50; n++) {
    CHECK(fib(n) == a);
    CHECK(fibTable(n) == a);
    long long c = a + b; a = b; b = c;
  }

  // the video's numbers: naive fib(n) makes 2*fib(n+1) - 1 calls (40,73,00,22,147 for n = 50)
  for (int n = 0; n <= 25; n++) {
    calls = 0;
    naive(n);
    CHECK(calls == 2 * fibTable(n + 1) - 1);
  }
  CHECK(2 * fibTable(51) - 1 == 40730022147LL);
}
