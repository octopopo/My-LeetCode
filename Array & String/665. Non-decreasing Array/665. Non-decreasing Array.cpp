class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int nL = nums.size();
        
        int i, j;
        //do the first iteration to find the first part that become non-decreasing
        for(i = 0; i < nL-1; i++)
        {
            //find the non-decreasing part
            if(nums[i] > nums[i+1])
                break;
        }
        //if the non decreasing part appear at the end, it is possible to get the result by one change
        if(i >= nL - 2)
        {
            return true;
        }
        
        //if not, start another iteration to find if there is another problem.
        for(j = i+1; j < nL-1; j++)
        {
            //Second problematic part appear, return false;
            if(nums[j] > nums[j+1])
            {
                return false;
            }
        }
        //the first problem it at the first position, and it can easily be changed.
        if(i == 0)
        {
            return true;
        }
        
        //detect if just change i or i+1 can fix the problem
        if(nums[i-1] < nums[i+1] || nums[i] < nums[i+2])
        {
            return true;
        }
        
        return false;
    }
};