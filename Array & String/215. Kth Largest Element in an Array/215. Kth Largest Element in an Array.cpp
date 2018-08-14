class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        
        int nL = nums.size();
        
        nL = nL-k;
        
        return nums[nL];
    }
};