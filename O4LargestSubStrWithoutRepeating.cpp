#include<bits/stdc++.h>
using namespace std;

class Solution {
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