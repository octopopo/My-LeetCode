class Solution {
public:
    bool canJump(vector<int>& nums) {
        int nL = nums.size();
        if(nL == 0)
        {
            return true;
        }
        
        int tempMax = 0;
        int tempDist = 0;
        for(int i = 0; i < nL; i++)
        {
            if(tempMax >= nL-1)
            {
                return true;
            }
            else
            {
                if(i == tempMax)
                {
                    if(nums[i] == 0)
                    {
                        return false;
                    }
                }
                tempDist = i + nums[i];
                tempMax = max(tempMax, tempDist);
            }
        }
        
        return true;
    }
};