class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int nSize = nums.size();
        int res = INT_MIN;
        int temp = 0;
        for(int i = 0; i < nSize; i++)
        {
            temp += nums[i];
            if(temp > res)
                res = temp;
            if(temp < 0)
                temp = 0;
        }
        
        return res;
    }
};