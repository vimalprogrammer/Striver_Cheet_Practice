class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt=0;
        int key=0;
        for(int num:nums)
        {
            if(cnt==0)
                key=num;
            if(num==key)
                cnt++;
            else
                cnt--;
        }
        return key;
    }
};