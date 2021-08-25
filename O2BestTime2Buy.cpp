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
    
    vector<int>prices;   
    int input;
    while(cin>>input)
        prices.push_back(input);
    Solution s;
    int res=s.MaxProfit(prices);
    cout<<res;
    return 0;
}