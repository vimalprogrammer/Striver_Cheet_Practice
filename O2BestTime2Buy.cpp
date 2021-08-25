#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int MaxProfit(vector<int>prices)
    {

        int MaxPro=0;
        int minPrice=INT_MAX;
        for(int i=0;i<prices.size();i++)
        {
            minPrice=min(minPrice,prices[i]);
            MaxPro=max(MaxPro,prices[i]-minPrice);
        }
        return MaxPro;
    }
};

int main()
{
    vector<int> v;
    string buffer;
    int data;
    getline(cin, buffer);
    istringstream iss(buffer);
    while (iss >> data)
          v.push_back(data);
    Solution s;
    cout<<s.MaxProfit(v);
    return 0;
}