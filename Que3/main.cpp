#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;
int main() {
  string s;
  cin >> s;
  int m = 0;
  unordered_set<char> ss;
  for (int i = 0, j = 0; j < s.length(); j++) {
    while (ss.count(s[j])) {
      ss.erase(s[i]);
      i++;
    }
    ss.insert(s[j]);
    m = max(m, j - i + 1);
  }
  cout << m;
}
