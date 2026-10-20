// DSA in 60s #05: Stack (Valid Parentheses, LeetCode 20)
// The function body is exactly the code shown in the video.
#include <map>
#include <stack>
#include <string>
using namespace std;

// true if every bracket is closed by the same type, in the right order. O(n)
bool isValid(const string& s) {
  map<char, char> opener =
    {{')', '('}, {']', '['}, {'}', '{'}};
  stack<char> st;
  for (char c : s) {  // only ()[]{}
    if (c == '(' || c == '[' || c == '{')
      st.push(c);
    else {
      if (st.empty() || st.top() != opener[c])
        return false;
      st.pop();
    }
  }
  return st.empty();
}

#ifndef DSA_TEST
#include <iostream>
int main() {
  cout << boolalpha;
  cout << isValid("{[()]}") << "\n";  // true
  cout << isValid("(]") << "\n";      // false: wrong type
  cout << isValid("(()") << "\n";     // false: 1 left on the stack
}
#endif
