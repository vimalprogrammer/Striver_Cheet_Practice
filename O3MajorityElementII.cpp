#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        int n1=-1,n2=-1,c1=0,c2=0;
        vector<int>ans;
        int l=nums.size();
        for(auto it:nums)
        {
            if(it==n1)
                c1++;
            else if(it==n2)
                c2++;
            else if(c1==0)
            {
                n1=it;
                c1=1;
            }
            else if(c2==0)
            {
                n2=it;
                c2=1;
            }
            else
            {
                c1--;
                c2--;
            }
        }
        c1=0;c2=0;
        for(int i=0;i<l;i++)
        {
            if(nums[i]==n1)
                c1++;
            else if(nums[i]==n2)
                c2++;
        }
        if(c1>l/3)
            ans.push_back(n1);
        if(c2>l/3)
            ans.push_back(n2);
        return ans;
    }
};