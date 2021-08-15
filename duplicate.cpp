/*
Input: 2 5 9 6 9 3 8 9 7 1
Output: 9
*/

#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
    int dup(vector<int>& nums)
    {
        int slow=nums[0];
        int fast=nums[0];
        do
        {
            slow=nums[slow];
            fast=nums[nums[fast]];
        }while(slow!=fast);
        fast=nums[0];
        while(slow!=fast)
        {
            slow=nums[slow];
            fast=nums[fast];
        }
        return slow;
    }
};
int main()
{
    vector<int> nums={2,5,9,6,9,3,8,9,7,1};
    int res;
    Solution s;
    res=s.dup(nums);
    cout<<res;
    return 0;
}

/*
//Hashing method - Multiple duplicates
//TC-O(n)
//SC-O(n)
//Input: 1,2,2,4,5,3,5,7,1,8,3,8
//Output: 2 5 1 3 8

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
	vector<int>repeat(vector<int>v,int temp[])
	{
		int cnt=0;
		vector<int>ans;
		for(auto it:v)
		{
			temp[it]+=1;
			cnt++;
			if(temp[it]>1)
			{

				ans.push_back(v[cnt-1]);
			}
		}
		return ans;
	}
};
int main()
{
	
	vector<int>v={1,2,2,4,5,3,5,7,1,8,3,8};
	int n=v.size();
	int temp[n]={0};
	Solution s;
	vector<int>res=s.repeat(v,temp);
	for(auto it:res)
		cout<<it<<" ";
	return 0;
}
*/

/* String array duplicate finding
//Using Map

//Output: at : 3
          hi : 2
          where : 2


#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    map<string,int>FindDuplicates(vector<string>VecStrings)
    {
        map<string,int>StrCount;
        
        for(auto &elem: VecStrings)
        {
            auto res=StrCount.insert(pair<string,int>(elem,1));
            if(res.second==false)
                res.first->second++;
        }
        return StrCount;
    }
    
};

int main()
{
    vector<string>VecStrings;
    string input;
    while(cin>>input)
        VecStrings.push_back(input);
        
    Solution s;    
    map<string,int>result=s.FindDuplicates(VecStrings);
    for(auto & it:result)
    {
        if(it.second>1)
            cout<<it.first<<" : "<<it.second<<"\n";
    }
    return 0;
}

*/