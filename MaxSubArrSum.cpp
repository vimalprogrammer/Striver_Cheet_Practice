//Normal Approach O(n^2)

#include<bits/stdc++.h>
using namespace std;

int maxi(int a,int b)
{
    if(a>b)
        return a;
    return b;
}

int main()
{
    int a[]={-2,-3,4,-1,-2,1,5,3};
    int n=sizeof(a,a+1);
    int sum,max_=a[0];
    for(int i=0;i<n-1;i++)
    {
        sum=0;
        for(int j=i;j<n;j++)
        {
            sum+=a[j];
            max_=maxi(sum,max_);
        }
    }
    cout<<max_;
}