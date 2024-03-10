#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

int main() {
  vector<int> nums1 = {1, 2, 2, 1};
  vector<int> nums2 = {2, 2};

  unordered_set<int> set1(nums1.begin(), nums1.end());
  unordered_set<int> set2(nums2.begin(), nums2.end());

  vector<int> ans;

  for (int num : set1) {
    if (set2.find(num) != set2.end()) {
      ans.push_back(num);
    }
  }

  for (int num : ans) {
    cout << num << " ";
  }
  cout << endl;

  return 0;
}
