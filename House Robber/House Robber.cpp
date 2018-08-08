class Solution {
public:
    int rob(vector<int>& nums) {
        //using dynamic programming
        int nL = nums.size();
        if(nL == 0)
        {
            return 0;
        }
        
        vector<int> totalAmount(nL);
        totalAmount[0] = nums[0];
        totalAmount[1] = max(nums[0],nums[1]);
        for(int i = 2; i < nL ; i++)
        {
            totalAmount[i] = max(totalAmount[i-1], nums[i] + totalAmount[i-2]);
        }
        
        return totalAmount[nL-1];
    }
};