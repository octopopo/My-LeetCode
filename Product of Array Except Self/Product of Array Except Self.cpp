class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int nL = nums.size();
        int pre = 1, pos = 1;
        int start = 1, end = nL-1;
        vector<int> res(nL,1);
        for(start = 0; start < nL; start++, end--)
        {
            res[start] *= pre;
            res[end] *= pos;
            pre *= nums[start];
            pos *= nums[end];
        }
        
        return res;
    }
};