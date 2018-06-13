class Solution {
public:
    static int compa(const void *a, const void *b){
        return (*(int*)b - *(int*)a);
    }
    
    int arrayPairSum(vector<int>& nums) {
        int nS = nums.size();
        int res = 0;
        qsort(&nums[0], nS, sizeof(int), compa);
        
        for(int i = 1; i < nS; i += 2){
            res += nums[i];
        }
        
        return res;
    }
};