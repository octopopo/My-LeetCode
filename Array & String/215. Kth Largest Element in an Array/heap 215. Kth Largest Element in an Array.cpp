class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int nL = nums.size();
        
        make_heap(nums.begin(), nums.end());
        
        while(--k)
        {
            pop_heap(nums.begin(), nums.end());
            nums.pop_back();
        }
        
        pop_heap(nums.begin(), nums.end());
        return nums.back();
        
    }
};