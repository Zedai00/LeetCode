#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> nums;
    nums.push_back(3);
    nums.push_back(2);
    nums.push_back(4);
    int target = 6;
    vector<int> n;
    int i = 0;
    int j = 1;
    while (i < nums.size())
    {
        if (nums[i] + nums[j] == target)
        {
            cout << i << " " << j;
            break;
        }
        if (j == nums.size() - 1)
        {
            i++;
            j = i+1;
        }
        else
            j++;
    }
}