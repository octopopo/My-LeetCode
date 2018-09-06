class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int res = 0;
        int nL = nums.size();
        vector<int> sumTable(nL, 0);
        int sum = 0;
        for(int i = 0; i < nL; i++)
        {
            sum = nums[i];
            sumTable[i] = sum;
            if(sum == k)
            {
                res++;
            }
        }
        int target = 0;
        //outer loop is length of subarray
        for(int i = 1; i < nL; i++)
        {
            //inner loop is the start of the subarray
            for(int j = 0; j < nL; j++)
            {
                target = j+i;
                if(target >= nL)
                {
                    break;
                }
                sum = sumTable[j] + nums[target];
                if(sum == k)
                {
                    res++;
                }
                sumTable[j] = sum;
            }
        }
        
        return res;
    }
};