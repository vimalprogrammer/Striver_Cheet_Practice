#include<bits/stdc++.h>
using namespace std;

/*
Input: arr[] = {4, 2, 2, 6, 4}
       k = 6
Output: cnt=4
Explanation: There are 4 subarrays with sum 6.
*/   
    
//TC: O(n log n)
//SC: O(n)

int Solution(vector<int> &A, int B) {
    map<int,int>mp;
    int cnt=0,xorr=0;
    for(auto it:A)
    {
        xorr=xorr^it;
        if(xorr==B)
            cnt++;
        if(mp.find(xorr^B)!=mp.end())
            cnt+=mp[xorr^B];
        
        mp[xorr]++;
    }
    return cnt;
}
