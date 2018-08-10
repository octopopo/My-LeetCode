class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int slowWalker = 0;
        int nL = nums.size();
        int temp;
        for(int i = 0; i < nL; i++)
        {
            temp = nums[i];
            if(temp != val)
            {
                nums[slowWalker] = temp;
                slowWalker++;
            }
            else
            {
                continue;
            }
        }
        
        return slowWalker;
    }
};