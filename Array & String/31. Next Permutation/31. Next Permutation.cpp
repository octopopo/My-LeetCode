class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int nL = nums.size();
        int i;
        //if the length of number is 0 or 1, return
        if(nL == 0 || nL == 1)
        {
            return;
        }
        int big, bfs;
        int tempSwap;
        //find the first decreasing pair;
        for(i = nL-1; i >= 1; i--)
        {
            if(i == 1 && nums[i] <= nums[i-1])
            {
                reorder(nums, 0, nL-1);
                return;
            }
            //found the big
            if(nums[i] > nums[i-1])
            {
                bfs = i-1;
                break;
            }
        }
        
        //find the smallest bigger element that is rightward to the bfs.
        for(i = nL-1; i >= bfs; i--)
        {
            if(nums[i] > nums[bfs])
            {
                big = i;
                break;
            }
        }
        
        tempSwap = nums[bfs];
        nums[bfs] = nums[big];
        nums[big] = tempSwap;
        
        reorder(nums, bfs+1, nL-1);
        
        return;
    }
    
    void reorder(vector<int> &nums, int begin, int end)
    {
        int nL = end - begin + 1;
        int temp;
        int tempP;
        for(int i = 0; i < nL/2; i++)
        {
            tempP = end-i;
            temp = nums[begin + i];
            nums[begin + i] = nums[tempP];
            nums[tempP] = temp;
        }
        
        return;
    }
};