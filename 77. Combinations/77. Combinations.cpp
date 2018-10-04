class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        if(k == 0 || n == 0)
        {
            vector<vector<int>> res;
            return res;
        }
        vector<vector<int>> res;
        vector<int> tempRes(k,0);
        dfs(tempRes, res, 0, n, k, 0);
        
        return res;
        
    }
    
    void dfs(vector<int> tempRes, vector<vector<int>> &res, int pos, int n, int k, int lastNum)
    {
        if(pos == k)
        {
            res.push_back(tempRes);
            return;
        }
        else
        {
            for(int i = lastNum+1; i <= n; i++)
            {
                if(i > n-(k-pos)+1)
                {
                    break;
                }
                tempRes[pos] = i;
                dfs(tempRes, res, pos+1, n, k, i);
            }
        }
    }
};