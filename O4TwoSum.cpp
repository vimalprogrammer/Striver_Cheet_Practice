#include<bits/stdc++.h>
using namespace std;

/*
    Input: nums = [2, 7, 11, 15], target = 9
    Output: [0, 1]
    Explanation: The sum of 2 and 7 is 9. Therefore index0 = 0, index1 = 1.
*/

//HashMap Technique Time Complexity: O(n)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        vector<int>ans;
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++)
        {
            if(mp.find(target-nums[i])!=mp.end())
            {
                ans.push_back(mp[target-nums[i]]);//storing maps index
                ans.push_back(i);
                return ans;
            }
            mp[nums[i]]=i;//nums[i]-> val  =i->index
        }
        return ans;
    }
};
