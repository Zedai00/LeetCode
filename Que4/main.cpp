#include <iostream>
#include <vector>
using namespace std;

void getMedian(int nums[]);
void median(vector<int> nums1, vector<int> nums2);

int main() {
  vector<int> nums1 = {4, 20, 32, 50, 55, 61};
  vector<int> nums2 = {1, 15, 22, 30, 70};
  median(nums1, nums2);
}

void median(vector<int> nums1, vector<int> nums2) {
  if (nums1.size() > nums2.size())
    return median(nums2, nums1);

  int start = 0;
  int end = nums1.size();
  while (start <= end) {
    int totalSize = nums1.size() + nums2.size();
    int i = (start + end) / 2;
    int j = (totalSize + 1) / 2 - i;
    int leftHalfA = 0;
    int leftHalfB = 0;
    if (i != 0) {
      leftHalfA = nums1[i - 1];
    }
    if (j != 0) {
      leftHalfB = nums2[j - 1];
    }
    int rightHalfA = 0;
    int rightHalfB = 0;
    if (i != nums1.size()) {
      rightHalfA = nums1[i];
    }
    if (j != nums2.size()) {
      rightHalfB = nums2[j];
    }
    if (leftHalfA <= rightHalfB && leftHalfB <= rightHalfA) {
      if (totalSize % 2 != 0) {
        cout << max(leftHalfA, leftHalfB) << endl;
        return;
      } else {
        int maxL = max(leftHalfA, leftHalfB);
        int maxR = max(rightHalfA, rightHalfB);
        cout << (maxL + maxR) / 2 << endl;
        return;
      }
    } else if (leftHalfA > rightHalfB) {
      end = i - 1;
    } else {
      start = i + 1;
    }
  }
}
