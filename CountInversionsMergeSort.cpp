#include <bits/stdc++.h>
using namespace std;

/*
Input: ar[]=[8,4,2,1]
Output: 6
Explanation: 8,4 | 8,2 | 8,1 | 4,2 | 4,1 | 2,1 ->> 6 combinations WRT a[i]>a[i+1]
*/

int merge(int arr[],int temp[],int left,int mid,int right)
{
    int i,j,k;
    int inv_count=0;
    i=left;
    j=mid;
    k=left;

    while((i<=mid-1)&&(j<=right))
    {
        if(arr[i]<=arr[j])
            temp[k++]=arr[i++];
        else
        {
            temp[k++]=arr[j++];
            inv_count=inv_count+(mid-i);
        }
    }
    while(i<=mid-1)
        temp[k++]=arr[i++];
    while(j<=right)
        temp[k++]=arr[j++];

    for(i=left;i<=right;i++)
        arr[i]=temp[i];

    return inv_count;
}

int _mergeSort(int arr[],int temp[],int left,int right)
{
    int mid,inv_count=0;
    if(right>left)
    {
        mid=(right+left)/2;
        inv_count+=_mergeSort(arr,temp,left,mid);
        inv_count+=_mergeSort(arr,temp,mid+1,right);

        inv_count+=merge(arr,temp,left,mid+1,right);        
    }
    return inv_count;
}


int main()
{
    
    int arr[]={5,3,2,4,1};
    int n=sizeof(arr)/sizeof(arr[0]);
    int temp[n];
    int ans=_mergeSort(arr,temp,0,n-1);
    cout<<"Number of inversions are "<<ans;
    return 0;
}