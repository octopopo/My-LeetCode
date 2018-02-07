class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int maxR = INT_MIN;
        int sum = 0;
        for(int i = 0; i < nums.size();i++){
            if(i < k){
                sum += nums[i];
            }
            else{
                maxR = max(sum,maxR);
                sum = sum + nums[i] - nums[i-k];
            }
        }
        maxR = max(maxR,sum);
        
        return (double)maxR / (double) k;
    }
};