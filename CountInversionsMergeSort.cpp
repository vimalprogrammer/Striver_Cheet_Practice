#include <bits/stdc++.h>
using namespace std;

/*
Input: ar[]=[8,4,2,1]
Output: 6
Explanation: 8,4 | 8,2 | 8,1 | 4,2 | 4,1 | 2,1 ->> 6 combinations WRT a[i]>a[j] and i<j
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

/*
// A STL Set based approach for inversion count 
#include<bits/stdc++.h>
using namespace std;
  
// Returns inversion count in arr[0..n-1]
int getInvCount(int arr[],int n)
{
    // Create an empty set and insert first element in it
    multiset<int> set1;
    set1.insert(arr[0]);
  
    int invcount = 0; // Initialize result
  
    multiset<int>::iterator itset1; // Iterator for the set
  
    // Traverse all elements starting from second
    for (int i=1; i<n; i++)
    {
        // Insert arr[i] in set (Note that set maintains
        // sorted order)
        set1.insert(arr[i]);
  
        // Set the iterator to first greater element than arr[i]
        // in set (Note that set stores arr[0],.., arr[i-1]
        itset1 = set1.upper_bound(arr[i]);
  
        // Get distance of first greater element from end
        // and this distance is count of greater elements
        // on left side of arr[i]
        invcount += distance(itset1, set1.end());
    }
  
    return invcount;
}
  
// Driver program to test above
int main()
{
    int arr[] = {8, 4, 2, 1};
    int n = sizeof(arr)/sizeof(int);
    cout << "Number of inversions count are : "
         << getInvCount(arr,n);
    return 0;
}
*/