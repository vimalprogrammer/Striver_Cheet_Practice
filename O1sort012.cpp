/*
Input: 0 1 1 0 1 2 1 2 0 0 0 1
Output: 0 0 0 0 0 1 1 1 1 1 2 2
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public:
  void sort(vector<int>& nums)
  {
    int low=0;
    int mid=0;
    int high=nums.size()-1;
    
    while(mid<=high)
    {
      switch(nums[mid])
      {
        case 0:
          swap(nums[low++],nums[mid++]);
          break;
        case 1:
          mid++;
          break;
        case 2:
          swap(nums[mid],nums[high--]);
          break;
      }
    }
  }
};


int main()
{
  vector <int> nums;
  short input;
  while (cin >> input)
  {
    nums.push_back(input);
  }
  Solution s;
  s.sort(nums);
  for(int i=0;i<nums.size();i++)
  {
    cout<<nums[i]<<" ";
  }
  return 0;
}