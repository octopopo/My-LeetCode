class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int nLength = nums.size();
        sort(nums.begin(), nums.end());
        return nums[nLength-k];
    }
};