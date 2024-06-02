#include <iostream>
using namespace std;
int expand(string s, int left, int right);

int main() {
  string s;
  cin >> s;
  int start = 0;
  int end = 0;
  for (int i = 0; i < s.length(); i++) {
    int lenOdd = expand(s, i, i);
    int lenEven = expand(s, i, i + 1);
    int len = max(lenOdd, lenEven);
    if (len > end - start) {
      start = i - ((len - 1) / 2);
      end = i + (len / 2);
    }
  }
  cout << s.substr(start, end - start + 1);
}

int expand(string s, int left, int right) {
  if (s.empty() || left > right)
    return 0;

  while (left >= 0 && right < s.length() && s[left] == s[right]) {
    right++;
    left--;
  }
  return right - left - 1;
}
