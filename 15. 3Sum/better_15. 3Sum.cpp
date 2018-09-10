class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        //sort the array
        sort(nums.begin(), nums.end());
        set<vector<int>> m_set;
        vector<vector<int>> res;
        vector<int> tempV;
        int nL = nums.size();
        if(nL == 0)
        {
            return res;
        }
        
        int headWalker, tailWalker;
        int tempSum;
        int a, b, c;
        
        for(int i = 0; i < nL-2; i++)
        {
            a = nums[i];
            for(int j = i+1, k = nL-1; j < k;)
            {
                b = nums[j];
                c = nums[k];
                tempSum = a + b + c;
                if(tempSum == 0)
                {
                    res.push_back(vector<int>({nums[i], nums[j], nums[k]}));
                    j++;
                    k--;
                    while(b == nums[j])
                    {
                        j++;
                    }
                    while(c == nums[k])
                    {
                        k--;
                    }
                }
                else if(tempSum > 0)
                {
                    k--;
                }
                else if(tempSum < 0)
                {
                    j++;
                }
            }
            //we don't want the i to iterate through the same number
            while(nums[i] == nums[i+1])
            {
                i++;
            }
        }
        
        return res;
    }
};