#include <bits/stdc++.h>
using namespace std;

/*
Input: [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
             Not 7-1 = 6, as selling price needs to be larger than buying price.
*/

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