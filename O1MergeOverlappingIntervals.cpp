#include<bits/stdc++.h>
using namespace std;

/*Input:{{1,3},{2,6},{8,10},{8,9},{9,11},{15,18},{2,4},{16,17}}
  
 Sorted:{{1,3},{2,4},{2,6},{8,9},{8,10},{9,11},{15,18},{16,17}}
        -----------------
              {1,6}         ------------------
                                 {8,11}         ----------------  
                                                    {15,18}    
  Output:{{1,6},{8,11},{15,18}}
  
*/ 

class Solution
{
    public:
    vector<vector<int>> MergeIntervals(vector<vector<int>>& intervals)
    {
        vector<vector<int>> Merged;
        if(intervals.size()==0)
            return Merged;
        
        sort(intervals.begin(),intervals.end());
        vector<int>tempInterval=intervals[0];
        
        for(auto it:intervals)
        {
            if(it[0]<=tempInterval[1])
            {
                tempInterval[1]=max(it[1],tempInterval[1]);       
            }
            else
            {
                Merged.push_back(tempInterval);
                tempInterval=it;
            }
        }
            Merged.push_back(tempInterval);
            return Merged;
    }
};
  
int main()
{
    vector<vector<int>>v;   
    int row,col;
    cout<<"Enter row and column separated by space: ";
    cin>>row>>col;
	for(int i=0;i<row;++i) { 
		//Create a vector  
		vector<int> row; 
		for(int j=0;j<col;++j){ 
			int value; 
			cin >> value; 
			row.push_back(value); 
		} 
		//Push the row in matrix 
		v.push_back(row); 
	} 

       //vector<vector<int>>intervals={{1,3},{2,6},{7,9},{8,10}};
        Solution s;
        vector<vector<int>>res=s.MergeIntervals(v);
        
        cout<<"-------------------------------------"<<endl;
        
        for(auto row_obj : res)
        {
            for (auto elem: row_obj)
            {
                cout<<elem<<" ";
            }
            cout<<endl;
        }
        cout<<endl;

}



