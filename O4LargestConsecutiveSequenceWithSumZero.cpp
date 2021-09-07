#include<bits/stdc++.h>
using namespace std;

/*
Given an array of integers, find the largest sub-array with sum zero.
Input:  arr[] = {1, 2, 3, -4, 5, -6, 7, 8, -9, 10}
Output: 4
The sub-array is {1, 2, 3, -4}
Explanation: The sub-array with sum zero is {1, 2, 3, -4}

Input: a[]={1,2,-2,4,-4}
Output: 4
The sub-array is {2, -2, 4, -4} with sum zero
*/

int Solution(vector<int> &A) {

    int sum=0;
    int maxi=0,j=0,m=0;
    map<int,int>mp;
    for(int i=0;i<A.size();i++){
        sum+=A[i];
        if(sum==0)
        {
            maxi=i+1;
        }
        else
        {
            if(mp.find(sum)!=mp.end())
            {
                maxi=max(maxi,i-mp[sum]);
            }
            else
                mp[sum]=i;
        }
    }
    return maxi;
}

int main()
{
    vector<int> A={1,2,-2,4,-4};
    int res=Solution(A);
    cout<<res;    
}
