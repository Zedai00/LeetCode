#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  bool isPalindrome(int x) {
    string s = to_string(x);
    string r = s;
    reverse(s.begin(), s.end());

    return (s == r);
  }
};

int main() {
  Solution s;
  int x;
  cin >> x;
  cout << s.isPalindrome(x);
}
