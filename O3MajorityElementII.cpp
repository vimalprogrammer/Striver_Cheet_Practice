#include<bits/stdc++.h>
using namespace std;
/*
problem: find all elements that appear more than ⌊ n/3 ⌋ times 
         bur defiendly not all elements appear more than ⌊ n/3 ⌋ times
         only 2 elements appear more than ⌊ n/3 ⌋ times
Input: [1,1,1,3,3,2,2,2]
Output: [1,2]
*/

// O(n) time, O(1) space

// 1. find the majority element
// 2. find the number of occurrences of the majority element
// 3. find the number of occurrences of the 2nd most frequent element
// 4. if the number of occurrences of the 2nd most frequent element is more than ⌊ n/3 ⌋ times, return the 2 elements
// 5. if the number of occurrences of the 2nd most frequent element is less than ⌊ n/3 ⌋ times, return the 1 element
// 6. if the number of occurrences of the majority element is more than ⌊ n/3 ⌋ times, return the 1 element
// 7. if the number of occurrences of the majority element is less than ⌊ n/3 ⌋ times, return the 2 elements

// Boyer-Moore majority vote algorithm

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