/*TC-O(n^2)
  SC-O(n^2)

  Input: 1 2 3
         4 5 6
         7 8 9
  
  Output: 7 4 1
          8 5 2
          9 6 3
*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>>rotateArr(vector<vector<int>>a,int n)
{
    vector<vector<int>>retArr;
    for(int i=0;i<n;i++)
    {
        vector<int>temp;
        for(int j=n-1;j>=0;--j)
        {
            int item=a[j][i];
            temp.push_back(item);
        }
        retArr.push_back(temp);
    }
    return retArr;
}

int main()
{
    int n;cin>>n;
    vector<vector<int>>v;
    for(int i=0;i<n;i++)
    {
        vector<int>temp;
        for(int j=0;j<n;j++)
        {
            int ele;cin>>ele;
            temp.push_back(ele);
        }
        v.push_back(temp);
        temp.clear();
    }
    vector<vector<int>>res=rotateArr(v,n);
    for(auto it:res)
    {
        for(auto i:it)
        {
            cout<<i<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
