class Solution {
public:
    string getPermutation(int n, int k) {
        if(n == 0)
        {
            return "";
        }
        
        vector<int> nums(n);
        int targetD = 1;
        for(int i = 1; i <= n; i++)
        {
            nums[i-1] = i;
            targetD *= i;
        }
        
        string res;
        k--;
        for(int i = 0; i < n; i++)
        {
            targetD /= (n-i);
            int tempP = k/targetD;
            res += (nums[tempP] + '0');
            nums.erase(nums.begin()+tempP);
            k = k%targetD;
        }
        
        return res;
        
    }
};