class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int nL = nums.size();
        if(nL == 0)
        {
            return 0;
        }
        
        int target;
        int tarCount;
        int walker;
        
        target = nums[0];
        tarCount = 1;
        walker = 1;
        
        for(int i = 1; i < nL; i++)
        {
            if(nums[i] == target)
            {
                if(tarCount >= 2)
                {
                    continue;
                }
                else
                {
                    tarCount++;
                    nums[walker] = nums[i];
                    walker++;
                }
            }
            else
            {
                target = nums[i];
                nums[walker] = nums[i];
                walker++;
                tarCount = 1;
            }
        }
        
        return walker;
    }
};