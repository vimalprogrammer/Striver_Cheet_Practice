#include<bits/stdc++.h>
using namespace std;

/*
Input: 102,4,100,1,101,3,2
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
*/

//Time Complexity: O(n)+O(n)+O(n)
//Space Complexity: O(n) used for storing the input array in a hashset

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {        
        unordered_set<int>hashset;
        for(int it:nums)
            hashset.insert(it);
        int longestStreak=0;
        for(int i:nums)
        {
            if(!hashset.count(i-1))
               {
                   int curStreak=1;
                   int curNum=i;
                   
                   while(hashset.count(curNum+1))
                   {
                       curStreak++;
                       curNum++;
                   }
                   longestStreak=max(curStreak,longestStreak);
               }
        }
        return longestStreak;
    }
};