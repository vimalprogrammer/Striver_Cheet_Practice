#include<bits/stdc++.h>
using namespace std;

/*
Given a string, find the length of the longest substring without repeating characters.
Input: "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/

/*class Solution {
public: 
    int lengthOfLongestSubstring(string s) {
    int n=s.size();
    int j=0;
    int maxx=0;
    int i=0;
    unordered_set<int> st;
    while(j<n)
    {       
        //char c=s[j];
        if (st.find(s[j]) == st.end())
        {
        st.insert(s[j++]);
            
        }
        else
            st.erase(s[i++]);
        int stsize=st.size();
        
        maxx= max(maxx,stsize);
        
    }
    return maxx;
     }
};
*/

class Solution {
public: 
    int lengthOfLongestSubstring(string s) {
        
        int len=0;
        int left=0,right=0;
        int n=s.size();
        vector<int>mpp(256,-1);
        
        while(right<n)
        {
            if(mpp[s[right]]!=-1)
                left=max(mpp[s[right]]+1,left);
            
            mpp[s[right]]=right;
            len=max(len,right-left+1);
            right++;
        }
        return len;
     }
};
