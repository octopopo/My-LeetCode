class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int nL = nums.size();
        int zP = -1;
        int tempSwap;
        for(int i = 0; i < nL; i++)
        {
            if(nums[i] == 0)
            {
                for(int j = i+1; j < nL; j++)
                {
                    if(j == nL-1 && nums[j] == 0)
                    {
                        return ;
                    }
                    if(nums[j] != 0)
                    {
                        tempSwap = nums[j];
                        nums[j] = 0;
                        nums[i] = tempSwap;
                        break;
                    }
                }
            }
        }
        
        return;
    }
};