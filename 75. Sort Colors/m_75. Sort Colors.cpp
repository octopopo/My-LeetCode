class Solution {
public:
    void sortColors(vector<int>& nums) {
        int nL = nums.size();
        if(nL == 0)
        {
            return;
        }
        int head = 0, tail = nL-1;
        for(int i = 0; i < nL; i++)
        {
            while((nums[i] == 0 && i > head) || (nums[i] == 2 && i < tail))
            {
                if(nums[i] == 0)
                {
                    swap(nums[i], nums[head]);
                    head++;
                }
                else if(nums[i] == 2)
                {
                    swap(nums[i], nums[tail]);
                    tail--;
                }
            }
        }
        
        return;
    }
};