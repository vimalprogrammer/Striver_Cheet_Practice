#include <bits/stdc++.h>
using namespace std;

/*
Input: 5
								1
							 1	 	1
						 1		2       1
					 1		3		3	    1
------->		  1		4		6		4	   1
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

/*r[i].resize(i+1);
1st iter - r={0}         --> r[i][0]=r[i][i]=1; --> r{1}
2nd iter - r={0,0}       --> r[i][0]=r[i][i]=1; --> r{1,1}
3rd iter - r={0,0,0}     --> r[i][0]=r[i][i]=1; --> r{1,0,1}
4th iter - r={0,0,0,0}   --> r[i][0]=r[i][i]=1; --> r{1,0,0,1}
5th iter - r={0,0,0,0,0} --> r[i][0]=r[i][i]=1; --> r{1,0,0,0,1}
*/

		for(int j=1;j<i;j++)
			r[i][j]=r[i-1][j-1]+r[i-1][j]; 
			
/* j - loop with respect to i
 1st - j=1, i=0 cond fails --> r={1}

 2nd - j=1, i=1 cond fails --> ={1,1} 

 3rd - j=1,i=2 cond true r[2][1]=r[1][0]+r[1][1]=1+1=2 
	-->	 Hence r={1,0,1} to r={1,2,1} 

 4th- j=1,i=3 cond true -  r[3][1]=r[2][0]+r[2][1]=1+2=3 
 then j=2,i=3 cond true -  r[3][2]=r[2][1]+r[2][2]=2+1=3 
	--> hence r={1,0,0,1} to r={1,3,3,1} 

 5th - j=1,i=4 cond true    r[4][1]=r[3][0]+r[3][1]=3+1=4 
  then j=2,i=4 cond true    r[4][2]=r[3][1]+r[3][2]==3+3=6 
  then j=3,i=4 cond true	r[4][3]=r[3][2]+r[3][3]==3+1=4 
	--> hence r={1,0,0,0,1} to r={1,4,6,4,1}
*/
	}
	return r;//will return the whole pascal triangle
}
};



int main()
{
    int n;cin>>n;
	Solution s;
	vector<vector<int>>res=s.Pascal(n);
	int cnt=0;
    int i,space;
   for (i = 0; i < n; i++) 
   {
      for (space = 1; space <= n - i; space++)
         printf("  ");
            for(auto j:res[i])
                cout<<j<<"   ";
        cout<<"\n";
   }
	return 0;
}