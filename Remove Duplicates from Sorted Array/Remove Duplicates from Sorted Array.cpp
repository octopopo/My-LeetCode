class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int nL = nums.size();
        if(nL == 0)
        {
            return 0;
        }
        
        int target = nums[0];
        int slowWalker = 0;
        
        for(int i = 1; i < nL; i++)
        {
            if(nums[i] != target)
            {
                target = nums[i];
                slowWalker++;
                nums[slowWalker] = nums[i];
            }
        }
        
        return slowWalker+1;
    }
};