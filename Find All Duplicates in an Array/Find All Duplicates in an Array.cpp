class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int nLength = nums.size();
        vector<int> res;
        int target;
        if(nLength == 0)
        {
            return res;
        }
        
        for(int i = 0; i < nLength; i++)
        {
            target = nums[i] % nLength;
            
            nums[target] += nLength;
            if(nums[target]> 2 * nLength)
            {
                if(target == 0)
                {
                    target += nLength;
                }
                res.push_back(target);
            }
        }
        
        return res;
    }
};