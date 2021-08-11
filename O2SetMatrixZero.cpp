#include<bits/stdc++.h>
using namespace std;

/*
Input : A[]= 1 1 1 1
             1 1 1 1
             1 1 0 1
             0 0 0 1

Output : A[]= 0 0 0 1
              0 0 0 1
              0 0 0 0
              0 0 0 0
*/  

class Solution
{
    public:
    void SetZeros(vector<vector<int>>& matrix)
    {
        int col0=1,row=matrix.size(),col=matrix[0].size();
        for(int i=0;i<row;i++)
        {
            if(matrix[i][0]==0)
                col0=0;
            for(int j=1;j<col;j++)
            {
                if(matrix[i][j]==0)
                    matrix[i][0]=matrix[0][j]=0;
            }
        }
        for(int i=row-1;i>=0;i--)
        {
            for(int j=col-1;j>=0;j--)
            {
                if(matrix[i][0]==0 || matrix[0][j]==0)
                {
                    matrix[i][j]=0;
                }
            }
            if(col0==0)
                matrix[i][0]=0;
        }
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

        Solution s;
        s.SetZeros(v);
        cout<<"-------------------------"<<"\n";
        for(auto row_obj : v)
        {
            for (auto elem: row_obj)
            {
                cout<<elem<<" ";
            }
            cout<<endl;
        }
        cout<<endl;

}
