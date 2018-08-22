class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        long res = INT_MAX;
        int tempT = target;
        int nL = nums.size();
        int tempS;
        
        for(int i = 0; i < nL-2; i++)
        {
            for(int j = i+1; j < nL-1; j++)
            {
                for(int k = j+1; k < nL; k++)
                {
                    tempS = nums[i] + nums[j] + nums[k];
                    if(tempS == target)
                    {
                        return target;
                    }
                    res = abs(tempS - target) < abs(res - target) ? tempS : res;
                }
                    
            }
        }
        
        return (int)res;
        
    }
};