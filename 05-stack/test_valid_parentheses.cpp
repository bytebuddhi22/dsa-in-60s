#define DSA_TEST
#include "valid_parentheses.cpp"
#include <cstdio>
#include <cstdlib>
#include <random>

#define CHECK(x) if (!(x)) { printf("FAIL line %d: %s\n", __LINE__, #x); exit(1); }

static bool bruteForce(string s) {
  string prev;
  while (prev != s) {
    prev = s;
    for (const char* p : {"()", "[]", "{}"})
      for (size_t i; (i = s.find(p)) != string::npos;) s.erase(i, 2);
  }
  return s.empty();
}

int main() {
  CHECK(isValid("{[()]}"));
  CHECK(!isValid("(]"));
  CHECK(!isValid("(()"));
  CHECK(isValid(""));
  CHECK(!isValid(")"));
  CHECK(!isValid("([)]"));

  mt19937 rng(5);
  const string chars = "()[]{}";
  for (int it = 0; it < 5000; it++) {
    string s;
    int n = rng() % 13;
    for (int i = 0; i < n; i++) s += chars[rng() % 6];
    CHECK(isValid(s) == bruteForce(s));
  }
}
