#include<bits/stdc++.h>
using namespace std;

/*
 Input: [1, 0, -1, 0, -2, 2]
 Output: [[-2, -1, 1, 2], [-2, 0, 0, 2], [-1, 0, 0, 1]]
 Explanation: {a+b+c+d = target} without using 3ptr approach 
*/

// TC: O(n^3) SC: O(1)

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) 
    {
        vector<vector<int>>ans;
        if(nums.empty())
            return ans;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++)
            {
                for(int j=i+1;j<n;j++)
                {
                    int start=j+1;
                    int end=n-1;
                    
                    int target2=target-nums[j]-nums[i]; 
                    while(start<end)
                    {
                        if((nums[start]+nums[end])<target2)
                            start++;
                        else if(nums[start]+nums[end]>target2)
                            end--;
                        else
                        {
                            vector<int>q(4,0);
                            q[0]=nums[i];
                            q[1]=nums[j];
                            q[2]=nums[start];
                            q[3]=nums[end];
                            ans.push_back(q);
                            while(start<end&&nums[start]==q[2]) ++start;
                            while(start<end&&nums[end]==q[3]) --end;
                        }   
                    }
                    while(j+1<n && nums[j+1]==nums[j]) ++j;
                }
                while(i+1<n && nums[i+1]==nums[i]) ++i;
            }
        return ans;
    }
};

int main()
{
    vector<int>a={4,3,3,4,4,2,1,2,1,1};
    Solution s;
    vector<vector<int>>res=s.fourSum(a,9);
    for(auto it:res)
    {
        for(auto i:it)
            cout<<i<<" ";
        cout<<"\n";
    }
}

