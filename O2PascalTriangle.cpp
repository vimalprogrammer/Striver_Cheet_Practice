#include <bits/stdc++.h>
using namespace std;

/*
Input: 5
								1
							1	 	1
						1		2       1
					1		3		3		1
------->		1		4		6		4		1

Output: 1 4 6 4 1
*/


class Solution
{
public:
	vector<vector<int>> Pascal(int num)
	{
		vector<vector<int>>r(num);

		for(int i=0;i<num;i++)
		{
			r[i].resize(i+1);
			r[i][0]=r[i][i]=1;

		for(int j=1;j<i;j++)
			r[i][j]=r[i-1][j-1]+r[i-1][j];
	}
	return r;
}
};



int main()
{
	Solution s;
	vector<vector<int>>res=s.Pascal(5);
	int cnt=0;
	for(auto it:res)
	{
		cnt++;
		if(cnt==5)
		{
			for(auto i:it)
			{
					cout<<" "<<i;
			}
			cout<<"\n";
		}
	}
	return 0;

}