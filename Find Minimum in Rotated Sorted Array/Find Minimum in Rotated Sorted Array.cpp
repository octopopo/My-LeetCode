class Solution {
public:
    int findMin(vector<int>& nums) {
        int nLength = nums.size();
        if(nLength == 0)
        {
            return 0;
        }
        
        int head = nums[0];
        int tail = nums[nLength-1];
        
        //this means that we should search the minimum from behind
        if(head > tail)
        {
            for(int i = nLength-1; i >= 0; i--)
            {
                if(nums[i] < nums[i-1])
                {
                    return nums[i];
                }
            }
        }
        else
        {
            return nums[0];
        }
        
        return nums[0];
    }
};