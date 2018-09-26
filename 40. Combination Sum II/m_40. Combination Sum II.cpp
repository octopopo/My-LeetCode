class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int cL = candidates.size();
        vector<vector<int>> res;
        set<vector<int>> resSet;
        if(cL == 0)
        {
            return res;
        }
        sort(candidates.begin(), candidates.end());
        vector<int> tempV;
        findComb(candidates, target, tempV, 0, -1, resSet);
        res.insert(res.end(), resSet.begin(), resSet.end());
        return res;
    }
    
    void findComb(vector<int>& candidates, int target, vector<int> tempV, int tempSum, int ptr, set<vector<int>>& resSet)
    {
        if(ptr >= (int)candidates.size())
        {
            return;
        }
        //find the solution without myself
        findComb(candidates, target, tempV, tempSum, ptr+1, resSet);
        //test the solution with myself
        if(ptr != -1)
        {
            tempSum += candidates[ptr];
            tempV.push_back(candidates[ptr]);
            if(tempSum == target)
            {
                resSet.insert(tempV);
                return;
            }
            else if(tempSum > target)
            {
                return;
            }
            else
            {
                findComb(candidates, target, tempV, tempSum, ptr+1, resSet);
            }
            return;
        }
        return;
    }
};