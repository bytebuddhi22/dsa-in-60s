#define DSA_TEST
#include "recursion.cpp"
#include <cstdio>
#include <cstdlib>

#define CHECK(x) if (!(x)) { printf("FAIL line %d: %s\n", __LINE__, #x); exit(1); }

int main() {
  CHECK(fact(4) == 24);
  CHECK(fact(0) == 1);
  CHECK(fact(1) == 1);
  CHECK(fact(20) == 2432902008176640000LL);  // largest that fits in long long
  long long f = 1;
  for (int n = 1; n <= 20; n++) { f *= n; CHECK(fact(n) == f); }
}
