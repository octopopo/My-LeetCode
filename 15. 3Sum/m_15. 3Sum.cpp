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
        
        for(int i = 0; i < nL-2; i++)
        {
            headWalker = i+1;
            tailWalker = nL-1;
            while(headWalker < tailWalker)
            {
                tempSum = nums[i] + nums[headWalker] + nums[tailWalker];
                if(tempSum == 0)
                {
                    tempV.push_back(nums[i]);
                    tempV.push_back(nums[headWalker]);
                    tempV.push_back(nums[tailWalker]);
                    if(!m_set.count(tempV))
                    {
                        m_set.insert(tempV);
                        res.push_back(tempV);
                    }
                    headWalker++;
                }
                else if(tempSum > 0)
                {
                    tailWalker--;
                }
                else
                {
                    headWalker++;
                }
                tempV.clear();
            }
        }
        
        return res;
    }
};