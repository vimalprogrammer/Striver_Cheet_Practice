#include <bits/stdc++.h>
using namespace std;

/*
Input: 1,2,3
Output: 1,3,2 

Input: 1,3,5,4,2
Output: 1,4,2,3,5

Input: 5,4,3,2,1
Output: 1,2,3,4,5
*/

class Solution
{
public:
	vector<int>nextPermutate(vector<int>& nums)
	{
		int len=nums.size(),k,l;
		for(k=len-2;k>=0;k--)
		{
			if(nums[k]<nums[k+1])
				break;
		}
		if(k<0)
			reverse(nums.begin(),nums.end());

		else
		{
			for(l=len-1;l>k;l--)
			{
				if(nums[l]>nums[k])
					break;
			}
			swap(nums[k],nums[l]);
			reverse(nums.begin()+k+1,nums.end());
		}
            return nums;
	}
};


int main()
{
	
	vector<int> a;
	int input;
    while (cin >> input)
        a.push_back(input);
        
	Solution s;
    s.nextPermutate(a);
	for(auto i:a)
	    cout<<i<<" ";
}