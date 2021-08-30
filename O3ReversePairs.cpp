#include<bits/stdc++.h>
using namespace std;

/*
 Given an integer array nums, return the number of reverse pairs in the array.
A reverse pair is a pair (i, j) where 0 <= i < j < nums.length and nums[i] > 2
 * nums[j]

Input: nums = [40,25,19,12,9,6,2]
Output: 15
Explanation: There are 15 reverse pairs in the given array.
40>2*19 40>2*12 40>2*9 40>2*6 40>2*2
25>2*12 25>2*9 25>2*6  25>2*2
19>2*9 19>2*6  19>2*2 
12>2*9 
9>2*6 
2>2*6
*/

class Solution {
    
    int merge(vector<int>&nums,int low,int mid,int high)
    {
        int cnt=0;
        int j=mid+1;
        for(int i=low;i<=mid;i++)
        {
            while(j<=high && nums[i]>2LL*nums[j])
            {
                j++;
            }
            cnt+=(j-(mid+1)); 
        }
        
        vector<int>temp;
        int l=low,r=mid+1;
        while(l<=mid && r<=high)
        {
            if(nums[l]<=nums[r])
                temp.push_back(nums[l++]);
            else
                temp.push_back(nums[r++]);
        }
        while(l<=mid)
            temp.push_back(nums[l++]);
        while(r<=high)
            temp.push_back(nums[r++]);
        
        
        for(int i=low;i<=high;i++)
            nums[i]=temp[i-low];
        return cnt;
    }
    
    
    int mergeSort(vector<int>&nums,int low,int high)
    {
        if(low>=high)return 0;
        int mid=(low+high)/2;
        int inv=mergeSort(nums,low,mid);
        inv+=mergeSort(nums,mid+1,high);
        inv+=merge(nums,low,mid,high);
        return inv;
    }
    
public:
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums,0,nums.size()-1);
    }
};