class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        int nL = nums.size();
        if(nL == 0)
        {
            return res;
        }
        
        sort(nums.begin(), nums.end());
        dfs(nums, res, 0);
        
        return res;
        
    }
    
    void dfs(vector<int> num, vector<vector<int>> &res, int pos)
    {
        if(pos == num.size())
        {
            res.push_back(num);
        }
        else
        {
            for(int i = pos; i < num.size(); i++)
            {
                if(i != pos && num[i] == num[pos])
                {
                    continue;
                }
                else
                {
                    swap(num[i], num[pos]);
                    dfs(num, res, pos+1);
                }
            }
        }
        return;
    }
};